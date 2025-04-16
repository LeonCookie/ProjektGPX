#pragma once
class PunktMapa
{
private:
	double szerokoscG;
	double dlugoscG;
	double wysokosc;
public:
	PunktMapa();//konstruktor domyslny
	PunktMapa(double szerokoscG, double dlugoscG, double wysokosc);

	//set
	
	//G-geograficzna
	void setSzerokoscG(double szerokoscG);
	void setDlugoscG(double dlugoscG);
	void setWysokosc(double wysokosc);

	//get
	double getSzerrokoscG();
	double getDlugoscG();
	double getWysokosc();

};

