#include "PlikGPX.h"
#include<iomanip>
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
	double szer = 0.0, dl = 0.0, wys = 0.0;
	string czas = "";
	while (getline(file, liniaPliku)) {
		if (liniaPliku.find("<trkpt") == 0) {
			string liczbaZpliku = "";
			int licznikcudzyslow = 0;

			for (char znak : liniaPliku) {
				if (znak == '"') {
					licznikcudzyslow++;
				}
				else if (licznikcudzyslow == 1 || licznikcudzyslow == 3) {
					liczbaZpliku += znak;
				}

				if (licznikcudzyslow == 2) {
					if (!liczbaZpliku.empty()) {//z jakiegos powodu co 5,4 zwracana wartosc byla pusta. filtrujemy te dane
						szer = stod(liczbaZpliku);
						liczbaZpliku = "";
						cout <<setprecision(15)<<szer<< endl;//setprecision z bibliotekio iomanip sprawa ze w cmd liczba nie jest skracana
					}
				}
				if (licznikcudzyslow == 4){
					dl = stod(liczbaZpliku);
					liczbaZpliku = "";
					//cout << setprecision(15) << dl << endl;
					break;//by dalej nie sprawdzac
				}
			}
			if (liniaPliku.find("<ele>") == 0) {
			}
			if (liniaPliku.find("<time>") == 0) {
			}
		}
		//PunktyV.push_back
	}
}



vector<PunktMapa> PlikGPX::zwrocPunkty()
{
	return PunktyV;
}
