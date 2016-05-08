#pragma once
#include "../Main/stdafx.h"

class InitializeSystem : public ISystem
{
public:
	InitializeSystem(IInitializeSystem* pInitializeSystem);
	virtual ~InitializeSystem();

	virtual void Execute();

private:
	IInitializeSystem* m_pInitializeSystem;
};
