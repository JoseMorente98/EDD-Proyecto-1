#pragma once
#include "Diccionario.h"
#include <fstream>

class DiccionarioLDC
{
private:
	Diccionario* primero;
	Diccionario* ultimo;
public:
	DiccionarioLDC();
	bool EsVacio() const;
	void Agregar(string palabra);
	void GenerarGrafico(string nombre);
};

