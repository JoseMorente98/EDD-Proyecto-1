#include "FichaJugadorLD.h"
#include <iostream>
#include <fstream>

int FichaJugadorLD::longitud = 0;

FichaJugadorLD::FichaJugadorLD() {
	this->primero = NULL;
	this->ultimo = NULL;
}

bool FichaJugadorLD::EsVacio() const
{
	return primero == NULL;
}

void FichaJugadorLD::Agregar(string letra, int punteo)
{
	FichaJugador* fichaJugador = new FichaJugador(letra, punteo);

	if (EsVacio()) {
		primero = fichaJugador;
		primero->setSiguiente(NULL);
		primero->setAnterior(NULL);
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(fichaJugador);
		fichaJugador->setSiguiente(NULL);
		fichaJugador->setAnterior(ultimo);
		ultimo = fichaJugador;
	}
	this->longitud++;
}

void FichaJugadorLD::Agregar(string letra, int punteo, int posicionX, int posicionY)
{
	FichaJugador* fichaJugador = new FichaJugador(letra, punteo, posicionX, posicionY);

	if (EsVacio()) {
		primero = fichaJugador;
		primero->setSiguiente(NULL);
		primero->setAnterior(NULL);
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(fichaJugador);
		fichaJugador->setSiguiente(NULL);
		fichaJugador->setAnterior(ultimo);
		ultimo = fichaJugador;
	}
	this->longitud++;
}

FichaJugador* FichaJugadorLD::Buscar(string letra)
{
	FichaJugador* temp;
	temp = primero;
	while (temp != NULL)
	{
		if (temp->getLetra() == letra) {
			return temp;
		}
		temp = temp->getSiguiente();
	}
	return NULL;
}

int FichaJugadorLD::Longitud()
{
	return this->longitud;
}

void FichaJugadorLD::Limpiar()
{
	this->primero = NULL;
}

void FichaJugadorLD::Mostrar()
{
	if (!EsVacio()) {
		FichaJugador* temp = primero;
		while (temp != NULL)
		{
			cout << temp->getLetra() << ", ";
			temp = temp->getSiguiente();
		}
		cout << "\n";
	}
	else {
		cout << "La cola se encuentra vac�a D:";
	}
}

void FichaJugadorLD::Eliminar(string letra)
{
	FichaJugador* temp = new FichaJugador();
	temp = primero;
	FichaJugador* anterior = new FichaJugador();
	anterior = NULL;
	bool encontrado = false;
	if (temp != NULL) {
		while (temp != NULL && encontrado != true) {
			if (temp->getLetra() == letra) {
				if (temp == primero) {
					primero = primero->getSiguiente();
					primero->setAnterior(NULL);
				}
				else if (temp == ultimo) {
					anterior->setSiguiente(NULL);
					ultimo = anterior;
				}
				else {
					anterior->setSiguiente(temp->getSiguiente());
					temp->getSiguiente()->setAnterior(anterior);
				}
				encontrado = true;
			}
			anterior = temp;
			temp = temp->getSiguiente();
		}
	}
	this->longitud--;
}

void FichaJugadorLD::GenerarGrafico(string nombre)
{
	string graficoCabeza = "digraph FichaJugadorLD {\n\trankdir=LR;";
	graficoCabeza += "node[shape = note, fontcolor = white, style = filled, color = deeppink4];\n";
	graficoCabeza += "graph[label = \""+nombre+"\", labelloc = t, fontsize = 20];\n";
	string bodyGraphiz;
	string archivoTexto = "";
	int contador = 0;
	
	ofstream escrituraArchivo("FichaJugadorLD.dot", ofstream::out);

	FichaJugador* temp = primero;

	while (temp != NULL)
	{
		bodyGraphiz += "\tObject" + to_string(contador) + " [label = " + '"' + temp->getLetra() + '"' + "];\n";
		temp = temp->getSiguiente();
		contador++;
	}

	for (size_t i = 0; i < contador - 1; i++)
	{
		bodyGraphiz += "\tObject" + to_string(i) + "->Object" + to_string(i + 1) + ";\nObject" + to_string(i + 1) + "->Object" + to_string(i) + ";\n";
	}
	archivoTexto = graficoCabeza + bodyGraphiz + "}";
	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o FichaJugadorLD.png FichaJugadorLD.dot");
	system("FichaJugadorLD.png");
}
