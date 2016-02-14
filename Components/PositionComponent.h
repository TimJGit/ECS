#pragma once
#include "../Main/stdafx.h"
#include "../Entity/Entity.h"

class PositionComponent : public IComponent
{
public:
	PositionComponent() : m_Position(0.0f, 0.0f, 0.0f) { }
	PositionComponent(const Vector3& position) : m_Position(position) { }
	PositionComponent(float x, float y, float z) : m_Position(x, y, z) { }
	virtual ~PositionComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Position; }

private:
	Vector3 m_Position;

	friend const Vector3& GetPosition(Entity* pEntity);

	PositionComponent(const PositionComponent&) = delete;
	PositionComponent& operator=(const PositionComponent&) = delete;
};

const Vector3& GetPosition(Entity* pEntity)
{
	PositionComponent* pPositionComponent = dynamic_cast<PositionComponent*>(pEntity->GetComponent(ComponentID::Position));
	return pPositionComponent->m_Position;
}
