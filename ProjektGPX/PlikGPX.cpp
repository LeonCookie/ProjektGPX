#include "PlikGPX.h"

//w przypadku pustej sceizki
PlikGPX::PlikGPX()
{
	cout << "Pusta sciiezka";
	sciezka = "";
}

PlikGPX::PlikGPX(string sciezka)
{
	this->sciezka = sciezka;
}

void PlikGPX::wczytaj()
{
	ifstream file(sciezka);
	string liniaPliku;
	if (!file.is_open()) {
		cout << "Zlyplik" << endl;
	}
	while (getline(file, liniaPliku)) {
		cout << liniaPliku << endl;
	}

}
