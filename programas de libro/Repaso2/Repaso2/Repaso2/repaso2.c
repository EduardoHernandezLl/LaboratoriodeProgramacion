/*Matriz dinamica de una dimension */
#include<stdio.h>
#include<stdlib.h>
#include"MemoryManager.h"
//funciones
void* insertarElemento(int* m, int* pnElementos, int pos);
void asignarValoresAleatorios(int* m, int n);
void mostrarMatriz(int* m, int n);
int main() 
{





	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}