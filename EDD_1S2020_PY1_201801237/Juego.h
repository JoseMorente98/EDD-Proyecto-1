#pragma once
class Juego
{
public:
	Juego();
	void MenuPrincipal();
	void MenuJuego();
	void MenuJugador();
	void MenuReporte();
	void ReportePunteoPorJugador();
	void CargaMasiva();
	void IniciarJuego();
	int ValidacionMatriz(int color);
};

