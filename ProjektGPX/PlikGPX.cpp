#include "PlikGPX.h"
#include<iomanip>
//w przypadku pustej sceizki
PlikGPX::PlikGPX()
{
	//cout << "Pusta sciiezka"; //drobny blad pozniej naprawie -> na popczatku w cmd wypieradala pusta sciezka ale tak nie jest bo dane sa zczytywane
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
	double szer = 0.0, dl = 0.0, wys = 0.0; //szeroko��G, d�ugo��G, wyskok��
	string czas = "";
	while (getline(file, liniaPliku))
	{
		//odnalezienie w pliku zacz�cia si� punktu pomiarowego
		if (liniaPliku.find("<trkpt") == 0) {//find(x)==0 sprawdza czy linia zaczyna sie od x
			string liczbaZpliku = "";
			int licznikcudzyslow = 0;

			// zbieranie wartosci lat(szerokosci) i lon(dlugosci) znajdujace si� miedzy 1�2 i 3�4 "".
			for (char znak : liniaPliku)
			{
				if (znak == '"')
				{
					licznikcudzyslow++;
				}
				else if (licznikcudzyslow == 1 or licznikcudzyslow == 3)
				{
					liczbaZpliku += znak;
				}

				if (licznikcudzyslow == 2)
				{
					if (!liczbaZpliku.empty())
					{
						//z jakiegos powodu co 5,4 zwracana wartosc byla pusta. filtrujemy te dane
						szer = stod(liczbaZpliku);
						liczbaZpliku = "";
						//cout <<setprecision(15)<<szer<< endl;//setprecision z bibliotekio iomanip sprawa ze w cmd liczba nie jest skracana
					}
				}
				if (licznikcudzyslow == 4)
				{
					dl = stod(liczbaZpliku);
					liczbaZpliku = "";
					//cout << setprecision(15) << dl << endl;
					break;//by dalej nie sprawdzac    <DO LEON> Nadal nie wiem po chuj ten break ale jak sie go wypierdoli to nie dzia�a, wiec niech na razie zostanie xD
				}
			}
		}

		//szukanie wysyko�ci
		if (liniaPliku.find("<ele>") == 0)
		{
			string liczbaZpliku = "";
			int licznikZnacznika = 0;

			for (char znak : liniaPliku) {
				if (znak == '>') {
					licznikZnacznika++;
					continue;
				}
				if (licznikZnacznika == 1 && znak != '<')
				{
					liczbaZpliku += znak;
				}
				if (znak == '<' && licznikZnacznika == 1)
				{
					if (!liczbaZpliku.empty())
					{
						wys = stod(liczbaZpliku);
						liczbaZpliku = "";
					}
					break; // ten break do wyjebania, ale na razie zostawiam (W my�l filozofii informatyk�w - jak dzia�a to nie ruszaj). Ogolnie break�w trzeba unika� jak ognia
				}
			}
		}

		//szukanie daty	
		if (liniaPliku.find("<time>") == 0)
		{
			string liczbaZpliku = "";
			int licznikZnacznika = 0;

			for (char znak : liniaPliku) {
				if (znak == '>') {
					licznikZnacznika++;
					continue;//ten te� do wyjebki
				}
				if (licznikZnacznika == 1 && znak != '<') {
					liczbaZpliku += znak;
				}
				if (znak == '<' && licznikZnacznika == 1) {
					if (!liczbaZpliku.empty()) {
						czas = liczbaZpliku;
						liczbaZpliku = "";
					}
					break;
				}
			}
		}

		
		


		//Zako�czenie pomiaru
		if (liniaPliku.find("</trkpt>") == 0) 
		{
			PunktMapa punkt(szer, dl, wys, czas);
			PunktyV.push_back(punkt);
		}
	}
}


//wypisywanie punkt�w na konsoli
void PlikGPX::wypiszPunkty()
{
	/*
	for (auto punkt : PunktyV) 
	{
		cout <<"Szerokosc"<<endl << setprecision(15) << punkt.getSzerrokoscG()<<endl;
		cout << " ";
		cout << "Dlugosc" << endl << setprecision(15) << punkt.getDlugoscG() << endl;
		cout << " ";
		cout << "Wysokosc" << endl << setprecision(15) << punkt.getWysokosc() << endl;
		cout << " ";
		cout << "Czas" << endl << punkt.getCzas() << endl;
		cout <<"======================" << endl<<endl;

	}
	*/
}



vector<PunktMapa> PlikGPX::zwrocPunkty()
{
	return PunktyV;
}
