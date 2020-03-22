#pragma once
#include <string>
using namespace std;

class ScoreBoard
{
	int puntos;
	string nombre;
	ScoreBoard* next;
	ScoreBoard(int puntos, string nombre);
	ScoreBoard();
};

