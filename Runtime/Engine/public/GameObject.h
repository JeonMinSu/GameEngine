#pragma once
#include "Transform.h"

class GameObject sealed
{
public:
	GameObject();
	~GameObject();

	void Operation();
	COMPONENT_NAME GetComponentID();

	template<class T>
	FORCEINLINE T *GetComponent()
	{
		if (componentList.empty()) return nullptr;

		T *C = new T();

		if (componentList.find(C->cName) == componentList.end()) return nullptr;

		return (T*)componentList[C->cName];
	}

	IComponent *GetComponent(COMPONENT_NAME InID);

	void SetComponent(IComponent *InComponent);
	void RemoveComponent(IComponent *InComponent);

	void SetParent(GameObject *InParent);
	void SetChildren(GameObject *InChildren);
	void RemoveChildren(GameObject *InChildren);

	GameObject *GetParent() { return parent;}
	bool IsParent();

public:
	const GameObject *gameObject = this;
	Transform transform;

private:
	std::map<COMPONENT_NAME, IComponent*> componentList;
	const COMPONENT_NAME cName = GAMEOBJECT;

	GameObject *parent = nullptr;
	std::set<GameObject*> children;

};