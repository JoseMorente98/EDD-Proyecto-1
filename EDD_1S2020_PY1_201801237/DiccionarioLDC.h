#pragma once
#include "Diccionario.h"
#include <fstream>

class DiccionarioLDC
{
private:
	Diccionario* primero = NULL;
	Diccionario* ultimo = NULL;
public:
	DiccionarioLDC();
	void Agregar(string palabra);
	void GenerarGrafico();
};

