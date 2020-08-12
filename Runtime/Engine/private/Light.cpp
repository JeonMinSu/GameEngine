
#include "Precompiled.h"
#include "Light.h"

Light::Light(const Light * l)
{
	memmove(this, l, sizeof(Light));
}

Light::~Light()
{
}

void Light::Operation()
{
	return;
}

COMPONENT_NAME Light::GetComponentID()
{
	return cName;
}

IComponent * Light::GetComponent(COMPONENT_NAME InID)
{
	return nullptr;
}

void Light::SetComponent(IComponent * InComponent)
{
}

void Light::RemoveComponent(IComponent * InComponent)
{
}

void Light::SetLight(D3DXVECTOR3 InDir, D3DLIGHTTYPE InType, float InRange ,LinearColor InColor)
{
	direction = InDir;
	type = InType;
	range = InRange;
	color = InColor;
}
