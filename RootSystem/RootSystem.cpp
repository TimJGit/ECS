#include "RootSystem.h"

RootSystem& RootSystem::GetInstance()
{
	static RootSystem instance;
	return instance;
}

void RootSystem::Execute()
{
	for(ISystem* pSystem : m_pSystems){
		pSystem->Execute();
	}
}

void RootSystem::AddSystem(ISystem* pNewSystem)
{
	m_pSystems.push_back(pNewSystem);
}
