#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include"MemoryManager.h"
using namespace std;
/*Clase de objetos CCuenta(Clase base)*/
class CCuenta
{
	//metodos
public:
	CCuenta(string nom, string cue, double sal, double tipo) 
	{
		asignarNombre(nom);
		asignarCuenta(cue);
		saldo = sal;
		TipoDeInteres = tipo;
	
	}
	CCuenta()
	{
		cout << "objeto CCuenta creado\n\n";
		saldo = 0.0;
		TipoDeInteres = 0.0;
	}
	void asignarNombre(string nom) 
	{
		if (nom.length() == 0) {
			cout << "Error: cadena vacia\n\n";
			return;
		}
		nombre = nom;
	}
	string obtenerNombre()
	{
		return nombre;
	}
	void asignarCuenta(string cue)
	{
		if (cue.length() == 0)
		{
			cout << "Error:cuenta no valida\n\n";
			return;
		}cuenta = cue;
	}
	string obtenerCuenta() 
	{
		return cuenta;
	}
	double estado()
	{
		return saldo;
	}
	void ingreso(double cantidad) 
	{
		if (cantidad < 0)
		{
			cout << "Error:cantidad negativa\n\n";
			return;
		}saldo = saldo + cantidad;
	}
	void reintegro(double cantidad) 
	{
		if (saldo - cantidad < 0)
		{
			cout << "Error:no dispone de saldo\n\n";
			return;
		}saldo = saldo - cantidad;
	}
	void asignarTipoDeInteres(double tipo) 
	{
		if (tipo < 0)
		{
			cout << "Error:tipo no valido\n\n";
			return;
		}TipoDeInteres = tipo;
	}
	double obtenerTipoDeInteres()
	{
		return TipoDeInteres;
	}
	//atributos 
private:
	string nombre;
	string cuenta;
	double saldo;
	double TipoDeInteres;

};
/*Clase de objetos CCuentaAhorro(Sub_clase)*/
class CCuentaAhorro : public CCuenta 
{
	//atributos
private	:
	double cuotaMantenimiento;
	//metodos 
public	:
	CCuentaAhorro() { cout << "objeto CCuentaAhorro creado\n\n"; }//constructor sin parametros
	CCuentaAhorro(string nom, string cue, double sal, double tipo, double mant) :CCuenta(nom, cue, sal, tipo) 
	{
		asignarCuotaManten(mant);
		cout << "objeto CCuentaAhorro02 creado\n\n";//constructor con parametros
	}
	void asignarCuotaManten(double cantidad) 
	{
		if (cantidad < 0)
		{
			cout << "Error:cantidad negativa\n\n";
		}cuotaMantenimiento = cantidad;
	}
	double obtenerCuotaManten()
	{
		return cuotaMantenimiento;
	}
	void reintegro(double cantidad)
	{
		double saldo = estado();
		double tipoDeInteres = obtenerTipoDeInteres();
		if ( tipoDeInteres >= 3.5)
		{
			if (saldo-cantidad<1500)
			{
				cout << "Error: no dispone de esa cantidad\n\n";
				return;
			}
		}CCuenta::reintegro(cantidad);
	}
};
int main()
{
	{	
		CCuentaAhorro cuenta02("Un nombre", "Una cuenta", 6000, 3.5, 2);
		//CCuenta cuenta02("Un nombre", "Una cuenta", 6000, 3.5);//¿debo tener distintos valores?
	
		CCuenta cuenta01;
		
		cuenta01.asignarNombre("Un nombre");
		cuenta01.asignarCuenta("Una cuenta");
		cuenta01.asignarTipoDeInteres(2.5);

		cuenta01.ingreso(12000);
		cuenta01.reintegro(3000);
		
		cout << cuenta01.obtenerNombre() << endl;
		cout << cuenta01.obtenerCuenta() << endl;
		cout << cuenta01.estado() << endl;
		cout << cuenta01.obtenerTipoDeInteres() << endl;
		cout << endl;
		//cobrar cuota de mantenimiento
		cuenta02.reintegro(cuenta02.obtenerCuotaManten());
		//ingreso
		cuenta02.ingreso(6000);
		//reintegro
		cuenta02.reintegro(10000);
		cout << cuenta02.obtenerNombre() << endl;
		cout << cuenta02.obtenerCuenta() << endl;
		cout << cuenta02.estado() << endl;
		cout << cuenta02.obtenerTipoDeInteres() << endl;
		cout << endl;
	}
	MemoryManager::dumpMemoryLeaks();
	system("PAUSE");
	return 0;
}
