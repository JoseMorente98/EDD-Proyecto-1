#include "ScoreBoardLS.h"
#include <fstream>

void ScoreBoardLS::Agregar(int puntos, string nombre)
{
    ScoreBoard* scoreBoard = new ScoreBoard(puntos, nombre);
    
    if (primero == NULL) {
        primero = scoreBoard;
    }
    else {
        if (puntos < primero->getPuntos()) {
            scoreBoard->setSiguiente(primero);
            primero = scoreBoard;
        }
        else {
            ScoreBoard* temporal = primero;
            ScoreBoard* anterior = primero;

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

void ScoreBoardLS::GenerarGrafico(string nombre)
{
	ScoreBoard* aux = primero;
	string graficoCabeza = "digraph ScoreBoard {rankdir=LR;"
		"node[shape = box];\n";
	ofstream ofs("ScoreBoardLS.dot", ofstream::out);
	string graficoNodo;
	string graficoMasNodo;
	string archivoTexto = "";
	int contador = 0;

	while (aux != NULL)
	{
		if (nombre != "")
		{
			if (aux->getNombre() == nombre)
			{
				graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + aux->getNombre() + string("\\l") + to_string(aux->getPuntos()) + '"' + "];\n";
				contador++;
			}
		}
		else {
			graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + aux->getNombre() + string("\\l") + to_string(aux->getPuntos()) + '"' + "];\n";
			contador++;
		}
		aux = aux->getSiguiente();
	}

	for (size_t i = contador - 1; i > 0; i--)
	{
		graficoMasNodo = graficoMasNodo + "Nodo" + to_string(i) + "->Nodo" + to_string(i - 1) + ";\n";
	}

	archivoTexto = graficoCabeza + graficoNodo + graficoMasNodo + "}";
	ofs << archivoTexto;

	ofs.close();
	system("dot -Tjpg -o ScoreBoardLS.png ScoreBoardLS.dot");
	system("ScoreBoardLS.png");
}

void ScoreBoardLS::GenerarGrafico()
{
}
