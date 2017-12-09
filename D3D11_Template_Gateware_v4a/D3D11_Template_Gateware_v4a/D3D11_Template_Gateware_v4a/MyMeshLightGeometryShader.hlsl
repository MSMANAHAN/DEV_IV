struct GSOutput
{
	float4 pos : SV_POSITION;
};

[maxvertexcount(3)]
//void MeshLightGeometryShader(shape coming in, struct coming out up the vertex shader, inout topology and output variable name
void MeshLightGeometryShader(
	triangle float4 input[3] : SV_POSITION, 
	inout TriangleStream< GSOutput > output
)
{
	for (uint i = 0; i < 3; i++)
	{
		GSOutput element;
        input[0].x = -10;
		element.pos = input[i];
		output.Append(element);
	}
}