#pragma once
#include <string>
using namespace std;

class TableroPuntuacion
{
protected:
	int puntos;
	string nombre;
	TableroPuntuacion* siguiente;
public:
	TableroPuntuacion(int puntos, string nombre);
	TableroPuntuacion();
	/*
		GETTER'S
	*/
	int getPuntos() const;
	string getNombre() const;
	TableroPuntuacion* getSiguiente() const;
	/*
		SETTER'S
	*/
	void setPuntos(int puntos);
	void setNombre(string nombre);
	void setSiguiente(TableroPuntuacion* siguiente);
};

