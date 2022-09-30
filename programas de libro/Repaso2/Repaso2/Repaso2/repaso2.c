/*Matriz dinamica de una dimension */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"MemoryManager.h"
//funciones
void* insertarElemento(int* m, int* pnElementos, int pos);
void asignarValoresAleatorios(int* m, int n);
void mostrarMatriz(int* m, int n);
int main() 
{
	int* m = NULL, * q = NULL;
	int correcto = 0, nElementos = 0;
	do
	{
		printf("Numero de elementos de la matriz: ");
		correcto = scanf("%d",&nElementos);
		while (getchar() != '\n');//limpiar buffer
	} while (!correcto||nElementos<1);
	//CREAR MATRIZ
	if ((m = (int*)malloc(nElementos * sizeof(int))) == NULL)
	{
		printf("Insuficiente Espacio de Memoria\n");
		return -1;
	}
	//INICIAR LOS ELEMENTOS A CERO
	for (int i = 0; i < nElementos; i++)
	{
		m[i] = 0;
	}
	asignarValoresAleatorios(m, nElementos);
	mostrarMatriz(m, nElementos);
	//INSERTAR UN ELEMENTO A LA POSICION 5
	int pos = 5;
	if ((q = (int*)insertarElemento(m, &nElementos, pos)) == NULL)
		printf("No es posible realizar la insercion\n");
	else
	{
		m = q;
	}
	//ELEMENTO A FINAL 
	pos = nElementos;
	if ((q = (int*)insertarElemento(m, &nElementos, pos)) == NULL)
		printf("No es posible realizar la insercion\n");
	else
	{
		m = q;
	}
	mostrarMatriz(m, nElementos);
	free(m);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}
void* insertarElemento(int* m, int* pnElementos, int pos)
{
	int n = *pnElementos;
	if (pos<0 || pos>n)return 0;
	m = (int*)realloc(m, (n + 1) * sizeof(int));
	if (m != 0)
	{
		for (int i = n; i > pos; i--) 
		{
			m[i] = m[i - 1];
			m[pos] = 0;//ELEMETO INSERTADO
			//ACUALIZAR NUEMRO DE ELEMTOS DE LA MATRIZ
			*pnElementos = n + 1;
		}
	}
	return m;
}

void asignarValoresAleatorios(int* m, int n) 
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		m[i] = rand();
	}

}
void mostrarMatriz(int* m, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d",m[i]);
		printf("\n\n");
	}

}