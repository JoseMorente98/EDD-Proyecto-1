#include "TableroPuntuacionLS.h"

bool TableroPuntuacionLS::EsVacio() const
{
	return primero == NULL;
}

void TableroPuntuacionLS::Agregar(int puntos, string nombre)
{
	TableroPuntuacion* scoreBoard = new TableroPuntuacion(puntos, nombre);

	if (EsVacio()) {
		primero = scoreBoard;
	}
	else {
		if (puntos < primero->getPuntos()) {
			scoreBoard->setSiguiente(primero);
			primero = scoreBoard;
		}
		else {
			TableroPuntuacion* temporal = primero;
			TableroPuntuacion* anterior = primero;

			while (puntos >= temporal->getPuntos() && temporal->getSiguiente() != NULL) {
				anterior = temporal;
				temporal = temporal->getSiguiente();
			}
			if (puntos >= temporal->getPuntos()) {
				temporal->setSiguiente(scoreBoard);
			}
			else {
				scoreBoard->setSiguiente(temporal);
				anterior->setSiguiente(scoreBoard);
			}
		}
	}
}

void TableroPuntuacionLS::Imprimir()
{
	TableroPuntuacion* temp = primero;
	while (temp != NULL)
	{
		cout << temp->getNombre() << " - " << temp->getPuntos() << "\n";
		temp = temp->getSiguiente();
	}
}

void TableroPuntuacionLS::GenerarGrafico(string nombre)
{
	TableroPuntuacion* temp = primero;
	string graficoCabeza = "digraph TableroPuntuacion {rankdir=LR;"
		"node[shape = component];\n";
	string graficoNodo;
	string graficoMasNodo;
	string archivoTexto = "";
	int contador = 0;

	ofstream ofs("TableroPuntuacionLS.dot", ofstream::out);

	while (temp != NULL)
	{
		if (nombre != "")
		{
			if (temp->getNombre() == nombre)
			{
				graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + temp->getNombre() + string("\\l") + to_string(temp->getPuntos()) + '"' + "];\n";
				contador++;
			}
		}
		else {
			graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + temp->getNombre() + string("\\l") + to_string(temp->getPuntos()) + '"' + "];\n";
			contador++;
		}
		temp = temp->getSiguiente();
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		graficoMasNodo = graficoMasNodo + "Nodo" + to_string(i) + "->Nodo" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + graficoNodo + graficoMasNodo + "}";
	ofs << archivoTexto;

	ofs.close();
	system("dot -Tjpg -o TableroPuntuacionLS.png TableroPuntuacionLS.dot");
	system("TableroPuntuacionLS.png");
}

void TableroPuntuacionLS::GenerarGrafico()
{
}
