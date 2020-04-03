#pragma once
#include "Apartado.h"
#include <string>
class ApartadoLD
{
private:
	Apartado* primero;
	Apartado* ultimo;
	Apartado* primeroTriple;
	Apartado* ultimoTriple;
	int matriz = 0;
	static int longitudDoble;
	static int longitudTriple;
	static ApartadoLD* instancia;
public:
	ApartadoLD();
	static ApartadoLD* Instancia();
	void AgregarDoble(int posicionX, int posicionY, bool esDoble, bool esTriple);
	void AgregarTriple(int posicionX, int posicionY, bool esDoble, bool esTriple);
	bool ValidarDoble(int posicionX, int posicionY);
	bool ValidarTriple(int posicionX, int posicionY);
	int getMatriz() const;
	void setMatriz(int matriz);

};

