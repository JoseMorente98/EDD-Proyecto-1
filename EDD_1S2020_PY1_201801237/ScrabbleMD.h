#pragma once
#include "Scrabble.h"
class ScrabbleMD
{
protected:
    Scrabble* root;
    Scrabble* ultimoDerecho;
    Scrabble* ultimoAbajo;
    string nodoX;
    string nodoY;
    string conexionX;
    string conexionY;

    ScrabbleMD();
    Scrabble* BuscarFila(int posicionY);
    Scrabble* BuscarColumna(int posicionX);
    Scrabble* BuscarLetra(int posicionX, int posicionY);
    Scrabble* AgregarFila(Scrabble* scrabble, Scrabble* scrabbleFila);
    Scrabble* AgregarColumna(Scrabble* scrabble, Scrabble* scrabbleColumna);
    Scrabble* CrearFila(int posicionY);
    Scrabble* CrearColumna(int posicionX);
    void Agregar(string dato, int posicionX, int posicionY, bool esDoble, bool esTriple);
    void GenerarGrafico();
    void Eliminar(int x, int y);

    Scrabble* ValidarDobleTriple(Scrabble* scrabble);
    void ImprimirX(Scrabble* x, int index);
    void ImprimirY(Scrabble* y, int index);
};

