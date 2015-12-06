#pragma once
#include "../Helpers/stdafx.h"

class InitializeSystem;
class ExecuteSystem;
class ReactiveSystem;

class RootSystem
{
public:
	virtual ~RootSystem();

	static RootSystem& GetInstance();
	void AddSystem(ISystem* pSystem);

private:
	RootSystem();

	unordered_set<InitializeSystem*> m_pInitializeSystems;
	unordered_set<ExecuteSystem*> m_pExecuteSystems;
	unordered_set<ReactiveSystem*> m_pReactiveSystems;

	RootSystem(const RootSystem&) = delete;
	void operator=(const RootSystem&) = delete;
};
