#include "stdafx.h"
#include "Lista.h"


Lista::Lista() {
	head = NULL;
	n = 0;
}

Lista::~Lista() {
	if (head != NULL){
		destruirRec(head);
	}
}

void Lista::destruirRec(Elemento * nodo) {
	if (nodo->getNext() != NULL) {
		destruirRec(nodo->getNext());
	}
	delete nodo;
}

void Lista::insertarElemento(Elemento * elemento) {
	if (head == NULL){
		head = elemento;
		n++;
	}
	else {
		insertarElementoFinal(elemento);
	}
}


void Lista::insertarElementoInicio(Elemento * elemento) {
	Elemento * temp = elemento;
	temp->setNext(head);
	head = temp;
	n++;
}


void Lista::insertarElementoCualquiera(Elemento * nodoActual, int k) {
	Elemento * temp = head;
	Elemento * anterior = NULL;
	int cont = 0;
	while (cont != k - 1){
		anterior = temp;
		temp = temp->getNext();
		cont++;
	}
	Elemento * temp1 = temp;
	anterior->setNext(nodoActual);
	n++;
	anterior->getNext()->setNext(temp);
}


void Lista::insertarElementoFinal(Elemento * nodoActual) {
	Elemento * temp = head;
	while (temp->getNext() != NULL){
		temp = temp->getNext();
	}
	temp->setNext(nodoActual);
	n++;
}


ostream & operator<<(ostream & out, Lista & l) {
	l.imprimir(l.head, out, 0);
	return out;
}

void Lista::imprimir(Elemento* nodo, ostream& out, int kElementos) {
	if (nodo->getNext() != NULL){
		out << *nodo << " -> ";
	}
	else {
		out << *nodo;
	}
	if (nodo->getNext() != NULL){
		imprimir(nodo->getNext(), out, kElementos + 1);
	}
	cout << "\t";
}


void Lista::eliminarElementoInicio(){
	Elemento * temp = head;
	head = head->getNext();
	delete temp;
	n--;
}


void Lista::eliminarElementoFinal(){
	Elemento * temp = head;
	Elemento * previous = NULL;
	while (temp->getNext() != NULL){
		previous = temp;
		temp = temp->getNext();
	}
	previous->setNext(NULL);
	delete temp;
	n--;
}


void Lista::eliminarPosicionCualquiera(int k){
	Elemento * temp = head;
	Elemento * previous = NULL;
	int i = 1;
	while (i < k){
		previous = temp;
		temp = temp->getNext();
		i++;
	}
	Elemento * reasign = NULL;
	previous->setNext(previous->getNext()->getNext());
	delete temp;
	n--;
}

void Lista::eliminarElementoCualquiera(Elemento * nodoActual){
	Elemento * temp = head;
	Elemento * previous = NULL;
	int i = 1;
	while (*temp != *nodoActual){
 		previous = temp;
		temp = temp->getNext();
		i++;
	}
	Elemento * reasign = NULL;
	previous->setNext(previous->getNext()->getNext());
	delete temp;
	n--;
}