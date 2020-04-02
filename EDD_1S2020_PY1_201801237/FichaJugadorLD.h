#pragma once
#include <string>
#include "FichaJugador.h"
class FichaJugadorLD
{
private:
	FichaJugador* primero;
	FichaJugador* ultimo;
	static int longitud;
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
};

