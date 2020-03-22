#pragma once
#include <string>
using namespace std;

class ScoreBoard
{
protected:
	int puntos;
	string nombre;
	ScoreBoard* siguiente;
public:
	ScoreBoard(int puntos, string nombre);
	ScoreBoard();
	/*
		GETTER'S
	*/
	int getPuntos() const;
	string getNombre() const;
	ScoreBoard* getSiguiente() const;
	/*
		SETTER'S
	*/
	void setPuntos(int puntos);
	void setNombre(string nombre);
	void setSiguiente(ScoreBoard* siguiente);
};

