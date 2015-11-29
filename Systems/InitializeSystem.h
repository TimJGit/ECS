#pragma once
#include "../Helpers/stdafx.h"

class InitializeSystem : public IInitializeSystem, public ISystem
{
public:
	InitializeSystem(IInitializeSystem* pInitializeSystem);
	virtual ~InitializeSystem();

	virtual void Initialize();

private:
	IInitializeSystem* m_pInitializeSystem;

	InitializeSystem(const InitializeSystem&) = delete;
	InitializeSystem& operator=(const InitializeSystem&) = delete;
};
