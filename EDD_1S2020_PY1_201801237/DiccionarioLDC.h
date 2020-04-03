#pragma once
#include "Diccionario.h"
#include <fstream>

class DiccionarioLDC
{
private:
	Diccionario* primero;
	Diccionario* ultimo;
	static DiccionarioLDC* instancia;
public:
	DiccionarioLDC();
	static DiccionarioLDC* Instancia();
	bool EsVacio() const;
	void Agregar(string palabra);
	Diccionario* Buscar(string palabra);
	void GenerarGrafico(string nombre);
};

