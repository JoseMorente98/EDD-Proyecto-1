#pragma once
#include "Ficha.h"
#include <fstream>
#include <iostream>

class FichaCola
{
private:
	Ficha* primero;
	Ficha* ultimo;
public:
	FichaCola();
	bool EsVacio() const;
	void Agregar(string letra, int punteo, int cantidad);
	Ficha* Eliminar();
	Ficha* Peek()const;
	void Imprimir();
	void Limpiar();
	void GenerarGrafico();
};

