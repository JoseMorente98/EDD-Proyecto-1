#include "TableroPuntuacion.h"
TableroPuntuacion::TableroPuntuacion(int puntos, string nombre)
{
	this->puntos = puntos;
	this->nombre = nombre;
	this->siguiente = NULL;
}

TableroPuntuacion::TableroPuntuacion()
{
}

int TableroPuntuacion::getPuntos() const
{
	return puntos;
}

string TableroPuntuacion::getNombre() const
{
	return nombre;
}

TableroPuntuacion* TableroPuntuacion::getSiguiente() const
{
	return siguiente;
}

void TableroPuntuacion::setPuntos(int puntos)
{
	this->puntos = puntos;
}

void TableroPuntuacion::setNombre(string nombre)
{
	this->nombre = nombre;
}

void TableroPuntuacion::setSiguiente(TableroPuntuacion* siguiente)
{
	this->siguiente = siguiente;
}
