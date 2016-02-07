#pragma once
#include "../Entity/Entity.h"

class LevelComponent : public IComponent
{
public:
	LevelComponent() : m_Level(0) { }
	LevelComponent(int level) : m_Level(level) { }
	virtual ~LevelComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Level; }

private:
	int m_Level;

	friend int GetLevel(Entity* pEntity);

	LevelComponent(const LevelComponent&) = delete;
	LevelComponent& operator=(const LevelComponent&) = delete;
};

int GetLevel(Entity* pEntity)
{
	LevelComponent* pLevelComponent = dynamic_cast<LevelComponent*>(pEntity->GetComponent(ComponentID::Level));
	return pLevelComponent->m_Level;
}
