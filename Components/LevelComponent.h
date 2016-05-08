#pragma once
#include "../Entity/Entity.h"

class LevelComponent final : public IComponent
{
public:
	LevelComponent(int level) : m_Level(level) {}
	~LevelComponent() {}

	virtual ComponentID GetComponentID() const { return ComponentID::Level; }

private:
	int m_Level;

	friend int GetLevel(Entity* pEntity);
};

int GetLevel(Entity* pEntity)
{
	LevelComponent* pLevelComponent = dynamic_cast<LevelComponent*>(pEntity->GetComponent(ComponentID::Level));
	if(!pLevelComponent){
		throw EntityDoesNotHaveComponentException("LevelComponent::GetLevel", COMPONENT_NAMES[ComponentID::Level]);
	}
	return pLevelComponent->m_Level;
}
