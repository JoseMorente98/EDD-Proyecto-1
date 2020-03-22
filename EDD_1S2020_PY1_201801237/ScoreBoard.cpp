#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(int puntos, string nombre)
{
	this->puntos = puntos;
	this->nombre = nombre;
	this->siguiente = NULL;
}

ScoreBoard::ScoreBoard()
{
}

int ScoreBoard::getPuntos() const
{
	return puntos;
}

string ScoreBoard::getNombre() const
{
	return nombre;
}

ScoreBoard* ScoreBoard::getSiguiente() const
{
	return siguiente;
}

void ScoreBoard::setPuntos(int puntos)
{
	this->puntos = puntos;
}

void ScoreBoard::setNombre(string nombre)
{
	this->nombre = nombre;
}

void ScoreBoard::setSiguiente(ScoreBoard* siguiente)
{
	this->siguiente = siguiente;
}
