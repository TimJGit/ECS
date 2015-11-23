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
	IComponent* GetComponent(ComponentID componentID) const;

private:
	Entity();

	vector<IComponent*> m_pComponents;

	vector<IObserver*> m_pOnComponentAddedObservers;
	vector<IObserver*> m_pOnComponentRemovedObservers;

	void SubscribeToEvent(ComponentEvent componentEvent, IObserver* pObserver);
	void UnSubscribeFromEvent(ComponentEvent componentEvent, IObserver* pObserver);

	friend class Pool;

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;
};
