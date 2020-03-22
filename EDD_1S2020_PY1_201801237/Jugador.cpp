#include "Jugador.h"
int Jugador::contador = 1;

Jugador::Jugador()
{
}

Jugador::Jugador(int longitud, string nombre)
{
	this->longitud = longitud;
	this->nombre = nombre;
	this->idJugador = contador++;
	this->izquierda = NULL;
	this->derecha = NULL;
}

int Jugador::getIdJugador() const
{
	return idJugador;
}

string Jugador::getNombre() const
{
	return nombre;
}

int Jugador::getLongitud() const
{
	return longitud;
}

Jugador* Jugador::getIzquierda() const
{
	return izquierda;
}

Jugador* Jugador::getDerecha() const
{
	return derecha;
}

void Jugador::setIdJugador(int idJugador)
{
	this->setIdJugador = idJugador;
}

void Jugador::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Jugador::setLongitud(int longitud)
{
	this->longitud = longitud;
}

void Jugador::setIzquierda(Jugador* izquierda)
{
	this->izquierda = izquierda;
}

void Jugador::setDerecha(Jugador* derecha)
{
	this->derecha = derecha;
}

void Jugador::GenerarGrafica()
{
}

string Jugador::GetCuerpo()
{
	return string();
}
