#include "ScrabbleMD.h"
#include <fstream>
#include <iostream>

ScrabbleMD::ScrabbleMD() {
	root = new Scrabble("Y/X", 0, -1, -1, false, false);
	this->ultimoAbajo = root;
	this->ultimoDerecho = root;
}

Scrabble* ScrabbleMD::BuscarFila(int posicionY)
{
	Scrabble* scrabbleY = root;
	while (scrabbleY != NULL)
	{
		if (scrabbleY->getPosicionY() == posicionY)
		{
			return scrabbleY;
			break;
		}
		scrabbleY = scrabbleY->getAbajo();
	}
	return NULL;
}

Scrabble* ScrabbleMD::BuscarColumna(int posicionX)
{
	Scrabble* scrabbleX = root;

	while (scrabbleX != NULL)
	{
		if (scrabbleX->getPosicionX() == posicionX)
		{
			return scrabbleX;
			break;
		}
		scrabbleX = scrabbleX->getSiguiente();
	}
	return NULL;
}

Scrabble* ScrabbleMD::BuscarLetra(int posicionX, int posicionY)
{
	Scrabble* scrabbleX = root;
	Scrabble* scrabbleY = NULL;

	while (scrabbleX != NULL)
	{
		if (scrabbleX->getPosicionX() == posicionX)
		{
			scrabbleY = scrabbleX;
			break;
		}
		scrabbleX = scrabbleX->getSiguiente();
	}

	while (scrabbleY != NULL)
	{
		if (scrabbleY->getPosicionY() == posicionY)
		{
			return scrabbleY;
			break;
		}
		scrabbleY = scrabbleY->getAbajo();
	}

	return NULL;
}

Scrabble* ScrabbleMD::AgregarFila(Scrabble* scrabble, Scrabble* root)
{
	Scrabble* scrabbleTemp = root;
	Scrabble* scrabbleTemp2 = root;

	while (scrabble->getPosicionX() >= scrabbleTemp->getPosicionX() && scrabbleTemp->getSiguiente() != NULL) {
		scrabbleTemp2 = scrabbleTemp;
		scrabbleTemp = scrabbleTemp->getSiguiente();
	}
	if (scrabble->getPosicionX() >= scrabbleTemp->getPosicionX()) {
		scrabbleTemp->setSiguiente(scrabble);
		scrabble->setAnterior(scrabbleTemp);
	}
	else {
		scrabble->setSiguiente(scrabbleTemp);
		scrabbleTemp->setAnterior(scrabble);
		scrabbleTemp2->setSiguiente(scrabble);
		scrabble->setAnterior(scrabbleTemp2);
	}
	return scrabble;
}

Scrabble* ScrabbleMD::AgregarColumna(Scrabble* scrabble, Scrabble* root)
{
	Scrabble* scrabbleTemp = root;
	Scrabble* scrabbleTemp2 = root;

	while (scrabble->getPosicionY() >= scrabbleTemp->getPosicionY() && scrabbleTemp->getAbajo() != NULL) {
		scrabbleTemp2 = scrabbleTemp;
		scrabbleTemp = scrabbleTemp->getAbajo();
	}
	if (scrabble->getPosicionY() >= scrabbleTemp->getPosicionY()) {
		scrabbleTemp->setAbajo(scrabble);
		scrabble->setArriba(scrabbleTemp);
		scrabble->setAbajo(NULL);
	}
	else {
		scrabble->setAbajo(scrabbleTemp);
		scrabbleTemp->setArriba(scrabble);
		scrabbleTemp2->setAbajo(scrabble);
		scrabble->setArriba(scrabbleTemp2);
		scrabbleTemp2 = scrabble;
	}
	return scrabble;
}

Scrabble* ScrabbleMD::CrearFila(int posicionY)
{
	Scrabble* scrabble = new Scrabble(to_string(posicionY), -1, posicionY, false, false);
	if (posicionY < root->getPosicionY()) {
		scrabble->setSiguiente(root);
		root = scrabble;
	}
	else {
		Scrabble* scrabbleTemp = root;
		Scrabble* scrabbleTemp2 = root;

		while (posicionY >= scrabbleTemp->getPosicionX() && scrabbleTemp->getAbajo() != NULL) {
			scrabbleTemp2 = scrabbleTemp;
			scrabbleTemp = scrabbleTemp->getAbajo();
		}
		if (posicionY >= scrabbleTemp->getPosicionY()) {
			scrabbleTemp->setAbajo(scrabble);
			scrabble->setArriba(scrabbleTemp);
		}
		else {
			scrabble->setAbajo(scrabbleTemp);
			scrabbleTemp->setArriba(scrabble);
			scrabbleTemp2->setAbajo(scrabble);
			scrabble->setArriba(scrabbleTemp2);
		}
	}
	return scrabble;
}

Scrabble* ScrabbleMD::CrearColumna(int posicionX)
{
	Scrabble* scrabble = new Scrabble(to_string(posicionX), posicionX, -1, false, false);
	if (posicionX < root->getPosicionX()) {

		scrabble->setSiguiente(root);
		root->setAnterior(scrabble);
		root = scrabble;
	}
	else {
		Scrabble* scrabbleTemp = root;
		Scrabble* scrabbleTemp2 = root;

		while (posicionX >= scrabbleTemp->getPosicionX() && scrabbleTemp->getSiguiente() != NULL) {
			scrabbleTemp2 = scrabbleTemp;
			scrabbleTemp = scrabbleTemp->getSiguiente();
		}
		if (posicionX >= scrabbleTemp->getPosicionX()) {
			scrabbleTemp->setSiguiente(scrabble);
			scrabble->setAnterior(scrabbleTemp);
		}
		else {
			scrabble->setSiguiente(scrabbleTemp);
			scrabbleTemp->setAnterior(scrabble);
			scrabbleTemp2->setSiguiente(scrabble);
			scrabble->setAnterior(scrabbleTemp2);
		}
	}
	return scrabble;
}

Scrabble* ScrabbleMD::ValidarDobleTriple(Scrabble* scrabble)
{
	return nullptr;
}

void ScrabbleMD::Agregar(string dato, int puntos, int posicionX, int posicionY, bool esDoble, bool esTriple)
{
	Scrabble* scrabbleColumna = this->BuscarColumna(posicionX);
	Scrabble* scrabbleFila = this->BuscarFila(posicionY);

	//NO EXISTE COLUMNA Y FILA
	if (scrabbleColumna == NULL && scrabbleFila == NULL)
	{
		scrabbleColumna = this->CrearColumna(posicionX);
		scrabbleFila = this->CrearFila(posicionY);
		Scrabble* new_node = new Scrabble(dato, puntos, posicionX, posicionY, false, false);
		new_node = this->AgregarColumna(new_node, scrabbleColumna);
		new_node = this->AgregarFila(new_node, scrabbleFila);
		new_node = this->ValidarDobleTriple(new_node);
		return;
	}
	//NO EXISTE COLUMNA Y FILA SI
	if (scrabbleColumna == NULL && scrabbleFila != NULL)
	{

		scrabbleColumna = this->CrearColumna(posicionX);
		Scrabble* new_node = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		new_node = this->AgregarColumna(new_node, scrabbleColumna);
		new_node = this->AgregarFila(new_node, scrabbleFila);
		new_node = this->ValidarDobleTriple(new_node);
		return;
	}
	//NO EXISTE FILA Y COLUMNA SI
	if (scrabbleColumna != NULL && scrabbleFila == NULL)
	{
		scrabbleFila = this->CrearFila(posicionY);
		Scrabble* new_node = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		new_node = this->AgregarColumna(new_node, scrabbleColumna);
		new_node = this->AgregarFila(new_node, scrabbleFila);
		new_node = this->ValidarDobleTriple(new_node);
		return;
	}
	/*CASO 4: COLUMNA Y FILA EXISTEN*/
	//EXISTEN AMBOS
	if (scrabbleColumna != NULL && scrabbleFila != NULL)
	{
		Scrabble* new_node = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		new_node = this->AgregarColumna(new_node, scrabbleColumna);
		new_node = this->AgregarFila(new_node, scrabbleFila);
		new_node = this->ValidarDobleTriple(new_node);
		return;
	}
}

void ScrabbleMD::Eliminar(int posicionX, int posicionY)
{
	Scrabble* scrabbleY = root;
	if (scrabbleY != NULL)
	{
		while (scrabbleY != NULL)
		{
			Scrabble* scrabbleX = scrabbleY;
			while (scrabbleX != NULL)
			{
				if (scrabbleX->getPosicionX() == posicionX && scrabbleX->getPosicionY() == posicionY)
				{
					scrabbleX->getAnterior()->setSiguiente(scrabbleX->getSiguiente());
					if (scrabbleX->getSiguiente() != NULL)
					{
						scrabbleX->getSiguiente()->setAnterior(scrabbleX->getAnterior());
					}
					scrabbleX->setAnterior(NULL);
					scrabbleX->setSiguiente(NULL);
					scrabbleX->getArriba()->setAbajo(scrabbleX->getAbajo());
					if (scrabbleX->getAbajo() != NULL)
					{
						scrabbleX->getAbajo()->setArriba(scrabbleX->getArriba());
					}
					scrabbleX->setArriba(NULL);
					scrabbleX->setAbajo(NULL);
					scrabbleX = NULL;
					break;
				}
				scrabbleX = scrabbleX->getSiguiente();
			}
			scrabbleY = scrabbleY->getAbajo();
		}
	}
}

void ScrabbleMD::ImprimirX(Scrabble* posicionX, int indice)
{
	nodoY = nodoY + "Nodox" + to_string(indice) + "->Nodoy" + to_string(posicionX->getIndice()) + "[dir=both]\n";
	while (posicionX != NULL)
	{
		if (posicionX->getAbajo() != NULL)
		{
			nodoY = nodoY + "Nodoy" + to_string(posicionX->getIndice()) + "->Nodoy" + to_string(posicionX->getAbajo()->getIndice()) + "[dir=both];\n";
		}
		posicionX = posicionX->getAbajo();

	}
}

void ScrabbleMD::ImprimirY(Scrabble* posicionY, int indice)
{
	nodoX = nodoX + "Nodoy" + to_string(indice) + "->Nodoy" + to_string(posicionY->getIndice()) + "[constraint=false, dir=both];\n";
	while (posicionY != NULL)
	{
		if (posicionY->getSiguiente() != NULL)
		{
			nodoX = nodoX + "Nodoy" + to_string(posicionY->getIndice()) + "->Nodoy" + to_string(posicionY->getSiguiente()->getIndice()) + "[constraint=false, dir=both];\n";

		}
		posicionY = posicionY->getSiguiente();
	}
}

void ScrabbleMD::GenerarGrafico()
{
	ofstream ofs("ScrabbleMD.dot", ofstream::out);


	//NUEVO CODIGO DE PRUEVA
	string graficoCabeza = "digraph Sparce_Matrix { \n node [shape=box]\n";
	graficoCabeza = graficoCabeza + "\tMt[ label = \"ScrabbleMD\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];\n";
	graficoCabeza = graficoCabeza + "\te0[ shape = point, width = 0 ];\ne1[shape = point, width = 0];\n";

	Scrabble* as = root;

	//CABECERAS Y;
	Scrabble* cabezaY = root->getAbajo();
	conexionY = "Mt->Nodoy" + to_string(cabezaY->getIndice()) + "[dir=both];\n";
	while (cabezaY != NULL)
	{
		if (cabezaY->getAbajo() != NULL)
		{
			nodoY = nodoY + "Nodoy" + to_string(cabezaY->getIndice()) + " [label = " + '"' + "Y=" + to_string(cabezaY->getPosicionY()) + '"' + " width = 1.5 style = filled, fillcolor = bisque1, group = 1  ];\n";
			conexionY = conexionY + "Nodoy" + to_string(cabezaY->getIndice()) + "->Nodoy" + to_string(cabezaY->getAbajo()->getIndice()) + "[dir=both];\n";
		}
		else
		{
			nodoY = nodoY + "Nodoy" + to_string(cabezaY->getIndice()) + " [label = " + '"' + "Y=" + to_string(cabezaY->getPosicionY()) + '"' + "width = 1.5 style = filled, fillcolor = bisque1, group = 1  ];\n";
		}
		cabezaY = cabezaY->getAbajo();

	}

	//CABECERAS X
	Scrabble* cabezaX = root->getSiguiente();
	conexionX = "Mt->Nodox" + to_string(cabezaX->getIndice()) + ";\n";
	string samex = " { rank = same; Mt; ";
	while (cabezaX != NULL)
	{
		if (cabezaX->getSiguiente() != NULL)
		{
			nodoX = nodoX + "Nodox" + to_string(cabezaX->getIndice()) + " [label = " + '"' + "X=" + to_string(cabezaX->getPosicionX()) + '"' + " width = 1.5 style = filled, fillcolor = lightskyblue, group =" + to_string(cabezaX->getIndice()) + "];\n";
			conexionX = conexionX + "Nodox" + to_string(cabezaX->getIndice()) + "->Nodox" + to_string(cabezaX->getSiguiente()->getIndice()) + "[dir=both];\n";
			samex = samex + "Nodox" + to_string(cabezaX->getIndice()) + "; ";
		}
		else {
			nodoX = nodoX + "Nodox" + to_string(cabezaX->getIndice()) + " [label = " + '"' + "X=" + to_string(cabezaX->getPosicionY()) + '"' + "width = 1.5 style = filled, fillcolor = lightskyblue, group =" + to_string(cabezaX->getIndice()) + "];\n";
			samex = samex + "Nodox" + to_string(cabezaX->getIndice()) + "}\n";

		}
		cabezaX = cabezaX->getSiguiente();
	}

	//NODOS INTERNOS
	Scrabble* temp = root->getAbajo();
	string nodoTemp = "";
	string samey = "{rank= same; ";
	string doubleTriple = "";
	while (temp != NULL)
	{
		Scrabble* auxtemp = temp;

		while (auxtemp != NULL)
		{

			//INDICA SI LA CASILLA ES DOBLE O TRIPLE
			if (auxtemp->getEsDoble())
			{
				doubleTriple = "\\n doble";
			}
			else if (auxtemp->getEsTriple())
			{
				doubleTriple = "\\n triple";
			}
			else {
				doubleTriple = "";
			}

			Scrabble* padre = auxtemp;
			do
			{
				padre = padre->getArriba();
			} while (padre->getArriba() != NULL);

			nodoTemp = nodoTemp + "Nodoy" + to_string(auxtemp->getIndice()) + "[label = \"" + auxtemp->getDato() + doubleTriple + "\" width = 1.5, group = " + to_string(padre->getIndice()) + "];" + "\n";

			if (auxtemp->getSiguiente() != NULL)
			{
				samey = samey + "Nodoy" + to_string(auxtemp->getIndice()) + ";";
			}
			else {
				samey = samey + "Nodoy" + to_string(auxtemp->getIndice());
			}
			auxtemp = auxtemp->getSiguiente();
		}
		if (temp->getAbajo() != NULL)
		{
			samey = samey + "}\n {rank=same;";
		}
		else {
			samey = samey + "}\n";
		}
		temp = temp->getAbajo();
	}


	//obtiene los enlaces hacia abajo 
	Scrabble* a = root->getSiguiente();
	while (a != NULL)
	{
		if (a->getAbajo() != NULL)
		{
			ImprimirX(a->getAbajo(), a->getIndice());
		}
		a = a->getSiguiente();
	}

	//obtiene los enlaces hacia la derecha
	Scrabble* b = root->getAbajo();
	while (b != NULL)
	{
		if (b->getSiguiente() != NULL)
		{
			ImprimirY(b->getSiguiente(), b->getIndice());
		}
		b = b->getAbajo();
	}

	string texto = graficoCabeza + nodoX + nodoY + conexionX + conexionY + samex + nodoTemp + samey + "}";
	//std::cout << texto;

	ofs << texto;

	ofs.close();
	graficoCabeza = nodoX = nodoY = conexionX = conexionY = samex = nodoTemp = samey = "";
	system("dot -Tjpg -o ScrabbleMD.png ScrabbleMD.dot");
	system("ScrabbleMD.png");
}

