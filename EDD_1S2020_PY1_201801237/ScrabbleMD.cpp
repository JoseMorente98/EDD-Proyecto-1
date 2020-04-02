#include "ScrabbleMD.h"

ScrabbleMD::ScrabbleMD() {
	root = new Scrabble("Scrabble", 0, -1, -1, false, false);
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

		while (posicionY >= scrabbleTemp->getPosicionY() && scrabbleTemp->getAbajo() != NULL) {
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

	if (scrabbleColumna == NULL && scrabbleFila == NULL)
	{
		scrabbleColumna = this->CrearColumna(posicionX);
		scrabbleFila = this->CrearFila(posicionY);
		Scrabble* scrabble = new Scrabble(dato, puntos, posicionX, posicionY, false, false);
		scrabble = this->AgregarColumna(scrabble, scrabbleColumna);
		scrabble = this->AgregarFila(scrabble, scrabbleFila);
		scrabble = this->ValidarDobleTriple(scrabble);
		return;
	}
	if (scrabbleColumna == NULL && scrabbleFila != NULL)
	{
		scrabbleColumna = this->CrearColumna(posicionX);
		Scrabble* scrabble = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		scrabble = this->AgregarColumna(scrabble, scrabbleColumna);
		scrabble = this->AgregarFila(scrabble, scrabbleFila);
		scrabble = this->ValidarDobleTriple(scrabble);
		return;
	}
	if (scrabbleColumna != NULL && scrabbleFila == NULL)
	{
		scrabbleFila = this->CrearFila(posicionY);
		Scrabble* scrabble = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		scrabble = this->AgregarColumna(scrabble, scrabbleColumna);
		scrabble = this->AgregarFila(scrabble, scrabbleFila);
		scrabble = this->ValidarDobleTriple(scrabble);
		return;
	}
	if (scrabbleColumna != NULL && scrabbleFila != NULL)
	{
		Scrabble* scrabble = new Scrabble(dato, puntos, posicionX, posicionY, esDoble, esTriple);
		scrabble = this->AgregarColumna(scrabble, scrabbleColumna);
		scrabble = this->AgregarFila(scrabble, scrabbleFila);
		scrabble = this->ValidarDobleTriple(scrabble);
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

void ScrabbleMD::GenerarGrafico(string nombre)
{
	string archivoTexto = "";
	string graficoCabeza = "";
	string bodyGraphiz = "";
	string rankX = "";
	string rankY = "";
	string esDobleTriple = "";
	string objectX = "";
	string objectY = "";
	string conexionX = "";
	string conexionY = "";
	ofstream escrituraArchivo("ScrabbleMD.dot", ofstream::out);

	graficoCabeza = "digraph ScrabbleMD {\n";
	graficoCabeza += "\tnode[shape = box3d]\n";
	graficoCabeza += "\tObjectRoot[label=\"Scrabble\", width=1,  fontcolor=white, fillcolor=darkgreen, style=filled,  group = 1 ];\n";
	graficoCabeza += "\tgraph[label=\""+nombre+"\", labelloc = t, fontsize = 20];";

	//COLUMNAS
	Scrabble* scrabbleHeaderX = root->getSiguiente();
	conexionX = "\tObjectRoot->ObjectX" + to_string(scrabbleHeaderX->getIndice()) + ";\n";
	rankX = "\t{ rank = same; ObjectRoot; ";
	while (scrabbleHeaderX != NULL)
	{
		if (scrabbleHeaderX->getSiguiente() != NULL)
		{
			objectX += "\tObjectX" + to_string(scrabbleHeaderX->getIndice()) + " [label=" + '"' + "" + to_string(scrabbleHeaderX->getPosicionX()) + '"' + " width=1,  fontcolor=white, fillcolor=darkgreen, style=filled,  group =" + to_string(scrabbleHeaderX->getIndice()) + "];\n";
			conexionX += "\tObjectX" + to_string(scrabbleHeaderX->getIndice()) + "->ObjectX" + to_string(scrabbleHeaderX->getSiguiente()->getIndice()) + ";\n";
			rankX += "\t\tObjectX" + to_string(scrabbleHeaderX->getIndice()) + "; ";
		}
		else {
			objectX += "\tObjectX" + to_string(scrabbleHeaderX->getIndice()) + " [label=" + '"' + "" + to_string(scrabbleHeaderX->getPosicionX()) + '"' + "width=1,  fontcolor=white, fillcolor=darkgreen, style=filled,  group =" + to_string(scrabbleHeaderX->getIndice()) + "];\n";
			rankX += "\t\tObjectX" + to_string(scrabbleHeaderX->getIndice()) + "}\n";

		}
		scrabbleHeaderX = scrabbleHeaderX->getSiguiente();
	}

	Scrabble* scrabbleX = root->getAbajo();
	while (scrabbleX != NULL)
	{
		if (scrabbleX->getSiguiente() != NULL)
		{
			Scrabble* posicionY = scrabbleX->getSiguiente();
			objectX += "\tObjectY" + to_string(scrabbleX->getIndice()) + "->ObjectY" + to_string(posicionY->getIndice()) + "[constraint=false];\n";
			while (posicionY != NULL)
			{
				if (posicionY->getSiguiente() != NULL)
				{
					objectX += "\tObjectY" + to_string(posicionY->getIndice()) + "->ObjectY" + to_string(posicionY->getSiguiente()->getIndice()) + "[constraint=false];\n";

				}
				posicionY = posicionY->getSiguiente();
			}
		}
		scrabbleX = scrabbleX->getAbajo();
	}

	//FILAS
	Scrabble* scrabbleHeaderY = root->getAbajo();
	conexionY = "\tObjectRoot->ObjectY" + to_string(scrabbleHeaderY->getIndice()) + ";\n";
	while (scrabbleHeaderY != NULL)
	{
		if (scrabbleHeaderY->getAbajo() != NULL)
		{
			objectY += "\tObjectY" + to_string(scrabbleHeaderY->getIndice()) + " [label=" + '"' + "" + to_string(scrabbleHeaderY->getPosicionY()) + '"' + " width=1,  fontcolor=white, fillcolor=darkgreen, style=filled,  group=1  ];\n";
			conexionY += "\tObjectY" + to_string(scrabbleHeaderY->getIndice()) + "->ObjectY" + to_string(scrabbleHeaderY->getAbajo()->getIndice()) + ";\n";
		}
		else
		{
			objectY += "\tObjectY" + to_string(scrabbleHeaderY->getIndice()) + " [label=" + '"' + "" + to_string(scrabbleHeaderY->getPosicionY()) + '"' + "width=1,  fontcolor=white, fillcolor=darkgreen, style=filled,  group=1  ];\n";
		}
		cout << scrabbleHeaderY->getPosicionY();
		scrabbleHeaderY = scrabbleHeaderY->getAbajo();
	}

	Scrabble* scrabbleY = root->getSiguiente();
	while (scrabbleY != NULL)
	{
		if (scrabbleY->getAbajo() != NULL)
		{
			Scrabble *posicionX = scrabbleY->getAbajo();
			objectY += "\tObjectX" + to_string(scrabbleY->getIndice()) + "->ObjectY" + to_string(posicionX->getIndice()) + "\n";
			while (posicionX != NULL)
			{
				if (posicionX->getAbajo() != NULL)
				{
					objectY += "\tObjectY" + to_string(posicionX->getIndice()) + "->ObjectY" + to_string(posicionX->getAbajo()->getIndice()) + ";\n";
				}
				posicionX = posicionX->getAbajo();
			}
		}
		scrabbleY = scrabbleY->getSiguiente();
	}

	//NODOS INTERNOS
	Scrabble* scrabbleTemp = root->getAbajo();
	rankY = "\t{rank= same; ";
	while (scrabbleTemp != NULL)
	{
		Scrabble* scrabbleAux = scrabbleTemp;

		while (scrabbleAux != NULL)
		{
			if (scrabbleAux->getEsDoble())
			{
				esDobleTriple = "\\n Doble";
			}
			else if (scrabbleAux->getEsTriple())
			{
				esDobleTriple = "\\n Triple";
			}
			else {
				esDobleTriple = "";
			}

			Scrabble* scrabbleAux2 = scrabbleAux;
			do
			{
				scrabbleAux2 = scrabbleAux2->getArriba();
			} while (scrabbleAux2->getArriba() != NULL);

			if (scrabbleAux2->getIndice() != 1) {
				bodyGraphiz += "\tObjectY" + to_string(scrabbleAux->getIndice()) + "[label=\"" + scrabbleAux->getDato() + esDobleTriple + "\" width = 1, style = filled, fillcolor = olivedrab2, group = " + to_string(scrabbleAux2->getIndice()) + "];" + "\n";
			}

			if (scrabbleAux->getSiguiente() != NULL)
			{
				rankY += "\t\tObjectY" + to_string(scrabbleAux->getIndice()) + ";";
			}
			else {
				rankY += "\t\tObjectY" + to_string(scrabbleAux->getIndice());
			}
			scrabbleAux = scrabbleAux->getSiguiente();
		}
		if (scrabbleTemp->getAbajo() != NULL)
		{
			rankY += "}\n\t{rank=same;";
		}
		else {
			rankY += "}\n";
		}
		scrabbleTemp = scrabbleTemp->getAbajo();
	}

	archivoTexto = graficoCabeza + objectX + objectY + conexionX + conexionY + rankX + bodyGraphiz + rankY + "}";

	escrituraArchivo << archivoTexto;

	escrituraArchivo.close();
	system("dot -Tjpg -o ScrabbleMD.png ScrabbleMD.dot");
	system("ScrabbleMD.png");
}
