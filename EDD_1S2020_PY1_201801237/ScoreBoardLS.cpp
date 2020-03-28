#include "ScoreBoardLS.h"

bool ScoreBoardLS::EsVacio() const
{
	return primero == NULL;
}

void ScoreBoardLS::Agregar(int puntos, string nombre)
{
    ScoreBoard* scoreBoard = new ScoreBoard(puntos, nombre);
    
    if (EsVacio()) {
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

void ScoreBoardLS::Imprimir()
{
    ScoreBoard* temp = primero;
    while (temp != NULL)
    {
        cout << temp->getNombre() << " - " << temp->getPuntos() << "\n";
        temp = temp->getSiguiente();
    }
}

void ScoreBoardLS::GenerarGrafico(string nombre)
{
	ScoreBoard* temp = primero;
	string graficoCabeza = "digraph ScoreBoard {rankdir=LR;"
		"node[shape = component];\n";
	string graficoNodo;
	string graficoMasNodo;
	string archivoTexto = "";
	int contador = 0;

	ofstream ofs("ScoreBoardLS.dot", ofstream::out);

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
	system("dot -Tjpg -o ScoreBoardLS.png ScoreBoardLS.dot");
	system("ScoreBoardLS.png");
}

void ScoreBoardLS::GenerarGrafico()
{
}
