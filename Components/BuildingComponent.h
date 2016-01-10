#pragma once

class BuildingComponent : public IComponent
{
public:
	BuildingComponent() { }
	virtual ~BuildingComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Building; }

private:
	BuildingComponent(const BuildingComponent&) = delete;
	BuildingComponent& operator=(const BuildingComponent&) = delete;
};
