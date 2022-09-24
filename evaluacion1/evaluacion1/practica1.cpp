#include "MemoryManager.h"
#include"funciones.cpp"
#include"funciones.h"
using namespace std;
int menu() {
	cout << "\n\n";
	cout << "1.Construir matriz\n";
	cout << "2.Introducir matriz\n";
	cout << "3.Volcar matriz\n";
	cout << "4.Destruir matriz\n";
	cout << "5.Terminar\n";
	int op;
	while (op<1||op>5)
	{
		cin.ignore();
		return op;

	}

}
int main()
{
	{
		int n, opcion=0;
		do
		{
			opcion = menu();
			switch (opcion)
			{
			case1://construir matriz
				break;
			case2://introducir matriz
				break;
			case3://volcar matriz
				break;
			case4://destruir matriz
				break;
			}

		} while (opcion !=5);
		return 0;
	}
	MemoryManager::dumpMemoryLeaks();
	system("PAUSE");
	return 0;
}
