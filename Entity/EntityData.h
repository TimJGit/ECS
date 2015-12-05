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

	TriggerEvent GetTriggerEvent() const { return m_TriggerEvent; }
	void SetTriggerEvent(TriggerEvent triggerEvent) { m_TriggerEvent = triggerEvent; }

private:
	Entity* m_pEntity;
	TriggerEvent m_TriggerEvent;

	EntitySystemData(const EntitySystemData&) = delete;
	EntitySystemData& operator=(const EntitySystemData&) = delete;
};
