// Lab5A11404.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"

#include "Elemento.h"
#include "Lista.h"
#include "Elemento.h"
#include "ElementoInt.h"
#include "ElementoDouble.h"
#include "Persona.h"
#include "ElementoPersona.h"
#include "ElementoIntInt.h"

using namespace std;

bool findRepeat(int[], int); //Declaración del método para buscar si un id es repetido
//@parametros:  - int []: array donde se guardan los id
//				- int: número aleatorio que se genera para el id

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned int)time(0));

	cout << "Seleccione el tipo de lista que desea generar (indique numero)" << endl;
	cout << "1. Lista de Int" << endl;
	cout << "2. Lista de Doubles" << endl;
	cout << "3. Lista de Personas" << endl;
	cout << "4. Lista de IntInt" << endl;
	cout << "Indice: ";
	int r = 0;
	cin >> r;
	cout << endl;

	if (r == 1){
		cout << "Lista de enteros" << endl;
		Lista l;
		for (int i = 0; i < 10; ++i) {
			l.insertarElemento(new ElementoInt(rand() % 100));
		}
		cout << l << endl;

		cout << "Inserta elemento al inicio" << endl;
		l.insertarElementoInicio(new ElementoInt(rand() % 100));
		cout << l << endl;

		cout << "Inserta elemento al final" << endl;
		l.insertarElementoFinal(new ElementoInt(rand() % 100));
		cout << l << endl;

		cout << "Inserta en cualquier posicion" << endl;
		int posicion = 5;
		int content = 58;
		l.insertarElementoCualquiera(new ElementoInt(content), posicion);
		cout << "Se inserta el elemento " << content << ", en la posicion " << posicion << " de la lista" << endl;
		cout << l << endl;

		cout << "Elimina al inicio" << endl;
		l.eliminarElementoInicio();
		cout << l << endl;

		cout << "Elimina al final" << endl;
		l.eliminarElementoFinal();
		cout << l << endl;

		cout << "Elimina cualquier posicion de 2 a n (1 seria Inicio)" << endl;
		posicion = 7;
		l.eliminarPosicionCualquiera(posicion);
		cout << "Elimina la posicion " << posicion << endl;
		cout << l << endl;

		cout << "Elimina el elemento en la lista que se indique (si esta repetido, elimina el primero que encuentra)" << endl;
		content = 58;
		l.eliminarElementoCualquiera(new ElementoInt(content));
		cout << "Elimina el elemento " << content << endl;
		cout << l << endl;
	}
	
	if (r == 2){
		cout << "Lista de doubles" << endl;
		Lista d;
		for (int i = 0; i < 15; ++i) {
			d.insertarElemento(new ElementoDouble(((double)rand()*(100.00 - 0.00)) / (double)RAND_MAX));
		}
		cout << d << endl;

		cout << "Inserta elemento al inicio" << endl;
		d.insertarElementoInicio(new ElementoDouble(((double)rand()*(100.00 - 0.00)) / (double)RAND_MAX));
		cout << d << endl;

		cout << "Inserta elemento al final" << endl;
		d.insertarElementoFinal(new ElementoDouble(((double)rand()*(100.00 - 0.00)) / (double)RAND_MAX));
		cout << d << endl;

		cout << "Inserta en cualquier posicion" << endl;
		int posicion = 4;
		double content = 58.97;
		d.insertarElementoCualquiera(new ElementoDouble(content), posicion);
		cout << "Se inserta el elemento " << content << ", en la posicion " << posicion << " de la lista" << endl;
		cout << d << endl;

		cout << "Elimina al inicio" << endl;
		d.eliminarElementoInicio();
		cout << d << endl;

		cout << "Elimina al final" << endl;
		d.eliminarElementoFinal();
		cout << d << endl;

		cout << "Elimina cualquier posicion de 2 a n (1 seria Inicio)" << endl;
		posicion = 7;
		d.eliminarPosicionCualquiera(posicion);
		cout << "Elimina la posicion " << posicion << endl;
		cout << d << endl;

		cout << "Elimina el elemento existente en la lista que se indique (si esta repetido, elimina el primero que encuentra)" << endl;
		content = 58.97;
		d.eliminarElementoCualquiera(new ElementoDouble(content));
		cout << "Elimina el elemento " << content << endl;
		cout << d << endl;
	}
	
	if (r == 3){
		cout << "Lista de personas" << endl;
		Lista q;
		string names[100];//Arreglo para los nombres
		int k = 0;
		ifstream myFile("nombres.txt");
		while (!myFile.eof()){
			getline(myFile, names[k]);
			k++;
		}

		//Array para crear id no repetidos para cada Persona
		int id[10];
		int c = 0;
		while (c < 10){
			int number = rand() % (110889 - 10000) + 10000;
			if (findRepeat(id, number) != true){
				id[c] = number;
				c++;
			}
		}
		Persona * p[10];
		for (int i = 0; i < 10; i++){
			p[i] = new Persona(names[rand() % 100], id[i]);
		}

		for (int i = 0; i < 10; ++i) {
			q.insertarElemento(new ElementoPersona(p[i]));
		}
		cout << q << endl;

		int posicion = 5;
		string name = "Maria";
		int id1 = 8733748;
		cout << "Inserta elemento al inicio" << endl;
		Persona * h = new Persona(name, id1);
		q.insertarElementoInicio(new ElementoPersona(h));
		cout << "Se inserta el elemento " << name << ", id" << id1 << " en la lista" << endl;
		cout << q << endl;

		cout << "Inserta elemento al final" << endl;
		q.insertarElementoFinal(new ElementoPersona(h));
		cout << q << endl;

		cout << "Inserta en cualquier posicion" << endl;
		q.insertarElementoCualquiera(new ElementoPersona(h), posicion);
		cout << "Se inserta el elemento " << name << ", id " << id1 << " de la lista" << endl;
		cout << q << endl;

		cout << "Elimina al inicio" << endl;
		q.eliminarElementoInicio();
		cout << q << endl;

		cout << "Elimina al final" << endl;
		q.eliminarElementoFinal();
		cout << q << endl;

		cout << "Elimina cualquier posicion de 2 a n (1 seria Inicio)" << endl;
		posicion = 8;
		q.eliminarPosicionCualquiera(posicion);
		cout << "Se elimina el elemento en la posicion " << posicion << " de la lista" << endl;
		cout << q << endl;

		cout << "Elimina cualquier elemento que se indique (si esta repetido, elimina el primero que encuentra)" << endl;
		q.eliminarElementoCualquiera(new ElementoPersona(h));
		cout << "Se elimina el elemento " << name << ", id " << id1 << " de la lista" << endl;
		cout << q << endl;
	}

	if (r == 4){
		cout << "Lista de IntInt" << endl;
		Lista m;
		for (int i = 0; i < 10; ++i) {
			m.insertarElemento(new ElementoIntInt(rand() % 100, rand() % 100));
		}
		cout << m << endl;

		cout << "Inserta elemento al inicio" << endl;
		m.insertarElementoInicio(new ElementoIntInt(rand() % 100, rand() % 100));
		cout << m << endl;

		cout << "Inserta elemento al final" << endl;
		m.insertarElementoFinal(new ElementoIntInt(rand() % 100, rand() % 100));
		cout << m << endl;

		cout << "Inserta en cualquier posicion" << endl;
		int posicion = 5;
		int content = 58;
		m.insertarElementoCualquiera(new ElementoIntInt(content, content), posicion);
		cout << "Se inserta el elemento " << content*content << ", en la posicion " << posicion << " de la lista" << endl;
		cout << m << endl;

		cout << "Elimina al inicio" << endl;
		m.eliminarElementoInicio();
		cout << m << endl;

		cout << "Elimina al final" << endl;
		m.eliminarElementoFinal();
		cout << m << endl;

		cout << "Elimina cualquier posicion de 2 a n (1 seria Inicio)" << endl;
		posicion = 7;
		m.eliminarPosicionCualquiera(posicion);
		cout << "Elimina la posicion " << posicion << endl;
		cout << m << endl;

		cout << "Elimina el elemento en la lista que se indique (si esta repetido, elimina el primero que encuentra)" << endl;
		content = 58;
		m.eliminarElementoCualquiera(new ElementoIntInt(content, content));
		cout << "Elimina el elemento " << content*content << endl;
		cout << m << endl;
	}

	system("pause");
	return 0;
}


//Función para buscar si el ID de persona random generado es repetido
bool findRepeat(int id[100], int number){
	for (int i = 0; i < 100; i++){
		if (number == id[i]){
			return true;
		}
	}
}