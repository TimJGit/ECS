#include "Entity.h"

Entity::Entity()
{
	m_pComponents.resize(TOTAL_COMPONENTS);
}

Entity::~Entity()
{
	for(IComponent* pComponent : m_pComponents){
		delete pComponent;
	}

	for(IObserver* pObserver : m_pOnComponentAddedObservers){
		delete pObserver;
	}

	for(IObserver* pObserver : m_pOnComponentRemovedObservers){
		delete pObserver;
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

	for(IObserver* pObserver : m_pOnComponentAddedObservers){
		pObserver->EventCallback();
	}
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

	for(IObserver* pObserver : m_pOnComponentRemovedObservers){
		pObserver->EventCallback();
	}
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

void Entity::SubscribeToEvent(ComponentEvent componentEvent, IObserver* pObserver)
{
	if(!pObserver){
		throw NullPointerException("Entity::SubscribeToEvent >> Cannot subscribe with null pointer!");
	}

	switch(componentEvent)
	{
	case ComponentAdded:
		m_pOnComponentAddedObservers.push_back(pObserver);
		break;

	case ComponentRemoved:
		m_pOnComponentRemovedObservers.push_back(pObserver);
		break;
	}
}

void Entity::UnSubscribeFromEvent(ComponentEvent componentEvent, IObserver* pObserver)
{
	switch(componentEvent)
	{
	case ComponentAdded:
		m_pOnComponentAddedObservers.erase(remove(m_pOnComponentAddedObservers.begin(), m_pOnComponentAddedObservers.end(), pObserver), m_pOnComponentAddedObservers.end());
		break;

	case ComponentRemoved:
		m_pOnComponentRemovedObservers.erase(remove(m_pOnComponentRemovedObservers.begin(), m_pOnComponentRemovedObservers.end(), pObserver), m_pOnComponentRemovedObservers.end());
		break;
	}
}
