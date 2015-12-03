#include "ReactiveSystem.h"
#include "../Pool/Pool.h"
#include "../Group/Group.h"

ReactiveSystem::ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem) :
	m_pReactiveSystem(pReactiveSystem)
{
	pPool->GetGroup(Triggers()).AddObserver(this);
}

ReactiveSystem::~ReactiveSystem()
{
	delete m_pReactiveSystem;
}

vector<ComponentID> ReactiveSystem::Triggers()
{
	return m_pReactiveSystem->Triggers();
}

void ReactiveSystem::Execute(vector<Entity*> pEntites)
{
	m_pReactiveSystem->Execute(pEntites);
}

void ReactiveSystem::Notify(void* pData)
{
}
