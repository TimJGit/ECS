#pragma once

class BuildingComponent final : public IComponent
{
public:
	BuildingComponent() {}
	~BuildingComponent() {}

	virtual ComponentID GetComponentID() const { return ComponentID::Building; }
};
