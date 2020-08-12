#pragma once

#include "RSIDataTypes.h"
#include <memory.h>


class Mesh
{
public:
	Mesh() = default;
	~Mesh()
	{
		ReleaseAllBuffers();
	}

	int GetVertexCount() const { return vertexCount; };
	CUSTOMVERTEX *GetVertexBuffer() const { return vertices; }

	void SetMesh(int InVertexCount, CUSTOMVERTEX* InVertexBuffer);
	void ReleaseAllBuffers();

private:
	int vertexCount;
	CUSTOMVERTEX *vertices = nullptr;

};