#include "Ficha.h"

Ficha::Ficha(string letra, int punteo, int cantidad)
{
	this->letra = letra;
	this->punteo = punteo;
	this->cantidad = cantidad;
	this->siguiente = NULL;
}

Ficha::Ficha()
{
}

string Ficha::getLetra() const
{
	return letra;
}

int Ficha::getPunteo() const
{
	return punteo;
}

int Ficha::getCantidad() const
{
	return cantidad;
}

Ficha* Ficha::getSiguiente() const
{
	return siguiente;
}

void Ficha::setLetra(string letra)
{
	this->letra = letra;
}

void Ficha::setPunteo(int punteo)
{
	this->punteo = punteo;
}

void Ficha::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

void Ficha::setSiguiente(Ficha* siguiente)
{
	this->siguiente = siguiente;
}
