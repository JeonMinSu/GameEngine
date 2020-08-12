#include "Precompiled.h"
#include "MeshFilter.h"

MeshFilter::MeshFilter(const MeshFilter * m)
{
	memmove(this, m, sizeof(MeshFilter));
}

MeshFilter::~MeshFilter()
{

}

void MeshFilter::Operation()
{
}

COMPONENT_NAME MeshFilter::GetComponentID()
{
	return cName;
}

IComponent * MeshFilter::GetComponent(COMPONENT_NAME InID)
{
	return nullptr;
}

void MeshFilter::SetComponent(IComponent * InComponent)
{

}

void MeshFilter::RemoveComponent(IComponent * InComponent)
{

}
