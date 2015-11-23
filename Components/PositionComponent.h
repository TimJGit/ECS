#pragma once
#include "../Helpers/stdafx.h"

class PositionComponent : public IComponent
{
public:
	PositionComponent();
	PositionComponent(const Vector3& position);
	PositionComponent(float x, float y, float z);
	virtual ~PositionComponent();

	virtual ComponentID GetComponentID() const;

	const Vector3& GetPosition() const;
	void SetPosition(const Vector3& position);

private:
	Vector3 m_Position;

	PositionComponent(const PositionComponent&) = delete;
	void operator=(const PositionComponent&) = delete;
};
