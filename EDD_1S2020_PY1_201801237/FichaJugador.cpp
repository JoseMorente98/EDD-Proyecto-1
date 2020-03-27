#include "FichaJugador.h"

FichaJugador::FichaJugador()
{
}

FichaJugador::FichaJugador(string letra, int punteo, int posicionX, int posicionY)
{
	this->letra = letra;
	this->punteo = punteo;
	this->posicionX = posicionX;
	this->posicionY = posicionY;
	this->siguiente = NULL;
	this->anterior = NULL;
}

string FichaJugador::getLetra() const
{
	return letra;
}

int FichaJugador::getPunteo() const
{
	return punteo;
}

int FichaJugador::getPosicionX() const
{
	return posicionX;
}

int FichaJugador::getPosicionY() const
{
	return posicionY;
}

FichaJugador* FichaJugador::getSiguiente() const
{
	return siguiente;
}

FichaJugador* FichaJugador::getAnterior() const
{
	return anterior;
}

void FichaJugador::setLetra(string letra)
{
	this->letra = letra;
}

void FichaJugador::setPunteo(int punteo)
{
	this->punteo = punteo;
}

void FichaJugador::setPosicionX(int posicionX)
{
	this->posicionX = posicionX;
}

void FichaJugador::setPosicionY(int posicionY)
{
	this->posicionY = posicionY;
}

void FichaJugador::setSiguiente(FichaJugador* siguiente)
{
	this->siguiente = siguiente;
}

void FichaJugador::setAnterior(FichaJugador* anterior)
{
	this->anterior = anterior;
}
