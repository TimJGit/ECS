#pragma once
#include "../Helpers/stdafx.h"

class PositionComponent : public IComponent
{
public:
	PositionComponent() : m_Position(0.0f, 0.0f, 0.0f) { }
	PositionComponent(const Vector3& position) : m_Position(position) { }
	PositionComponent(float x, float y, float z) : m_Position(x, y, z) { }
	virtual ~PositionComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Position; }

	const Vector3& GetPosition() const { return m_Position; }
	void SetPosition(const Vector3& position) { m_Position = position; }

private:
	Vector3 m_Position;

	PositionComponent(const PositionComponent&) = delete;
	void operator=(const PositionComponent&) = delete;
};
