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
	vector<PunktMapa>PunktyV;
public:
	
	PlikGPX();//konstruktor domyslny
	PlikGPX(string sciezka);


	//metody
	void wczytaj();
};

