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

	double szer=0.0, dl = 0.0, wys=0.0;
	while (getline(file, liniaPliku)) {
		//cout << liniaPliku << endl;
		if (liniaPliku.find("<trkpt")==0) {
			cout << liniaPliku << endl;
		}
		if (liniaPliku.find("<ele>") == 0) {
			cout << liniaPliku << endl;
		}
		if (liniaPliku.find("<time>") == 0) {
			cout << liniaPliku << endl;
		}
	}



}

vector<PunktMapa> PlikGPX::zwrocPunkty()
{
	return PunktyV;
}
