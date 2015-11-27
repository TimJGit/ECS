#pragma once
#include "../Helpers/stdafx.h"

class Entity;

class EntityData
{
public:
	EntityData() { }
	virtual ~EntityData() { }

	Entity* GetEntity() const { return m_pEntity; }
	void SetEntity(Entity* pEntity) { m_pEntity = pEntity; }

	ComponentID GetComponentID() const { return m_ComponentID; }
	void SetComponentID(ComponentID componentID) { m_ComponentID = componentID; }

	ComponentEvent GetComponentEvent() const { return m_ComponentEvent; }
	void SetComponentEvent(ComponentEvent componentEvent) { m_ComponentEvent = componentEvent; }

private:
	Entity* m_pEntity;
	ComponentID m_ComponentID;
	ComponentEvent m_ComponentEvent;

	EntityData(const EntityData&) = delete;
	EntityData& operator=(const EntityData&) = delete;
};
