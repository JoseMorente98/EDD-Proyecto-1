#include "JugadorAB.h"
#include <iostream>

void JugadorAB::Agregar(string nombre)
{
	Agregar(nombre, root);
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

void JugadorAB::InOrden(Jugador* jugador)
{
	if (jugador != NULL) {
		InOrden(jugador->getIzquierda());
		cout << jugador->getNombre() << ", ";
		InOrden(jugador->getDerecha());
	}

}

void JugadorAB::PreOrden(Jugador* jugador)
{
	if (jugador != NULL) {
		cout << jugador->getNombre() << ", ";
		PreOrden(jugador->getIzquierda());
		PreOrden(jugador->getDerecha());
	}

}

void JugadorAB::PosOrden(Jugador* jugador)
{
	if (jugador != NULL) {
		PosOrden(jugador->getIzquierda());
		PosOrden(jugador->getDerecha());
		cout << jugador->getNombre() << ", ";
	}
}

Jugador* JugadorAB::GetRaiz()
{
	return this->root;
}

void JugadorAB::GenerarGrafico(string nombre)
{
	this->root->GenerarGrafica();
}
