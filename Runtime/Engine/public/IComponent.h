#pragma once

#include <map>
#include <set>
#include <Windows.h>

#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>


enum COMPONENT_NAME
{
	NONE = 0,
	GAMEOBJECT = 1,
	TRANSFORM = 2,
	MESHFILTER = 3,
	CAMERA = 4,
	LIGHT = 5
};

class GameObject;
class Transform;

class IComponent 
{
public:
	virtual void Operation() = 0;
	virtual COMPONENT_NAME GetComponentID() = 0;

	virtual IComponent *GetComponent(COMPONENT_NAME InID) = 0;
	virtual void SetComponent(IComponent *InComponent) = 0;
	virtual void RemoveComponent(IComponent *InComponent) = 0;

public:
	
	GameObject *gameObject = nullptr;
	Transform *transform = nullptr;

protected:
	friend class GameObject;
	friend class Transform;

	COMPONENT_NAME cName;


};