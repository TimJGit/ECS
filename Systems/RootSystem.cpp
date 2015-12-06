#include "RootSystem.h"
#include "ExecuteSystem.h"
#include "InitializeSystem.h"
#include "ReactiveSystem.h"

RootSystem::RootSystem()
{
}

RootSystem::~RootSystem()
{
	for(InitializeSystem* pInitializeSystem : m_pInitializeSystems){
		delete pInitializeSystem;
	}

	for(ExecuteSystem* pExecuteSystem : m_pExecuteSystems){
		delete pExecuteSystem;
	}

	for(ReactiveSystem* pReactiveSystem : m_pReactiveSystems){
		delete pReactiveSystem;
	}
}

RootSystem& RootSystem::GetInstance()
{
	static RootSystem instance;
	return instance;
}

void RootSystem::AddSystem(ISystem* pSystem)
{
	InitializeSystem* pInitializeSystem = dynamic_cast<InitializeSystem*>(pSystem);
	if(pInitializeSystem){
		m_pInitializeSystems.insert(pInitializeSystem);
		return;
	}

	ExecuteSystem* pExecuteSystem = dynamic_cast<ExecuteSystem*>(pSystem);
	if(pExecuteSystem){
		m_pExecuteSystems.insert(pExecuteSystem);
		return;
	}

	ReactiveSystem* pReactiveSystem = dynamic_cast<ReactiveSystem*>(pSystem);
	if(pReactiveSystem){
		m_pReactiveSystems.insert(pReactiveSystem);
		return;
	}

	throw UnknownSystemTypeException("RootSystem::AddSystem >> System has an unknown type!");
}
