#pragma once
#include "../Helpers/stdafx.h"

class RootSystem : public ISystem
{
public:
	virtual ~RootSystem();

	virtual void Execute();

	static RootSystem& GetInstance();
	void AddSystem(ISystem* pSystem);

private:
	RootSystem();

	vector<ISystem*> m_pSystems;

	RootSystem(const RootSystem&) = delete;
	void operator=(const RootSystem&) = delete;
};
