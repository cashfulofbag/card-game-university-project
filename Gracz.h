#pragma once
#include "Karta.h"
#include "Kasyno.h"


class Kasyno;
class Gracz
{
protected:
	Karta* reka[10];
	int karty_na_rece;
	int wartosc_kart;
	bool pasuj = 0;
	Kasyno *kasyno;
	char nazwa[20];

public:
	Gracz();
	void wezKarte(Karta* _karta);
	void wyswietl_karty();
	int daj_wartosc();
	void pas();
	bool daj_pas();
	void przypisz_do_kasyna(Kasyno* _kasyno);
	void zmien_nazwe();
	void wyswietl_mnie();
	char* daj_nazwe();
	int daj_karty_na_rece();
	Karta* daj_reke();
	void decyzja();
};

class Gracz_wirtualny : public Gracz
{
	int odwaga;
};

