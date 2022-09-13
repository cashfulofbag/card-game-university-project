#include <fstream>
#include "Gracz.h"
#include "Karta.h"
#include "Kasyno.h"

class Kasyno;

Gracz::Gracz()
	:karty_na_rece(0)
	, wartosc_kart(0)
{

}

void Gracz::przypisz_do_kasyna(Kasyno* _kasyno)
{
	kasyno = _kasyno;
}

void Gracz::wezKarte(Karta* _karta)
{
	int wartosc;
	reka[karty_na_rece] = _karta;
	karty_na_rece++;
	this->wartosc_kart = this->wartosc_kart + _karta->getWartosc();
}

void Gracz::wyswietl_karty()
{
	for (int i = 0; i < this->karty_na_rece; i++)
		std::cout << this->reka[i].getFigura() << this->reka[i].getKolor() << std::endl;
}

void Gracz::zmien_nazwe()
{
	char pom[20];
	std::cout << "Jak chcesz sie nazywac" << std::endl;
	while (1)
	{
		std::cin >> pom;
		if (std::cin.fail() == true) 
		{
			std::cout << "wykryto blad" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		else break;
	}
	for (int i = 0; i < 20; i++)
	{
		this->nazwa[i] = pom[i];
	}
}

int Gracz::daj_wartosc()
{
	return(this->wartosc_kart);
}

void Gracz::pas()
{
	this->pasuj = 1;
}

bool Gracz::daj_pas()
{
	return this->pasuj;
}

void Gracz::wyswietl_mnie()
{
	int nic;
	std::cout << this->nazwa;
	std::cout << std::endl;
	this->wyswietl_karty();
	nic = this->daj_wartosc();
	std::cout << "Suma punktow:" << nic << std::endl;
}

char* Gracz::daj_nazwe()
{
	return this->nazwa;
}

int Gracz::daj_karty_na_rece()
{
	return this->karty_na_rece;
}

Karta* Gracz::daj_reke()
{
	return this->reka;
}

void decyzja()
{

}
