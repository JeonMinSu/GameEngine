#include "Precompiled.h"
#include "GameObject.h"

GameObject::GameObject()
{
	SetComponent(&transform);
}

GameObject::~GameObject()
{

}

void GameObject::Operation()
{
	for (auto it = componentList.begin(); it != componentList.end(); it++)
	{
		(*it).second->Operation();
	}
}

COMPONENT_NAME GameObject::GetComponentID()
{
	return cName;
}

void GameObject::SetComponent(IComponent * InComponent)
{

	auto ret = componentList.insert({ InComponent->cName, nullptr });

	if (ret.second)
	{
		if (InComponent->gameObject == nullptr)
		{
			InComponent->gameObject = this;
			InComponent->transform = &transform;
			ret.first->second = InComponent;
		}
	}
	return;
}

//template<class T>
//FORCEINLINE T * GameObject::GetComponent()
//{
//	if (componentList.empty()) return nullptr;
//
//	T *C = new T();
//
//	if (componentList.find(C->cName) == componentList.end())
//	{
//		delete C;
//		return nullptr;
//	}
//	COMPONENT_NAME name = C->cName;
//
//	delete C;
//	return (T*)componentList[name];
//}

IComponent * GameObject::GetComponent(COMPONENT_NAME InID)
{
	IComponent *Component = componentList[InID];

	if (Component)
	{
		return Component;
	}

	return nullptr;
}

void GameObject::RemoveComponent(IComponent * InComponent)
{
	IComponent *Component = componentList[InComponent->cName];
	if(Component != NULL)
	{
		componentList.erase(InComponent->cName);
	}
}

void GameObject::SetParent(GameObject * InParent)
{
	//InParent->children.insert();

}

void GameObject::SetChildren(GameObject * InChildren)
{
}

void GameObject::RemoveChildren(GameObject * InChildren)
{
}

bool GameObject::IsParent()
{
	bool isParent = parent == nullptr ? false : true;
	return isParent;
}



//template<class T>
//FORCEINLINE T *GameObject::GetComponent()
//{
//	if (cList.size() == 0)
//	{
//		return NULL;
//	}
//
//	T *c = new T();
//
//	for (auto it = cList.begin(); it != cList.end(); it++)
//	{
//		if (!strcmp((*it)->GetComponentID(), c->GetComponentID()))
//		{
//			delete c;
//			return ((T*)*it);
//		}
//
//	}
//	return NULL;
//}

//void GameObject::SetMesh(Mesh * InMeshPtr)
//{
//	SharedMeshPtr = InMeshPtr;
//}

