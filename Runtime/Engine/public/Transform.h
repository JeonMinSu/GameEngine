#pragma once
#include "IComponent.h"

class GameObject;
class Transform : public IComponent
{
public:
	Transform() { cName = TRANSFORM; };
	Transform(const Transform * t);
	~Transform();

public:
	virtual void Operation() override;

	virtual COMPONENT_NAME GetComponentID() override;

	virtual IComponent *GetComponent(COMPONENT_NAME InID) override;
	virtual void SetComponent(IComponent *InComponent) override;
	virtual void RemoveComponent(IComponent *InComponent) override;

	void SetPosition(const D3DXVECTOR3 InPosition);
	void SetLocalPosition(const D3DXVECTOR3 InPosition);
	void AddPosition(const D3DXVECTOR3 InPosition);
	void AddLocalPosition(const D3DXVECTOR3 InPosition);

	D3DXVECTOR3 GetPosition() const;
	D3DXVECTOR3 GetLocalPosition() const;
	

public:
	friend class GameObject;
	friend class Camera;

private:
	D3DXVECTOR3 LocalPosition;
	D3DXVECTOR3 Position;

	Vector3 Scale = Vector3::One;

	Vector3 Forward = Vector3::UnitZ;
	Vector3 Right = Vector3::UnitX;
	Vector3 Up = Vector3::UnitY;

};