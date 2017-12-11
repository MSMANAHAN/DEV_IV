/////////////
// GLOBALS //
/////////////
TextureCube shaderTexture;
SamplerState SampleType;

cbuffer LightBuffer
{
    float4 diffuseColor;
    float3 lightDirection;
    float padding;
};

//////////////
// TYPEDEFS //
//////////////
struct PixelInputType
{
    float4 position : SV_POSITION;
    float3 tex : TEXCOORD0;
    float3 normals : NORMAL;
    float3 skyPos : POSITION;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 SkyBoxMeshLightPixelShader(PixelInputType input) : SV_TARGET
{
    float4 textureColor;
    float3 lightDir;
    float lightIntensity;
    float4 color;
    
    //x,y,z position before view and projection mult is u,v,w

    input.tex[0] = input.skyPos.x;
    input.tex[1] = input.skyPos.y;
    input.tex[2] = input.skyPos.z;
    
    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, (float3) input.tex);

    // Multiply the texture pixel and the final diffuse color to get the final pixel color result.
    color = textureColor;

    return color;
}
