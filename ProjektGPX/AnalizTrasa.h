
#include "PlikGPX.h"
//klasa pochodna do klasy PLIKGPX, sluzaca do analizowania tras(np. dlugosc trasy)
class AnalizTrasa : public PlikGPX
{
public:
	AnalizTrasa();//konstruktor domyslny;
	AnalizTrasa(string sciezka);

	//metody
	//dystans calkowity
	//predkosc maks, minimalna
	//czas calkowity

};
