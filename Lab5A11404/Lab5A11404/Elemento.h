#pragma once
using namespace std;

class Elemento {
	friend ostream & operator<<(ostream &, const Elemento &);

protected:
	Elemento();
	Elemento * next;

public:
	Elemento * getNext();
	void setNext(Elemento *);
	virtual ~Elemento();
	virtual int compareTo(Elemento *) = 0;
	virtual void imprimir(ostream &) const = 0;

	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);
	bool operator!=(Elemento &);
};

ostream & operator<<(ostream &, const Elemento &);
