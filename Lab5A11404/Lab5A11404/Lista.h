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
	
	Elemento * previo(Elemento *, int);//retorna el elemento anterior al que se desea insertar
	
	void eliminarElementoInicio();
	void eliminarElementoFinal();
	void eliminarPosicionCualquiera(int);
	void eliminarElementoCualquiera(Elemento *);
	void destruirRec(Elemento *);
	
	void imprimir(Elemento *, ostream &, int);
};

ostream & operator<<(ostream &, Lista &);
