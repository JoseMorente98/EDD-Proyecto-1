#pragma once
#include "ScoreBoard.h"
#include <fstream>
#include <iostream>

class ScoreBoardLS
{
	ScoreBoard* primero;
	void Agregar(int puntos, string nombre);
	void Imprimir();
	void GenerarGrafico(string nombre);
	void GenerarGrafico();
};

