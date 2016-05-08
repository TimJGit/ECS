#pragma once
#include "../Main/stdafx.h"

class Entity
{
public:
	virtual ~Entity();

	bool HasComponent(ComponentID componentID) const;
	void AddComponent(IComponent* pComponent);
	void RemoveComponent(ComponentID componentID);
	void ReplaceComponent(IComponent* pComponent);
	IComponent* GetComponent(ComponentID componentID) const;

private:
	Entity(INotifiablePool* pObserver);

	INotifiablePool* m_pObserver;
	vector<IComponent*> m_pComponents;

	friend class Pool;
};
