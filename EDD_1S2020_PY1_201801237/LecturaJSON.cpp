#include "LecturaJSON.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "ModernJSON.h"
#include "DiccionarioLDC.h"
#include "ApartadoLD.h"
using json = nlohmann::json;
using namespace std;
/*
    SINGLETON
*/
DiccionarioLDC* controladorDiccionario = DiccionarioLDC::Instancia();
ApartadoLD* controladorApartado = ApartadoLD::Instancia();

void LecturaJSON::CargarArchivo()
{
    //LIMPIAR VARIABLES
    controladorDiccionario->Limpiar();
    controladorApartado->LimpiarDoble();
    controladorApartado->LimpiarTriple();

    bool estado = true;
    do
    {
        Menu menu;
        menu.MenuAbrir();
        string pathArchivo = "";
        std::cout << ">> ";
        cin >> pathArchivo;

        ifstream fileStream;

        fileStream.open(pathArchivo, ios::in);

        if (!fileStream.fail())
        {

            ifstream fileStream(pathArchivo);
            json body;
            fileStream >> body;

            //TABLERO DIMENSION
            controladorApartado->setMatriz(body.at("dimension"));

            //DICCIONARIO
            for (size_t i = 0; i < body.at("diccionario").size(); i++)
            {
                controladorDiccionario->Agregar(body.at("diccionario")[i].at("palabra"));
            }
            
            //DOBLES
            for (size_t i = 0; i < body.at("casillas").at("dobles").size(); i++)
            {
                controladorApartado->AgregarDoble(body.at("casillas").at("dobles")[i].at("x"), body.at("casillas").at("dobles")[i].at("y"), true, false);
            }

            //TRIPLE
            for (size_t i = 0; i < body.at("casillas").at("triples").size(); i++)
            {
                controladorApartado->AgregarTriple(body.at("casillas").at("triples")[i].at("x"), body.at("casillas").at("triples")[i].at("y"), false, true);
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "Archivo encontrado :D\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            system("pause");
            system("cls");
            estado = false;
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Archivo no localizado D:\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            system("pause");
            system("cls");
            estado = true;
        }
    } while (estado);
}