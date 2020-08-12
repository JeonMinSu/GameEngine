#include "Mesh.h"

void Mesh::SetMesh(int InVertexCount, CUSTOMVERTEX * InVertexBuffer)
{
	vertexCount = InVertexCount;
	vertices = new CUSTOMVERTEX[InVertexCount];

	for (int i = 0; i < InVertexCount; i++)
	{
		vertices[i] = InVertexBuffer[i];
	}
}

void Mesh::ReleaseAllBuffers()
{
	if (vertices != nullptr)
	{
		delete vertices;
		vertices = nullptr;
	}
}
