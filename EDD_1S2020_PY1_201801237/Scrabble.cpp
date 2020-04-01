#include "Scrabble.h"
int Scrabble::contador = 1;

Scrabble::Scrabble()
{
}

Scrabble::Scrabble(string dato, int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	this->dato = dato;
	this->posicionX = posicionY;
	this->posicionY = posicionY;
	this->indice = contador++;
	this->esDoble = esDoble;
	this->esTriple = esTriple;
	this->siguiente = NULL;
	this->anterior = NULL;
	this->arriba = NULL;
	this->abajo = NULL;
}

Scrabble::Scrabble(string dato, int puntos, int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	this->dato = dato;
	this->posicionX = posicionY;
	this->posicionY = posicionY;
	this->puntos = puntos;
	this->indice = contador++;
	this->esDoble = esDoble;
	this->esTriple = esTriple;
	this->siguiente = NULL;
	this->anterior = NULL;
	this->arriba = NULL;
	this->abajo = NULL;
}

int Scrabble::getIndice() const
{
	return indice;
}

string Scrabble::getDato() const
{
	return dato;
}

bool Scrabble::getEsDoble() const
{
	return esDoble;
}

bool Scrabble::getEsTriple() const
{
	return esTriple;
}

int Scrabble::getPosicionX() const
{
	return posicionX;
}

int Scrabble::getPosicionY() const
{
	return posicionY;
}

int Scrabble::getPuntos() const
{
	return puntos;
}

Scrabble* Scrabble::getSiguiente() const
{
	return siguiente;
}

Scrabble* Scrabble::getAnterior() const
{
	return anterior;
}

Scrabble* Scrabble::getArriba() const
{
	return arriba;
}

Scrabble* Scrabble::getAbajo() const
{
	return abajo;
}

void Scrabble::setIndice(int indice)
{
	this->indice = indice;
}

void Scrabble::setDato(string dato)
{
	this->dato = dato;
}

void Scrabble::setEsDoble(bool esDoble)
{
	this->esDoble = esDoble;
}

void Scrabble::setEsTriple(bool esTriple)
{
	this->esTriple = esTriple;
}

void Scrabble::setPositionX(int posicionX)
{
	this->posicionX = posicionX;
}

void Scrabble::setPositionY(int posicionY)
{
	this->posicionY = posicionY;
}

void Scrabble::setPuntos(int puntos)
{
	this->puntos = puntos;
}

void Scrabble::setSiguiente(Scrabble* siguiente)
{
	this->siguiente = siguiente;
}

void Scrabble::setAnterior(Scrabble* anterior)
{
	this->anterior = anterior;
}

void Scrabble::setArriba(Scrabble* arriba)
{
	this->arriba = arriba;
}

void Scrabble::setAbajo(Scrabble* abajo)
{
	this->abajo = abajo;
}
