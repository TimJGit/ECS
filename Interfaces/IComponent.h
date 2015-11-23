#pragma once

class IComponent
{
public:
	virtual ~IComponent() { }

	virtual ComponentID GetComponentID() const = 0;
};
