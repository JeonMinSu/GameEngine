
#include "Precompiled.h"
#include "Transform.h"
#include "GameObject.h"


Transform::Transform(const Transform * t)
{
	memmove(this, t, sizeof(Transform));
}

Transform::~Transform()
{
}

void Transform::Operation()
{
	return;
}

COMPONENT_NAME Transform::GetComponentID()
{
	return cName;
}

void Transform::SetComponent(IComponent * InComponent)
{
	/// GameObject�� �ؼ� ������
	return;
}

IComponent * Transform::GetComponent(COMPONENT_NAME InID)
{
	/// GameObject�� �ؼ� ������
	return nullptr;
}

void Transform::RemoveComponent(IComponent * InComponent)
{
	/// GameObject�� �ؼ� ������
	return;
}

void Transform::SetPosition(const D3DXVECTOR3 InPosition)
{
	Position = InPosition;
}

void Transform::SetLocalPosition(const D3DXVECTOR3 InPosition)
{
	LocalPosition = InPosition;
}

void Transform::AddPosition(const D3DXVECTOR3 InPosition)
{
	Position += InPosition;

}

void Transform::AddLocalPosition(const D3DXVECTOR3 InPosition)
{
	D3DXVECTOR3 pos;

	if (gameObject != nullptr)
	{
		if (gameObject->IsParent())
		{
			GameObject *parent = gameObject->GetParent();
			pos = parent->transform.Position + InPosition;
		}
	}
	LocalPosition += ( InPosition + pos);
}

D3DXVECTOR3 Transform::GetPosition() const
{
	return Position;
}

D3DXVECTOR3 Transform::GetLocalPosition() const
{
	return LocalPosition;
}
