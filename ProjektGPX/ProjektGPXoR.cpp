#include <iostream>
#include"PlikGPX.h"
#include "AnalizTrasa.h"
int main()
{
	//z jakegos powodu plik nie wczutuje sie gdy uzywamy \ lub \\(blad cerr), ale juz tak gdy/ tak jak ponizej
	//trzeba zmienic plik .gpx na .txt

	//L.R

	//PlikGPX GdyniaPlik("C:/Users/leonr/OneDrive/Pulpit/Gdynia.txt");
	//PlikGPX CzernicaPlik("C:/Users/leonr/OneDrive/Pulpit/Czernica.txt");

	//O.R

	 PlikGPX GdyniaPlik1("C:/Users/oryba/Desktop/gdynia.txt");
	 GdyniaPlik1.wczytaj();
	 AnalizTrasa GdyniaAnaliza(GdyniaPlik1.zwrocPunkty());
	
	//PlikGPX CzernicaPlik("C:/Users/oryba/Desktop/czernia.txt");
	
	GdyniaAnaliza.czasCalkowity();
	GdyniaAnaliza.dystansCalkowity();
	GdyniaAnaliza.predkosci();
	
	
	//GdyniaPlik.wypiszPunkty();
}
