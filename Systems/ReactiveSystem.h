#pragma once
#include "../Helpers/stdafx.h"

class Pool;

class ReactiveSystem : public IReactiveSystem, public ISystem, public INotifiable
{
public:
	ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem);
	virtual ~ReactiveSystem();

	virtual vector<ComponentID> Triggers();
	virtual void Execute(vector<Entity*> pEntites);

	virtual void Notify(void* pData);

private:
	IReactiveSystem* m_pReactiveSystem;

	ReactiveSystem(const ReactiveSystem&) = delete;
	ReactiveSystem& operator=(const ReactiveSystem&) = delete;
};
