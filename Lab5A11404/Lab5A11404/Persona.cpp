#include "stdafx.h"
#include "Persona.h"

using namespace std;

Persona::Persona(string name, int id) {
	this->name = name;
	this->id = id;

	setName(name);
	setId(id);
}

Persona::~Persona() {

}

ostream & operator<<(ostream & out, const Persona & p){
	out << p.name << "::" << p.id;
	return out;
}

void Persona::setName(string n){
	name = n;
}

void Persona::setId(int i){
	id = i;
}

string Persona::getName(){
	return name;
}

int Persona::getId(){
	return id;
}

