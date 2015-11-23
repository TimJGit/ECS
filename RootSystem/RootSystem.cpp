#include "RootSystem.h"

RootSystem::RootSystem()
{
}

RootSystem::~RootSystem()
{
}

void RootSystem::Execute()
{
	for(ISystem* pSystem : m_pSystems){
		pSystem->Execute();
	}
}

RootSystem& RootSystem::GetInstance()
{
	static RootSystem instance;
	return instance;
}

void RootSystem::AddSystem(ISystem* pSystem)
{
	m_pSystems.push_back(pSystem);
}
