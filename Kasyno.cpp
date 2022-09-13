#include "Kasyno.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

class Gracz;
Kasyno::Kasyno()
	:gracze(nullptr)

{
	int i = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			this->talia[i] = Karta(x, y);
			i++;
		}
	}
}

Kasyno::~Kasyno()
{
	delete[] gracze;
}

void Kasyno::wyswietl_gracza(int _numer_gracza)
{
	
	this->gracze[_numer_gracza].wyswietl_mnie();
}

void Kasyno::g_pasuj(int _gracz)
{
	this->gracze[_gracz].pas();
}

void Kasyno::tasuj()
{
	int max = 51;
	srand(time(0));
	Karta pom(0, 0);
	for (int x = 0; x <= 1000; x++)
	{
		int i = rand() % max;
		if (i != max)
		{
			pom = this->talia[i];
			this->talia[i] = this->talia[i + 1];
			this->talia[i + 1] = pom;
		}
		else
		{
			pom = this->talia[i];
			this->talia[i] = this->talia[0];
			this->talia[0] = pom;
		}
	}
}

void Kasyno::nowa_talia()
{
	int i = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 14; y++)
		{
			this->talia[i] = Karta(x, y);
			i++;
		}
	}
}

void Kasyno::dodaj_graczy(int _suma, int _ludzie)
{
	this->gracze = new Gracz[_suma];
	//for (int i = 0; i < _suma; i++)
	//{
	//	if (i >= _ludzie)
	//	{
	//		this->gracze[i] = Gracz_wirtualny();
	//	}
	//}
	for (int i = 0; i < _suma; i++)
	{
		this->gracze[i].zmien_nazwe();
	}
}

//void Kasyno::dodaj_boty(int _boty)
//{
//	this->boty = new Gracz_wirtualny[_boty];
//	for (int i = 0; i < _boty; i++)
//	{
//		this->boty[i].zmien_nazwe(i);
//	}
//}

void Kasyno::dajKarte(int _karty_wydane, int _i)
{
	this->gracze[_i].wezKarte(&this->talia[_karty_wydane]);
}

int Kasyno::sprawdz_wartosc(int _i)
{
	return (this->gracze[_i].daj_wartosc());
}

bool Kasyno::sprawdz_pas(int _i)
{
	return (this->gracze[_i].daj_pas());
}

bool Kasyno::sprawdz_koniec(int _ilosc_graczy)
{
	int x = 0;
	for (int i = 0; i < _ilosc_graczy; i++)
	{
		if (this->gracze[i].daj_pas() == 1)
		{
			x++;
		}
	}
	if (x == _ilosc_graczy)
	{
		return 1;
	}
	return 0;
}

void Kasyno::wyswietl_wyniki(int _ilosc_graczy)
{
	Gracz* wyniki = nullptr;
	wyniki = new Gracz[_ilosc_graczy];
	Gracz pom;

	for (int i = 0; i < _ilosc_graczy; i++)
	{
		wyniki[i] = this->gracze[i];
	}
	
	for (int i = 0; i < _ilosc_graczy; i++)
	{
		for (int j = i; j < _ilosc_graczy - 1; j++)
		{
			if (wyniki[j].daj_wartosc() < wyniki[j + 1].daj_wartosc())
			{
				Gracz pom = wyniki[j];
				wyniki[j] = wyniki[j + 1];
				wyniki[j + 1] = pom;
			}
		}
	}

	for (int i = 0; i < _ilosc_graczy; i++)
	{
		if (this->gracze[i].daj_wartosc() == this->gracze[i + 1].daj_wartosc())
		{
			std::cout << "Remis " << this->gracze[i].daj_nazwe() << " i " << this->gracze[i + 1].daj_nazwe() << std::endl;
			break;
		}
		
		if (this->gracze[i].daj_wartosc() <= 21)
		{
			std::cout << "Wygrywa " << this->gracze[i].daj_nazwe() << ", z wynikiem " << this->gracze[i].daj_wartosc() << std::endl;
			break;
		}

		if (i == _ilosc_graczy - 1)
		{
			std::cout << "Wszyscy przegrali :(" << std::endl;
		}
	}
}

void Kasyno::zapisz(int _ilosc_graczy)
{
	std::ofstream plik;
	plik.open("wyniki.txt", std::ifstream::out);
	Karta reka_pom[10];
	for (int i = 0; i < _ilosc_graczy; i++)
	{
		*reka_pom = *this->gracze[i].daj_reke();
		plik << this->gracze[i].daj_nazwe();
		std::cout.setf(std::ios::internal);
		for (int j = 0; j < this->gracze[i].daj_karty_na_rece(); j++)
		{
			if (reka_pom[j].getKolor() == 3)
			{
				plik << "Kier ";
			}
			if (reka_pom[j].getKolor() == 4)
			{
				plik << "Karo ";
			}
			if (reka_pom[j].getKolor() == 5)
			{
				plik << "Trefl ";
			}
			if (reka_pom[j].getKolor() == 6)
			{
				plik << "Pik ";
			}

			plik << reka_pom[j].getFigura();
		}
		std::cout.unsetf(std::ios::internal);
		std::cout.setf(std::ios::right);
		plik << this->gracze[i].daj_wartosc() << std::endl;
		std::cout.unsetf(std::ios::right);
	}
	plik.close();
}

void Kasyno::wypisz_talie()
{
	for (int i = 0; i < 52; i++)
		std::cout << this->talia[i].getFigura() << this->talia[i].getKolor() << std::endl;
}
