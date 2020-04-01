#include "FichaCola.h"

FichaCola::FichaCola() {
	this->primero = NULL;
	this->ultimo = NULL;
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
		throw "La cola se encuentra vacía D:";
	}
}

Ficha* FichaCola::Peek() const
{
	if (EsVacio()) {
		throw "La cola se encuentra vacía D:";
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
		throw "La cola se encuentra vacía D:";
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

void FichaCola::GenerarGrafico()
{
	Ficha* temp = primero;
	string graficoCabeza = "digraph FichaCola {rankdir=LR;"
		"node[shape = component];\n";
	string graficoNodo;
	string graficoMasNodo;
	string archivoTexto = "";
	int contador = 0;

	ofstream ofs("FichaCola.dot", ofstream::out);

	while (temp != NULL)
	{
		if (temp->getLetra() == "Ñ") {
			graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + "Letter: Ñ" + string("\\lPoints:") + to_string(temp->getPunteo()) + string("\\lCant:") + to_string(temp->getCantidad()) + '"' + "];\n";
		}
		else {
			graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + "Letter:" + temp->getLetra() + string("\\lPoints:") + to_string(temp->getPunteo()) + string("\\lCant:") + to_string(temp->getCantidad()) + '"' + "];\n";
		}

		temp = temp->getSiguiente();
		contador++;
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		graficoMasNodo = graficoMasNodo + "Nodo" + to_string(i) + "->Nodo" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + graficoNodo + graficoMasNodo + "}";
	ofs << archivoTexto;

	ofs.close();
	system("dot -Tjpg -o FichaCola.png FichaCola.dot");
	system("FichaCola.png");
}
