#pragma once

#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>

struct MatFloat
{
	int nFilas; // N�mero de filas
	int nColumnas; // N�mero de columnas
	float** ppMatrizF; // Datos de la matriz
};


float** ConstruirMatriz(int nFilas, int nColumnas);

void IntroducirDatos(MatFloat* pDestino);

void Mostrar(MatFloat mOrigen);

void Destruir(MatFloat* pMatFloat);
