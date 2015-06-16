#include "stdafx.h"
#include "ElementoPersona.h"
#include "Persona.h"


ElementoPersona::ElementoPersona(Persona * p) {
	this->p = p;
}

ElementoPersona::~ElementoPersona() {

}

Persona * ElementoPersona::getPersona(){
	return p;
}

int ElementoPersona::compareTo(Elemento * otro){
	int cmp = 0;
	int idThis = this->getPersona()->getId();
	ElementoPersona * ePer = dynamic_cast<ElementoPersona *>(otro);
	if (ePer != 0) {
		int idOtro = ePer->getPersona()->getId();
		cmp = idThis < idOtro ? -1 : idThis == idOtro ? 0 : 1;
	}
	return cmp;
}

void ElementoPersona::imprimir(ostream& out) const {
	out << *p;
}
