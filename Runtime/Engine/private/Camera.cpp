#include "Precompiled.h"
#include "Camera.h"


Camera::Camera(const Camera * c)
{
	memmove(this, c, sizeof(Camera));
}

Camera::~Camera()
{
}

void Camera::Operation()
{
	return;
}

COMPONENT_NAME Camera::GetComponentID()
{
	return cName;
}

IComponent * Camera::GetComponent(COMPONENT_NAME InID)
{
	return nullptr;
}

void Camera::SetComponent(IComponent * InComponent)
{
}

void Camera::RemoveComponent(IComponent * InComponent)
{
}

void Camera::GetLookAtMatrix(Transform & TargetObject, D3DXMATRIXA16 * outMatView)
{

	D3DXVECTOR3 viewZ;
	D3DXVec3Normalize(&viewZ, &(transform->Position - TargetObject.Position));

	D3DXVECTOR3 viewX;
	D3DXVec3Cross(&viewX, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), &viewZ);

	if (viewX == D3DXVECTOR3(0.f, 0.f, 0.f))
	{
		viewX = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	}
	D3DXVECTOR3 viewY;
	D3DXVec3Cross(&viewY, &viewZ, &viewX);
	D3DXVec3Normalize(&viewY, &viewY);

	D3DXMatrixLookAtLH(outMatView, &transform->Position, &viewZ, &viewY);

}
