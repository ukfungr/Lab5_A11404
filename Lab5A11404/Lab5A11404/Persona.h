#pragma once

using namespace std;

class Persona
{
	friend ostream & operator<<(ostream &, const Persona &);
	
private:
	string name;
	int id;

public:
	Persona(string, int);
	virtual ~Persona();
	void setName(string);
	void setId(int);
	string getName();
	int getId();
	Persona getPersona();
};

