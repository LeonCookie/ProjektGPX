#include "PlikGPX.h"
#include<iomanip>
//w przypadku pustej sceizki
PlikGPX::PlikGPX()
{
	sciezka = "";
}

PlikGPX::PlikGPX(string sciezka)
{
	this->sciezka = sciezka;
}
double wyciagnijWartoscStrzalka(string linia) {
	string liczbaZpliku = "";
	int licznikZnacznika = 0;

	for (char znak : linia) {
		if (znak == '>') {
			licznikZnacznika++;
		}
		else if (licznikZnacznika == 1 && znak != '<')
		{
			liczbaZpliku += znak;
		}
		if (znak == '<' && licznikZnacznika == 1)
		{
			if (!liczbaZpliku.empty()) {
				return stod(liczbaZpliku);
			}
			break;// przerywamy  petle  i dalsze czytanie linii jest zbedne
		}
	}


	return 0.0;
}

void PlikGPX::wczytaj()
{
	ifstream file(sciezka);
	string liniaPliku;
	if (!file.is_open()) {
		cout << "Zlyplik" << endl;
	}
	double szer = 0.0, dl = 0.0, wys = 0.0; //szerokoœæG, d³ugoœæG, wyskokœæ
	string czas = "";
	while (getline(file, liniaPliku))
	{
		//odnalezienie w pliku zaczêcia siê punktu pomiarowego
		if (liniaPliku.find("<trkpt") == 0) {//find(x)==0 sprawdza czy linia zaczyna sie od x
			string liczbaZpliku = "";
			int licznikcudzyslow = 0;

			// zbieranie wartosci lat(szerokosci) i lon(dlugosci) znajdujace siê miedzy 1–2 i 3–4 "".
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
						szer = stod(liczbaZpliku);
						liczbaZpliku = "";
					}
				}
				if (licznikcudzyslow == 4)
				{
					dl = stod(liczbaZpliku);
					liczbaZpliku = "";
					break;// przerywamy  petle  i dalsze czytanie linii jest zbedne
				}
			}
		}

		//szukanie wysykoœci
		if (liniaPliku.find("<ele>") == 0)
		{
			wys = wyciagnijWartoscStrzalka(liniaPliku);// uzywamy tylko dla wysokosci i wynikow z pliku poniewaz w samym pliku sa to liczby, a czas jest tekstem
		}

		//szukanie daty	
		if (liniaPliku.find("<time>") == 0)
		{
			string liczbaZpliku = "";
			int licznikZnacznika = 0;//dane znajduja sie miedzy > a <

			for (char znak : liniaPliku) {
				if (znak == '>') {
					licznikZnacznika++;
				}
				else if (licznikZnacznika == 1 && znak != '<') {
					liczbaZpliku += znak;
				}
				else if (znak == '<' && licznikZnacznika == 1) {
					if (!liczbaZpliku.empty()) {
						czas = liczbaZpliku;
						liczbaZpliku = "";
					}
					break;
				}
			}
		}





		//Zakoñczenie pomiaru
		if (liniaPliku.find("</trkpt>") == 0)
		{
			PunktMapa punkt(szer, dl, wys, czas);
			PunktyV.push_back(punkt);
		}
	}
}


//wypisywanie punktów na konsoli
void PlikGPX::wypiszPunkty()
{

	for (auto punkt : PunktyV)
	{
		cout << "Szerokosc" << endl << setprecision(15) << punkt.getSzerrokoscG() << endl;
		cout << " ";
		cout << "Dlugosc" << endl << setprecision(15) << punkt.getDlugoscG() << endl;
		cout << " ";
		cout << "Wysokosc" << endl << setprecision(15) << punkt.getWysokosc() << endl;
		cout << " ";
		cout << "Czas" << endl << punkt.getCzas() << endl;
		cout << "======================" << endl << endl;

	}

}


void PlikGPX::oszukajObliczanie()
{
	ifstream file(sciezka);
	string liniaPliku;
	if (!file.is_open()) {
		cout << "Zlyplik" << endl;
	}
	double dis = 0.0, ele = 0.0, avggr = 0.0, durat = 0.0, avgspeed = 0.0;
	while (getline(file, liniaPliku))
	{
		if (liniaPliku.find("<distance>") == 0) {
			dis = wyciagnijWartoscStrzalka(liniaPliku);
		}
		if (liniaPliku.find("<elevationgain>") == 0) {
			ele = wyciagnijWartoscStrzalka(liniaPliku);
		}
		if (liniaPliku.find("<avggradient>") == 0) {
			avggr = wyciagnijWartoscStrzalka(liniaPliku);
		}
		if (liniaPliku.find("<duration>") == 0) {
			durat = wyciagnijWartoscStrzalka(liniaPliku);
			durat = durat / 1000;
		}
		if (liniaPliku.find("<avgspeed>") == 0) {
			avgspeed = wyciagnijWartoscStrzalka(liniaPliku);
			break;
		}
	}
	
	cout << "-------------cheatsheet----------------" << endl;
	cout << "oszukane czytane wartosci dystans: " << dis << endl;
	cout << "ilosc wspiec(w m): " << ele << endl;
	cout << "srednie nachylenie: " << avggr << endl;
	cout << "czas trwania(s): " << durat << endl;
	cout << "srednia predkosc (m/s): " << avgspeed << endl;
	cout << "---------------------------------------" << endl;
}
/* oszukajObliczanie() czyta gotowe dane dystans czas predkosc zapisane w pliku 
 wyswietlDane() liczy wszystko samemu na podstawie punktow gps i uwzglednia spadki wzniesienia czyli dystans 3D
 dlatego wyniki sa inne bo jedna metoda bierze gotowe liczby a druga wszystko przelicza z terenu*/


vector<PunktMapa> PlikGPX::zwrocPunkty()
{
	return PunktyV;
}