#include "InitializeSystem.h"

InitializeSystem::InitializeSystem(IInitializeSystem* pInitializeSystem) :
	m_pInitializeSystem(pInitializeSystem)
{
}

InitializeSystem::~InitializeSystem()
{
	delete m_pInitializeSystem;
}

void InitializeSystem::Initialize()
{
	m_pInitializeSystem->Initialize();
}
