#include "DiccionarioLDC.h"
DiccionarioLDC* DiccionarioLDC::instancia = NULL;

DiccionarioLDC::DiccionarioLDC()
{
	this->primero = NULL;
	this->ultimo = NULL;
}

DiccionarioLDC* DiccionarioLDC::Instancia()
{
	if (instancia == NULL)
	{
		instancia = new DiccionarioLDC();
	}
	return instancia;
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

void DiccionarioLDC::GenerarGrafico(string nombre)
{
	string graficoCabeza = "digraph DiccionarioListaDobleCircular {rankdir=LR\n";
	graficoCabeza += "\tnode[shape = note];\n";
	graficoCabeza += "\tgraph[label = \"" + nombre + "\", labelloc = t, fontsize = 20];\n";
	graficoCabeza += "\tnode[shape = note,fontcolor = white,style = filled,color = blue4];\n";

	string bodyGraphiz;
	string archivoTexto = "";
	int contador = 0;

	ofstream escrituraArchivo("DiccionarioLDC.dot", ofstream::out);

	Diccionario* temp = primero;
	do
	{
		bodyGraphiz += "\tObject" + to_string(contador) + " [label = " + '"' + temp->getPalabra() + '"' + "];\n";
		contador++;
		temp = temp->getSiguiente();
	} while (temp != primero);

	for (size_t i = 0; i < contador - 1; i++)
	{
		bodyGraphiz += "\tObject" + to_string(i) + "->Object" + to_string(i + 1) + ";\n";
		bodyGraphiz += "\tObject" + to_string(i+1) + "->Object" + to_string(i) + ";\n";
	}

	bodyGraphiz += "\tObject0->Object" + to_string(contador - 1) + ";\n";
	bodyGraphiz += "\tObject" + to_string(contador - 1) + "->Object0;";

	//GENERADOR DE GRAFICO
	archivoTexto = graficoCabeza + bodyGraphiz + "\n}";
	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o DiccionarioLDC.png DiccionarioLDC.dot");
	system("DiccionarioLDC.png");
}
