#pragma once
#include "IComponent.h"
#include "Mesh.h"


class MeshFilter : public IComponent
{
public:
	MeshFilter() { cName = MESHFILTER; };
	MeshFilter(const MeshFilter* m);
	~MeshFilter();

public:

	virtual void Operation() override;

	virtual COMPONENT_NAME GetComponentID() override;

	virtual IComponent *GetComponent(COMPONENT_NAME InID) override;
	virtual void SetComponent(IComponent *InComponent) override;
	virtual void RemoveComponent(IComponent *InComponent) override;

	void SetMesh(const Mesh InMesh) { *mesh = InMesh; }
	void SetSharedMesh(Mesh *InSharedMesh) { sharedMesh = InSharedMesh; }

	Mesh *GetMesh() const { return mesh; }
	Mesh *GetSharedMesh() const { return sharedMesh; }

private:
	Mesh *mesh;
	Mesh *sharedMesh = nullptr;

};