#pragma once
#include "ElementoInt.h"

using namespace std;

class ElementoIntInt :
	public ElementoInt
{
private:
	int j;

public:
	ElementoIntInt(int i, int j);
	virtual ~ElementoIntInt();
	int compareTo(Elemento *);
	void imprimir(ostream &) const;
};

