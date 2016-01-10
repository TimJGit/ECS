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
		}
	}

private:
	BuildingSetupSystem(const BuildingSetupSystem&) = delete;
	BuildingSetupSystem& operator=(const BuildingSetupSystem&) = delete;
};

class BuildingCreatedSystem : public IReactiveSystem
{
public:
	BuildingCreatedSystem() { }
	virtual ~BuildingCreatedSystem() { }

	virtual vector<ComponentID> GetTriggers() { return { ComponentID::Building }; };
	virtual TriggerEvent GetTriggerEvent() { return TriggerEvent::TriggerAdded; };
	virtual void Execute(vector<Entity*> pEntites)
	{
		for(Entity* pEntity : pEntites){
			cout << "Building created!" << endl;
		}
	}

private:
	BuildingCreatedSystem(const BuildingCreatedSystem&) = delete;
	BuildingCreatedSystem& operator=(const BuildingCreatedSystem&) = delete;
};

void RunTest()
{
	RootSystem* pRootSystem = new RootSystem();
	pRootSystem->AddSystem(new InitializeSystem(new BuildingSetupSystem()));
	pRootSystem->AddSystem(new ReactiveSystem(&Repo::Core(), new BuildingCreatedSystem()));

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
	}

	_CrtDumpMemoryLeaks();
}
