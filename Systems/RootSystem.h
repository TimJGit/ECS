#pragma once
#include "../Helpers/stdafx.h"

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
	unordered_set<ISystem*> m_pInitializeSystems;
	unordered_set<ISystem*> m_pExecuteSystems;

	RootSystem(const RootSystem&) = delete;
	void operator=(const RootSystem&) = delete;
};
