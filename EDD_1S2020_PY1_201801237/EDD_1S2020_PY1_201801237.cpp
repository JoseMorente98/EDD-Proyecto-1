// EDD_1S2020_PY1_201801237.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "LecturaJSON.h"
#include "DiccionarioLDC.h"
#include "FichaCola.h"
#include "FichaJugador.h"
#include "FichaJugadorLD.h"
#include "JugadorAB.h"
#include "TableroPuntuacionLS.h"
#include "Scrabble.h"
#include "ScrabbleMD.h"

int main()
{
    /*LecturaJSON lectura;
    lectura.CargarArchivo();*/
    /*DiccionarioLDC diccionario;
    diccionario.Agregar("Hola");
    diccionario.Agregar("Suselly");
    diccionario.Agregar("Chica");
    diccionario.Agregar("Preciosa");
    diccionario.Agregar("<3");
    diccionario.GenerarGrafico("Lista Doble Circular");*/
    /*FichaCola ficha;
    ficha.Agregar("A", 1, 10);
    ficha.Agregar("B", 1, 10);
    ficha.Agregar("C", 1, 10);
    ficha.Agregar("D", 1, 10);
    ficha.Agregar("E", 1, 10);
    ficha.Agregar("F", 1, 10);
    ficha.Agregar("G", 1, 10);
    ficha.Eliminar();
    ficha.GenerarGrafico("Cola");*/
    /*FichaJugadorLD f;
    f.Agregar("A", 5);
    f.Agregar("B", 5);
    f.Agregar("C", 5);
    f.Agregar("D", 5);
    f.GenerarGrafico("Lista Doble");*/
    /*JugadorAB j;
    j.Agregar("Juan");
    j.Agregar("Pablo");
    j.Agregar("Pedro");
    j.Agregar("David");
    j.Agregar("Rafael");
    j.Agregar("Antonieta");
    j.Agregar("Suselly");
    j.Agregar("Paola");
    j.GenerarGrafico("Arbol Binario");
    j.ReporteInOrden("In Order");
    j.ReportePosOrden("Pos Order");
    j.ReportePreOrden("Pre Order");*/
    /*TableroPuntuacionLS t;
    t.Agregar(54, "Jose");
    t.Agregar(10, "Rafael");
    t.Agregar(104, "Morente");
    t.Agregar(14, "Paola");
    t.Agregar(15, "Jose");
    t.Imprimir();
    t.GenerarGrafico("Lista Simple Ordenada");
    t.GenerarGraficoPorJugador("Jose");*/
    ScrabbleMD s;
    s.Agregar("H", 15, 3, 4, false, false);
    s.Agregar("O", 15, 3, 5, false, false);
    s.Agregar("L", 15, 3, 6, false, false);
    s.Agregar("A", 15, 3, 7, false, false);
    s.Agregar("P", 15, 7, 4, false, false);
    s.Agregar("R", 15, 9, 7, false, false);
    s.Agregar("A", 15, 2, 9, false, false);
    s.Agregar("A", 15, 6, 4, false, false);
    s.Agregar("A", 15, 6, 1, false, false);
    s.GenerarGrafico("Scrabble");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
