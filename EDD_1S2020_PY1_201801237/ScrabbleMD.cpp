#include "ScrabbleMD.h"

ScrabbleMD::ScrabbleMD() {
	root = new Scrabble("Y/X", 0, -1, -1, false, false);
	this->ultimoAbajo = root;
	this->ultimoDerecho = root;
}

Scrabble* ScrabbleMD::BuscarFila(int posicionY)
{
	Scrabble* scrabbleY = root;
	while (scrabbleY != NULL)
	{
		if (scrabbleY->getPosicionY() == posicionY)
		{
			return scrabbleY;
			break;
		}
		scrabbleY = scrabbleY->getAbajo();
	}
	return NULL;
}

Scrabble* ScrabbleMD::BuscarColumna(int posicionX)
{
	Scrabble* scrabbleX = root;

	while (scrabbleX != NULL)
	{
		if (scrabbleX->getPosicionX() == posicionX)
		{
			return scrabbleX;
			break;
		}
		scrabbleX = scrabbleX->getSiguiente();
	}
	return NULL;
}

Scrabble* ScrabbleMD::BuscarLetra(int posicionX, int posicionY)
{
	Scrabble* scrabbleX = root;
	Scrabble* scrabbleY = NULL;

	while (scrabbleX != NULL)
	{
		if (scrabbleX->getPosicionX() == posicionX)
		{
			scrabbleY = scrabbleX;
			break;
		}
		scrabbleX = scrabbleX->getSiguiente();
	}

	while (scrabbleY != NULL)
	{
		if (scrabbleY->getPosicionY() == posicionY)
		{
			return scrabbleY;
			break;
		}
		scrabbleY = scrabbleY->getAbajo();
	}

	return NULL;
}

Scrabble* ScrabbleMD::AgregarFila(Scrabble* scrabble, Scrabble* root)
{
	Scrabble* scrabbleTemp = root;
	Scrabble* scrabbleTemp2 = root;

	while (scrabble->getPosicionX() >= scrabbleTemp->getPosicionX() && scrabbleTemp->getSiguiente() != NULL) {
		scrabbleTemp2 = scrabbleTemp;
		scrabbleTemp = scrabbleTemp->getSiguiente();
	}
	if (scrabble->getPosicionX() >= scrabbleTemp->getPosicionX()) {
		scrabbleTemp->setSiguiente(scrabble);
		scrabble->setAnterior(scrabbleTemp);
	}
	else {
		scrabble->setSiguiente(scrabbleTemp);
		scrabbleTemp->setAnterior(scrabble);
		scrabbleTemp2->setSiguiente(scrabble);
		scrabble->setAnterior(scrabbleTemp2);
	}
	return scrabble;
}

Scrabble* ScrabbleMD::AgregarColumna(Scrabble* scrabble, Scrabble* root)
{
	Scrabble* scrabbleTemp = root;
	Scrabble* scrabbleTemp2 = root;

	while (scrabble->getPosicionY() >= scrabbleTemp->getPosicionY() && scrabbleTemp->getAbajo() != NULL) {
		scrabbleTemp2 = scrabbleTemp;
		scrabbleTemp = scrabbleTemp->getAbajo();
	}
	if (scrabble->getPosicionY() >= scrabbleTemp->getPosicionY()) {
		scrabbleTemp->setAbajo(scrabble);
		scrabble->setArriba(scrabbleTemp);
		scrabble->setAbajo(NULL);
	}
	else {
		scrabble->setAbajo(scrabbleTemp);
		scrabbleTemp->setArriba(scrabble);
		scrabbleTemp2->setAbajo(scrabble);
		scrabble->setArriba(scrabbleTemp2);
		scrabbleTemp2 = scrabble;
	}
	return scrabble;
}

Scrabble* ScrabbleMD::CrearFila(int posicionY)
{
	return nullptr;
}

Scrabble* ScrabbleMD::CrearColumna(int posicionX)
{
	return nullptr;
}

