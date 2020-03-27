#include "DiccionarioLDC.h"

DiccionarioLDC::DiccionarioLDC()
{
	this->primero = NULL;
	this->ultimo = NULL;
}

bool DiccionarioLDC::EsVacio() const
{
	return primero == NULL;
}

void DiccionarioLDC::Agregar(string palabra)
{
	Diccionario* diccionario;
	diccionario = new Diccionario(palabra);
	if (EsVacio()) {
		primero = diccionario;
		primero->setSiguiente(NULL);
		primero->setAnterior(NULL);
		primero->setSiguiente(primero);
		ultimo = primero;
	}
	else {
		ultimo->setSiguiente(diccionario);
		diccionario->setSiguiente(primero);
		diccionario->setAnterior(ultimo);
		ultimo = diccionario;
	}
}

void DiccionarioLDC::GenerarGrafico()
{
	Diccionario* aux = primero;

	string graficoCabeza = "digraph DiccionarioListaDobleCircular {rankdir=LR\n"
		"node[shape = component];\n";
	string graficoNodo;
	string graficoMasNodo;
	string archivoTexto = "";
	int contador = 0;

	ofstream ofs("DiccionarioLDC.dot", ofstream::out);

	do
	{
		graficoNodo = graficoNodo + "Nodo" + to_string(contador) + " [label = " + '"' + aux->getPalabra() + '"' + "];\n";
		contador++;
		aux = aux->getSiguiente();
	} while (aux != primero);

	for (size_t i = 0; i < contador - 1; i++)
	{
		graficoMasNodo = graficoMasNodo + "Nodo" + to_string(i) + "->Nodo" + to_string(i + 1) + "[dir=both];\n";
	}

	archivoTexto = graficoCabeza + graficoNodo + graficoMasNodo + "Nodo0->Nodo" + to_string(contador - 1) + "[dir=both]\n" + "}";
	ofs << archivoTexto;

	ofs.close();
	system("dot -Tjpg -o DiccionarioLDC.png DiccionarioLDC.dot");
	system("DiccionarioLDC.png");
}
