#pragma once
#include "Jugador.h"
class JugadorAB
{
private:
	Jugador* root = NULL;
	int longitud;
public:
	void Agregar(string nombre);
	Jugador* Agregar(string nombre, Jugador *raiz);
	Jugador* Buscar(string nombre);
	Jugador* Buscar(string nombre, Jugador* root);
	int Longitud();
	void InOrden(Jugador* jugador);
	void PreOrden(Jugador* jugador);
	void PosOrden(Jugador* jugador);
	Jugador* GetRaiz();
	void GenerarGrafico(string nombre);
};

