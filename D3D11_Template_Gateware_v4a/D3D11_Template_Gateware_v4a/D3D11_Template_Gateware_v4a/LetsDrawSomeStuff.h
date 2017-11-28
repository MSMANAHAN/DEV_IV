// This file can be used to contain very basic DX11 Loading, Drawing & Clean Up. (Start Here, or Make your own set of classes)
#pragma once
// Include our DX11 middle ware
#include "Gateware Redistributable R4a/Interface/G_Graphics/GDirectX11Surface.h"
// You can clean this up and make it much nicer, otherwise you are stuck in debug 32bit :P
#pragma comment(lib, "Gateware Redistributable R4a/Archive/Win32/Gateware_i386/Debug/GDirectX11Surface.lib")

// Include DirectX11 for interface access
#include <d3d11.h>
#include <DirectXMath.h>
#include <dxgiformat.h> 
#include "DirectXTex-master\DirectXTex\DirectXTex.h"
#include "DirectXTex-master\DDSTextureLoader\DDSTextureLoader.h"
//#include <d3dx11tex.h>
#include "cameraclass.h"
#include "ShaderInvoker.h"
#include "test pyramid.h"
using namespace DirectX;

#define COLOR false
#define TEXTURE false
#define MESHLIGHT true

// Simple Container class to make life easier/cleaner
class LetsDrawSomeStuff
{
	// variables here
	GW::GRAPHICS::GDirectX11Surface* mySurface = nullptr;
	// Gettting these handles from GDirectX11Surface will increase their internal refrence counts, be sure to "Release()" them when done!
	ID3D11Device *myDevice = nullptr;
	IDXGISwapChain *mySwapChain = nullptr;
	ID3D11DeviceContext *myContext = nullptr;

	// TODO: Add your own D3D11 variables here (be sure to "Release()" them when done!)
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	ID3D11ShaderResourceView* m_shaderResourceView;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc;
	ID3D11Resource * m_texture;
	ID3D11Texture2D * m_textureTwoD;

	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
public:
	CameraClass* m_Camera;
	ShaderInvoker *m_ShaderInv;
	// Init
	LetsDrawSomeStuff(GW::SYSTEM::GWindow* attatchPoint);
	// Shutdown
	~LetsDrawSomeStuff();
	// Draw
	void Render();
	float rotation = 0;
	float translation = 0;
private:
	int GetIndexCount();
};

struct Vertex
{
	XMFLOAT3 position;
	XMFLOAT4 color;
};

struct MyTexVertex
{
	MyTexVertex() {};
	MyTexVertex(float x, float y, float z,
		float u, float v)
		: position(x, y, z), UV(u, v) {}

	XMFLOAT3 position;
	XMFLOAT2 UV;
};

struct MyMeshLightVertex
{
	MyMeshLightVertex() {};
	MyMeshLightVertex(float x, float y, float z,
		float u, float v, float w,
		float nx, float ny, float nz)
		: position(x, y, z), UVW(u, v, w), normals(nx, ny, nz) {}

	XMFLOAT3 position;
	XMFLOAT3 UVW;
	XMFLOAT3 normals;
};

// Init
LetsDrawSomeStuff::LetsDrawSomeStuff(GW::SYSTEM::GWindow* attatchPoint)
{
	if (attatchPoint) // valid window?
	{
		// Create surface, will auto attatch to GWindow
		if (G_SUCCESS(GW::GRAPHICS::CreateGDirectX11Surface(attatchPoint, GW::GRAPHICS::DEPTH_BUFFER_SUPPORT, &mySurface)))
		{
			// Grab handles to all DX11 base interfaces
			mySurface->GetDevice((void**)&myDevice);
			mySurface->GetSwapchain((void**)&mySwapChain);
			mySurface->GetContext((void**)&myContext);

			#pragma region Not needed
#if 0
			m_Image->format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			m_Image->height = 1024;
			m_Image->width = 1024;
			m_Image->rowPitch = 128;
			m_Image->slicePitch = 128;
			m_Image->pixels = (uint8_t)1048576;//1048576

			m_Meta->arraySize = 1048576;
			m_Meta->depth = 1;
			m_Meta->dimension = TEX_DIMENSION_TEXTURE2D;
			m_Meta->format = DXGI_FORMAT_R32G32B32A32_FLOAT;
			m_Meta->height = 1024;
			m_Meta->width = 1024;
			m_Meta->mipLevels = 1;
			m_Meta->miscFlags = 0;
			m_Meta->miscFlags2 = 0;
			CreateShaderResourceView(myDevice, m_Image, 1, &m_Meta, &m_shaderResourceView);

#endif // 0
#if 0
			D3D11_TEXTURE2D_DESC desc;
			desc.Width = 256;
			desc.Height = 256;
			desc.MipLevels = desc.ArraySize = 1;
			desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			desc.SampleDesc.Count = 1;
			desc.Usage = D3D11_USAGE_DYNAMIC;
			desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
			desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			desc.MiscFlags = 0;

			ID3D11Texture2D *pTexture = NULL;
			myDevice->CreateTexture2D(&desc, NULL, &pTexture);
			

#endif // 0
#pragma endregion

			// TODO: Create new DirectX stuff here! (Buffers, Shaders, Layouts, Views, Textures, etc...)
			//Vertex* vertices;
			HRESULT result;

#if TEXTURE
			result = CreateDDSTextureFromFile(myDevice, L"GrassTexture.dds", &m_texture, &m_shaderResourceView, DXGI_ALPHA_MODE_UNSPECIFIED);

			if (FAILED(result))
			{
				cout << "Texture not work";
			}

			// Set the number of vertices in the vertex array.
			m_vertexCount = 24;

			// Set the number of indices in the index array.
			m_indexCount = 36;		
			MyTexVertex cubeVerts[] =
			{
				// Front Face
				MyTexVertex(-1.0f, -1.0f, -1.0f, 0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, -1.0f, 0.0f, 0.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f, 1.0f, 0.0f),
				MyTexVertex(1.0f, -1.0f, -1.0f, 1.0f, 1.0f),

				// Back Face
				MyTexVertex(-1.0f, -1.0f, 1.0f, 1.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, 1.0f, 0.0f, 1.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f, 0.0f, 0.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f, 1.0f, 0.0f),

				// Top Face
				MyTexVertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f, 1.0f, 1.0f),

				// Bottom Face
				MyTexVertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, -1.0f, 0.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, 1.0f, 0.0f, 0.0f),
				MyTexVertex(-1.0f, -1.0f, 1.0f, 1.0f, 0.0f),

				// Left Face
				MyTexVertex(-1.0f, -1.0f, 1.0f, 0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f, 0.0f, 0.0f),
				MyTexVertex(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f),
				MyTexVertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f),

				// Right Face
				MyTexVertex(1.0f, -1.0f, -1.0f, 0.0f, 1.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f, 0.0f, 0.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f, 1.0f, 0.0f),
				MyTexVertex(1.0f, -1.0f, 1.0f, 1.0f, 1.0f),
			};

			unsigned int indices[] = {
				// Front Face
				0,  1,  2,
				0,  2,  3,

				// Back Face
				4,  5,  6,
				4,  6,  7,

				// Top Face
				8,  9, 10,
				8, 10, 11,

				// Bottom Face
				12, 13, 14,
				12, 14, 15,

				// Left Face
				16, 17, 18,
				16, 18, 19,

				// Right Face
				20, 21, 22,
				20, 22, 23
			};

			// Set up the description of the static vertex buffer.
			vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc.ByteWidth = sizeof(MyTexVertex) * m_vertexCount;
			vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc.CPUAccessFlags = 0;
			vertexBufferDesc.MiscFlags = 0;
			vertexBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData.pSysMem = cubeVerts;
			vertexData.SysMemPitch = 0;
			vertexData.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);

			// Set up the description of the static index buffer.
			indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc.ByteWidth = sizeof(unsigned int) * m_indexCount;
			indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc.CPUAccessFlags = 0;
			indexBufferDesc.MiscFlags = 0;
			indexBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the index data.
			indexData.pSysMem = indices;
			indexData.SysMemPitch = 0;
			indexData.SysMemSlicePitch = 0;

			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);

			// Create the camera object.
			m_Camera = new CameraClass;
			// Set the initial position of the camera.
			m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

			m_ShaderInv = new ShaderInvoker;
			m_ShaderInv->Initialize(myDevice);

			// Release the arrays now that the vertex and index buffers have been created and loaded.
			//delete[] cubeVerts;
			//cubeVerts = 0;

			//delete[] indices;
			////indices = 0;
#endif // TEXTURE

#if COLOR
			
			Vertex* vertices;
			unsigned int * indices;//may need to be unsigned long

			// Set the number of vertices in the vertex array.
			m_vertexCount = 3;

			// Set the number of indices in the index array.
			m_indexCount = 3;

			// Create the vertex array.
			vertices = new Vertex[m_vertexCount];

			// Create the index array.
			indices = new unsigned int[m_indexCount];

			// Load the vertex array with data.
			vertices[0].position = XMFLOAT3(-1.0f, -1.0f, 0.0f);  // Bottom left.
			vertices[0].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

			vertices[1].position = XMFLOAT3(0.0f, 1.0f, 0.0f);  // Top middle.
			vertices[1].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

			vertices[2].position = XMFLOAT3(1.0f, -1.0f, 0.0f);  // Bottom right.
			vertices[2].color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

			// Load the index array with data.
			indices[0] = 0;  // Bottom left.
			indices[1] = 1;  // Top middle.
			indices[2] = 2;  // Bottom right.


			


			// Set up the description of the static vertex buffer.
			vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc.ByteWidth = sizeof(Vertex) * m_vertexCount;
			vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc.CPUAccessFlags = 0;
			vertexBufferDesc.MiscFlags = 0;
			vertexBufferDesc.StructureByteStride = 0;


			// Give the subresource structure a pointer to the vertex data.
			vertexData.pSysMem = vertices;
			vertexData.SysMemPitch = 0;
			vertexData.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);

			// Set up the description of the static index buffer.
			indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc.ByteWidth = sizeof(unsigned int) * m_indexCount;
			indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc.CPUAccessFlags = 0;
			indexBufferDesc.MiscFlags = 0;
			indexBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the index data.
			indexData.pSysMem = indices;
			indexData.SysMemPitch = 0;
			indexData.SysMemSlicePitch = 0;

			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);

			// Create the camera object.
			m_Camera = new CameraClass;
			// Set the initial position of the camera.
			m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

			m_ShaderInv = new ShaderInvoker;
			m_ShaderInv->Initialize(myDevice);

			//Set up resource, shader view description, shader resource view
			//m_textureResource;
			//m_textureResource
			//m_ShaderResourceViewDesc;
			//m_shaderResourceView;

			//myDevice->CreateShaderResourceView(m_textureResource, )

			// Release the arrays now that the vertex and index buffers have been created and loaded.
			delete[] vertices;
			vertices = 0;

			delete[] indices;
			indices = 0;
#endif // 0

#if MESHLIGHT
			result = CreateDDSTextureFromFile(myDevice, L"Pyramid.dds", &m_texture, &m_shaderResourceView, DXGI_ALPHA_MODE_UNSPECIFIED);

			if (FAILED(result))
			{
				cout << "Texture not work";
			}
			// Set the number of vertices in the vertex array.
			m_vertexCount = 768;

			// Set the number of indices in the index array.
			m_indexCount = 1674;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount;
			vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc.CPUAccessFlags = 0;
			vertexBufferDesc.MiscFlags = 0;
			vertexBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData.pSysMem = test_pyramid_data;
			vertexData.SysMemPitch = 0;
			vertexData.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);

			// Set up the description of the static index buffer.
			indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc.ByteWidth = sizeof(unsigned int) * m_indexCount;
			indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc.CPUAccessFlags = 0;
			indexBufferDesc.MiscFlags = 0;
			indexBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the index data.
			indexData.pSysMem = test_pyramid_indicies;
			indexData.SysMemPitch = 0;
			indexData.SysMemSlicePitch = 0;

			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);

			// Create the camera object.
			m_Camera = new CameraClass;
			// Set the initial position of the camera.
			m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

			m_ShaderInv = new ShaderInvoker;
			m_ShaderInv->Initialize(myDevice);
#endif // MESHLIGHT

		}
	}
}

// Shutdown
LetsDrawSomeStuff::~LetsDrawSomeStuff()
{
	// Release DX Objects aquired from the surface
	myDevice->Release();
	mySwapChain->Release();
	myContext->Release();

	// TODO: "Release()" more stuff here!

	if (mySurface) // Free Gateware Interface
	{
		mySurface->DecrementCount(); // reduce internal count (will auto delete on Zero)
		mySurface = nullptr; // the safest way to fly
	}

	// If index buffer exists, release and set to 0
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// If vertex buffer exists, release and set to 0
	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	if (m_Camera)
	{
		delete m_Camera;
	}

	if (m_ShaderInv)
	{
		delete m_ShaderInv;
	}
}

// Draw
void LetsDrawSomeStuff::Render()
{
	if (mySurface) // valid?
	{
		// this could be changed during resolution edits, get it every frame
		ID3D11RenderTargetView *myRenderTargetView = nullptr;
		ID3D11DepthStencilView *myDepthStencilView = nullptr;
		if (G_SUCCESS(mySurface->GetRenderTarget((void**)&myRenderTargetView)))
		{
			// Grab the Z Buffer if one was requested
			if (G_SUCCESS(mySurface->GetDepthStencilView((void**)&myDepthStencilView)))
			{
				myContext->ClearDepthStencilView(myDepthStencilView, D3D11_CLEAR_DEPTH, 1, 0); // clear it to Z exponential Far.
				myDepthStencilView->Release();
			}

			// Set active target for drawing, all array based D3D11 functions should use a syntax similar to below
			ID3D11RenderTargetView* const targets[] = { myRenderTargetView };
			myContext->OMSetRenderTargets(1, targets, myDepthStencilView);

			// Clear the screen to black
			const float black[] = { 0, 0, 1, 1 };
			myContext->ClearRenderTargetView(myRenderTargetView, black);
			
			// TODO: Set your shaders, Update & Set your constant buffers, Attatch your vertex & index buffers, Set your InputLayout & Topology & Draw!
			XMMATRIX worldMatrix, viewMatrix, projectionMatrix;

			m_Camera->Render();

			#pragma region MODEL RENDER
			// TODO: Set your shaders, Update & Set your constant buffers, Attatch your vertex & index buffers, Set your InputLayout & Topology & Draw!
			unsigned int stride;
			unsigned int offset;

#if MESHLIGHT
			// Set vertex buffer stride and offset.
			stride = sizeof(MyMeshLightVertex);
			offset = 0;


#endif // TEXTURE

#if TEXTURE
			// Set vertex buffer stride and offset.
			stride = sizeof(MyTexVertex);
			offset = 0;


#endif // TEXTURE

#if COLOR
			// Set vertex buffer stride and offset.
			stride = sizeof(Vertex);
			offset = 0;

#endif // COLOR

			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

			// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
			myContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

#pragma endregion

			worldMatrix = DirectX::XMMatrixIdentity();
			m_Camera->GetViewMatrix(viewMatrix);
			projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(3.14f / 4.0f, 1024 / 768, 0.1f, 10);
			myContext->PSSetShaderResources(0, 1, &m_shaderResourceView);
			//worldMatrix = XMMatrixRotationRollPitchYaw(rotation, 0, 0);
			worldMatrix = XMMatrixScaling(3, 3, 3);
			m_ShaderInv->Render(myContext, GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
			worldMatrix = XMMatrixTranslation(translation, 0, 0);
			m_ShaderInv->Render(myContext, GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);

			// Present Backbuffer using Swapchain object
			// Framerate is currently unlocked, we suggest "MSI Afterburner" to track your current FPS and memory usage.
			mySwapChain->Present(0, 0);

			// Free any temp DX handles acquired this frame
			myRenderTargetView->Release();
		}
	}
}

int LetsDrawSomeStuff::GetIndexCount()
{
	return m_indexCount;
}
