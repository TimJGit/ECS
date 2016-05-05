#include "stdafx.h"
#include "../Components/Components.h"
#include "../Entity/Entity.h"
#include "../Group/Group.h"
#include "../Pool/Pool.h"
#include "../Systems/Systems.h"

class Repo
{
public:
	virtual ~Repo() { }

	static Pool* Core()
	{
		if(!m_pCorePool){
			m_pCorePool = new Pool();
		}
		return m_pCorePool;
	}

private:
	Repo() { }

	static Pool* m_pCorePool;

	Repo(const Repo&) = delete;
	Repo& operator=(const Repo&) = delete;
};
Pool* Repo::m_pCorePool = nullptr;

class BuildingSetupSystem : public IInitializeSystem
{
public:
	BuildingSetupSystem() { }
	virtual ~BuildingSetupSystem() { }

	virtual void Initialize()
	{
		for(int i = 1; i <= 10; i++){
			Entity* pEntity = Repo::Core()->CreateEntity();
			pEntity->AddComponent(new BuildingComponent());
			pEntity->AddComponent(new TypeComponent("House"));
			pEntity->AddComponent(new LevelComponent(i));

			cout << "New entity created of type " << GetType(pEntity) << " and level " << GetLevel(pEntity) << endl;
		}
	}

private:
	BuildingSetupSystem(const BuildingSetupSystem&) = delete;
	BuildingSetupSystem& operator=(const BuildingSetupSystem&) = delete;
};

class BuildingPositioningSystem : public IReactiveSystem
{
public:
	BuildingPositioningSystem() { }
	virtual ~BuildingPositioningSystem() { }

	virtual vector<ComponentID> GetTriggers() { return { ComponentID::Building, ComponentID::Type, ComponentID::Level }; }
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerAdded; }
	virtual void Execute(vector<Entity*> pEntities)
	{
		cout << endl;
		for(Entity* pEntity : pEntities){
			pEntity->AddComponent(new PositionComponent(2.0f, 5.0f, 0.5f));

			cout << "Entity of type " << GetType(pEntity) << " and level " << GetLevel(pEntity) << " received a position" << endl;
		}
	}

private:
	BuildingPositioningSystem(const BuildingPositioningSystem&) = delete;
	BuildingPositioningSystem& operator=(const BuildingPositioningSystem&) = delete;
};

class BuildingDestructionSystem : public IReactiveSystem
{
public:
	BuildingDestructionSystem() { }
	virtual ~BuildingDestructionSystem() { }

	virtual vector<ComponentID> GetTriggers() { return { ComponentID::Building, ComponentID::Position }; }
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerAdded; }
	virtual void Execute(vector<Entity*> pEntities)
	{
		for(Entity* pEntity : pEntities){
			if(GetLevel(pEntity) == 5){
				pEntity->RemoveComponent(ComponentID::Building);
			}
		}
	}

private:
	BuildingDestructionSystem(const BuildingDestructionSystem&) = delete;
	BuildingDestructionSystem& operator=(const BuildingDestructionSystem&) = delete;
};

class BuildingLogSystem : public IReactiveSystem
{
public:
	BuildingLogSystem() { }
	virtual ~BuildingLogSystem() { }

	virtual vector<ComponentID> GetTriggers() { return { ComponentID::Building }; }
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerRemoved; }
	virtual void Execute(vector<Entity*> pEntities)
	{
		cout << endl;
		for(Entity* pBuilding : pEntities){
			cout << "Building of type " << GetType(pBuilding) << " and level " << GetLevel(pBuilding) << " removed" << endl;
		}
	}

private:
	BuildingLogSystem(const BuildingLogSystem&) = delete;
	BuildingLogSystem& operator=(const BuildingLogSystem&) = delete;
};

class BuildingCleanupSystem : public IReactiveSystem
{
public:
	BuildingCleanupSystem() { }
	virtual ~BuildingCleanupSystem() { }

	virtual vector<ComponentID> GetTriggers() { return{ ComponentID::Building }; }
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerRemoved; }
	virtual void Execute(vector<Entity*> pEntities)
	{
		cout << endl;

		for(Entity* pEntity : pEntities){
			Repo::Core()->DestroyEntity(pEntity);
		}

		vector<Entity*> pBuildings = Repo::Core()->GetGroup({ ComponentID::Building, ComponentID::Type, ComponentID::Level }).GetEntities();
		for(Entity* pBuilding : pBuildings){
			cout << "Building of type " << GetType(pBuilding) << " and level " << GetLevel(pBuilding) << " remaining" << endl;
		}
	}

private:
	BuildingCleanupSystem(const BuildingCleanupSystem&) = delete;
	BuildingCleanupSystem& operator=(const BuildingCleanupSystem&) = delete;
};

void RunTest()
{
	RootSystem* pRootSystem = new RootSystem();
	pRootSystem->AddSystem(new InitializeSystem(new BuildingSetupSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(Repo::Core(), new BuildingPositioningSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(Repo::Core(), new BuildingDestructionSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(Repo::Core(), new BuildingLogSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(Repo::Core(), new BuildingCleanupSystem()));

	pRootSystem->Initialize();
	while(true){
		pRootSystem->Execute();
		if(GetAsyncKeyState(VK_RETURN)){
			break;
		}
	}

	delete pRootSystem;
	delete Repo::Core();
}

int main()
{
	HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);

	try{
		RunTest();
	}catch(runtime_error error){
		SetConsoleTextAttribute(hnd, 12);
		cout << "ERROR >> " << error.what() << endl;
		cin.get();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}
