#pragma once
#include <string>
using namespace std;

class Scrabble
{
protected:
	string dato;
	bool esDoble;
	bool esTriple;
	int puntos;
	int posicionX;
	int posicionY;
	int indice;
	static int contador;
	Scrabble* siguiente;
	Scrabble* anterior;
	Scrabble* arriba;
	Scrabble* abajo;
public:
	Scrabble();
	Scrabble(string dato, int posicionX, int posicionY, bool esDoble, bool esTriple);
	Scrabble(string dato, int puntos, int posicionX, int posicionY, bool esDoble, bool esTriple);
	/*
	GETTER'S
	*/
	int getIndice() const;
	string getDato() const;
	bool getEsDoble() const;
	bool getEsTriple() const;
	int getPosicionX() const;
	int getPosicionY() const;
	int getPuntos() const;
	Scrabble* getSiguiente() const;
	Scrabble* getAnterior() const;
	Scrabble* getArriba() const;
	Scrabble* getAbajo() const;
	/*
		SETTER'S
	*/
	void setIndice(int indice);
	void setDato(string dato);
	void setEsDoble(bool esDoble);
	void setEsTriple(bool esTriple);
	void setPositionX(int posicionX);
	void setPositionY(int posicionY);
	void setPuntos(int puntos);
	void setSiguiente(Scrabble* siguiente);
	void setAnterior(Scrabble* anterior);
	void setArriba(Scrabble* arriba);
	void setAbajo(Scrabble* abajo);
};

