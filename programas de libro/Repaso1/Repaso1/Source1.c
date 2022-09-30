/*Puntero de puntero 
puntero a puntero 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void leerMatriz(int **q, int f, int c) 
{
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++) {
			printf("Elemento [%d][%d]: ",i,j);
			scanf("%d",&q[i][j]);
		
		}
	}
}
void visualizaMatriz(int** q, int f, int c) {
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++) {
			printf("%7d", q[i][j]);
			printf("\n");
		}

	}

}
	int main(void) 
{
		int a[5][5];//matriz de dos dimensiones
		int* p[5];//matriz de punteros
		for (int i = 0; i < 5; i++)
		{
			p[i] = a[i];//asignar a P las filas de A
		}
		leerMatriz(p, 5, 5);
		visualizaMatriz(p, 5, 5);
		system("PAUSE");
		return 0;
	




}




