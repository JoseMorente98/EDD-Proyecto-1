#pragma once
#include "ScoreBoard.h"

class ScoreBoardLS
{
	ScoreBoard* primero;
	void Agregar(int puntos, string nombre);
	void GenerarGrafico(string nombre);
	void GenerarGrafico();
};

