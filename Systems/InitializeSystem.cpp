#include "InitializeSystem.h"

InitializeSystem::InitializeSystem(IInitializeSystem* pInitializeSystem) :
	m_pInitializeSystem(pInitializeSystem)
{
}

InitializeSystem::~InitializeSystem()
{
	delete m_pInitializeSystem;
}

void InitializeSystem::Execute()
{
	if(!m_pInitializeSystem){
		throw NullPointerException("InitializeSystem::Execute", "InitializeSystem is null");
	}

	m_pInitializeSystem->Initialize();
}
