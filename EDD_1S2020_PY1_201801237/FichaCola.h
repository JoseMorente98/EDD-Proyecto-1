#pragma once
#include "Ficha.h"
#include <fstream>
#include <iostream>

class FichaCola
{
	Ficha* primero, * ultimo;
	FichaCola();
	void Agregar(string letra, int punteo, int cantidad);
	bool EsVacio() const;
	Ficha* Eliminar();
	Ficha* Peek()const;
	void Limpiar();
	void GenerarGrafico();

};

