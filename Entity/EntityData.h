#pragma once

class Entity;

class EntityPoolData
{
public:
	EntityPoolData() { }
	virtual ~EntityPoolData() { }

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

	EntityPoolData(const EntityPoolData&) = delete;
	EntityPoolData& operator=(const EntityPoolData&) = delete;
};

class EntitySystemData
{
public:
	EntitySystemData() { }
	virtual ~EntitySystemData() { }

	Entity* GetEntity() const { return m_pEntity; }
	void SetEntity(Entity* pEntity) { m_pEntity = pEntity; }

	EntityEvent GetEntityEvent() const { return m_EntityEvent; }
	void SetEntityEvent(EntityEvent entityEvent) { m_EntityEvent = entityEvent; }

private:
	Entity* m_pEntity;
	EntityEvent m_EntityEvent;

	EntitySystemData(const EntitySystemData&) = delete;
	EntitySystemData& operator=(const EntitySystemData&) = delete;
};
