#pragma once
#include "../Main/stdafx.h"

class Entity;
class EntitySystemData;
class Pool;

class ReactiveSystem : public ISystem, public INotifiableSystem
{
public:
	ReactiveSystem(Pool* pPool, IReactiveSystem* pReactiveSystem);
	virtual ~ReactiveSystem();

	virtual void Execute();
	virtual void Notify(EntitySystemData* pData);

private:
	Pool* m_pPool;
	IReactiveSystem* m_pReactiveSystem;
	unordered_set<Entity*> m_pCollectedEntities;

	inline void SubscribeToGroup();
	inline void UnsubscribeFromGroup();

	inline void CleanupCollectedEntities();

	ReactiveSystem(const ReactiveSystem&) = delete;
	ReactiveSystem& operator=(const ReactiveSystem&) = delete;
};
