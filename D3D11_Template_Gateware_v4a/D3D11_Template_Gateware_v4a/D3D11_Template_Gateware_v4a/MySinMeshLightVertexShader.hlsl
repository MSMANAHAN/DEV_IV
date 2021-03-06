/////////////
// GLOBALS //
/////////////
cbuffer MatrixBuffer
{
    matrix worldMatrix;
    matrix viewMatrix;
    matrix projectionMatrix;
};


//////////////
// TYPEDEFS //
//////////////
struct VertexInputType
{
    float4 position : POSITION;
    float3 tex : TEXCOORD0;
    float3 normals : NORMAL;
    float3 instancePosition : TEXCOORD1;
};

struct GeometryInputType
{
    float4 position : SV_POSITION;
    float3 tex : TEXCOORD0;
    float3 normals : NORMAL;
    float3 skyPos : POSITION;
};

struct PixelInputType
{
    float4 position : SV_POSITION;
    float3 tex : TEXCOORD0;
    float3 normals : NORMAL;
    float3 skyPos : POSITION;
};


////////////////////////////////////////////////////////////////////////////////
// New Vertex Shader For Textures
////////////////////////////////////////////////////////////////////////////////
PixelInputType SinMeshLightVertexShader(VertexInputType input)
{
    GeometryInputType output;
    
    // Change the position vector to be 4 units for proper matrix calculations.
    input.position.w = 1.0f;
        // Update the position of the vertices based on the data for this particular instance.
    input.position.x += input.instancePosition.x;
    input.position.y += input.instancePosition.y;
    input.position.z += input.instancePosition.z;
    //input.position.y = sin(-input.position.y);
    // Calculate the position of the vertex against the world, view, and projection matrices.
    output.position = mul(input.position, worldMatrix);
    output.skyPos.x = output.position.x;
    output.skyPos.y = output.position.y;
    output.skyPos.z = output.position.z;
    output.position = mul(output.position, viewMatrix);
    output.position = mul(output.position, projectionMatrix);

    // Store the texture coordinates for the pixel shader.
    output.tex = input.tex;

    // Calculate the normal vector against the world matrix only.
    output.normals = mul(input.normals, (float3x3) worldMatrix);
	
    // Normalize the normal vector.
    output.normals = normalize(output.normals);

    
    return output;
}

//MySinMeshLightVertexShader