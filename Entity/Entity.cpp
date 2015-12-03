#include "Entity.h"
#include "EntityData.h"

Entity::Entity() :
	m_pObserver(nullptr)
{
	m_pComponents.resize(TOTAL_COMPONENTS);
}

Entity::~Entity()
{
	for(IComponent* pComponent : m_pComponents){
		if(pComponent){
			delete pComponent;
		}
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

	NotifyObserver(componentID, ComponentEvent::ComponentAdded);
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

	NotifyObserver(componentID, ComponentEvent::ComponentRemoved);
}

IComponent& Entity::GetComponent(ComponentID componentID) const
{
	if(!HasComponent(componentID)){
		stringstream buffer;
		buffer << "Entity::GetComponent >> Entity does not have component \'" << COMPONENT_NAMES[componentID] << "\'!";
		throw EntityDoesNotHaveComponentException(buffer.str().c_str());
	}

	return *m_pComponents[componentID];
}

void Entity::SetObserver(INotifiable* pObserver)
{
	m_pObserver = pObserver;
}

inline void Entity::NotifyObserver(ComponentID componentID, ComponentEvent componentEvent)
{
	EntityData* pEntityData = new EntityData();
	
	pEntityData->SetEntity(this);
	pEntityData->SetComponentID(componentID);
	pEntityData->SetComponentEvent(componentEvent);

	m_pObserver->Notify(pEntityData);

	delete pEntityData;
}
