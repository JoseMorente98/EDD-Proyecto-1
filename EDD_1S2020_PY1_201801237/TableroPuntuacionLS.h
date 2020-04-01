#pragma once
#include "TableroPuntuacion.h"
#include <fstream>
#include <iostream>

class TableroPuntuacionLS
{
private:
	TableroPuntuacion* primero;
public:
	bool EsVacio() const;
	void Agregar(int puntos, string nombre);
	void Imprimir();
	void GenerarGrafico(string nombre);
	void GenerarGrafico();
};

