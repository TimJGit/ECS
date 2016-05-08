#pragma once
#include "../Main/stdafx.h"

class ExecuteSystem : public ISystem
{
public:
	ExecuteSystem(IExecuteSystem* pExecuteSystem);
	virtual ~ExecuteSystem();

	virtual void Execute();

private:
	IExecuteSystem* m_pExecuteSystem;
};
