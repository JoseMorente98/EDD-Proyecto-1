#include "JugadorAB.h"
#include <iostream>

JugadorAB::JugadorAB()
{
	this->root = NULL;
}

void JugadorAB::Agregar(string nombre)
{
	root = Agregar(nombre, root);
	this->longitud++;
}

Jugador* JugadorAB::Agregar(string nombre, Jugador* raiz)
{
	if (raiz == NULL) {
		raiz = new Jugador(nombre.length(), nombre);
	}
	else {
		char* str1 = new char[nombre.length() + 1];
		memcpy(str1, nombre.c_str(), nombre.length() + 1);

		char* str2 = new char[raiz->getLongitud() + 1];
		memcpy(str2, raiz->getNombre().c_str(), raiz->getNombre().length() + 1);

		if (strcmp(str1, str2) < 0)
		{
			Jugador* jugadorIzquierda;
			jugadorIzquierda = Agregar(nombre, raiz->getIzquierda());
			raiz->setIzquierda(jugadorIzquierda);
		}
		else if (strcmp(str1, str2) >= 0) {
			Jugador* jugadorDerecha;
			jugadorDerecha = Agregar(nombre, raiz->getDerecha());
			raiz->setDerecha(jugadorDerecha);
		}
	}
	return raiz;
}

Jugador* JugadorAB::Buscar(string nombre)
{
	return Buscar(nombre, root);
}

Jugador* JugadorAB::Buscar(string nombre, Jugador* raiz)
{
	if (raiz != NULL) {
		char* str1 = new char[nombre.length() + 1];
		memcpy(str1, nombre.c_str(), nombre.length() + 1);

		char* str2 = new char[raiz->getNombre().length() + 1];
		memcpy(str2, raiz->getNombre().c_str(), raiz->getNombre().length() + 1);

		if (nombre == raiz->getNombre()) {
			return raiz;
		} 
		else if (strcmp(str1, str2) < 0) {
			return Buscar(nombre, raiz->getIzquierda());
		}
		else {
			return Buscar(nombre, raiz->getDerecha());
		}
	}
	return NULL;
}

int JugadorAB::Longitud()
{
	return this->longitud;
}

string JugadorAB::InOrden(Jugador* jugador, string bodyGraphiz)
{
	if (jugador != NULL) {
		bodyGraphiz = InOrden(jugador->getIzquierda(), bodyGraphiz);
		bodyGraphiz += "Object" + to_string(jugador->getIdJugador()) + "[label = \" " + jugador->getNombre() + "\"];\n";
		cout << jugador->getNombre() << endl;
		bodyGraphiz = InOrden(jugador->getDerecha(), bodyGraphiz);
	}
	return bodyGraphiz;
}

string JugadorAB::PreOrden(Jugador* jugador, string bodyGraphiz)
{
	if (jugador != NULL) {
		bodyGraphiz += "Object" + to_string(jugador->getIdJugador()) + "[label = \" " + jugador->getNombre() + "\"];\n";
		cout << jugador->getNombre() << endl;
		bodyGraphiz = PreOrden(jugador->getIzquierda(), bodyGraphiz);
		bodyGraphiz = PreOrden(jugador->getDerecha(), bodyGraphiz);
	}
	return bodyGraphiz;
}

string JugadorAB::PosOrden(Jugador* jugador, string bodyGraphiz)
{
	if (jugador != NULL) {
		bodyGraphiz = PosOrden(jugador->getIzquierda(), bodyGraphiz);
		bodyGraphiz = PosOrden(jugador->getDerecha(), bodyGraphiz);
		bodyGraphiz += "Object" + to_string(jugador->getIdJugador()) + "[label = \" " + jugador->getNombre() + "\"];\n";
		cout << jugador->getNombre() << endl;
	}
	return bodyGraphiz;
}

Jugador* JugadorAB::GetRaiz()
{
	return this->root;
}

void JugadorAB::GenerarGrafico(string nombre)
{
	string archivoCabeza = "digraph ArbolBinario {\n";
	archivoCabeza += "\trankdir=TB;\n";
	archivoCabeza += "\tnode[shape = ellipse, fontcolor = black, style = filled, color = gainsboro];\n";
	archivoCabeza += "\tgraph[label = \"" +nombre+"\", labelloc = t, fontsize = 20];\n";

	ofstream escrituraArchivo("ArbolBinarioBusqueda.dot", ofstream::out);

	string archivoTexto = "";

	archivoTexto = archivoCabeza + this->root->GetCuerpo() + "}";

	escrituraArchivo << archivoTexto;
	escrituraArchivo.close();
	system("dot -Tjpg -o ArbolBinarioBusqueda.png ArbolBinarioBusqueda.dot");
	system("ArbolBinarioBusqueda.png");
}

void JugadorAB::ReporteInOrden(string nombre)
{
	string archivoCabeza = "digraph ArbolBinario {\n";
	archivoCabeza += "\trankdir=TB;\n"; 
	archivoCabeza += "\tnode[shape = note, fontcolor = black, style = filled, color = lightskyblue];\n";
	archivoCabeza += "\tgraph[label = \"" + nombre + "\", labelloc = t, fontsize = 20];\n";

	ofstream escrituraArchivo("InOrden.dot", ofstream::out);

	string archivoTexto = "";

	archivoTexto = archivoCabeza + this->InOrden(this->root, "") + "}";

	escrituraArchivo << archivoTexto;
	escrituraArchivo.close();
	system("dot -Tjpg -o InOrden.png InOrden.dot");
	system("InOrden.png");
}

void JugadorAB::ReportePreOrden(string nombre)
{
	string archivoCabeza = "digraph ArbolBinario {\n";
	archivoCabeza += "\trankdir=TB;\n";
	archivoCabeza += "\tnode[shape = note, fontcolor = black, style = filled, color = lavenderblush];\n";
	archivoCabeza += "\tgraph[label = \"" + nombre + "\", labelloc = t, fontsize = 20];\n";

	ofstream escrituraArchivo("PreOrden.dot", ofstream::out);

	string archivoTexto = "";

	archivoTexto = archivoCabeza + this->PreOrden(this->root, "") + "}";

	escrituraArchivo << archivoTexto;
	escrituraArchivo.close();
	system("dot -Tjpg -o PreOrden.png PreOrden.dot");
	system("PreOrden.png");
}

void JugadorAB::ReportePosOrden(string nombre)
{
	string archivoCabeza = "digraph ArbolBinario {\n";
	archivoCabeza += "\trankdir=TB;\n";
	archivoCabeza += "\tnode[shape = note, fontcolor = black, style = filled, color = navajowhite];\n";
	archivoCabeza += "\tgraph[label = \"" + nombre + "\", labelloc = t, fontsize = 20];\n";

	ofstream escrituraArchivo("PosOrden.dot", ofstream::out);

	string archivoTexto = "";

	archivoTexto = archivoCabeza + this->PosOrden(this->root, "") + "}";

	escrituraArchivo << archivoTexto;
	escrituraArchivo.close();
	system("dot -Tjpg -o PosOrden.png PosOrden.dot");
	system("PosOrden.png");
}