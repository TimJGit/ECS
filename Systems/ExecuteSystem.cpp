#include "ExecuteSystem.h"

ExecuteSystem::ExecuteSystem(IExecuteSystem* pExecuteSystem) :
	m_pExecuteSystem(pExecuteSystem)
{
}

ExecuteSystem::~ExecuteSystem()
{
	delete m_pExecuteSystem;
}

void ExecuteSystem::Execute()
{
	if(!m_pExecuteSystem){
		throw NullPointerException("ExecuteSystem::Execute", "ExecuteSystem is null");
	}

	m_pExecuteSystem->Execute();
}
