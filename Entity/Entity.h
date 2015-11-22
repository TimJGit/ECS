#pragma once
#include "../Helpers/stdafx.h"

enum ComponentEvent { ComponentAdded, ComponentRemoved };

class Entity
{
public:
	virtual ~Entity();

	//Components
	bool HasComponent(ComponentID componentID) const;
	void AddComponent(IComponent* pComponent);
	void RemoveComponent(ComponentID componentID);
	IComponent* GetComponent(ComponentID componentID) const;

	//Events
	void SubscribeToEvent(ComponentEvent componentEvent, IObserver* pObserver);
	void UnSubscribeFromEvent(ComponentEvent componentEvent, IObserver* pObserver);

private:
	Entity();

	//Components
	vector<IComponent*> m_pComponents;

	//Events
	vector<IObserver*> m_pOnComponentAddedObservers;
	vector<IObserver*> m_pOnComponentRemovedObservers;

	//Delete default copy constructor and assignment operator
	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;

	friend class Pool;
};
