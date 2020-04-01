#pragma once
#include "Scrabble.h"
class ScrabbleMD
{
protected:
    /*
        PROPIEDADES
    */
    Scrabble* root;
    Scrabble* ultimoDerecho;
    Scrabble* ultimoAbajo;
    string nodoX;
    string nodoY;
    string conexionX;
    string conexionY;

public:
    ScrabbleMD();
    Scrabble* BuscarFila(int posicionY);
    Scrabble* BuscarColumna(int posicionX);
    Scrabble* BuscarLetra(int posicionX, int posicionY);
    Scrabble* AgregarFila(Scrabble* scrabble, Scrabble* scrabbleFila);
    Scrabble* AgregarColumna(Scrabble* scrabble, Scrabble* scrabbleColumna);
    Scrabble* CrearFila(int posicionY);
    Scrabble* CrearColumna(int posicionX);
    Scrabble* ValidarDobleTriple(Scrabble* scrabble);
    void Agregar(string dato, int puntos, int posicionX, int posicionY, bool esDoble, bool esTriple);
    void Eliminar(int posicionX, int posicionY);
    void ImprimirX(Scrabble* posicionX, int index);
    void ImprimirY(Scrabble* posicionY, int index);
    void GenerarGrafico();
};

