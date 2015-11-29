#include "RootSystem.h"

RootSystem::RootSystem()
{
}

RootSystem::~RootSystem()
{
	for(IInitializeSystem* pInitializeSystem : m_pInitializeSystems){
		delete pInitializeSystem;
	}

	for(IReactiveSystem* pReactiveSystem : m_pReactiveSystems){
		delete pReactiveSystem;
	}

	for(IExecuteSystem* pExecuteSystem : m_pExecuteSystems){
		delete pExecuteSystem;
	}
}

RootSystem& RootSystem::GetInstance()
{
	static RootSystem instance;
	return instance;
}

void RootSystem::AddSystem(ISystem* pSystem)
{
	IInitializeSystem* pInitializeSystem = dynamic_cast<IInitializeSystem*>(pSystem);
	if(pInitializeSystem){
		m_pInitializeSystems.push_back(pInitializeSystem);
		return;
	}

	IReactiveSystem* pReactiveSystem = dynamic_cast<IReactiveSystem*>(pSystem);
	if(pReactiveSystem){
		m_pReactiveSystems.push_back(pReactiveSystem);
		return;
	}

	IExecuteSystem* pExecuteSystem = dynamic_cast<IExecuteSystem*>(pSystem);
	if(pExecuteSystem){
		m_pExecuteSystems.push_back(pExecuteSystem);
		return;
	}

	throw UnknownSystemTypeException("RootSystem::AddSystem >> The system cannot be added as it has an unknown type!");
}
