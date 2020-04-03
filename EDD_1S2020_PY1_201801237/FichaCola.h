#pragma once
#include "Ficha.h"
#include <fstream>
#include <iostream>

class FichaCola
{
private:
	Ficha* primero;
	Ficha* ultimo;
	static FichaCola* instancia;
public:
	FichaCola();
	static FichaCola* Instancia();
	bool EsVacio() const;
	void Agregar(string letra, int punteo, int cantidad);
	Ficha* Eliminar();
	Ficha* Peek()const;
	void Imprimir();
	void Limpiar();
	void GenerarGrafico(string nombre);
};

