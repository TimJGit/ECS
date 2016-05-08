#pragma once
#include "../Main/stdafx.h"
#include "../Entity/Entity.h"

class PositionComponent final : public IComponent
{
public:
	PositionComponent() : m_Position(0.0f, 0.0f, 0.0f) {}
	PositionComponent(const Vector3& position) : m_Position(position) {}
	PositionComponent(float x, float y, float z) : m_Position(x, y, z) {}
	~PositionComponent() {}

	virtual ComponentID GetComponentID() const { return ComponentID::Position; }

private:
	Vector3 m_Position;

	friend const Vector3& GetPosition(Entity* pEntity);
};

const Vector3& GetPosition(Entity* pEntity)
{
	PositionComponent* pPositionComponent = dynamic_cast<PositionComponent*>(pEntity->GetComponent(ComponentID::Position));
	if(!pPositionComponent){
		throw EntityDoesNotHaveComponentException("PositionComponent::GetPosition", COMPONENT_NAMES[ComponentID::Position]);
	}
	return pPositionComponent->m_Position;
}
