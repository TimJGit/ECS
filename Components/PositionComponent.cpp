#include "PositionComponent.h"

PositionComponent::PositionComponent() :
	IComponent(ComponentID::PositionComponent),
	m_Position(0.0f, 0.0f, 0.0f)
{
}

PositionComponent::PositionComponent(const Vector3& position) :
	IComponent(ComponentID::PositionComponent),
	m_Position(position)
{
}

PositionComponent::PositionComponent(float x, float y, float z) :
	IComponent(ComponentID::PositionComponent),
	m_Position(x, y, z)
{
}

PositionComponent::~PositionComponent()
{
}

const Vector3& PositionComponent::GetPosition() const
{
	return m_Position;
}

void PositionComponent::SetPosition(const Vector3& position)
{
	m_Position = position;
}
