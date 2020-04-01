#include "Apartado.h"

Apartado::Apartado()
{
}

Apartado::Apartado(int posicionX, int posicionY, bool esDoble, bool esTriple)
{
}

int Apartado::getPosicionX() const
{
	return this->posicionX;
}

int Apartado::getPosicionY() const
{
	return this->posicionY;
}

bool Apartado::getEsDoble() const
{
	return this->esDoble;
}

bool Apartado::getEsTriple() const
{
	return this->esTriple;
}

Apartado* Apartado::getSiguiente() const
{
	return this->siguiente;
}

Apartado* Apartado::getAnterior() const
{
	return this->anterior;
}

void Apartado::setPositionX(int posicionX)
{
	this->posicionX = posicionX;
}

void Apartado::setPositionY(int posicionY)
{
	this->posicionY = posicionY;
}

void Apartado::setEsDoble(bool esDoble)
{
	this->esDoble = esDoble;
}

void Apartado::setEsTriple(bool esTriple)
{
	this->esTriple = esTriple;
}

void Apartado::setSiguiente(Apartado* siguiente)
{
	this->siguiente = siguiente;
}

void Apartado::setAnterior(Apartado* anterior)
{
	this->anterior = anterior;
}
