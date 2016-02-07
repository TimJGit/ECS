#pragma once
#include "../Entity/Entity.h"

class TypeComponent : public IComponent
{
public:
	TypeComponent() : m_Type("") { }
	TypeComponent(char* type) : m_Type(type) { }
	virtual ~TypeComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Type; }

private:
	char* m_Type;

	friend const char* GetType(Entity* pEntity);

	TypeComponent(const TypeComponent&) = delete;
	TypeComponent& operator=(const TypeComponent&) = delete;
};

const char* GetType(Entity* pEntity)
{
	TypeComponent* pTypeComponent = dynamic_cast<TypeComponent*>(pEntity->GetComponent(ComponentID::Type));
	return pTypeComponent->m_Type;
}
