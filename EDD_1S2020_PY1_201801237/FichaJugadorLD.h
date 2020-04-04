#pragma once
#include "FichaJugador.h"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
class FichaJugadorLD
{
private:
	FichaJugador* primero;
	FichaJugador* ultimo;
	int longitud;
public:
	FichaJugadorLD();
	bool EsVacio() const;
	void Agregar(string letra, int punteo);
	void Agregar(string letra, int punteo, int posicionX, int posicionY);
	FichaJugador* Buscar(string search);
	int Longitud();
	void Limpiar();
	void Mostrar();
	void Eliminar(string search);
	void GenerarGrafico(string nombre);
	FichaJugador* getPrimero() const;
	FichaJugador* getUltimo() const;
	void setUltimo(FichaJugador* ultimo);
	void setPrimero(FichaJugador* primero);
};

