#pragma once
#include <string>
using namespace std;

class Jugador
{
	/*
		PROPIEDADES
	*/
protected:
	int idJugador;
	string nombre;
	int longitud;
	static int contador;
	Jugador* izquierda, * derecha;

public:
	Jugador();
	Jugador(int longitud, string nombre);
	/*
		GETTER'S
	*/
	int getIdJugador() const;
	string getNombre() const;
	int getLongitud() const;
	Jugador* getIzquierda() const;
	Jugador* getDerecha() const;
	/*
		SETTER'S
	*/
	void setIdJugador(int idJugador);
	void setNombre(string nombre);
	void setLongitud(int longitud);
	void setIzquierda(Jugador* izquierda);
	void setDerecha(Jugador* derecha);

	void GenerarGrafica();
	string GetCuerpo();
};

