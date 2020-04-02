#include "TableroPuntuacionLS.h"

TableroPuntuacionLS::TableroPuntuacionLS()
{
	this->primero = NULL;
}

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
	string graficoCabeza = "digraph TableroPuntuacion {\n";
	graficoCabeza += " rankdir = LR; ";
	graficoCabeza += "node[shape = tab, fontcolor = black, style = filled, color = lightskyblue];";
	graficoCabeza += "graph[label = \""+nombre+"\", labelloc = t, fontsize = 20];";
	string bodyGraphiz;
	string archivoTexto = "";
	int contador = 0;

	ofstream escrituraArchivo("TableroPuntuacionLS.dot", ofstream::out);

	while (temp != NULL)
	{
		bodyGraphiz += "Object" + to_string(contador) + " [label = " + '"' + temp->getNombre() + string("\\lPuntos: ") + to_string(temp->getPuntos()) + '"' + "];\n";
		contador++;
		temp = temp->getSiguiente();
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		bodyGraphiz +=  "Object" + to_string(i) + "->Object" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + bodyGraphiz + "}";
	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o TableroPuntuacionLS.png TableroPuntuacionLS.dot");
	system("TableroPuntuacionLS.png");
}

void TableroPuntuacionLS::GenerarGraficoPorJugador(string nombre)
{
	TableroPuntuacion* temp = primero;
	string graficoCabeza = "digraph TableroPuntuacion {\n";
	graficoCabeza += " rankdir = LR; ";
	graficoCabeza += "node[shape = star, fontcolor = black, style = filled, color = gold];";
	graficoCabeza += "graph[label = \"Lista Simple Ordenada " + nombre + "\", labelloc = t, fontsize = 20];";
	string bodyGraphiz;
	string archivoTexto = "";
	int contador = 0;

	ofstream escrituraArchivo("TableroPuntuacionJugadorLS.dot", ofstream::out);

	while (temp != NULL)
	{
		if (temp->getNombre() == nombre)
		{
			bodyGraphiz += "Object" + to_string(contador) + " [label = " + '"' + to_string(temp->getPuntos()) + '"' + "];\n";
			contador++;
		}
		temp = temp->getSiguiente();
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		bodyGraphiz += "Object" + to_string(i) + "->Object" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + bodyGraphiz + "}";
	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o TableroPuntuacionJugadorLS.png TableroPuntuacionJugadorLS.dot");
	system("TableroPuntuacionJugadorLS.png");
}
