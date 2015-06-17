#pragma once
#include "Elemento.h"

using namespace std;

class Lista {
	friend ostream & operator<<(ostream &, Lista &);

protected:
	Elemento * head;

public:
	int n;
	Lista();
	virtual ~Lista();
	
	void insertarElemento(Elemento *);
	void insertarElementoInicio(Elemento *);
	void insertarElementoFinal(Elemento *);
	void insertarElementoCualquiera(Elemento *, int);
	
	void eliminarElementoInicio();
	void eliminarElementoFinal();
	void eliminarPosicionCualquiera(int);
	void eliminarElementoCualquiera(Elemento *);
	void destruirRec(Elemento *);
	
	void imprimir(Elemento *, ostream &, int);
};

ostream & operator<<(ostream &, Lista &);
