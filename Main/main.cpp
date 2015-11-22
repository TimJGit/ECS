#include "../Helpers/stdafx.h"

int main()
{
	HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);

	try{
	}
	catch(runtime_error error){
		SetConsoleTextAttribute(hnd, 12);
		cout << "ERROR >> " << error.what() << endl;
	}

	_CrtDumpMemoryLeaks();
}
