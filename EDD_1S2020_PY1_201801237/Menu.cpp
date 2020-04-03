#include "Menu.h"
#include <iostream>
#include <windows.h>
#include "Jugador.h"

using namespace std;
// 6 y 13
void Menu::MenuPrincipal()
{
	system("cls");
	/*for (size_t i = 0; i < 15; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

		cout << "__________________________________________________\n";

	}*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA\n";
	cout << "FACULTAD DE INGENIERIA\n";
	cout << "ESTRUCTURA DE DATOS A\n";
	cout << "PRACTICA NO. 1\n";
	cout << "JOSE RAFAEL MORENTE GONZALEZ\n";
	cout << "201801237\n";
	cout << "__________________________________________________\n";
	cout << "MENU PRINCIPAL\n";
	cout << "1. Lectura de Archivo\n";
	cout << "2. Juego\n";
	cout << "3. Reportes\n";
	cout << "4. Salir\n";
	cout << "__________________________________________________\n";
}

void Menu::MenuJuego()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "CONFIGURACION DE JUEGO\n";
	cout << "__________________________________________________\n";
	cout << "1. Jugadores\n";
	cout << "2. Iniciar Juego\n";
	cout << "3. Menu Principal\n";
	cout << "__________________________________________________\n";
}

void Menu::MenuJugador()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "JUGADOR\n";
	cout << "__________________________________________________\n";
}

void Menu::MenuReporte()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "REPORTES\n";
	cout << "__________________________________________________\n";
	cout << "1. Lista Doble Circular - Diccionario\n";
	cout << "2. Cola - Fichas\n";
	cout << "3. Arbol Binario - Jugadores\n";
	cout << "4. Arbol Binario Pre Orden - Jugadores\n";
	cout << "5. Arbol Binario In Orden - Jugadores\n";
	cout << "6. Arbol Binario Post Orden - Jugadores\n";
	cout << "7. Lista Simple Ordenada- Tablero de Puntos\n";
	cout << "8. Lista Simple Ordenada- Puntos Por Jugador\n";
	cout << "9. Menu Principal\n";
	cout << "__________________________________________________\n";
}

void Menu::MenuAbrir()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "CARGAR ARCHIVO\n";
	cout << "__________________________________________________\n";
	cout << "Ingrese la ruta del archivo: \n";
}

void Menu::MenuNuevoJuego()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "SCRABBLE\n";
	cout << "__________________________________________________\n";
}