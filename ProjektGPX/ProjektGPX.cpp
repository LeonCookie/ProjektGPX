﻿#include <iostream>
#include"PlikGPX.h"
#include"AnalizTrasa.h"
int main()
{
	//z jakegos powodu plik nie wczutuje sie gdy uzywamy \ lub \\(blad cerr), ale juz tak gdy/ tak jak ponizej
	//trzeba zmienic plik .gpx na .txt

	//L.R
	PlikGPX GdyniaPlik("C:/Users/leonr/OneDrive/Pulpit/Gdynia.txt");
	PlikGPX CzernicaPlik("C:/Users/leonr/OneDrive/Pulpit/Czernica.txt");
	//O.R
	/*
	PlikGPX GdyniaPlik("sciezka rybaczyk");
	PlikGPX CzernicaPlik("sciezka rybaczyk");
	*/
	GdyniaPlik.wczytaj();
	//GdyniaPlik.wypiszPunkty();//klasa bazowa PlikGPX, wypisuje wszystkie obiekty z vectora(klasy pomocniczej punkty)
	//GdyniaPlik.oszukajObliczanie();//wyswietla wyniki z pliku
	AnalizTrasa GdyniaAnaliza(GdyniaPlik.zwrocPunkty());
	GdyniaAnaliza.wyswietlDane();

}
