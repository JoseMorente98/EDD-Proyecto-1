#pragma once
class Apartado
{
protected:
	/*
	PROPIEDADES
	*/
	int posicionX;
	int posicionY;
	bool esDoble;
	bool esTriple;
	Apartado* siguiente;
	Apartado* anterior;
public:
	Apartado();
	Apartado(int posicionX, int posicionY, bool esDoble, bool esTriple);
	/*
	GETTER'S
	*/
	int getPosicionX() const;
	int getPosicionY() const;
	bool getEsDoble() const;
	bool getEsTriple() const;
	Apartado* getSiguiente() const;
	Apartado* getAnterior() const;
	/*
		SETTER'S
	*/
	void setPositionX(int posicionX);
	void setPositionY(int posicionY);
	void setEsDoble(bool esDoble);
	void setEsTriple(bool esTriple);
	void setSiguiente(Apartado* siguiente);
	void setAnterior(Apartado* anterior);
};

