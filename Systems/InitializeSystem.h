#pragma once
#include "../Helpers/stdafx.h"

class InitializeSystem : public ISystem
{
public:
	InitializeSystem(IInitializeSystem* pInitializeSystem);
	virtual ~InitializeSystem();

	virtual void Execute();

private:
	IInitializeSystem* m_pInitializeSystem;

	InitializeSystem(const InitializeSystem&) = delete;
	InitializeSystem& operator=(const InitializeSystem&) = delete;
};
