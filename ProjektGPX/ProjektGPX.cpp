#include <iostream>
#include"PlikGPX.h"
int main()
{
	//z jakegos powodu plik nie wczutuje sie gdy uzywamy \ lub \\(blad cerr), ale juz tak gdy/ tak jak ponizej
	PlikGPX plik("C:/Users/leonr/OneDrive/Pulpit/Gdynia.txt");
	plik.wczytaj();
}
