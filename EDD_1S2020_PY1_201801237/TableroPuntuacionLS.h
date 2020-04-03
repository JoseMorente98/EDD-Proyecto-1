#pragma once
#include "TableroPuntuacion.h"
#include <fstream>
#include <iostream>

class TableroPuntuacionLS
{
private:
	TableroPuntuacion* primero;
	static TableroPuntuacionLS* instancia;
public:
	TableroPuntuacionLS();
	static TableroPuntuacionLS* Instancia();
	bool EsVacio() const;
	void Agregar(int puntos, string nombre);
	TableroPuntuacion* Buscar(string nombre);
	void Imprimir();
	void GenerarGrafico(string nombre);
	void GenerarGraficoPorJugador(string nombre);
};

