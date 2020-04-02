#include "Menu.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Menu::MenuPrincipal()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "UNIVERSIDAD DE SAN CARLOS DE GUATEMALA\n";
	cout << "FACULTAD DE INGENIERIA\n";
	cout << "ESTRUCTURA DE DATOS A\n";
	cout << "PRACTICA NO. 1\n";
	cout << "JOSE RAFAEL MORENTE GONZALEZ\n";
	cout << "201801237\n";
	cout << "MENU PRINCIPAL\n";
	cout << "1. Lectura de Archivo\n";
	cout << "2. Juego\n";
	cout << "3. Reportes\n";
	cout << "4. Salir\n";
	cout << "__________________________________________________\n";
}

void Menu::MenuAbrir()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "__________________________________________________\n";
	cout << "CARGAR ARCHIVO\n";
	cout << "Ingrese la ruta del archivo: \n";
	cout << "__________________________________________________\n";
}