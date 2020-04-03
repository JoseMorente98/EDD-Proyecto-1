#include "Juego.h"
#include "Menu.h"
#include "Validador.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "LecturaJSON.h"
#include "Jugador.h"
#include "JugadorAB.h"
#include "DiccionarioLDC.h"
#include "FichaCola.h"
#include "TableroPuntuacionLS.h"
#include <time.h>
#include "ApartadoLD.cpp"
using namespace std;

/*
	SINGLETON
*/
JugadorAB* controladorJugador = JugadorAB::Instancia();
DiccionarioLDC* controladorDiccionario2 = DiccionarioLDC::Instancia();
FichaCola* controladorFicha = FichaCola::Instancia();
TableroPuntuacionLS* controladorTablero = TableroPuntuacionLS::Instancia();
ApartadoLD* controladorConfiguracion = ApartadoLD::Instancia();

/*
	PROPIEDADES
*/
Ficha* fichasJuego[25];
Menu menu;
LecturaJSON lectura;

Juego::Juego() 
{
	fichasJuego[0] = new Ficha("A", 1, 12);
	fichasJuego[1] = new Ficha("E", 1, 12);
	fichasJuego[2] = new Ficha("O", 1, 9);
	fichasJuego[3] = new Ficha("I", 1, 6);
	fichasJuego[4] = new Ficha("S", 1, 6);
	fichasJuego[5] = new Ficha("N", 1, 5);
	fichasJuego[6] = new Ficha("L", 1, 4);
	fichasJuego[7] = new Ficha("R", 1, 5);
	fichasJuego[8] = new Ficha("U", 1, 5);
	fichasJuego[9] = new Ficha("T", 1, 4);
	fichasJuego[10] = new Ficha("D", 2, 5);
	fichasJuego[11] = new Ficha("G", 2, 2);
	fichasJuego[12] = new Ficha("C", 3, 4);
	fichasJuego[13] = new Ficha("B", 3, 2);
	fichasJuego[14] = new Ficha("M", 3, 2);
	fichasJuego[15] = new Ficha("P", 3, 2);
	fichasJuego[16] = new Ficha("H", 4, 2);
	fichasJuego[17] = new Ficha("F", 4, 1);
	fichasJuego[18] = new Ficha("V", 4, 1);
	fichasJuego[19] = new Ficha("Y", 4, 1);
	fichasJuego[20] = new Ficha("Q", 5, 1);
	fichasJuego[21] = new Ficha("J", 8, 1);
	fichasJuego[22] = new Ficha("Ñ", 8, 1);
	fichasJuego[23] = new Ficha("X", 8, 1);
	fichasJuego[24] = new Ficha("Z", 10, 1);
}

void Juego::MenuPrincipal()
{	
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
				this->MenuJuego();
				break;
			case 3:
				this->MenuReporte();
				break;
			case 4:
				estado = false;
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

void Juego::MenuJuego()
{	
	bool estado = true;
	string textoEntrada;
	do {
		menu.MenuJuego();
		std::cout << ">> ";
		std::cin >> textoEntrada;
		Validador validador;
		if (validador.EsNumero(textoEntrada)) {
			int textoEntrada2 = stoi(textoEntrada);
			switch (textoEntrada2)
			{
			case 1:
				this->MenuJugador();
				MenuJuego();
				break;
			case 2:
				this->IniciarJuego();
				break;
			case 3:
				estado = false;
				this->MenuPrincipal();
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

void Juego::MenuJugador() {	
	bool estado = true;
	do
	{
		menu.MenuJugador();
		string nombre;
		cout << "Nombre Jugador\n";
		std::cout << ">> ";
		cin >> nombre;
		Jugador* jugador = controladorJugador->Buscar(nombre);

		if (jugador == NULL) {
			controladorJugador->Agregar(nombre);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << "Jugador agregado exitosamente :D\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			cout << "¿Quiere seguir agregando? (Y/N)" << endl;
			std::cout << ">> ";
			string entradaOpcion = "";
			cin >> entradaOpcion;
			if (entradaOpcion == "Y") {
				estado = true;
			}
			else if (entradaOpcion == "N") {
				estado = false;
			}
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "El jugador ya existe D:\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			system("pause");
			system("cls");
			estado = true;
		}
	} while (estado);
}

void Juego::MenuReporte()
{
	bool estado = true;
	string textoEntrada;
	menu.MenuReporte();
	do {
		std::cout << ">> ";
		std::cin >> textoEntrada;
		Validador validador;
		if (validador.EsNumero(textoEntrada)) {
			int textoEntrada2 = stoi(textoEntrada);
			switch (textoEntrada2)
			{
			case 1:
				if (!controladorDiccionario2->EsVacio()) {
					controladorDiccionario2->GenerarGrafico("Lista Doble Circular");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 2:
				if (!controladorFicha->EsVacio()) {
					controladorFicha->GenerarGrafico("Cola");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 3:
				if (controladorJugador->Longitud() != 0) {
					controladorJugador->GenerarGrafico("Arbol Binario");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 4:
				if (controladorJugador->Longitud() != 0) {
					controladorJugador->ReportePreOrden("Pre Orden");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 5:
				if (controladorJugador->Longitud() != 0) {
					controladorJugador->ReporteInOrden("In Orden");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 6:
				if (controladorJugador->Longitud() != 0) {
					controladorJugador->ReportePosOrden("Post Orden");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				estado = true;
				break;
			case 7:
				if (!controladorTablero->EsVacio()) {
					controladorTablero->GenerarGrafico("Lista Simple Ordenada");
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				break;
			case 8:
				if (!controladorTablero->EsVacio()) {
					this->ReportePunteoPorJugador();
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "La estructura se encuentra vacía D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
				}
				break;
			case 9:
				estado = false;
				this->MenuPrincipal();
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

void Juego::ReportePunteoPorJugador() {
	bool estado = true;
	do
	{
		string nombre;
		cout << "Buscar Jugador\n";
		std::cout << ">> ";
		cin >> nombre;
		TableroPuntuacion* jugador = controladorTablero->Buscar(nombre);

		if (jugador != NULL) {
			controladorTablero->GenerarGraficoPorJugador(nombre);
			estado = false;
			this->MenuReporte();
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Jugador no encontrado D:\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			system("pause");
			system("cls");
			estado = true;
		}
	} while (estado);
}

void Juego::CargaMasiva() {
	//srand(time(NULL));
	controladorFicha->Limpiar();
	bool estado = true;
	while (estado) {
		int aleatorio = rand() % 25;		
		if (fichasJuego[aleatorio]->getCantidad() == 0) {
			int contador = 0;
			for (size_t i = 0; i < 25; i++)
			{
				if (fichasJuego[i]->getCantidad() > 0) {
					contador++;
					cout << "CONTADOR : " << contador;
				}
			}
			if (contador == 0) {
				estado = false;
			}
		}
		if (fichasJuego[aleatorio]->getCantidad() > 0) {
			fichasJuego[aleatorio]->setCantidad(fichasJuego[aleatorio]->getCantidad() - 1);
			controladorFicha->Agregar(fichasJuego[aleatorio]->getLetra(), fichasJuego[aleatorio]->getPunteo(), 1);
			estado = true;
		}
	}
}

void Juego::IniciarJuego() {
	this->CargaMasiva();
	bool estado = true;
	menu.MenuNuevoJuego();
	do {
		//VALIDAR TAMAÑO DE TABLERO
		if (controladorConfiguracion->getMatriz() == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Configuración del juego no iniciado.\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			lectura.CargarArchivo();
		}
		//VALIDAR USUARIOS
		if (controladorConfiguracion->getMatriz() == 0) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Configuración del juego no iniciado.\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			lectura.CargarArchivo();
		}
	} while (estado);
}