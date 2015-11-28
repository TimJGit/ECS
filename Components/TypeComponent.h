#pragma once

class TypeComponent : public IComponent
{
public:
	TypeComponent() : m_Type("") { }
	TypeComponent(char* type) : m_Type(type) { }
	virtual ~TypeComponent() { }

	virtual ComponentID GetComponentID() const { return ComponentID::Type; }

	const char* GetType() const { return m_Type; }
	void SetType(char* type) { m_Type = type; }

private:
	char* m_Type;

	TypeComponent(const TypeComponent&) = delete;
	void operator=(const TypeComponent&) = delete;
};
