#include "PunktMapa.h"

PunktMapa::PunktMapa()
{
	szerokoscG = 0.0;
	dlugoscG = 0.0;
	wysokosc = 0.0;
}

PunktMapa::PunktMapa(double szerokoscG, double dlugoscG, double wysokosc)
{
	this->dlugoscG = dlugoscG;
	this->szerokoscG = szerokoscG;
	this->wysokosc = wysokosc;
}

void PunktMapa::setSzerokoscG(double szerokoscG)
{
	this->szerokoscG = szerokoscG;
}

void PunktMapa::setDlugoscG(double dlugoscG)
{
	this->dlugoscG = dlugoscG;
}

void PunktMapa::setWysokosc(double wysokosc)
{
	this->wysokosc = wysokosc;
}

double PunktMapa::getSzerrokoscG()
{
	return szerokoscG;
}

double PunktMapa::getDlugoscG()
{
	return dlugoscG;
}

double PunktMapa::getWysokosc()
{
	return wysokosc;
}
