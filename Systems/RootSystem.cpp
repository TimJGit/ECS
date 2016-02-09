#include "RootSystem.h"
#include "ExecuteSystem.h"
#include "InitializeSystem.h"
#include "ReactiveSystem.h"

RootSystem::RootSystem()
{
}

RootSystem::~RootSystem()
{
	for(ISystem* pSystem : m_pInitializeSystems){
		delete pSystem;
	}

	for(ISystem* pSystem : m_pExecuteSystems){
		delete pSystem;
	}
}

void RootSystem::AddSystem(ISystem* pSystem)
{
	InitializeSystem* pInitializeSystem = dynamic_cast<InitializeSystem*>(pSystem);
	if(pInitializeSystem){
		m_pInitializeSystems.push_back(pInitializeSystem);
		return;
	}

	ExecuteSystem* pExecuteSystem = dynamic_cast<ExecuteSystem*>(pSystem);
	if(pExecuteSystem){
		m_pExecuteSystems.push_back(pExecuteSystem);
		return;
	}

	ReactiveSystem* pReactiveSystem = dynamic_cast<ReactiveSystem*>(pSystem);
	if(pReactiveSystem){
		m_pExecuteSystems.push_back(pReactiveSystem);
		return;
	}

	throw UnknownSystemTypeException("RootSystem::AddSystem >> System has an unknown type!");
}

void RootSystem::Initialize()
{
	for(ISystem* pSystem : m_pInitializeSystems){
		pSystem->Execute();
	}
}

void RootSystem::Execute()
{
	for(ISystem* pSystem : m_pExecuteSystems){
		pSystem->Execute();
	}
}
