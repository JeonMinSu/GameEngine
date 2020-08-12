#pragma once
#include "IComponent.h"
#include "Transform.h"

class Transform;

class Light : public IComponent
{

public:
	Light() : direction(D3DXVECTOR3(0.0f, 0.0f, 0.0f)), color(LinearColor::White), type(D3DLIGHT_DIRECTIONAL), range(1000.f), isEnable(true)
	{
		cName = LIGHT;
	}
	Light(const Light* l);
	~Light();

public:

	virtual void Operation() override;

	virtual COMPONENT_NAME GetComponentID() override;

	virtual IComponent *GetComponent(COMPONENT_NAME InID) override;
	virtual void SetComponent(IComponent *InComponent) override;
	virtual void RemoveComponent(IComponent *InComponent) override;

	void SetLight(D3DXVECTOR3 InDir, D3DLIGHTTYPE InType, float InRange = 1000.f, LinearColor InColor = LinearColor::White);

	void SetLightType(D3DLIGHTTYPE InType) { type = InType; }
	void SetDirection(D3DXVECTOR3 InDir) { direction = InDir; }
	void SetColor(LinearColor InColor) { color = InColor; }
	void SetRange(float InRange) { range = InRange; }

	D3DXVECTOR3 GetDirection() { return direction; }
	D3DLIGHTTYPE GetType() { return type; }
	LinearColor GetColor() { return color; }
	float GetRange() { return range; }


	bool GetEnable() { return isEnable; }
	bool SetEnable(bool InEnable) { isEnable = InEnable; }


private:
	D3DXVECTOR3 direction;
	LinearColor color;
	D3DLIGHTTYPE type;

	float range;

	bool isEnable;



};
