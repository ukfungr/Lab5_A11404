#pragma once

#include "Elemento.h"

using namespace std;

class ElementoDouble : public Elemento {

private:
	double d;

public:
	ElementoDouble(double d);
	virtual ~ElementoDouble();
	int compareTo(Elemento *);
	void imprimir(ostream &) const;
};

