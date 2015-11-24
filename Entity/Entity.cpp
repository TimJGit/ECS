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

	for(EventCallBack callBack : m_OnComponentAddedCallBacks){
		callBack();
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

	for(EventCallBack callBack : m_OnComponentRemovedCallBacks){
		callBack();
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

void Entity::SubscribeToEvent(ComponentEvent componentEvent, EventCallBack callBack)
{
	switch(componentEvent)
	{
	case ComponentAdded:
		m_OnComponentAddedCallBacks.push_back(callBack);
		break;

	case ComponentRemoved:
		m_OnComponentRemovedCallBacks.push_back(callBack);
		break;
	}
}

void Entity::UnsubscribeFromEvent(ComponentEvent componentEvent, EventCallBack callBack)
{
	switch(componentEvent)
	{
	case ComponentAdded:
		m_OnComponentAddedCallBacks.erase(remove(m_OnComponentAddedCallBacks.begin(), m_OnComponentAddedCallBacks.end(), callBack), m_OnComponentAddedCallBacks.end());
		break;

	case ComponentRemoved:
		m_OnComponentRemovedCallBacks.erase(remove(m_OnComponentRemovedCallBacks.begin(), m_OnComponentRemovedCallBacks.end(), callBack), m_OnComponentRemovedCallBacks.end());
		break;
	}
}
