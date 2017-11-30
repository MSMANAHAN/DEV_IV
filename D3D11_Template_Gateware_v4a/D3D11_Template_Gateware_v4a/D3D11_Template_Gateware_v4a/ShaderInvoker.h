#pragma once
//////////////
// INCLUDES //
//////////////
#include <d3d11.h>
//#include <d3dx11async.h>
#include <fstream>
#include <DirectXMath.h>
#include "MyVertexShader.csh"
#include "MyPixelShader.csh"
#include "MyTexPixelShader.csh"
#include "MyTexVertexShader.csh"
#include "MyMeshLightVertexShader.csh"
#include "MyMeshLightPixelShader.csh"
using namespace std;
using namespace DirectX;

#define TEXTURESH false
#define COLORSH false
#define MESHLIGHTSH true
class ShaderInvoker
{
private:
	struct MatrixBufferType
	{
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};


public:
	ShaderInvoker();
	~ShaderInvoker();

	bool Initialize(ID3D11Device*);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int, int, XMMATRIX, XMMATRIX, XMMATRIX);

private:
	bool InitializeShader(ID3D11Device*);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, XMMATRIX, XMMATRIX, XMMATRIX);
	void RenderShader(ID3D11DeviceContext*, int, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11VertexShader* m_vertexTexShader;
	ID3D11PixelShader * m_pixelTexShader;
	ID3D11VertexShader* m_vertexMeshLightShader;
	ID3D11PixelShader * m_pixelMeshLightShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
	ID3D11SamplerState* m_samplerState;
	D3D11_SAMPLER_DESC m_samplerDesc;
};

