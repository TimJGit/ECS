#include "../Helpers/stdafx.h"
#include "../Components/Components.h"
#include "../Entity/Entity.h"
#include "../Group/Group.h"
#include "../Pool/Pool.h"

void RunTest()
{
	Pool* pPool = new Pool();
	delete pPool;
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

	cin.get();
	_CrtDumpMemoryLeaks();
}
