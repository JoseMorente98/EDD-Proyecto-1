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
#include "ApartadoLD.h"
#include "FichaJugadorLD.h"
#include "ScrabbleMD.h"
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
ScrabbleMD scrabble;
int posicionInicialX = 0;
int posicionInicialY = 0;
int posicionFinalX = 0;
int posicionFinalY = 0;

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

	srand(time(NULL));
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
	//PROPIEDADES DEL JUEGO
	Jugador* jugador1 = NULL;
	Jugador* jugador2 = NULL;
	FichaJugadorLD fichaJugador1;
	FichaJugadorLD fichaJugadorAux1;
	FichaJugadorLD fichaJugador2;
	FichaJugadorLD fichaJugadorAux2;
	int ptsJugador1 = 0;
	int ptsJugador2 = 0;

	this->CargaMasiva();
	bool estado = true;
	menu.MenuNuevoJuego();
	do {
#pragma region INICIO DE JUEGO
		//VALIDAR TAMAÑO DE TABLERO
		if (controladorConfiguracion->getMatriz() == 0) {
			lectura.CargarArchivo();
		}
		//VALIDAR USUARIOS
		if (controladorJugador->Longitud() < 2) {
			this->MenuJugador();
		} else {
			controladorJugador->ImprimirInOrden();
			//VALIDACION JUGADOR 1
			bool estadoJugador1 = true;
			do
			{
				string nombre;
				cout << "Buscar Jugador 1: \n";
				std::cout << ">> ";
				cin >> nombre;
				Jugador* jugador = controladorJugador->Buscar(nombre);

				if (jugador != NULL) {
					jugador1 = jugador;
					//CARGA DE FICHAS
					/*for (size_t i = 0; i < 7; i++)
					{
						Ficha *ficha = controladorFicha->Eliminar();
						fichaJugador1.Agregar(ficha->getLetra(), ficha->getPunteo());
					}*/
					fichaJugador1.Agregar("H", 1);
					fichaJugador1.Agregar("O", 1);
					fichaJugador1.Agregar("L", 1);
					fichaJugador1.Agregar("A", 1);
					fichaJugador1.Agregar("M", 1);
					fichaJugador1.Agregar("S", 1);
					fichaJugador1.Agregar("S", 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "__________________________________________________\n";
					cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
					fichaJugador1.Mostrar();
					cout << "__________________________________________________\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					estadoJugador1 = false;
					estado = false;
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "Jugador no encontrado D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					system("pause");
					estadoJugador1 = true;
				}
			} while (estadoJugador1);

			//VALIDACION JUGADOR 1
			bool estadoJugador2 = true;
			do
			{
				string nombre;
				cout << "Buscar Jugador 2: \n";
				std::cout << ">> ";
				cin >> nombre;
				Jugador* jugador = controladorJugador->Buscar(nombre);

				if (jugador != NULL) {
					if (jugador1->getNombre() != jugador->getNombre()) {
						jugador2 = jugador;						
						//CARGA DE FICHAS
						for (size_t i = 0; i < 7; i++)
						{
							Ficha* ficha = controladorFicha->Eliminar();
							fichaJugador2.Agregar(ficha->getLetra(), ficha->getPunteo());
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
						cout << "__________________________________________________\n";
						cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
						fichaJugador2.Mostrar();
						cout << "__________________________________________________\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						estadoJugador2 = false;
						estado = false;
					}
					else {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						cout << "No puedes jugar contra ti mismo D:\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						system("pause");
						estadoJugador2 = true;
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "Jugador no encontrado D:\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					system("pause");
					estadoJugador2 = true;
				}
			} while (estadoJugador2);
		}
	} while (estado);
#pragma endregion

	system("pause");
	bool estadoPartida = true;
	srand(time(NULL));
	//int ronda = rand() % 2 + 1;
	int ronda = 1;
	int contador = 0;
	do {
		if (ronda == 1) {
			contador = 0;
			bool estadoRonda1 = true;
			string opcionRonda;
			do {
#pragma region JUGADOR 1
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "__________________________________________________\n";
				cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
				fichaJugador1.Mostrar();
				cout << "__________________________________________________\n";
				cout << "¿Que deseas hacer?\n";
				cout << "1. Colocar Fichas\n";
				cout << "2. Intercambiar Fichas\n";
				cout << "3. Reporte Fichas\n";
				cout << "4. Finalizar Juego\n";
				cout << "__________________________________________________\n";
				std::cout << ">> ";
				std::cin >> opcionRonda;
				Validador validador;
				if (validador.EsNumero(opcionRonda)) {
					int opcionRonda2 = stoi(opcionRonda);
					bool estadoLetra = true;
					bool estadoIntercambio = true;
					bool estadoFinalizar = true;
					string opcionFinalizar;

					switch(opcionRonda2)
					{
					case 1:
#pragma region COLOCAR FICHAS JUGADOR 1
						//JUGAR
						while (estadoLetra) {
							system("cls");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
							cout << "__________________________________________________\n";
							cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
							fichaJugador1.Mostrar();
							cout << "__________________________________________________\n";
							//VALIDAR LETRA ENCONTRADA
							string letra;
							int posicionX;
							int posicionY;
							bool busquedaLetra = true;
							FichaJugador* ficha = NULL;
							do
							{
								cout << "Escriba una letra: \n";
								std::cout << ">> ";
								cin >> letra;
								ficha = fichaJugador1.Buscar(letra);

								if (ficha == NULL) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Letra no encontrada D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
									system("pause");
									busquedaLetra = true;
								}
								else {
									busquedaLetra = false;
								}
							} while (busquedaLetra);
							//VALIDAR POSICIONES Y OCUPACIONES
							bool validarLetra = true;
							do {
								cout << "Coordenada X: \n";
								std::cout << ">> ";
								cin >> posicionX;
								cout << "Coordenada Y: \n";
								std::cout << ">> ";
								cin >> posicionY;
								int longitud = controladorConfiguracion->getMatriz();
								if (posicionX >= longitud || posicionY >= longitud) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "La posición excede el limite D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);	
									system("pause");
								}
								else {
									if (scrabble.BuscarLetra(posicionX, posicionY) != NULL) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "No puedes colocar una letra acá D:\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
										system("pause");
										estadoLetra = false;
									}
									else {
										validarLetra = false;
										//OBTENER LAS PRIMERAS POSICIONES 
										contador++;
										if (contador == 1) {
											posicionInicialX = posicionX;
											posicionInicialY = posicionY;
										}
										fichaJugador1.Eliminar(ficha->getLetra());
										fichaJugadorAux1.Agregar(ficha->getLetra(), ficha->getPunteo(), posicionX, posicionY);
										scrabble.Agregar(ficha->getLetra(), ficha->getPunteo(), posicionX, posicionY, false, false);
										scrabble.GenerarGrafico("Scrabble");
									}
								}
							} while (validarLetra);
							//OTRAS OPCIONES
							cout << "__________________________________________________\n";
							cout << "¿Que deseas hacer?\n";
							cout << "1. Continuar\n";
							cout << "2. Validar\n";
							cout << "__________________________________________________\n";
							bool estadoContinuar = true;
							string opcionContinuar;
							do {
								std::cout << ">> ";
								std::cin >> opcionContinuar;
								Validador validador;
								int validacion;
								if (validador.EsNumero(opcionContinuar)) {
									int opcionContinuar2 = stoi(opcionContinuar);
									switch (opcionContinuar2) {
									case 1:
										estadoLetra = true;
										estadoContinuar = false;
										break;
									case 2:
										posicionFinalX = posicionX;
										posicionFinalY = posicionY;
										//VALIDAR
										validacion = ValidacionMatriz(6);
										if (validacion == 0) {
											//REVERTIR MOVIMIENTO DE PARTIDA
											while (fichaJugadorAux1.getPrimero() != NULL)
											{
												FichaJugador *fichaTemp = fichaJugadorAux1.getPrimero();
												scrabble.Eliminar(fichaTemp->getPosicionX(), fichaTemp->getPosicionY());
												fichaJugador1.Agregar(fichaTemp->getLetra(), ficha->getPunteo());
												fichaJugador1.setPrimero(fichaJugador1.getPrimero()->getSiguiente());
											}
										}
										else {
											//SUMAR
											int longi = fichaJugador1.Longitud();
											if (longi <= 7) {
												int nuevaLongitud = 7 - fichaJugador1.Longitud();
												for (size_t i = 0; i < nuevaLongitud; i++)
												{
													Ficha* ficha = controladorFicha->Eliminar();
													fichaJugador1.Agregar(ficha->getLetra(), ficha->getPunteo());
												}
											}
											ptsJugador1 += validacion;
										}
										estadoLetra = false;
										estadoContinuar = false;
										estadoRonda1 = false;
										cout << "__________________________________________________\n";
										cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
										cout << "__________________________________________________\n";
										system("pause");
										break;
									default:
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "Usted ha ingresado una opción incorrecta.\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
										estadoContinuar = true;
										opcionContinuar;
										break;
									}
								} else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Solamente puede ingresar digitos.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
									estadoContinuar = true;
									opcionContinuar;
								}
							} while (estadoContinuar);
						}
#pragma endregion
						break;
					case 2:
#pragma region INTERCAMBIO DE PALABRAS JUGADOR 1
						while (estadoIntercambio) {
							system("cls");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
							cout << "__________________________________________________\n";
							cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
							fichaJugador1.Mostrar();
							cout << "__________________________________________________\n";
							string letra;
							bool busquedaLetra = true;
							FichaJugador* ficha = NULL;
							//VALIDACION DE BUSQUEDA
							do
							{
								cout << "Escriba una letra: \n";
								std::cout << ">> ";
								cin >> letra;
								ficha = fichaJugador1.Buscar(letra);

								if (ficha == NULL) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Letra no encontrada D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
									system("pause");
									busquedaLetra = true;
								}
								else {
									busquedaLetra = false;
								}
							} while (busquedaLetra);
							//INTERCAMBIO DE PALABRA
							if (!controladorFicha->EsVacio()) {
								controladorFicha->Agregar(ficha->getLetra(), ficha->getPunteo(), 1);
								fichaJugador1.Eliminar(letra);
								Ficha* ficha = controladorFicha->Eliminar();
								fichaJugador1.Agregar(ficha->getLetra(), ficha->getPunteo());
								cout << "Se cambiol la letra: " << letra << " por: " << ficha->getLetra() << "\n";
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
								cout << "La cola ya se encuentra vacía D:\n";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
							}
							cout << "__________________________________________________\n";
							cout << "¿Que deseas hacer?\n";
							cout << "1. Continuar\n";
							cout << "2. Regresar\n";
							cout << "__________________________________________________\n";
							bool estadoContinuar = true;
							string opcionContinuar;
							do {
								std::cout << ">> ";
								std::cin >> opcionContinuar;
								Validador validador;
								int validacion;
								if (validador.EsNumero(opcionContinuar)) {
									int opcionContinuar2 = stoi(opcionContinuar);
									switch (opcionContinuar2) {
									case 1:
										estadoContinuar = false;
										estadoIntercambio = true;
										break;
									case 2:
										estadoIntercambio = false;
										estadoContinuar = false;
										estadoRonda1 = false;
										ronda = 2;
										break;
									default:
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "Usted ha ingresado una opción incorrecta.\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
										estadoContinuar = true;
										opcionContinuar;
										break;
									}
								}
								else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Solamente puede ingresar digitos.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
									estadoContinuar = true;
									opcionContinuar;
								}
							} while (estadoContinuar);
						}
#pragma endregion
						break;
					case 3:
#pragma region GRAFICA DE LISTA DOBLE
						fichaJugador1.GenerarGrafico("Lista Doble");
						estadoRonda1 = true;
#pragma endregion
						break;
					case 4:
#pragma region FINALIZAR JUEGO JUGADOR 1
						cout << "__________________________________________________\n";
						cout << "¿Seguro quieres salir de la partida?\n";
						cout << "1. Si\n";
						cout << "2. No\n";
						cout << "__________________________________________________\n";
						do {
							std::cout << ">> ";
							std::cin >> opcionFinalizar;
							Validador validador;
							int validacion;
							if (validador.EsNumero(opcionFinalizar)) {
								int opcionFinalizar2 = stoi(opcionFinalizar);
								switch (opcionFinalizar2) {
								case 1:
									//GUARDAR PUNTEOS
									controladorTablero->Agregar(ptsJugador1, jugador1->getNombre());
									controladorTablero->Agregar(ptsJugador2, jugador2->getNombre());
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
									cout << "__________________________________________________\n";
									cout << "JUEGO TERMINADO\n";
									cout << "__________________________________________________\n";
									cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
									cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
									cout << "__________________________________________________\n";
									estadoFinalizar = false;
									estadoRonda1 = false;
									estadoPartida = false;
									system("pause");
									break;
								case 2:
									estadoFinalizar = false;
									estadoRonda1 = true;
									break;
								default:
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Usted ha ingresado una opción incorrecta.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
									estadoFinalizar = true;
									opcionFinalizar;
									break;
								}
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
								cout << "Solamente puede ingresar digitos.\n";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
								estadoFinalizar = true;
								opcionFinalizar;
							}
						} while (estadoFinalizar);
#pragma endregion
						break;
					default:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						cout << "Usted ha ingresado una opción incorrecta.\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						estadoRonda1 = true;
						opcionRonda;
						break;
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "Solamente puede ingresar digitos.\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					estadoRonda1 = true;
					opcionRonda;
				}
			} while (estadoRonda1);
			ronda = 2;
#pragma endregion
		}
		else if (ronda == 2) {
			contador = 0;
			bool estadoRonda1 = true;
			string opcionRonda;
			do {
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << "__________________________________________________\n";
				cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
				fichaJugador2.Mostrar();
				cout << "__________________________________________________\n";
				cout << "¿Que deseas hacer?\n";
				cout << "1. Colocar Fichas\n";
				cout << "2. Intercambiar Fichas\n";
				cout << "3. Reporte Fichas\n";
				cout << "4. Finalizar Juego\n";
				cout << "__________________________________________________\n";
				std::cout << ">> ";
				std::cin >> opcionRonda;
				Validador validador;
				if (validador.EsNumero(opcionRonda)) {
					int opcionRonda2 = stoi(opcionRonda);
					bool estadoLetra = true;
					bool estadoIntercambio = true;
					bool estadoFinalizar = true;
					string opcionFinalizar;

					switch(opcionRonda2)
					{
					case 1:
#pragma region COLOCAR FICHAS JUGADOR 1
						//JUGAR
						while (estadoLetra) {
							system("cls");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							cout << "__________________________________________________\n";
							cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
							fichaJugador2.Mostrar();
							cout << "__________________________________________________\n";
							//VALIDAR LETRA ENCONTRADA
							string letra;
							int posicionX;
							int posicionY;
							bool busquedaLetra = true;
							FichaJugador* ficha = NULL;
							do
							{
								cout << "Escriba una letra: \n";
								std::cout << ">> ";
								cin >> letra;
								ficha = fichaJugador2.Buscar(letra);

								if (ficha == NULL) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Letra no encontrada D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
									system("pause");
									busquedaLetra = true;
								}
								else {
									busquedaLetra = false;
								}
							} while (busquedaLetra);
							//VALIDAR POSICIONES Y OCUPACIONES
							bool validarLetra = true;
							do {
								cout << "Coordenada X: \n";
								std::cout << ">> ";
								cin >> posicionX;
								cout << "Coordenada Y: \n";
								std::cout << ">> ";
								cin >> posicionY;
								int longitud = controladorConfiguracion->getMatriz();
								if (posicionX >= longitud || posicionY >= longitud) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "La posición excede el limite D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);	
									system("pause");
								}
								else {
									if (scrabble.BuscarLetra(posicionX, posicionY) != NULL) {
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "No puedes colocar una letra acá D:\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
										system("pause");
										estadoLetra = false;
									}
									else {
										validarLetra = false;
										//OBTENER LAS PRIMERAS POSICIONES 
										contador++;
										if (contador == 1) {
											posicionInicialX = posicionX;
											posicionInicialY = posicionY;
										}
										fichaJugador2.Eliminar(ficha->getLetra());
										fichaJugadorAux2.Agregar(ficha->getLetra(), ficha->getPunteo(), posicionX, posicionY);
										scrabble.Agregar(ficha->getLetra(), ficha->getPunteo(), posicionX, posicionY, false, false);
										scrabble.GenerarGrafico("Scrabble");
									}
								}
							} while (validarLetra);
							//OTRAS OPCIONES
							cout << "__________________________________________________\n";
							cout << "¿Que deseas hacer?\n";
							cout << "1. Continuar\n";
							cout << "2. Validar\n";
							cout << "__________________________________________________\n";
							bool estadoContinuar = true;
							string opcionContinuar;
							do {
								std::cout << ">> ";
								std::cin >> opcionContinuar;
								Validador validador;
								int validacion;
								if (validador.EsNumero(opcionContinuar)) {
									int opcionContinuar2 = stoi(opcionContinuar);
									switch (opcionContinuar2) {
									case 1:
										estadoLetra = true;
										estadoContinuar = false;
										break;
									case 2:
										posicionFinalX = posicionX;
										posicionFinalY = posicionY;
										//VALIDAR
										validacion = ValidacionMatriz(14);
										if (validacion == 0) {
											//REVERTIR MOVIMIENTO DE PARTIDA
											while (fichaJugadorAux2.getPrimero() != NULL)
											{
												FichaJugador *fichaTemp = fichaJugadorAux2.getPrimero();
												scrabble.Eliminar(fichaTemp->getPosicionX(), fichaTemp->getPosicionY());
												fichaJugador2.Agregar(fichaTemp->getLetra(), ficha->getPunteo());
												fichaJugador2.setPrimero(fichaJugador2.getPrimero()->getSiguiente());
											}
										}
										else {
											//SUMAR
											int longi = fichaJugador2.Longitud();
											if (longi <= 7) {
												int nuevaLongitud = 7 - fichaJugador2.Longitud();
												for (size_t i = 0; i < nuevaLongitud; i++)
												{
													Ficha* ficha = controladorFicha->Eliminar();
													fichaJugador2.Agregar(ficha->getLetra(), ficha->getPunteo());
												}
											}
											ptsJugador2 += validacion;
										}
										estadoLetra = false;
										estadoContinuar = false;
										estadoRonda1 = false;
										cout << "__________________________________________________\n";
										cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
										cout << "__________________________________________________\n";
										system("pause");
										break;
									default:
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "Usted ha ingresado una opción incorrecta.\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
										estadoContinuar = true;
										opcionContinuar;
										break;
									}
								} else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Solamente puede ingresar digitos.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
									estadoContinuar = true;
									opcionContinuar;
								}
							} while (estadoContinuar);
						}
#pragma endregion
						break;
					case 2:
#pragma region INTERCAMBIO DE PALABRAS JUGADOR 1
						while (estadoIntercambio) {
							system("cls");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							cout << "__________________________________________________\n";
							cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
							fichaJugador2.Mostrar();
							cout << "__________________________________________________\n";
							string letra;
							bool busquedaLetra = true;
							FichaJugador* ficha = NULL;
							//VALIDACION DE BUSQUEDA
							do
							{
								cout << "Escriba una letra: \n";
								std::cout << ">> ";
								cin >> letra;
								ficha = fichaJugador2.Buscar(letra);

								if (ficha == NULL) {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Letra no encontrada D:\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
									system("pause");
									busquedaLetra = true;
								}
								else {
									busquedaLetra = false;
								}
							} while (busquedaLetra);
							//INTERCAMBIO DE PALABRA
							if (!controladorFicha->EsVacio()) {
								controladorFicha->Agregar(ficha->getLetra(), ficha->getPunteo(), 1);
								fichaJugador2.Eliminar(letra);
								Ficha* ficha = controladorFicha->Eliminar();
								fichaJugador2.Agregar(ficha->getLetra(), ficha->getPunteo());
								cout << "Se cambiol la letra: " << letra << " por: " << ficha->getLetra() << "\n";
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
								cout << "La cola ya se encuentra vacía D:\n";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
							}
							cout << "__________________________________________________\n";
							cout << "¿Que deseas hacer?\n";
							cout << "1. Continuar\n";
							cout << "2. Regresar\n";
							cout << "__________________________________________________\n";
							bool estadoContinuar = true;
							string opcionContinuar;
							do {
								std::cout << ">> ";
								std::cin >> opcionContinuar;
								Validador validador;
								int validacion;
								if (validador.EsNumero(opcionContinuar)) {
									int opcionContinuar2 = stoi(opcionContinuar);
									switch (opcionContinuar2) {
									case 1:
										estadoContinuar = false;
										estadoIntercambio = true;
										break;
									case 2:
										estadoIntercambio = false;
										estadoContinuar = false;
										estadoRonda1 = false;
										ronda = 2;
										break;
									default:
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
										cout << "Usted ha ingresado una opción incorrecta.\n";
										SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
										estadoContinuar = true;
										opcionContinuar;
										break;
									}
								}
								else {
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Solamente puede ingresar digitos.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
									estadoContinuar = true;
									opcionContinuar;
								}
							} while (estadoContinuar);
						}
#pragma endregion
						break;
					case 3:
#pragma region GRAFICA DE LISTA DOBLE
						fichaJugador2.GenerarGrafico("Lista Doble");
						estadoRonda1 = true;
#pragma endregion
						break;
					case 4:
#pragma region FINALIZAR JUEGO JUGADOR 1
						cout << "__________________________________________________\n";
						cout << "¿Seguro quieres salir de la partida?\n";
						cout << "1. Si\n";
						cout << "2. No\n";
						cout << "__________________________________________________\n";
						do {
							std::cout << ">> ";
							std::cin >> opcionFinalizar;
							Validador validador;
							int validacion;
							if (validador.EsNumero(opcionFinalizar)) {
								int opcionFinalizar2 = stoi(opcionFinalizar);
								switch (opcionFinalizar2) {
								case 1:
									//GUARDAR PUNTEOS
									controladorTablero->Agregar(ptsJugador1, jugador1->getNombre());
									controladorTablero->Agregar(ptsJugador2, jugador2->getNombre());
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
									cout << "__________________________________________________\n";
									cout << "JUEGO TERMINADO\n";
									cout << "__________________________________________________\n";
									cout << "Jugador: " << jugador1->getNombre() << ", Puntos: " << ptsJugador1 << "\n";
									cout << "Jugador: " << jugador2->getNombre() << ", Puntos: " << ptsJugador2 << "\n";
									cout << "__________________________________________________\n";
									estadoFinalizar = false;
									estadoRonda1 = false;
									estadoPartida = false;
									system("pause");
									break;
								case 2:
									estadoFinalizar = false;
									estadoRonda1 = true;
									break;
								default:
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
									cout << "Usted ha ingresado una opción incorrecta.\n";
									SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
									estadoFinalizar = true;
									opcionFinalizar;
									break;
								}
							}
							else {
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
								cout << "Solamente puede ingresar digitos.\n";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
								estadoFinalizar = true;
								opcionFinalizar;
							}
						} while (estadoFinalizar);
#pragma endregion
						break;
					default:
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
						cout << "Usted ha ingresado una opción incorrecta.\n";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
						estadoRonda1 = true;
						opcionRonda;
						break;
					}
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "Solamente puede ingresar digitos.\n";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					estadoRonda1 = true;
					opcionRonda;
				}
			} while (estadoRonda1);
			ronda = 2;
		}
	} while (estadoPartida);
}

int Juego::ValidacionMatriz(int color) {
	int puntosObtenidos = 0;
	int posicionX = posicionInicialX;
	int posicionY = posicionInicialY;
	int posicionTempX = posicionInicialX;
	int posicionTempY = posicionInicialY;
	string palabraDiccionario;
	Scrabble* scrabbleTemp = NULL;

	//HORIZONTAL
	if (posicionInicialX == posicionFinalX) {
		int longitud = posicionFinalY - posicionInicialY;
		for (size_t i = 0; i < longitud + 1; i++)
		{
			scrabbleTemp = scrabble.BuscarLetra(posicionX, posicionY);
			if (scrabbleTemp != NULL)
			{
				palabraDiccionario +=  scrabbleTemp->getDato();
				if (scrabbleTemp->getEsTriple() == true) {
					puntosObtenidos = puntosObtenidos + (3 * scrabbleTemp->getPuntos());
				}
				else if (scrabbleTemp->getEsDoble() == true) {
					puntosObtenidos = puntosObtenidos + (2 * scrabbleTemp->getPuntos());
				}
				else {
					puntosObtenidos = puntosObtenidos + scrabbleTemp->getPuntos();
				}
				posicionY++;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "No existe elemento en: (" << posicionX << "," << posicionY << ")\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				return 0;
			}
		}
	}

	//VERTICAL
	if (posicionInicialY == posicionFinalY) {
		int longitud = posicionFinalX - posicionInicialX;
		for (size_t i = 0; i < longitud +1; i++)
		{
			scrabbleTemp = scrabble.BuscarLetra(posicionX, posicionY);
			if (scrabbleTemp != NULL)
			{
				palabraDiccionario += scrabbleTemp->getDato();
				if (scrabbleTemp->getEsTriple() == true) {
					puntosObtenidos = puntosObtenidos + (3 * scrabbleTemp->getPuntos());
				}
				else if (scrabbleTemp->getEsDoble() == true) {
					puntosObtenidos = puntosObtenidos + (2 * scrabbleTemp->getPuntos());
				}
				else {
					puntosObtenidos = puntosObtenidos + scrabbleTemp->getPuntos();
				}
				posicionX++;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "No existe elemento en: (" << posicionX << "," << posicionY << "\n";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
				return 0;
			}
		}
	}


	//BUSCAR PALABRA EN DICCIONARIO
	Diccionario* diccionario = controladorDiccionario2->Buscar(palabraDiccionario);

	if (diccionario != NULL) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << "Palabra encontrada: " << palabraDiccionario << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Palabra no encontrada\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		puntosObtenidos = 0;
	}

	return puntosObtenidos;
}