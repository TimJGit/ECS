#pragma once
#include "../Helpers/stdafx.h"

class Pool;

class ReactiveSystem : public ISystem, public INotifiableSystem
{
public:
	ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem);
	virtual ~ReactiveSystem();

	void Execute();

	virtual void Notify(EntitySystemData* pData);

private:
	Pool* m_pPool;
	IReactiveSystem* m_pReactiveSystem;
	unordered_set<Entity*> m_pCollectedEntites;

	inline void SubscribeToGroup();
	inline void UnsubscribeFromGroup();

	ReactiveSystem(const ReactiveSystem&) = delete;
	ReactiveSystem& operator=(const ReactiveSystem&) = delete;
};
