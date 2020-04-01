#include "ApartadoLD.h"

int ApartadoLD::longitudDoble = 0;
int ApartadoLD::longitudTriple = 0;

ApartadoLD::ApartadoLD()
{
}

void ApartadoLD::AgregarDoble(int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	Apartado* apartado = new Apartado(posicionX, posicionY, esDoble, esTriple);

	if (primero == NULL) {
		primero = apartado;
		primero->setSiguiente(NULL);
		primero->setAnterior(NULL);
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(apartado);
		apartado->setSiguiente(NULL);
		apartado->setAnterior(ultimo);
		ultimo = apartado;
	}
	this->longitudDoble++;
}

void ApartadoLD::AgregarTriple(int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	Apartado* apartado = new Apartado(posicionX, posicionY, esDoble, esTriple);

	if (primeroTriple == NULL) {
		primeroTriple = apartado;
		primeroTriple->setSiguiente(NULL);
		primeroTriple->setAnterior(NULL);
		ultimoTriple = primeroTriple;
	}
	else {
		ultimoTriple->setSiguiente(apartado);
		apartado->setSiguiente(NULL);
		apartado->setAnterior(ultimoTriple);
		ultimoTriple = apartado;
	}
	this->longitudTriple++;
}

bool ApartadoLD::ValidarDoble(int posicionX, int posicionY)
{
	Apartado* temp;
	temp = primero;
	while (temp != NULL)
	{
		if (temp->getPosicionX() == posicionX && temp->getPosicionY() == posicionY) {
			return true;
		}
		temp = temp->getSiguiente();
	}
	return false;
}

bool ApartadoLD::ValidarTriple(int posicionX, int posicionY)
{
	Apartado* temp;
	temp = primeroTriple;
	while (temp != NULL)
	{
		if (temp->getPosicionX() == posicionX && temp->getPosicionY() == posicionY) {
			return true;
		}
		temp = temp->getSiguiente();
	}
	return false;
}
