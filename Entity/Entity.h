#pragma once
#include "../Helpers/stdafx.h"

class Entity
{
public:
	virtual ~Entity();

	bool HasComponent(ComponentID componentID) const;
	void AddComponent(IComponent* pComponent);
	void RemoveComponent(ComponentID componentID);
	IComponent* GetComponent(ComponentID componentID) const;

private:
	Entity();

	INotifiable* m_pObserver;
	vector<IComponent*> m_pComponents;

	void SetObserver(INotifiable* pObserver);

	friend class Pool;

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;
};
