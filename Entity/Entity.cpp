#include "Entity.h"

Entity::Entity() :
	m_pObserver(nullptr)
{
	m_pComponents.resize(TOTAL_COMPONENTS);
}

Entity::~Entity()
{
	delete m_pObserver;

	for(IComponent* pComponent : m_pComponents){
		delete pComponent;
	}
}

bool Entity::HasComponent(ComponentID componentID) const
{
	return m_pComponents[componentID] != nullptr;
}

void Entity::AddComponent(IComponent* pComponent)
{
	if(!pComponent){
		throw NullPointerException("Entity::AddComponent >> Cannot add null pointer!");
	}

	ComponentID componentID = pComponent->GetComponentID();

	if(HasComponent(componentID)){
		stringstream buffer;
		buffer << "Entity::AddComponent >> Entity already has component \'" << COMPONENT_NAMES[componentID] << "\'!";
		throw EntityAlreadyHasComponentException(buffer.str().c_str());
	}

	m_pComponents[componentID] = pComponent;

	m_pObserver->Notify(this);
}

void Entity::RemoveComponent(ComponentID componentID)
{
	if(!HasComponent(componentID)){
		stringstream buffer;
		buffer << "Entity::RemoveComponent >> Entity does not have component \'" << COMPONENT_NAMES[componentID] << "\'!";
		throw EntityDoesNotHaveComponentException(buffer.str().c_str());
	}

	delete m_pComponents[componentID];
	m_pComponents[componentID] = nullptr;

	m_pObserver->Notify(this);
}

IComponent* Entity::GetComponent(ComponentID componentID) const
{
	if(!HasComponent(componentID)){
		stringstream buffer;
		buffer << "Entity::GetComponent >> Entity does not have component \'" << COMPONENT_NAMES[componentID] << "\'!";
		throw EntityDoesNotHaveComponentException(buffer.str().c_str());
	}

	return m_pComponents[componentID];
}

void Entity::SetObserver(INotifiable* pObserver)
{
	m_pObserver = pObserver;
}
