#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "MemoryManager.h"


int main()
{
	{
		"hola"; "al fin pude";//aqui va su comentario

	}
	MemoryManager::dumpMemoryLeaks();
	system("PAUSE");
	return 0;
}
