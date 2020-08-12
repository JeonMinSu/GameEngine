#pragma once
#include "IComponent.h"
#include "Transform.h"

class Transform;
class Camera : public IComponent
{
public:
	Camera() { cName = CAMERA; }
	Camera(const Camera *c);
	~Camera();

public:
	virtual void Operation() override;

	virtual COMPONENT_NAME GetComponentID() override;

	virtual IComponent *GetComponent(COMPONENT_NAME InID) override;
	virtual void SetComponent(IComponent *InComponent) override;
	virtual void RemoveComponent(IComponent *InComponent) override;

	void GetLookAtMatrix(Transform &TargetObject, D3DXMATRIXA16 *matView);

	float GetFOV() const { return FOV; }
	float SetFOV(const float InFOV) { FOV = InFOV; }

	float GetNearZ() const  { return NearZ; }
	float SetNaerZ(const float InNearZ) { NearZ = InNearZ; }

	float GetFarZ() const { return FarZ; }
	float SetFarZ(const float InFarZ) { FarZ = InFarZ; }

private:

	float FOV = 60.f;
	float NearZ = 5.5f;
	float FarZ = 1000.f;


};
