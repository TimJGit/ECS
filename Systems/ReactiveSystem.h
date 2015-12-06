#pragma once
#include "../Helpers/stdafx.h"

class Pool;

class ReactiveSystem : public IReactiveSystem, public ISystem, public INotifiableSystem
{
public:
	ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem);
	virtual ~ReactiveSystem();

	virtual vector<ComponentID> GetTriggers();
	virtual TriggerEvent GetTriggerEvent();
	virtual void Execute(vector<Entity*> pEntites);

	virtual void Notify(EntitySystemData* pData);

private:
	Pool* m_pPool;
	IReactiveSystem* m_pReactiveSystem;

	ReactiveSystem(const ReactiveSystem&) = delete;
	ReactiveSystem& operator=(const ReactiveSystem&) = delete;
};
