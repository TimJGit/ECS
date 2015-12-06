#pragma once
#include "../Helpers/stdafx.h"

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
	INotifiablePool* m_pObserver;

	void SetObserver(INotifiablePool* pObserver);
	inline void NotifyObserver(ComponentID componentID, ComponentEvent componentEvent);

	friend class Pool;

	Entity(const Entity&) = delete;
	void operator=(const Entity&) = delete;
};
