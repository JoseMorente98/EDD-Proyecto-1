#pragma once
#include <string>
using namespace std;

class FichaJugador
{
protected:
    /*
        PROPIEDADES
    */
    string letra;
    int punteo;
    int posicionX;
    int posicionY;
    FichaJugador* siguiente;
    FichaJugador* anterior;
public:
	FichaJugador();
	FichaJugador(string letra, int punteo, int posicionX, int posicionY);
	/*
		GETTER'S
	*/
	string getLetra() const;
	int getPunteo() const;
	int getPosicionX() const;
	int getPosicionY() const;
	FichaJugador* getSiguiente() const;
	FichaJugador* getAnterior() const;
	/*
		SETTER'S
	*/
	void setLetra(string letra);
	void setPunteo(int punteo);
	void setPosicionX(int posicionX);
	void setPosicionY(int posicionY);
	void setSiguiente(FichaJugador* siguiente);
	void setAnterior(FichaJugador* anterior);
};

