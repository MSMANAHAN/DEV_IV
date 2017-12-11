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
#include <iostream>
#include <thread>
#include "DirectXTex-master\DirectXTex\DirectXTex.h"
#include "DirectXTex-master\DDSTextureLoader\DDSTextureLoader.h"
//#include <d3dx11tex.h>
#include "cameraclass.h"
#include "ShaderInvoker.h"
#include "test pyramid.h"
#include "tree.h"
#include "wall.h"
#include "sword1.h"
#include "model.h"
#include "Grass_03.h"
#include "Rope Bridge.h"
#include "chevalier.h"
#include "Knight2.h"
#include "knight3.h"
#include "Rock_6.h"
#include "Rock.h"
#include "Asian_Nomad_Old_Man_Body.h"

using namespace DirectX;
#define COLOR false
#define TEXTURE false
#define MESHLIGHT true
#define TEXTURECOUNT 11

// Simple Container class to make life easier/cleaner
class LetsDrawSomeStuff
{
	// variables here
	GW::GRAPHICS::GDirectX11Surface* mySurface = nullptr;
	// Gettting these handles from GDirectX11Surface will increase their internal refrence counts, be sure to "Release()" them when done!
	ID3D11Device *myDevice = nullptr;
	IDXGISwapChain *mySwapChain = nullptr;
	ID3D11DeviceContext *myImmContext = nullptr;
	ID3D11DeviceContext *myDefContext = nullptr;

	XMFLOAT4 m_diffuseColor;
	XMFLOAT3 m_lightDir;
	ID3D11Buffer* m_instanceBuffer;
	int m_instanceCount;
	std::vector<std::thread> ThreadVector;


	// TODO: Add your own D3D11 variables here (be sure to "Release()" them when done!)
#pragma region Mesh 1
	ID3D11Buffer *m_vertexBuffer1;
	ID3D11Buffer *m_indexBuffer1;
	int m_vertexCount1;
	int m_indexCount1;
	ID3D11ShaderResourceView* m_shaderResourceView1;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc1; 
	ID3D11Resource * m_texture1;
	D3D11_BUFFER_DESC vertexBufferDesc1;
	D3D11_BUFFER_DESC indexBufferDesc1;
	D3D11_SUBRESOURCE_DATA vertexData1;
	D3D11_SUBRESOURCE_DATA indexData1;
#pragma endregion
	
#pragma region Mesh 2
	ID3D11Buffer *m_vertexBuffer2;
	ID3D11Buffer *m_indexBuffer2;
	int m_vertexCount2;
	int m_indexCount2;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc2;
	ID3D11ShaderResourceView* m_shaderResourceView2;
	ID3D11Resource * m_texture2;
	D3D11_BUFFER_DESC vertexBufferDesc2;
	D3D11_BUFFER_DESC indexBufferDesc2;
	D3D11_SUBRESOURCE_DATA vertexData2;
	D3D11_SUBRESOURCE_DATA indexData2;

#pragma endregion

#pragma region Mesh 3
	ID3D11Buffer *m_vertexBuffer3;
	ID3D11Buffer *m_indexBuffer3;
	int m_vertexCount3;
	int m_indexCount3;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc3;
	ID3D11ShaderResourceView* m_shaderResourceView3;
	ID3D11Resource * m_texture3;
	D3D11_BUFFER_DESC vertexBufferDesc3;
	D3D11_BUFFER_DESC indexBufferDesc3;
	D3D11_SUBRESOURCE_DATA vertexData3;
	D3D11_SUBRESOURCE_DATA indexData3;
#pragma endregion

#pragma region Mesh4
	ID3D11Buffer *m_vertexBuffer4;
	ID3D11Buffer *m_indexBuffer4;
	int m_vertexCount4;
	int m_indexCount4;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc4;
	ID3D11ShaderResourceView* m_shaderResourceView4;
	ID3D11Resource * m_texture4;
	D3D11_BUFFER_DESC vertexBufferDesc4;
	D3D11_BUFFER_DESC indexBufferDesc4;
	D3D11_SUBRESOURCE_DATA vertexData4;
	D3D11_SUBRESOURCE_DATA indexData4;
#pragma endregion

#pragma region Mesh5
	ID3D11Buffer *m_vertexBuffer5;
	ID3D11Buffer *m_indexBuffer5;
	int m_vertexCount5;
	int m_indexCount5;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc5;
	ID3D11ShaderResourceView* m_shaderResourceView5;
	ID3D11Resource * m_texture5;
	D3D11_BUFFER_DESC vertexBufferDesc5;
	D3D11_BUFFER_DESC indexBufferDesc5;
	D3D11_SUBRESOURCE_DATA vertexData5;
	D3D11_SUBRESOURCE_DATA indexData5;
#pragma endregion

#pragma region Mesh6
	ID3D11Buffer *m_vertexBuffer6;
	ID3D11Buffer *m_indexBuffer6;
	int m_vertexCount6;
	int m_indexCount6;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc6;
	ID3D11ShaderResourceView* m_shaderResourceView6;
	ID3D11Resource * m_texture6;
	D3D11_BUFFER_DESC vertexBufferDesc6;
	D3D11_BUFFER_DESC indexBufferDesc6;
	D3D11_SUBRESOURCE_DATA vertexData6;
	D3D11_SUBRESOURCE_DATA indexData6;
#pragma endregion

#pragma region Mesh7
	ID3D11Buffer *m_vertexBuffer7;
	ID3D11Buffer *m_indexBuffer7;
	int m_vertexCount7;
	int m_indexCount7;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc7;
	ID3D11ShaderResourceView* m_shaderResourceView7;
	ID3D11Resource * m_texture7;
	D3D11_BUFFER_DESC vertexBufferDesc7;
	D3D11_BUFFER_DESC indexBufferDesc7;
	D3D11_SUBRESOURCE_DATA vertexData7;
	D3D11_SUBRESOURCE_DATA indexData7;
#pragma endregion

#pragma region Mesh8
	ID3D11Buffer *m_vertexBuffer8;
	ID3D11Buffer *m_indexBuffer8;
	int m_vertexCount8;
	int m_indexCount8;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc8;
	ID3D11ShaderResourceView* m_shaderResourceView8;
	ID3D11Resource * m_texture8;
	D3D11_BUFFER_DESC vertexBufferDesc8;
	D3D11_BUFFER_DESC indexBufferDesc8;
	D3D11_SUBRESOURCE_DATA vertexData8;
	D3D11_SUBRESOURCE_DATA indexData8;
#pragma endregion

#pragma region Mesh9
	ID3D11Buffer *m_vertexBuffer9;
	ID3D11Buffer *m_indexBuffer9;
	int m_vertexCount9;
	int m_indexCount9;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc9;
	ID3D11ShaderResourceView* m_shaderResourceView9;
	ID3D11Resource * m_texture9;
	D3D11_BUFFER_DESC vertexBufferDesc9;
	D3D11_BUFFER_DESC indexBufferDesc9;
	D3D11_SUBRESOURCE_DATA vertexData9;
	D3D11_SUBRESOURCE_DATA indexData9;
#pragma endregion

#pragma region Mesh10
	ID3D11Buffer *m_vertexBuffer10;
	ID3D11Buffer *m_indexBuffer10;
	int m_vertexCount10;
	int m_indexCount10;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc10;
	ID3D11ShaderResourceView* m_shaderResourceView10;
	ID3D11Resource * m_texture10;
	D3D11_BUFFER_DESC vertexBufferDesc10;
	D3D11_BUFFER_DESC indexBufferDesc10;
	D3D11_SUBRESOURCE_DATA vertexData10;
	D3D11_SUBRESOURCE_DATA indexData10;
#pragma endregion

#pragma region Mesh11
	ID3D11Buffer *m_vertexBuffer11;
	ID3D11Buffer *m_indexBuffer11;
	int m_vertexCount11;
	int m_indexCount11;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDesc11;
	ID3D11ShaderResourceView* m_shaderResourceView11;
	ID3D11Resource * m_texture11;
	D3D11_BUFFER_DESC vertexBufferDesc11;
	D3D11_BUFFER_DESC indexBufferDesc11;
	D3D11_SUBRESOURCE_DATA vertexData11;
	D3D11_SUBRESOURCE_DATA indexData11;
#pragma endregion


#pragma region Skybox
	ID3D11Buffer *m_vertexBufferSky;
	ID3D11Buffer *m_indexBufferSky;
	int m_vertexCountSky;
	int m_indexCountSky;
	D3D11_SHADER_RESOURCE_VIEW_DESC m_ShaderResourceViewDescSky;
	ID3D11ShaderResourceView* m_shaderResourceViewSky;
	ID3D11Resource * m_textureSky;
	D3D11_BUFFER_DESC vertexBufferDescSky;
	D3D11_BUFFER_DESC indexBufferDescSky;
	D3D11_SUBRESOURCE_DATA vertexDataSky;
	D3D11_SUBRESOURCE_DATA indexDataSky;
#pragma endregion


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
	float nearPlane = 0.1f;
	float farPlane = 50;
	float zoomFOV = 4;
	bool UVScrolling = false;
	unsigned int width;
	unsigned int height;
private:
	int GetIndexCount();
	struct TextureThreadType
	{
		int id;
		ID3D11Device* d3dDevice;
		const wchar_t* fileName;
		ID3D11Resource** texture;
		ID3D11ShaderResourceView** textureView;
	};
	void JoinableThreadEntrypoint(TextureThreadType *threadData);
	void ProcessTextures(int id);
	TextureThreadType arrayOfTextures[TEXTURECOUNT];
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
		: position(x, y, z, w), UVW(u, v, w), normals(nx, ny, nz) {}

	XMFLOAT4 position;
	XMFLOAT3 UVW;
	XMFLOAT3 normals;
};

struct InstanceType
{
	XMFLOAT3 position;
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
			mySurface->GetContext((void**)&myImmContext);

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
				MyTexVertex(-1.0f, -1.0f, -1.0f,0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, -1.0f,0.0f,0.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f, 1.0f,0.0f),
				MyTexVertex(1.0f, -1.0f, -1.0f, 1.0f, 1.0f),

				// Back Face
				MyTexVertex(-1.0f, -1.0f, 1.0f, 1.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, 1.0f,0.0f, 1.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f,0.0f,0.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f, 1.0f,0.0f),

				// Top Face
				MyTexVertex(-1.0f, 1.0f, -1.0f,0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f,0.0f,0.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f, 1.0f,0.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f, 1.0f, 1.0f),

				// Bottom Face
				MyTexVertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, -1.0f,0.0f, 1.0f),
				MyTexVertex(1.0f, -1.0f, 1.0f,0.0f,0.0f),
				MyTexVertex(-1.0f, -1.0f, 1.0f, 1.0f,0.0f),

				// Left Face
				MyTexVertex(-1.0f, -1.0f, 1.0f,0.0f, 1.0f),
				MyTexVertex(-1.0f, 1.0f, 1.0f,0.0f,0.0f),
				MyTexVertex(-1.0f, 1.0f, -1.0f, 1.0f,0.0f),
				MyTexVertex(-1.0f, -1.0f, -1.0f, 1.0f, 1.0f),

				// Right Face
				MyTexVertex(1.0f, -1.0f, -1.0f,0.0f, 1.0f),
				MyTexVertex(1.0f, 1.0f, -1.0f,0.0f,0.0f),
				MyTexVertex(1.0f, 1.0f, 1.0f, 1.0f,0.0f),
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
			m_Camera->SetPosition(0.0f,0.0f, -5.0f);

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
			vertices[0].position = XMFLOAT3(-1.0f, -1.0f,0.0f);  // Bottom left.
			vertices[0].color = XMFLOAT4(0.0f, 1.0f,0.0f, 1.0f);

			vertices[1].position = XMFLOAT3(0.0f, 1.0f,0.0f);  // Top middle.
			vertices[1].color = XMFLOAT4(0.0f, 1.0f,0.0f, 1.0f);

			vertices[2].position = XMFLOAT3(1.0f, -1.0f,0.0f);  // Bottom right.
			vertices[2].color = XMFLOAT4(0.0f, 1.0f,0.0f, 1.0f);

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
			m_Camera->SetPosition(0.0f,0.0f, -5.0f);

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

#pragma region arrayOfTextures Initialization

			arrayOfTextures[0] =
			{
				0,
				myDevice,
				L"wall.dds",
				&m_texture1,
				&m_shaderResourceView1
			};
			arrayOfTextures[1] =
			{
				1,
				myDevice,
				L"Pyramid.dds",
				&m_texture2,
				&m_shaderResourceView2
			};
			arrayOfTextures[2] =
			{
				2,
				myDevice,
				L"grass_diff.dds",
				&m_texture3,
				&m_shaderResourceView3
			};
			arrayOfTextures[3] =
			{
				3,
				myDevice,
				L"Bridge_Plank.dds",
				&m_texture5,
				&m_shaderResourceView5
			};
			arrayOfTextures[4] =
			{
				4,
				myDevice,
				L"chevalier.dds",
				&m_texture6,
				&m_shaderResourceView6
			};
			arrayOfTextures[5] =
			{
				5,
				myDevice,
				L"SunsetSkybox.dds",
				&m_textureSky,
				&m_shaderResourceViewSky
			};
			arrayOfTextures[6] =
			{
				6,
				myDevice,
				L"knight2.dds",
				&m_texture7,
				&m_shaderResourceView7
			};
			arrayOfTextures[7] =
			{
				7,
				myDevice,
				L"knight3.dds",
				&m_texture8,
				&m_shaderResourceView8
			};

			arrayOfTextures[8] =
			{
				8,
				myDevice,
				L"Rock_6_d.dds",
				&m_texture9,
				&m_shaderResourceView9
			};
			arrayOfTextures[9] =
			{
				9,
				myDevice,
				L"Rock_Base_Color.dds",
				&m_texture10,
				&m_shaderResourceView10
			};

			arrayOfTextures[10] =
			{
				10,
				myDevice,
				L"OldMan.dds",
				&m_texture11,
				&m_shaderResourceView11
			};
#pragma endregion

		for (size_t i = 0; i < TEXTURECOUNT; i++)
		{
			ThreadVector.push_back(std::thread(&LetsDrawSomeStuff::JoinableThreadEntrypoint, this, &arrayOfTextures[i]));
		}

		for (auto& thread : ThreadVector)
		{
			thread.join();
		}

#pragma region Mesh1

			//result = CreateDDSTextureFromFile(myDevice, L"wall.dds", &m_texture1, &m_shaderResourceView1, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount1 = 776;

			// Set the number of indices for the tree
			m_indexCount1 = 1692;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc1.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc1.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount1;
			vertexBufferDesc1.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc1.CPUAccessFlags = 0;
			vertexBufferDesc1.MiscFlags = 0;
			vertexBufferDesc1.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData1.pSysMem = wall_data;
			vertexData1.SysMemPitch = 0;
			vertexData1.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc1, &vertexData1, &m_vertexBuffer1);

			// Set up the description of the static index buffer.
			indexBufferDesc1.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc1.ByteWidth = sizeof(unsigned int) * (m_indexCount1);
			indexBufferDesc1.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc1.CPUAccessFlags = 0;
			indexBufferDesc1.MiscFlags = 0;
			indexBufferDesc1.StructureByteStride = 0;

			// Give the subresource structure a pointer to the index data.
			indexData1.pSysMem = wall_indicies;
			indexData1.SysMemPitch = 0;
			indexData1.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc1, &indexData1, &m_indexBuffer1);

#pragma endregion

#pragma region Mesh2
			//result = CreateDDSTextureFromFile(myDevice, L"Pyramid.dds", &m_texture2, &m_shaderResourceView2, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount2 = 768;

			// Set the number of indices for the pyramid
			m_indexCount2 = 1674;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc2.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc2.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount2;
			vertexBufferDesc2.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc2.CPUAccessFlags = 0;
			vertexBufferDesc2.MiscFlags = 0;
			vertexBufferDesc2.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData2.pSysMem = test_pyramid_data;
			vertexData2.SysMemPitch = 0;
			vertexData2.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc2, &vertexData2, &m_vertexBuffer2);

			// Set up the description of the static index buffer.
			indexBufferDesc2.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc2.ByteWidth = sizeof(unsigned int) * (m_indexCount2);
			indexBufferDesc2.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc2.CPUAccessFlags = 0;
			indexBufferDesc2.MiscFlags = 0;
			indexBufferDesc2.StructureByteStride = 0;

			indexData2.pSysMem = test_pyramid_indicies;
			indexData2.SysMemPitch = 0;
			indexData2.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc2, &indexData2, &m_indexBuffer2);
#pragma endregion

#pragma region Mesh3

			InstanceType* instances;
			D3D11_BUFFER_DESC vertexBufferDesc, instanceBufferDesc;
			D3D11_SUBRESOURCE_DATA vertexData, instanceData;
			// Set the number of instances in the array.
			//result = CreateDDSTextureFromFile(myDevice, L"grass_diff.dds", &m_texture3, &m_shaderResourceView3, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{				
			//	std::cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount3 = 8989;

			// Set the number of indices for the pyramid
			m_indexCount3 = 18429;
			
			m_instanceCount = 100;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc3.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc3.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount3;
			vertexBufferDesc3.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc3.CPUAccessFlags = 0;
			vertexBufferDesc3.MiscFlags = 0;
			vertexBufferDesc3.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData3.pSysMem = Grass_03_data;
			vertexData3.SysMemPitch = 0;
			vertexData3.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc3, &vertexData3, &m_vertexBuffer3);

			// Set up the description of the static index buffer.
			indexBufferDesc3.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc3.ByteWidth = sizeof(unsigned int) * (m_indexCount3);
			indexBufferDesc3.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc3.CPUAccessFlags = 0;
			indexBufferDesc3.MiscFlags = 0;
			indexBufferDesc3.StructureByteStride = 0;

			indexData3.pSysMem = Grass_03_indicies;
			indexData3.SysMemPitch = 0;
			indexData3.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc3, &indexData3, &m_indexBuffer3);

			// Create the instance buffer.
			instances = new InstanceType[m_instanceCount];
			// Load the instance array with data.
			float xGrass = 3;
			float ZGrassReal = 0;
			for (unsigned int i = 0; i < m_instanceCount; i++)
			{
				/*
					         g  6  g
					         g  5  g
					         g  4  g
					          g 3 g
					          g 2 g
					          g 1 g
					6 5 4 3 2 1 0 1 2 3 4 5 6
				*/
				if (i % 10)
				{
					//xGrass +=1.0f;
				}
				if (i % 2 == 0)
				{
					ZGrassReal +=1.0f;
					instances[i].position = XMFLOAT3(-xGrass, 0, ZGrassReal);				
				}
				else
					instances[i].position = XMFLOAT3(xGrass, 0, ZGrassReal);

			}

			// Set up the description of the instance buffer.
			instanceBufferDesc.Usage = D3D11_USAGE_DEFAULT;
			instanceBufferDesc.ByteWidth = sizeof(InstanceType) * m_instanceCount;
			instanceBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			instanceBufferDesc.CPUAccessFlags = 0;
			instanceBufferDesc.MiscFlags = 0;
			instanceBufferDesc.StructureByteStride = 0;

			// Give the subresource structure a pointer to the instance data.
			instanceData.pSysMem = instances;
			instanceData.SysMemPitch = 0;
			instanceData.SysMemSlicePitch = 0;

			// Create the instance buffer.
			result = myDevice->CreateBuffer(&instanceBufferDesc, &instanceData, &m_instanceBuffer);
#pragma endregion

#pragma region Mesh4
			MyMeshLightVertex spiralArr[361];
			unsigned int indicies[361];
			//circle array initialization
			for (int i = 0; i < 361; i++)
			{
				spiralArr[i].normals.x = 0;
				spiralArr[i].normals.y = 0;
				spiralArr[i].normals.z = 0;

				spiralArr[i].UVW.x = 0;
				spiralArr[i].UVW.y = 0;
				spiralArr[i].UVW.z = 0;

				spiralArr[i].position.x = 0.95f *sin(XMConvertToRadians(i));
				spiralArr[i].position.y = 0.95f *cos(XMConvertToRadians(i));
				spiralArr[i].position.z = 1;
				spiralArr[i].position.w = 1;
				indicies[i] = i;
			}

			// Set the number of vertices in the vertex array.
			m_vertexCount4 = 361;

			// Set the number of indices for the pyramid
			m_indexCount4 = 361;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc4.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc4.ByteWidth = sizeof(MyMeshLightVertex) * m_vertexCount4;
			vertexBufferDesc4.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc4.CPUAccessFlags = 0;
			vertexBufferDesc4.MiscFlags = 0;
			vertexBufferDesc4.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData4.pSysMem = spiralArr;
			vertexData4.SysMemPitch = 0;
			vertexData4.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc4, &vertexData4, &m_vertexBuffer4);

			// Set up the description of the static index buffer.
			indexBufferDesc4.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc4.ByteWidth = sizeof(unsigned int) * (m_indexCount4);
			indexBufferDesc4.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc4.CPUAccessFlags = 0;
			indexBufferDesc4.MiscFlags = 0;
			indexBufferDesc4.StructureByteStride = 0;

			indexData4.pSysMem = indicies;
			indexData4.SysMemPitch = 0;
			indexData4.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc4, &indexData4, &m_indexBuffer4);
#pragma endregion

#pragma region Mesh5
			//result = CreateDDSTextureFromFile(myDevice, L"Bridge_Plank.dds", &m_texture5, &m_shaderResourceView5, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount5 = 3307;

			// Set the number of indices for the pyramid
			m_indexCount5 = 9936;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc5.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc5.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount5;
			vertexBufferDesc5.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc5.CPUAccessFlags = 0;
			vertexBufferDesc5.MiscFlags = 0;
			vertexBufferDesc5.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData5.pSysMem = Rope_Bridge_data;
			vertexData5.SysMemPitch = 0;
			vertexData5.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc5, &vertexData5, &m_vertexBuffer5);

			// Set up the description of the static index buffer.
			indexBufferDesc5.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc5.ByteWidth = sizeof(unsigned int) * (m_indexCount5);
			indexBufferDesc5.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc5.CPUAccessFlags = 0;
			indexBufferDesc5.MiscFlags = 0;
			indexBufferDesc5.StructureByteStride = 0;

			indexData5.pSysMem = Rope_Bridge_indicies;
			indexData5.SysMemPitch = 0;
			indexData5.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc5, &indexData5, &m_indexBuffer5);
#pragma endregion

#pragma region Mesh6
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount6 = 1211;

			// Set the number of indices for the pyramid
			m_indexCount6 = 2922;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc6.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc6.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount6;
			vertexBufferDesc6.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc6.CPUAccessFlags = 0;
			vertexBufferDesc6.MiscFlags = 0;
			vertexBufferDesc6.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData6.pSysMem = chevalier_data;
			vertexData6.SysMemPitch = 0;
			vertexData6.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc6, &vertexData6, &m_vertexBuffer6);

			// Set up the description of the static index buffer.
			indexBufferDesc6.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc6.ByteWidth = sizeof(unsigned int) * (m_indexCount6);
			indexBufferDesc6.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc6.CPUAccessFlags = 0;
			indexBufferDesc6.MiscFlags = 0;
			indexBufferDesc6.StructureByteStride = 0;

			indexData6.pSysMem = chevalier_indicies;
			indexData6.SysMemPitch = 0;
			indexData6.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc6, &indexData6, &m_indexBuffer6);
#pragma endregion

#pragma region Mesh7
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount7 = 6623;

			// Set the number of indices for the pyramid
			m_indexCount7 = 8178;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc7.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc7.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount7;
			vertexBufferDesc7.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc7.CPUAccessFlags = 0;
			vertexBufferDesc7.MiscFlags = 0;
			vertexBufferDesc7.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData7.pSysMem = Knight2_data;
			vertexData7.SysMemPitch = 0;
			vertexData7.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc7, &vertexData7, &m_vertexBuffer7);

			// Set up the description of the static index buffer.
			indexBufferDesc7.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc7.ByteWidth = sizeof(unsigned int) * (m_indexCount7);
			indexBufferDesc7.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc7.CPUAccessFlags = 0;
			indexBufferDesc7.MiscFlags = 0;
			indexBufferDesc7.StructureByteStride = 0;

			indexData7.pSysMem = Knight2_indicies;
			indexData7.SysMemPitch = 0;
			indexData7.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc7, &indexData7, &m_indexBuffer7);
#pragma endregion

#pragma region Mesh8
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount8 = 7326;

			// Set the number of indices for the pyramid
			m_indexCount8 = 17766;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc8.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc8.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount8;
			vertexBufferDesc8.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc8.CPUAccessFlags = 0;
			vertexBufferDesc8.MiscFlags = 0;
			vertexBufferDesc8.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData8.pSysMem = knight3_data;
			vertexData8.SysMemPitch = 0;
			vertexData8.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc8, &vertexData8, &m_vertexBuffer8);

			// Set up the description of the static index buffer.
			indexBufferDesc8.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc8.ByteWidth = sizeof(unsigned int) * (m_indexCount8);
			indexBufferDesc8.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc8.CPUAccessFlags = 0;
			indexBufferDesc8.MiscFlags = 0;
			indexBufferDesc8.StructureByteStride = 0;

			indexData8.pSysMem = knight3_indicies;
			indexData8.SysMemPitch = 0;
			indexData8.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc8, &indexData8, &m_indexBuffer8);
#pragma endregion

#pragma region Mesh9
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount9 = 1874;

			// Set the number of indices for the pyramid
			m_indexCount9 = 7986;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc9.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc9.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount9;
			vertexBufferDesc9.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc9.CPUAccessFlags = 0;
			vertexBufferDesc9.MiscFlags = 0;
			vertexBufferDesc9.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData9.pSysMem = Rock_6_data;
			vertexData9.SysMemPitch = 0;
			vertexData9.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc9, &vertexData9, &m_vertexBuffer9);

			// Set up the description of the static index buffer.
			indexBufferDesc9.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc9.ByteWidth = sizeof(unsigned int) * (m_indexCount9);
			indexBufferDesc9.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc9.CPUAccessFlags = 0;
			indexBufferDesc9.MiscFlags = 0;
			indexBufferDesc9.StructureByteStride = 0;

			indexData9.pSysMem = Rock_6_indicies;
			indexData9.SysMemPitch = 0;
			indexData9.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc9, &indexData9, &m_indexBuffer9);
#pragma endregion

#pragma region Mesh10
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount10 = 1844;

			// Set the number of indices for the pyramid
			m_indexCount10 = 7422;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc10.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc10.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount10;
			vertexBufferDesc10.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc10.CPUAccessFlags = 0;
			vertexBufferDesc10.MiscFlags = 0;
			vertexBufferDesc10.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData10.pSysMem = Rock_data;
			vertexData10.SysMemPitch = 0;
			vertexData10.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc10, &vertexData10, &m_vertexBuffer10);

			// Set up the description of the static index buffer.
			indexBufferDesc10.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc10.ByteWidth = sizeof(unsigned int) * (m_indexCount10);
			indexBufferDesc10.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc10.CPUAccessFlags = 0;
			indexBufferDesc10.MiscFlags = 0;
			indexBufferDesc10.StructureByteStride = 0;

			indexData10.pSysMem = Rock_indicies;
			indexData10.SysMemPitch = 0;
			indexData10.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc10, &indexData10, &m_indexBuffer10);
#pragma endregion

#pragma region Mesh11
			//result = CreateDDSTextureFromFile(myDevice, L"chevalier.dds", &m_texture6, &m_shaderResourceView6, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}
			// Set the number of vertices in the vertex array.
			m_vertexCount11 = 6680;

			// Set the number of indices for the pyramid
			m_indexCount11 = 25200;

			// Set up the description of the static vertex buffer.
			vertexBufferDesc11.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDesc11.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCount11;
			vertexBufferDesc11.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDesc11.CPUAccessFlags = 0;
			vertexBufferDesc11.MiscFlags = 0;
			vertexBufferDesc11.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexData11.pSysMem = Asian_Nomad_Old_Man_Body_data;
			vertexData11.SysMemPitch = 0;
			vertexData11.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDesc11, &vertexData11, &m_vertexBuffer11);

			// Set up the description of the static index buffer.
			indexBufferDesc11.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDesc11.ByteWidth = sizeof(unsigned int) * (m_indexCount11);
			indexBufferDesc11.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDesc11.CPUAccessFlags = 0;
			indexBufferDesc11.MiscFlags = 0;
			indexBufferDesc11.StructureByteStride = 0;

			indexData11.pSysMem = Asian_Nomad_Old_Man_Body_indicies;
			indexData11.SysMemPitch = 0;
			indexData11.SysMemSlicePitch = 0;
			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDesc11, &indexData11, &m_indexBuffer11);
#pragma endregion

#pragma region SkyBox
			//result = CreateDDSTextureFromFile(myDevice, L"SunsetSkybox.dds", &m_textureSky, &m_shaderResourceViewSky, DXGI_ALPHA_MODE_UNSPECIFIED);

			//if (FAILED(result))
			//{
			//	cout << "Texture not work";
			//}

			// Set the number of vertices in the vertex array.
			m_vertexCountSky = 36;

			// Set the number of indices in the index array.
			m_indexCountSky = 36;
			_OBJ_VERT_ cubeVerts[] =
			{
				_OBJ_VERT_ {-1.0f,	1.0f,-1.0f,		0.0f, 0.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//00	LEFT	TOP NEAR
				_OBJ_VERT_ {1.0f,	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//01	RIGHT	TOP NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//02	LEFT	BOT NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//03	LEFT	BOT NEAR
				_OBJ_VERT_ {1.0f,	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//04	RIGHT	TOP NEAR
				_OBJ_VERT_ {1.0f,-	1.0f,-1.0f,		1.0f, 1.0f,	0.0f,	 0.0f, 0.0f,-1.0f		},//05	RIGHT	BOT NEAR
				_OBJ_VERT_ {1.0f,	1.0f,-1.0f,		0.0f, 0.0f,	0.0f,	 1.0f, 0.0f, 0.0f		},//06	RIGHT	TOP NEAR
				_OBJ_VERT_ {1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 1.0f, 0.0f, 0.0f,		},//07	RIGHT	TOP FAR
				_OBJ_VERT_ {1.0f,-	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 1.0f, 0.0f, 0.0f		},//08	RIGHT	BOT NEAR
				_OBJ_VERT_ {1.0f,-	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 1.0f, 0.0f, 0.0f		},//09	RIGHT	BOT NEAR
				_OBJ_VERT_ {1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 1.0f, 0.0f, 0.0f		},//10	RIGHT	TOP FAR
				_OBJ_VERT_ {1.0f,-	1.0f, 1.0f,		1.0f, 1.0f,	0.0f,	 1.0f, 0.0f, 0.0f		},//11	RIGHT	BOT FAR
				_OBJ_VERT_ {1.0f,	1.0f, 1.0f,		0.0f, 0.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//12	RIGHT	TOP FAR
				_OBJ_VERT_ {-1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//13	LEFT	TOP FAR
				_OBJ_VERT_ {1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//14	RIGHT	BOT FAR
				_OBJ_VERT_ {1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//15	RIGHT	BOT FAR
				_OBJ_VERT_ {-1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//16	LEFT	TOP FAR
				_OBJ_VERT_ {-1.0f,-	1.0f, 1.0f,		1.0f, 1.0f,	0.0f,	 0.0f, 0.0f, 1.0f		},//17	LEFT	BOT FAR
				_OBJ_VERT_ {-1.0f,	1.0f, 1.0f,		0.0f, 0.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//18	LEFT	TOP FAR
				_OBJ_VERT_ {-1.0f,	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//19	LEFT	TOP NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//20	LEFT	BOT FAR
				_OBJ_VERT_ {-1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//21	LEFT	BOT FAR
				_OBJ_VERT_ {-1.0f,	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//22	LEFT	TOP NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f,-1.0f,		1.0f, 1.0f,	0.0f,	-1.0f, 0.0f, 0.0f		},//23	LEFT	BOT NEAR
				_OBJ_VERT_ {-1.0f,	1.0f, 1.0f,		0.0f, 0.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//24	LEFT	TOP FAR
				_OBJ_VERT_ {1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//25	RIGHT	TOP FAR
				_OBJ_VERT_ {-1.0f,	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//26	LEFT	TOP NEAR
				_OBJ_VERT_ {-1.0f,	1.0f,-1.0f,		0.0f, 1.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//27	LEFT	TOP NEAR
				_OBJ_VERT_ {1.0f,	1.0f, 1.0f,		1.0f, 0.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//28	RIGHT	TOP FAR
				_OBJ_VERT_ {1.0f,	1.0f,-1.0f,		1.0f, 1.0f,	0.0f,	 0.0f, 1.0f, 0.0f		},//29	RIGHT	TOP NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f,-1.0f,		0.0f, 0.0f,	0.0f,	 0.0f,-1.0f, 0.0f		},//30	LEFT	BOT NEAR
				_OBJ_VERT_ {1.0f,-	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	 0.0f,-1.0f, 0.0f		},//31	RIGHT	BOT NEAR
				_OBJ_VERT_ {-1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	 0.0f,-1.0f, 0.0f		},//32	LEFT	BOT FAR
				_OBJ_VERT_ {-1.0f,-	1.0f, 1.0f,		0.0f, 1.0f,	0.0f,	 0.0f,-1.0f, 0.0f		},//33	LEFT	BOT FAR
				_OBJ_VERT_ {1.0f,-	1.0f,-1.0f,		1.0f, 0.0f,	0.0f,	 0.0f,-1.0f, 0.0f		},//34	RIGHT	BOT NEAR
				_OBJ_VERT_ {1.0f,-	1.0f, 1.0f,		1.0f, 1.0f,	0.0f,	 0.0f,-1.0f, 0.0f		} //35	RIGHT	BOT FAR
			};										   

			unsigned int PainInTheInt_SkyIndices[] = {
				// Near Face
				0,  2,  5,
				8,  1,  19,

				// Far Face
				20,  13,  7,
				10,  14,  32,

				// Bottom Face
				9,3,17,
				21,11,31,

				//17,3,9,
				//31,11,21,

				// Top Face
				12,16,22,
				26,4,25,

				// Left Face
				23,27,18,
				24,33,30,

				// Right Face
				15, 28, 6,
				29, 34, 35
			};

			// Set up the description of the static vertex buffer.
			vertexBufferDescSky.Usage = D3D11_USAGE_DEFAULT;
			vertexBufferDescSky.ByteWidth = sizeof(_OBJ_VERT_) * m_vertexCountSky;
			vertexBufferDescSky.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			vertexBufferDescSky.CPUAccessFlags = 0;
			vertexBufferDescSky.MiscFlags = 0;
			vertexBufferDescSky.StructureByteStride = 0;

			// Give the subresource structure a pointer to the vertex data.
			vertexDataSky.pSysMem = cubeVerts;
			vertexDataSky.SysMemPitch = 0;
			vertexDataSky.SysMemSlicePitch = 0;

			// Now create the vertex buffer.
			result = myDevice->CreateBuffer(&vertexBufferDescSky, &vertexDataSky, &m_vertexBufferSky);

			// Set up the description of the static index buffer.
			indexBufferDescSky.Usage = D3D11_USAGE_DEFAULT;
			indexBufferDescSky.ByteWidth = sizeof(unsigned int) * m_indexCountSky;
			indexBufferDescSky.BindFlags = D3D11_BIND_INDEX_BUFFER;
			indexBufferDescSky.CPUAccessFlags = 0;
			indexBufferDescSky.MiscFlags = 0;
			indexBufferDescSky.StructureByteStride = 0;

			// Give the subresource structure a pointer to the index data.
			indexDataSky.pSysMem = PainInTheInt_SkyIndices;
			indexDataSky.SysMemPitch = 0;
			indexDataSky.SysMemSlicePitch = 0;

			// Create the index buffer.
			result = myDevice->CreateBuffer(&indexBufferDescSky, &indexDataSky, &m_indexBufferSky);
#pragma endregion

			// Create the camera object.
			m_Camera = new CameraClass;

			// Set the initial position of the camera.
			m_Camera->SetPosition(0.0f,0.0f, -5.0f);

			m_ShaderInv = new ShaderInvoker;
			m_ShaderInv->Initialize(myDevice);

			// Release the instance array now that the instance buffer has been created and loaded.
			delete[] instances;
			instances = 0;
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
	myImmContext->Release();

	// TODO: "Release()" more stuff here!
	if (mySurface) // Free Gateware Interface
	{
		mySurface->DecrementCount(); // reduce internal count (will auto delete on Zero)
		mySurface = nullptr; // the safest way to fly
	}
	#pragma region Release Vertex Buffers

		// If vertex buffer exists, release and set to 0
		if (m_vertexBufferSky)
		{
			m_vertexBufferSky->Release();
			m_vertexBufferSky = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer1)
		{				  
			m_vertexBuffer1->Release();
			m_vertexBuffer1 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer2)
		{
			m_vertexBuffer2->Release();
			m_vertexBuffer2 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer3)
		{
			m_vertexBuffer3->Release();
			m_vertexBuffer3 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer4)
		{
			m_vertexBuffer4->Release();
			m_vertexBuffer4 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer5)
		{
			m_vertexBuffer5->Release();
			m_vertexBuffer5 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer6)
		{
			m_vertexBuffer6->Release();
			m_vertexBuffer6 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer7)
		{
			m_vertexBuffer7->Release();
			m_vertexBuffer7 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_vertexBuffer8)
		{
			m_vertexBuffer8->Release();
			m_vertexBuffer8 = 0;
		}

		if (m_vertexBuffer9)
		{
			m_vertexBuffer9->Release();
			m_vertexBuffer9 = 0;
		}

		if (m_vertexBuffer10)
		{
			m_vertexBuffer10->Release();
			m_vertexBuffer10 = 0;
		}

		if (m_vertexBuffer11)
		{				   
			m_vertexBuffer11->Release();
			m_vertexBuffer11 = 0;
		}
	#pragma endregion

	#pragma region Release Index Buffers

		// If index buffer exists, release and set to 0
		if (m_indexBuffer1)
		{
			m_indexBuffer1->Release();
			m_indexBuffer1 = 0;
		}

		// If index buffer exists, release and set to 0
		if (m_indexBuffer2)
		{
			m_indexBuffer2->Release();
			m_indexBuffer2 = 0;
		}

		// If index buffer exists, release and set to 0
		if (m_indexBuffer3)
		{
			m_indexBuffer3->Release();
			m_indexBuffer3 = 0;
		}
		// If index buffer exists, release and set to 0
		if (m_indexBuffer4)
		{
			m_indexBuffer4->Release();
			m_indexBuffer4 = 0;
		}
		// If index buffer exists, release and set to 0
		if (m_indexBuffer5)
		{
			m_indexBuffer5->Release();
			m_indexBuffer5 = 0;
		}
		// If index buffer exists, release and set to 0
		if (m_indexBuffer6)
		{
			m_indexBuffer6->Release();
			m_indexBuffer6 = 0;
		}
		// If index buffer exists, release and set to 0
		if (m_indexBuffer7)
		{
			m_indexBuffer7->Release();
			m_indexBuffer7 = 0;
		}
		// If index buffer exists, release and set to 0
		if (m_indexBuffer8)
		{
			m_indexBuffer8->Release();
			m_indexBuffer8 = 0;
		}

		if (m_indexBuffer9)
		{
			m_indexBuffer9->Release();
			m_indexBuffer9 = 0;
		}

		if (m_indexBuffer10)
		{
			m_indexBuffer10->Release();
			m_indexBuffer10 = 0;
		}

		if (m_indexBuffer11)
		{				  
			m_indexBuffer11->Release();
			m_indexBuffer11 = 0;
		}

		if (m_indexBufferSky)
		{
			m_indexBufferSky->Release();
			m_indexBufferSky = 0;
		}
	#pragma endregion

	#pragma region Release ShaderResourceView

		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceViewSky)
		{
			m_shaderResourceViewSky->Release();
			m_shaderResourceViewSky = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView1)
		{
			m_shaderResourceView1->Release();
			m_shaderResourceView1 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView2)
		{
			m_shaderResourceView2->Release();
			m_shaderResourceView2 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView3)
		{
			m_shaderResourceView3->Release();
			m_shaderResourceView3 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView4)
		{
			m_shaderResourceView4->Release();
			m_shaderResourceView4 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView5)
		{
			m_shaderResourceView5->Release();
			m_shaderResourceView5 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView6)
		{
			m_shaderResourceView6->Release();
			m_shaderResourceView6 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView7)
		{
			m_shaderResourceView7->Release();
			m_shaderResourceView7 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_shaderResourceView8)
		{
			m_shaderResourceView8->Release();
			m_shaderResourceView8 = 0;
		}

		if (m_shaderResourceView9)
		{
			m_shaderResourceView9->Release();
			m_shaderResourceView9 = 0;
		}

		if (m_shaderResourceView10)
		{
			m_shaderResourceView10->Release();
			m_shaderResourceView10 = 0;
		}

		if (m_shaderResourceView11)
		{						 
			m_shaderResourceView11->Release();
			m_shaderResourceView11 = 0;
		}
	#pragma endregion

	#pragma region Release Textures

		// If vertex buffer exists, release and set to 0
		if (m_textureSky)
		{
			m_textureSky->Release();
			m_textureSky = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_texture1)
		{
			m_texture1->Release();
			m_texture1 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_texture2)
		{
			m_texture2->Release();
			m_texture2 = 0;
		}

		// If vertex buffer exists, release and set to 0
		if (m_texture3)
		{
			m_texture3->Release();
			m_texture3 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_texture4)
		{
			m_texture4->Release();
			m_texture4 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_texture5)
		{
			m_texture5->Release();
			m_texture5 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_texture6)
		{
			m_texture6->Release();
			m_texture6 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_texture7)
		{
			m_texture7->Release();
			m_texture7 = 0;
		}
		// If vertex buffer exists, release and set to 0
		if (m_texture8)
		{
			m_texture8->Release();
			m_texture8 = 0;
		}

		if (m_texture9)
		{
			m_texture9->Release();
			m_texture9 = 0;
		}

		if (m_texture10)
		{
			m_texture10->Release();
			m_texture10 = 0;
		}

		if (m_texture11)
		{			  
			m_texture11->Release();
			m_texture11 = 0;
		}
	#pragma endregion

	if (m_instanceBuffer)
	{
		m_instanceBuffer->Release();
		m_instanceBuffer = 0;
	}

	if (m_Camera)
	{
		delete m_Camera;
	}

	if (m_ShaderInv)
	{
		m_ShaderInv->Shutdown();
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
				myImmContext->ClearDepthStencilView(myDepthStencilView, D3D11_CLEAR_DEPTH, 1, 0); // clear it to Z exponential Far.
				myDepthStencilView->Release();
			}

			// Set active target for drawing, all array based D3D11 functions should use a syntax similar to below
			ID3D11RenderTargetView* const targets[] = { myRenderTargetView };
			myImmContext->OMSetRenderTargets(1, targets, myDepthStencilView);

			// Clear screen to black
			const float black[] = { .5f, .05f, .5f, 1 };
			myImmContext->ClearRenderTargetView(myRenderTargetView, black);
			
			// TODO: Set your shaders, Update & Set your constant buffers, Attatch your vertex & index buffers, Set your InputLayout & Topology & Draw!
			XMMATRIX worldMatrix, viewMatrix, projectionMatrix;

			m_Camera->Render();

			#pragma region MODEL RENDER
			// TODO: Set your shaders, Update & Set your constant buffers, Attatch your vertex & index buffers, Set your InputLayout & Topology & Draw!
			unsigned int stride;
			unsigned int offset;

#if MESHLIGHT
			// Set vertex buffer stride and offset.
			stride = sizeof(_OBJ_VERT_);
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

			//// Set the vertex buffer to active in the input assembler so it can be rendered.
			//myContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

			//// Set the index buffer to active in the input assembler so it can be rendered.
			//myContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

			//// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
			//myContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

#pragma endregion
			
			//Set up matrices
			worldMatrix = DirectX::XMMatrixIdentity();
			m_Camera->GetViewMatrix(viewMatrix);
			if (height && width)
			{
				if (width >= height)
				{
					projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(3.14f / zoomFOV, width / height, nearPlane, farPlane);
				}
				else
					projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(3.14f / zoomFOV, height / width, nearPlane, farPlane);


			}

			m_lightDir = XMFLOAT3(translation, 0, 50);
			m_diffuseColor = XMFLOAT4(0, 0, 0, 1);

			#pragma region Mesh1
						myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView1);
						// Set the vertex buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer1, &stride, &offset);
						
						// Set the index buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetIndexBuffer(m_indexBuffer1, DXGI_FORMAT_R32_UINT, 0);
					
						// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
						myImmContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
						//Individual Object worldMatrix
						worldMatrix = XMMatrixMultiply(XMMatrixTranslation(3.0f, -05.0f, -0.0f), XMMatrixRotationRollPitchYaw(90, 0, 0));
						//INDEXCOUNT, INDEXOFFSET
						m_ShaderInv->Render(myImmContext, m_vertexCount1, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			#pragma endregion

			#pragma region Mesh2
						//m_ShaderInv->UVScrolling = true;
						//myContext->PSSetShaderResources(0, 1, &m_shaderResourceView2);
						//// Set the vertex buffer to active in the input assembler so it can be rendered.
						//myContext->IASetVertexBuffers(0, 1, &m_vertexBuffer2, &stride, &offset);

						//// Set the index buffer to active in the input assembler so it can be rendered.
						//myContext->IASetIndexBuffer(m_indexBuffer2, DXGI_FORMAT_R32_UINT, 0);

						//// Set the index buffer to active in the input assembler so it can be rendered.
						//worldMatrix = XMMatrixMultiply(XMMatrixScaling(5, 5, 5), XMMatrixTranslation(m_lightDir.x, m_lightDir.y, m_lightDir.z));
						//m_ShaderInv->Render(myContext, m_indexCount2, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

						//m_ShaderInv->UVScrolling = true;
						//myContext->PSSetShaderResources(0, 1, &m_shaderResourceView2);
						//// Set the vertex buffer to active in the input assembler so it can be rendered.
						//myContext->IASetVertexBuffers(0, 1, &m_vertexBuffer2, &stride, &offset);

						//// Set the index buffer to active in the input assembler so it can be rendered.
						//myContext->IASetIndexBuffer(m_indexBuffer2, DXGI_FORMAT_R32_UINT, 0);

						//// Set the index buffer to active in the input assembler so it can be rendered.
						//worldMatrix = XMMatrixMultiply(XMMatrixScaling(45, 45, 45), XMMatrixTranslation(140 + translation, 25, 60));
						//m_ShaderInv->Render(myContext, m_indexCount2, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			#pragma endregion

			#pragma region Mesh3
						unsigned int strides[2];
						unsigned int offsets[2];
						ID3D11Buffer* bufferPointers[2];
						m_ShaderInv->instanceRendering = true;
						// Set the buffer strides.
						strides[0] = sizeof(_OBJ_VERT_);
						strides[1] = sizeof(InstanceType);

						// Set the buffer offsets.
						offsets[0] = 0;
						offsets[1] = 0;
						// Set the array of pointers to the vertex and instance buffers.
						bufferPointers[0] = m_vertexBuffer3;
						bufferPointers[1] = m_instanceBuffer;
						m_ShaderInv->UVScrolling = false;
						m_ShaderInv->instanceRendering = true;

						//Grass
						myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView3);
						// Set the vertex buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetVertexBuffers(0, 2, bufferPointers, strides, offsets);

						// Set the index buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetIndexBuffer(m_indexBuffer3, DXGI_FORMAT_R32_UINT, 0);
						worldMatrix = XMMatrixMultiply(XMMatrixTranslation(0, 4.0f, 10), XMMatrixScaling(1.0f, 1.0f, 1.0f));
						m_ShaderInv->Render(myImmContext, m_indexCount3, 0, m_instanceCount, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);
						m_ShaderInv->instanceRendering = false;
			#pragma endregion

			#pragma region Mesh4
#if 0
						myContext->PSSetShaderResources(0, 1, &m_shaderResourceView4);
			//			 Set the vertex buffer to active in the input assembler so it can be rendered.
						myContext->IASetVertexBuffers(0, 1, &m_vertexBuffer4, &stride, &offset);

						// Set the index buffer to active in the input assembler so it can be rendered.
						myContext->IASetIndexBuffer(m_indexBuffer4, DXGI_FORMAT_R32_UINT, 0);

						// Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
						myContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

						// Set the index buffer to active in the input assembler so it can be rendered.
						worldMatrix = XMMatrixMultiply(XMMatrixScaling(45, 45, 45), XMMatrixTranslation(-translation, 4, 60));
						m_ShaderInv->Render(myContext, m_indexCount4, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

#endif // 0

			#pragma endregion

			#pragma region Mesh5
						m_ShaderInv->sinRendering = true;
						myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView5);
						// Set the vertex buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer5, &stride, &offset);

						// Set the index buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetIndexBuffer(m_indexBuffer5, DXGI_FORMAT_R32_UINT, 0);

						// Set the index buffer to active in the input assembler so it can be rendered.
						worldMatrix = XMMatrixMultiply(XMMatrixScaling(3, 3, 3), XMMatrixTranslation(0, 8, 140));
						m_ShaderInv->Render(myImmContext, m_indexCount5, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);
						m_ShaderInv->sinRendering = false;

			#pragma endregion

			#pragma region Mesh6
						myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView6);
						// Set the vertex buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer6, &stride, &offset);

						// Set the index buffer to active in the input assembler so it can be rendered.
						myImmContext->IASetIndexBuffer(m_indexBuffer6, DXGI_FORMAT_R32_UINT, 0);

						// Set the index buffer to active in the input assembler so it can be rendered.
						worldMatrix = XMMatrixMultiply(XMMatrixScaling(6, 6, 6), XMMatrixTranslation(-100, 5, 170));
						worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(0, 3.14159265, 0), worldMatrix);

						m_ShaderInv->Render(myImmContext, m_indexCount6, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			#pragma endregion

			#pragma region Mesh7
			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView7);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer7, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBuffer7, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(.1, .1, .1), XMMatrixTranslation(-10, 4, 50));
			m_ShaderInv->Render(myImmContext, m_indexCount7, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			#pragma endregion

			#pragma region Mesh8
			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView8);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer8, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBuffer8, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(55 , 3.14159265, 0), XMMatrixTranslation(-100, -3, 160));
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(.3, .3, .3), worldMatrix);
			m_ShaderInv->Render(myImmContext, m_indexCount8, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			#pragma endregion

			#pragma region Mesh9
			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView9);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer9, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBuffer9, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(80, 200, 120), XMMatrixTranslation(25, -60, -180));
			worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(0,.5,0), worldMatrix);
			m_ShaderInv->Render(myImmContext, m_indexCount9, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

#pragma endregion

			#pragma region Mesh10
			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView10);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer10, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBuffer10, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(1,1,1), XMMatrixTranslation(5, -45, 0));
			worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(0, .5, 0), worldMatrix);
			m_ShaderInv->Render(myImmContext, m_indexCount10, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(1, 1, 1), XMMatrixTranslation(5, -45, 240));
			worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(0, .5, 0), worldMatrix);
			m_ShaderInv->Render(myImmContext, m_indexCount10, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

#pragma endregion

			#pragma region Mesh11
			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceView11);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBuffer11, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBuffer11, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(.05, .05, .05), XMMatrixTranslation(-10, 5, 60));
			worldMatrix = XMMatrixMultiply(XMMatrixRotationRollPitchYaw(0, 3.14159265, 0), worldMatrix);
			m_ShaderInv->Render(myImmContext, m_indexCount11, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);

#pragma endregion

			#pragma region Skybox
			m_ShaderInv->skyBox = true;
			myImmContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

			myImmContext->PSSetShaderResources(0, 1, &m_shaderResourceViewSky);
			// Set the vertex buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetVertexBuffers(0, 1, &m_vertexBufferSky, &stride, &offset);

			// Set the index buffer to active in the input assembler so it can be rendered.
			myImmContext->IASetIndexBuffer(m_indexBufferSky, DXGI_FORMAT_R32_UINT, 0);

			// Set the index buffer to active in the input assembler so it can be rendered.
			worldMatrix = XMMatrixMultiply(XMMatrixScaling(800.0f, 800.0f, 800.0f), XMMatrixTranslation((float)(m_Camera->m_positionX + 2000), (float)(m_Camera->m_positionY + 9), (float)(m_Camera->m_positionZ - 760)));
			m_ShaderInv->Render(myImmContext, m_indexCountSky, 0, 0, worldMatrix, viewMatrix, projectionMatrix, m_lightDir, m_diffuseColor);
			m_ShaderInv->skyBox = false;

			#pragma endregion


			// Present Backbuffer using Swapchain object
			// Framerate is currently unlocked, we suggest "MSI Afterburner" to track your current FPS and memory usage.
			mySwapChain->Present(0, 0);

			// Free any temp DX handles acquired this frame
			myRenderTargetView->Release();
		}
	}
}

 void LetsDrawSomeStuff::ProcessTextures(int id)
 {
	 CreateDDSTextureFromFile(arrayOfTextures[id].d3dDevice, arrayOfTextures[id].fileName, arrayOfTextures[id].texture, arrayOfTextures[id].textureView, DXGI_ALPHA_MODE_UNSPECIFIED);
 }

 void LetsDrawSomeStuff::JoinableThreadEntrypoint(TextureThreadType * threadData)
{
	std::thread textureCreator(&LetsDrawSomeStuff::ProcessTextures, this, threadData->id);
	textureCreator.join();
}

int LetsDrawSomeStuff::GetIndexCount()
{
	return m_indexCount1;
}