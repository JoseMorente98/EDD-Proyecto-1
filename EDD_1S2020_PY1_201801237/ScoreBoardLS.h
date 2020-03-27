#pragma once
#include "ScoreBoard.h"
#include <fstream>
#include <iostream>

class ScoreBoardLS
{
private:
	ScoreBoard* primero;
public:
	bool EsVacio() const;
	void Agregar(int puntos, string nombre);
	void Imprimir();
	void GenerarGrafico(string nombre);
	void GenerarGrafico();
};

