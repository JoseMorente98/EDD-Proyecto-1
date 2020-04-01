#include "LecturaJSON.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "ModernJSON.h"
using json = nlohmann::json;
using namespace std;

void LecturaJSON::CargarArchivo()
{
    bool estado = true;
    do
    {
        Menu menu;
        menu.MenuAbrir();

        string pathArchivo = "";
        cin >> pathArchivo;

        ifstream fileStream;

        fileStream.open(pathArchivo, ios::in);

        if (!fileStream.fail())
        {

            ifstream fileStream(pathArchivo);
            json body;
            fileStream >> body;

            //TABLERO DIMENSION
            cout << body.at("dimension") << "\n";

            //DICCIONARIO
            for (int x = 0; x < body.at("diccionario").size(); x++)
            {
                cout << "DICCIONARIO: " << body.at("diccionario")[x].at("palabra") << "\n";
            }

            //DOBLES
            for (int fileStream = 0; fileStream < body.at("casillas").at("dobles").size(); fileStream++)
            {
                cout << "X" << body.at("casillas").at("dobles")[fileStream].at("x") << "\n";
                cout << "Y" << body.at("casillas").at("dobles")[fileStream].at("y") << "\n";
            }

            //TRIPLE
            for (int fileStream = 0; fileStream < body.at("casillas").at("triples").size(); fileStream++)
            {
                cout << "X" << body.at("casillas").at("triples")[fileStream].at("x") << "\n";
                cout << "Y" << body.at("casillas").at("triples")[fileStream].at("y") << "\n";
            }

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            cout << "__________________________________________________\n";
            cout << "Archivo encontrado :D\n";
            cout << "__________________________________________________\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            system("pause");
            break;
        }
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "__________________________________________________\n";
            cout << "Archivo no encontrado D:\n";
            cout << "__________________________________________________\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
            system("pause");
            system("cls");
        }
    } while (estado);
}