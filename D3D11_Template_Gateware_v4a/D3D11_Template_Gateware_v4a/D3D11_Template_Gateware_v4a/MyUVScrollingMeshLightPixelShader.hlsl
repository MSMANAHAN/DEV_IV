/////////////
// GLOBALS //
/////////////
Texture2D shaderTexture;
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
    float4 normals : NORMAL;
    float3 skyPos : POSITION;
};


////////////////////////////////////////////////////////////////////////////////
// Pixel Shader
////////////////////////////////////////////////////////////////////////////////
float4 UVScrollingMeshLightPixelShader(PixelInputType input) : SV_TARGET
{
    float4 textureColor;
    float lightDir;
    float lightIntensity;
    float4 color;
    float4 color2;
    float4 ambient;
    float4 redTint;
    float3 surfacePos;
    float lightposSurf;
    float radius = 10;
    input.tex[0] *= input.position[0];
    input.tex[1] *= input.position[0];
    
    ambient[0] = .2;
    ambient[1] = .2;
    ambient[2] = .2;
    ambient[3] = 0;

    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, (float2) input.tex);

    redTint[0] = .5;
    redTint[1] = 0;
    redTint[2] = 0;
    redTint[3] = 0;

    surfacePos = input.skyPos;
    //attentuation   
    float xTwoMinusxOne = (surfacePos[0] - lightDirection[0]);
    float yTwoMinusyOne = (surfacePos[1] - lightDirection[1]);
    float zTwoMinuszOne = (surfacePos[2] - lightDirection[2]);
    xTwoMinusxOne *= xTwoMinusxOne;
    yTwoMinusyOne *= yTwoMinusyOne;
    zTwoMinuszOne *= zTwoMinuszOne;
    float dist = sqrt(xTwoMinusxOne + yTwoMinusyOne + zTwoMinuszOne);

    float4 attenuation[3]; // = 1 - saturate(dist / 1.00);
    
    attenuation[0] = ambient * textureColor;

    //Direction Light Calculations
    lightDir = -lightDirection;
    lightIntensity = saturate(dot((float3) input.normals, lightDir))/3;
    attenuation[1] = saturate(diffuseColor * lightIntensity);
    attenuation[1] *= textureColor;

    //Point Light Calculations with red tint
    lightposSurf = (dist) / radius;
    lightDir = 1 - saturate(lightposSurf);
    lightIntensity = saturate(dot((float3) input.normals, lightDir));
    attenuation[2] = saturate((redTint) * lightIntensity);
    attenuation[2] *= textureColor;

    //color /= attenuation;
    // ambient light + point light + directional light * the color of the texture
    color =
    attenuation[0] +
    attenuation[1] * dist +
    attenuation[2] * (dist * dist);
    return color;
}
