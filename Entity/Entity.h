#pragma once
#include "../Helpers/stdafx.h"

enum ComponentEvent { ComponentAdded, ComponentRemoved };

class Entity
{
public:
	virtual ~Entity();

	bool HasComponent(ComponentID componentID) const;
	void AddComponent(IComponent* pComponent);
	void RemoveComponent(ComponentID componentID);
	IComponent& GetComponent(ComponentID componentID) const;

private:
	Entity();

	vector<IComponent*> m_pComponents;
	INotifiable* m_pObserver;

	void SetObserver(INotifiable* pObserver);
	inline void NotifyObserver(ComponentID componentID, ComponentEvent componentEvent);

	friend class Pool;

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;
};
