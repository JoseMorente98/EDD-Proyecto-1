#pragma once
#include <string>
using namespace std;

class Ficha
{
	/*
		PROPIEDADES
	*/
protected:
	string letra;
	int punteo;
	int cantidad;
	Ficha* siguiente;

public:
	Ficha(string letra, int punteo, int cantidad);
	Ficha();
	/*
	GETTER'S
	*/
	string getLetra() const;
	int getPunteo() const;
	int getCantidad() const;
	Ficha* getSiguiente() const;

	/*
		SETTER'S
	*/
	void setLetra(string letra);
	void setPunteo(int punteo);
	void setCantidad(int cantidad);
	void setSiguiente(Ficha* siguiente);
};

