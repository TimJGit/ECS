#pragma once
#include "../Helpers/stdafx.h"

class RootSystem
{
public:
	virtual ~RootSystem();

	static RootSystem& GetInstance();
	void AddSystem(ISystem* pSystem);

private:
	RootSystem();

	vector<IInitializeSystem*> m_pInitializeSystems;
	vector<IReactiveSystem*> m_pReactiveSystems;
	vector<IExecuteSystem*> m_pExecuteSystems;

	RootSystem(const RootSystem&) = delete;
	void operator=(const RootSystem&) = delete;
};
