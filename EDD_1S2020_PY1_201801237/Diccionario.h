#pragma once
#include <string>
using namespace std;

class Diccionario
{
protected:
	/*
		PROPIEDADES
	*/
	string palabra;
	Diccionario* anterior, * siguiente;

public:
	Diccionario();
	Diccionario(string palabra);
	/*
		GETTER'S
	*/
	string getPalabra() const;
	Diccionario* getAnterior() const;
	Diccionario* getSiguiente() const;

	/*
		SETTER'S
	*/
	void setPalabra(string palabra);
	void setAnterior(Diccionario* anterior);
	void setSiguiente(Diccionario* siguiente);
};

