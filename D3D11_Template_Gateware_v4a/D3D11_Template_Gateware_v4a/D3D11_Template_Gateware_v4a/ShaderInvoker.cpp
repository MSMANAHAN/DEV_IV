#include "ShaderInvoker.h"


ShaderInvoker::ShaderInvoker()
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
}


ShaderInvoker::~ShaderInvoker()
{
}

bool ShaderInvoker::Initialize(ID3D11Device *mydevice)
{
	bool result;


	// Initialize the vertex and pixel shaders.
	result = InitializeShader(mydevice);
	if (!result)
	{
		return false;
	}

	return true;
}

void ShaderInvoker::Shutdown()
{
}

bool ShaderInvoker::Render(ID3D11DeviceContext *deviceContext, int indexCount, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	bool result;


	// Set the shader parameters that it will use for rendering.
	result = SetShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix);
	if (!result)
	{
		return false;
	}

	// Now render the prepared buffers with the shader.
	RenderShader(deviceContext, indexCount);

	return true;
}

bool ShaderInvoker::InitializeShader(ID3D11Device* device)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	//ID3D10Blob* vertexShaderBuffer;
	//ID3D10Blob* pixelShaderBuffer;
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;

#if COLORSH
	// Create the vertex shader from the buffer.
	result = device->CreateVertexShader(MyVertexShader, ARRAYSIZE(MyVertexShader), NULL, &m_vertexShader);
	if (FAILED(result))
	{
		return false;
	}

	// Create the pixel shader from the buffer.
	result = device->CreatePixelShader(MyPixelShader, ARRAYSIZE(MyPixelShader), NULL, &m_pixelShader);
	if (FAILED(result))
	{
		return false;
	}

	//Input Layout Setup
	//Now setup the layout of the data that goes into the shader.

	D3D11_INPUT_ELEMENT_DESC m_layoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	// Get a count of the elements in the layout.
	numElements = sizeof(m_layoutDesc) / sizeof(m_layoutDesc[0]);

	// Create the vertex input layout.
	result = device->CreateInputLayout(m_layoutDesc, numElements, MyVertexShader,
		ARRAYSIZE(MyVertexShader), &m_layout);
	if (FAILED(result))
	{
		return false;
	}

	// Create the vertex input layout.
	result = device->CreateInputLayout(m_layoutDesc, numElements, MyVertexShader,
		ARRAYSIZE(MyVertexShader), &m_layout);
	if (FAILED(result))
	{
		return false;
	}


#endif // COLORSH

#if TEXTURESH
	// Create the vertex shader from the buffer.
	result = device->CreateVertexShader(MyTexVertexShader, ARRAYSIZE(MyTexVertexShader), NULL, &m_vertexTexShader);
	if (FAILED(result))
	{
		return false;
	}

	// Create the pixel shader from the buffer.
	result = device->CreatePixelShader(MyTexPixelShader, ARRAYSIZE(MyTexPixelShader), NULL, &m_pixelTexShader);
	if (FAILED(result))
	{
		return false;
	}

	//Input Layout Setup
	//Now setup the layout of the data that goes into the shader.

	D3D11_INPUT_ELEMENT_DESC m_layoutDesc[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	// Get a count of the elements in the layout.
	numElements = sizeof(m_layoutDesc) / sizeof(m_layoutDesc[0]);

	// Create the vertex input layout.
	result = device->CreateInputLayout(m_layoutDesc, numElements, MyTexVertexShader,
		ARRAYSIZE(MyTexVertexShader), &m_layout);
	if (FAILED(result))
	{
		return false;
	}

	m_samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	m_samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	m_samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	m_samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	m_samplerDesc.MipLODBias = 0.0f;
	m_samplerDesc.MaxAnisotropy = 1;
	m_samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	m_samplerDesc.BorderColor[0] = 0;
	m_samplerDesc.BorderColor[1] = 0;
	m_samplerDesc.BorderColor[2] = 0;
	m_samplerDesc.BorderColor[3] = 0;
	m_samplerDesc.MinLOD = 0;
	m_samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;



	result = device->CreateSamplerState(&m_samplerDesc, &m_samplerState);

#endif // TEXTURESH

	// Setup the description of the dynamic matrix constant buffer that is in the vertex shader.
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	result = device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if (FAILED(result))
	{
		return false;
	}

	return true;
}

void ShaderInvoker::ShutdownShader()
{
	// Release the matrix constant buffer.
	if (m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	// Release the layout.
	if (m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}
#if COLORSH
	// Release the pixel shader.
	if (m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	// Release the vertex shader.
	if (m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

#endif // COLORSH

#if TEXTURESH
	// Release the pixel shader.
	if (m_pixelTexShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	// Release the vertex shader.
	if (m_vertexTexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}
#endif // TEXTURESH


	return;
}

void ShaderInvoker::OutputShaderErrorMessage(ID3D10Blob *, HWND, WCHAR *)
{
}

bool ShaderInvoker::SetShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix,
	XMMATRIX viewMatrix, XMMATRIX projectionMatrix)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBufferType* dataPtr;
	unsigned int bufferNumber;

	//Transpose the matrices to prepare them for the shader.
	worldMatrix = DirectX::XMMatrixTranspose(worldMatrix);
	viewMatrix = DirectX::XMMatrixTranspose(viewMatrix);
	projectionMatrix = DirectX::XMMatrixTranspose(projectionMatrix);

	// Lock the constant buffer so it can be written to.
	result = deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		return false;
	}
	
	// Get a pointer to the data in the constant buffer.
	dataPtr = (MatrixBufferType*)mappedResource.pData;

	// Copy the matrices into the constant buffer.
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;

	// Unlock the constant buffer.
	deviceContext->Unmap(m_matrixBuffer, 0);

	// Position of the constant buffer in the vertex shader.
	bufferNumber = 0;

	// Set the constant buffer in the vertex shader with the updated values.
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_matrixBuffer);

	return true;
}

void ShaderInvoker::RenderShader(ID3D11DeviceContext *deviceContext, int indexCount)
{
	// Set the vertex input layout.
	deviceContext->IASetInputLayout(m_layout);
#if COLORSH
	// Set the vertex and pixel shaders that will be used to render this triangle.
	deviceContext->VSSetShader(m_vertexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelShader, NULL, 0);

#endif // 0

#if TEXTURESH
	// Set the vertex and pixel shaders that will be used to render this triangle.
	deviceContext->VSSetShader(m_vertexTexShader, NULL, 0);
	deviceContext->PSSetShader(m_pixelTexShader, NULL, 0);
	deviceContext->PSSetSamplers(0, 1, &m_samplerState);
#endif // TEXTURESH


	// Render the triangle.
	deviceContext->DrawIndexed(indexCount, 0, 0);

	return;
}
