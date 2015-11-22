#pragma once

class IComponent
{
public:
	virtual ~IComponent() { }

	ComponentID GetComponentID() const { return COMPONENT_ID; }

protected:
	IComponent(ComponentID componentID) : COMPONENT_ID(componentID) { }

private:
	const ComponentID COMPONENT_ID;
};
