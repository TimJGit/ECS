#include "../Helpers/stdafx.h"
#include "../Components/Components.h"
#include "../Entity/Entity.h"
#include "../Group/Group.h"
#include "../Pool/Pool.h"
#include "../Systems/Systems.h"

class Repo
{
public:
	virtual ~Repo() { }

	static Pool& Core()
	{
		static Pool corePool;
		return corePool;
	}

private:
	Repo() { }

	Repo(const Repo&) = delete;
	Repo& operator=(const Repo&) = delete;
};

class BuildingSetupSystem : public IInitializeSystem
{
public:
	BuildingSetupSystem() { }
	virtual ~BuildingSetupSystem() { }

	virtual void Initialize()
	{
		for(int i = 0; i < 10; i++){
			Entity& entity = Repo::Core().CreateEntity();
			entity.AddComponent(new BuildingComponent());
			entity.AddComponent(new TypeComponent("House"));
			entity.AddComponent(new LevelComponent(1));
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

	virtual vector<ComponentID> GetTriggers() { return { ComponentID::Building, ComponentID::Type, ComponentID::Level }; };
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerAdded; };
	virtual void Execute(vector<Entity*> pEntites)
	{
		for(Entity* pEntity : pEntites){
			pEntity->AddComponent(new PositionComponent(2.0f, 5.0f, 0.5f));
		}
	}

private:
	BuildingPositioningSystem(const BuildingPositioningSystem&) = delete;
	BuildingPositioningSystem& operator=(const BuildingPositioningSystem&) = delete;
};

void RunTest()
{
	RootSystem* pRootSystem = new RootSystem();
	pRootSystem->AddSystem(new InitializeSystem(new BuildingSetupSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(&Repo::Core(), new BuildingPositioningSystem()));

	pRootSystem->Initialize();
	while(true){
		if(GetAsyncKeyState(VK_ESCAPE)){
			break;
		}
		pRootSystem->Execute();
	}
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
}
