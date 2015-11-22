#pragma once
#include "../Helpers/stdafx.h"

class RootSystem : public ISystem
{
public:
	static RootSystem& GetInstance();

	virtual void Execute();

	void AddSystem(ISystem* pNewSystem);

private:
	vector<ISystem*> m_pSystems;

	//Disable constructor
	RootSystem() { };

	//Delete default copy constructor and assignment operator
	RootSystem(const RootSystem&) = delete;
	void operator=(const RootSystem&) = delete;
};
