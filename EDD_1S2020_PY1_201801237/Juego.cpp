#include "Juego.h"
#include "Menu.h"
#include "Validador.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "LecturaJSON.h"
using namespace std;

LecturaJSON lectura;

void Juego::MenuPrincipal()
{
	Menu menu;
	menu.MenuPrincipal();
	bool estado = true;
	string textoEntrada;
	do {
		std::cout << ">> ";
		std::cin >> textoEntrada;
		Validador validador;
		if (validador.EsNumero(textoEntrada)) {
			int textoEntrada2 = stoi(textoEntrada);
			switch (textoEntrada2)
			{
			case 1:
				lectura.CargarArchivo();
				this->MenuPrincipal();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "Usted ha ingresado una opción incorrecta.\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				estado = true;
				textoEntrada;
				break;
			}
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Solamente puede ingresar digitos.\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			estado = true;
			textoEntrada;
		}
	} while (estado);
}
