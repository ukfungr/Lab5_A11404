#pragma once
#include "Elemento.h"
class ElementoInt :
	public Elemento
{
protected:
	int i;

public:
	ElementoInt(int i);
	virtual ~ElementoInt();
	int compareTo(Elemento *);
	virtual void imprimir(ostream &) const;
};

