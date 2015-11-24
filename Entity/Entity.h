#pragma once
#include "../Helpers/stdafx.h"

typedef void(*EventCallBack)();

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

	vector<EventCallBack> m_OnComponentAddedCallBacks;
	vector<EventCallBack> m_OnComponentRemovedCallBacks;

	void SubscribeToEvent(ComponentEvent componentEvent, EventCallBack callBack);
	void UnsubscribeFromEvent(ComponentEvent componentEvent, EventCallBack callBack);

	friend class Pool;

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;
};
