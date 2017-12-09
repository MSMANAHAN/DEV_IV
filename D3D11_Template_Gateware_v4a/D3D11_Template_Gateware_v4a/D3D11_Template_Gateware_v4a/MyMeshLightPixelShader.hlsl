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
float4 MeshLightPixelShader(PixelInputType input) : SV_TARGET
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
    float3 lightToPixelVec;
    float radius = 20;
    float4 greenTint;
    float3 lightDirect;
    float4 lightPosSurface;
    ambient[0] = .2;
    ambient[1] = .2;
    ambient[2] = .2;
    ambient[3] = 0;

    // Sample the pixel color from the texture using the sampler at this texture coordinate location.
    textureColor = shaderTexture.Sample(SampleType, (float2) input.tex);

    redTint[0] = 1;
    redTint[1] = 0;
    redTint[2] = 0;
    redTint[3] = 0;

    greenTint[0] = 0;
    greenTint[1] = 1;
    greenTint[2] = 0;
    greenTint[3] = 0;

    surfacePos = input.skyPos;
    //attentuation   
    float xTwoMinusxOne = (surfacePos[0] - lightDirection[0]);
    float yTwoMinusyOne = (surfacePos[1] - lightDirection[1]);
    float zTwoMinuszOne = (surfacePos[2] - lightDirection[2]);
    xTwoMinusxOne *= xTwoMinusxOne;
    yTwoMinusyOne *= yTwoMinusyOne;
    zTwoMinuszOne *= zTwoMinuszOne;
    float dist = sqrt(xTwoMinusxOne + yTwoMinusyOne + zTwoMinuszOne);

    float4 attenuation[4]; // = 1 - saturate(dist / 1.00);
    
    attenuation[0] = ambient * textureColor;

    lightDirect = surfacePos - lightDirection;
    lightDirect = saturate(lightDirect);
    //Direction Light Calculations
    //lightDir = -lightDirection;
    lightIntensity = saturate(dot(lightDirect.xyz, input.normals.xyz));
    attenuation[1] = saturate(diffuseColor * lightIntensity);
    attenuation[1] *= textureColor;

    //Spot Light Calculations with red tint
    lightposSurf = (dist) / (radius - 10);
    lightDir = 1 - saturate(lightposSurf);
    lightIntensity = saturate(dot(input.normals.xyz, lightDir));
    attenuation[2] = saturate((redTint) * lightIntensity);
    attenuation[2] *= textureColor;

    //Point Light
    float fRangeAtt = 1 - saturate(dist/radius);
    //lightIntensity = saturate(dot(lightDirect.xyz, input.normals.xyz));
    attenuation[3] = saturate((greenTint) * fRangeAtt);
    attenuation[3] *= textureColor;

    color =
    attenuation[0] +
    attenuation[1] * dist +
    attenuation[2] * (dist * dist)+
    attenuation[3] * (dist);
    return color;
}
