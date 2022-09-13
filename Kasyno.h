#pragma once
#include "Karta.h"
#include "Gracz.h"
#include "Gracz_wirtualny.h"

class Gracz;
class Gracz_wirtualny;
class Kasyno{
	Karta talia[52];
	Gracz* gracze;

public:
	Kasyno();
	~Kasyno();
	void tasuj();
	void nowa_talia();
	void dodaj_graczy(int _suma, int _ludzie);
	void dodaj_boty(int _boty);
	void dajKarte(int _karty_wydane, int _i);
	void wyswietl_gracza(int _numer_gracza);
	void g_pasuj(int _gracz);
	int sprawdz_wartosc(int _i);
	bool sprawdz_pas(int _i);
	bool sprawdz_koniec(int _ilosc_graczy);
	void wyswietl_wyniki(int _ilosc_graczy);
	void zapisz(int _ilosc_graczy);
	void wypisz_talie();
	int sprawdz_bot(int _i);
};

