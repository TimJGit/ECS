#include "Entity.h"

Entity::Entity(INotifiablePool* pObserver)
{
	m_pObserver = pObserver;
	m_pComponents.resize(ComponentID::TOTAL_COMPONENTS);
}

Entity::~Entity()
{
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
		throw NullPointerException("Entity::AddComponent", "Component is null");
	}

	ComponentID componentID = pComponent->GetComponentID();
	if(HasComponent(componentID)){
		throw EntityAlreadyHasComponentException("Entity::AddComponent", COMPONENT_NAMES[componentID]);
	}

	m_pComponents[componentID] = pComponent;
	m_pObserver->Notify(this, componentID, ComponentEvent::ComponentAdded);
}

void Entity::RemoveComponent(ComponentID componentID)
{
	if(!HasComponent(componentID)){
		throw EntityDoesNotHaveComponentException("Entity::RemoveComponent", COMPONENT_NAMES[componentID]);
	}

	delete m_pComponents[componentID];
	m_pComponents[componentID] = nullptr;
	m_pObserver->Notify(this, componentID, ComponentEvent::ComponentRemoved);
}

void Entity::ReplaceComponent(IComponent* pComponent)
{
	RemoveComponent(pComponent->GetComponentID());
	AddComponent(pComponent);
}

IComponent* Entity::GetComponent(ComponentID componentID) const
{
	if(!HasComponent(componentID)){
		throw EntityDoesNotHaveComponentException("Entity::GetComponent", COMPONENT_NAMES[componentID]);
	}

	return m_pComponents[componentID];
}
