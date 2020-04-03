#pragma once
#include "Jugador.h"
#include <fstream>
#include <iostream>
#include <windows.h>

class JugadorAB
{
public:
	Jugador* root;
	int longitud = 0;
	static JugadorAB* instancia;
public:
	JugadorAB();
	static JugadorAB* Instancia();
	void Agregar(string nombre);
	Jugador* Agregar(string nombre, Jugador *raiz);
	Jugador* Buscar(string nombre);
	Jugador* Buscar(string nombre, Jugador* root);
	int Longitud();
	void InOrden(Jugador* jugador);
	string InOrden(Jugador* jugador, string bodyGraphiz);
	string PreOrden(Jugador* jugador, string bodyGraphiz);
	string PosOrden(Jugador* jugador, string bodyGraphiz);
	Jugador* GetRaiz();
	void ImprimirInOrden();
	void GenerarGrafico(string nombre);
	void ReporteInOrden(string nombre);
	void ReportePreOrden(string nombre);
	void ReportePosOrden(string nombre);
};

