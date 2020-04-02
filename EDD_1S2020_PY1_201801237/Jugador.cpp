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
	this->idJugador = idJugador;
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

string Jugador::GetCuerpo()
{
	string bodyGraphiz;
	if (izquierda == NULL && derecha == NULL)
	{
		bodyGraphiz = "\tObject" + to_string(getIdJugador()) + " [ label =\""+ getNombre()  + "\"];\n";
	}
	else
	{
		bodyGraphiz = "\tObject" + to_string(getIdJugador()) + "[ label =\"" + getNombre() + "\"];\n";
	}
	if (izquierda != NULL)
	{
		bodyGraphiz += izquierda->GetCuerpo() +
			"Object" + to_string(getIdJugador()) + "->Object" + to_string(izquierda->getIdJugador()) + "\n";
	}
	if (derecha != NULL)
	{
		bodyGraphiz += derecha->GetCuerpo() +
			"Object" + to_string(getIdJugador()) + "->Object" + to_string(derecha->getIdJugador()) + "\n";
	}
	return bodyGraphiz;
}
