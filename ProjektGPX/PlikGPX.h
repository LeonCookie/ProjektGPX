#pragma once
#include "PunktMapa.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;


class PlikGPX
{
private:
	string sciezka;
protected:
	vector<PunktMapa>PunktyV;
public:

	PlikGPX();//konstruktor domyslny
	PlikGPX(string sciezka);


	//metody
	void wczytaj();
	void wypiszPunkty();//metoda pr�bna do wy�wietlenia zgodno�ci danych z plikiem
	vector<PunktMapa> zwrocPunkty();// zwraca wektor punktow wyciagnietych z pliku
};

