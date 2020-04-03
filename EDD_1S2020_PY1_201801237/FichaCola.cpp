#include "FichaCola.h"
FichaCola* FichaCola::instancia = NULL;

FichaCola::FichaCola() {
	this->primero = NULL;
	this->ultimo = NULL;
}

FichaCola* FichaCola::Instancia()
{
	if (instancia == NULL)
	{
		instancia = new FichaCola();
	}
	return instancia;
}

bool FichaCola::EsVacio() const
{
	return primero == NULL;
}

void FichaCola::Agregar(string letra, int punteo, int cantidad)
{
	Ficha* ficha = new Ficha(letra, punteo, cantidad);
	if (EsVacio())
	{
		primero = ficha;
	}
	else
	{
		ultimo->setSiguiente(ficha);
	}
	ultimo = ficha;
}

Ficha* FichaCola::Eliminar()
{
	if (!EsVacio()) {
		Ficha* temp = primero;
		Ficha* a = primero;
		primero = primero->getSiguiente();
		return temp;
	}
	else {
		throw "La cola se encuentra vac�a D:";
	}
}

Ficha* FichaCola::Peek() const
{
	if (EsVacio()) {
		throw "La cola se encuentra vac�a D:";
	}
	return primero;
}

void FichaCola::Imprimir()
{
	if (!EsVacio()) {
		Ficha* temp = primero;
		while (temp != NULL)
		{
			cout << temp->getLetra() << ",";
			temp = temp->getSiguiente();
		}
	}
	else {
		throw "La cola se encuentra vac�a D:";
	}
}

void FichaCola::Limpiar()
{
	while (!EsVacio())
	{
		Ficha* temp;
		temp = primero;
		primero = primero->getSiguiente();
		delete temp;
	}
	ultimo = NULL;
}

void FichaCola::GenerarGrafico(string nombre)
{
	string graficoCabeza = "digraph FichaCola {\n\trankdir=TB;";
	graficoCabeza += "\tnode[shape = note, fontcolor = white, style = filled, color = darkgreen];\n";
	graficoCabeza += "\tgraph[label = \"" +nombre+"\", labelloc = t, fontsize = 20];\n";
	string bodyGraphiz;
	string archivoTexto = "";
	int contador = 0;

	ofstream escrituraArchivo("FichaCola.dot", ofstream::out);

	Ficha* temp = primero;
	while (temp != NULL)
	{
		bodyGraphiz += "\tObject" + to_string(contador) + " [label = \"Caracter:" + temp->getLetra() + string("\\lPuntos:") + to_string(temp->getPunteo()) + "\"];\n";
		temp = temp->getSiguiente();
		contador++;
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		bodyGraphiz += "\tObject" + to_string(i) + "->Object" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + bodyGraphiz + "}";
	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o FichaCola.png FichaCola.dot");
	system("FichaCola.png");
}
