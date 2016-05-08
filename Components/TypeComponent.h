#pragma once
#include "../Entity/Entity.h"

class TypeComponent final : public IComponent
{
public:
	TypeComponent(char* type) : m_Type(type) {}
	~TypeComponent() {}

	virtual ComponentID GetComponentID() const { return ComponentID::Type; }

private:
	char* m_Type;

	friend const char* GetType(Entity* pEntity);
};

const char* GetType(Entity* pEntity)
{
	TypeComponent* pTypeComponent = dynamic_cast<TypeComponent*>(pEntity->GetComponent(ComponentID::Type));
	if(!pTypeComponent){
		throw EntityDoesNotHaveComponentException("TypeComponent::GetType", COMPONENT_NAMES[ComponentID::Type]);
	}
	return pTypeComponent->m_Type;
}
