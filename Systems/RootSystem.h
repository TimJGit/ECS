#pragma once
#include "../Main/stdafx.h"

class InitializeSystem;
class ExecuteSystem;
class ReactiveSystem;

class RootSystem
{
public:
	RootSystem();
	virtual ~RootSystem();

	void AddSystem(ISystem* pSystem);
	void Initialize();
	void Execute();

private:
	vector<ISystem*> m_pInitializeSystems;
	vector<ISystem*> m_pExecuteSystems;
};
