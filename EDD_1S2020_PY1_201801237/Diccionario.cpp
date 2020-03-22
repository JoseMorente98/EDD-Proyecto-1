#include "Diccionario.h"

Diccionario::Diccionario()
{
}

Diccionario::Diccionario(string palabra)
{
	this->palabra = palabra;
	this->anterior = NULL;
	this->siguiente = NULL;
}

string Diccionario::getPalabra() const
{
	return palabra;
}

Diccionario* Diccionario::getAnterior() const
{
	return anterior;
}

Diccionario* Diccionario::getSiguiente() const
{
	return siguiente;
}

void Diccionario::setPalabra(string palabra)
{
	this->palabra = palabra;
}

void Diccionario::setAnterior(Diccionario* anterior)
{
	this->anterior = anterior;
}

void Diccionario::setSiguiente(Diccionario* siguiente)
{
	this->siguiente = siguiente;
}
