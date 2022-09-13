#include <iostream>
#include "Karta.h"
#include "Kasyno.h"
#include "Gracz.h"
#include <windows.h>
#include <fstream>

void sprawdz()
{
	if (std::cin.fail() == true) 
	{
		std::cout << "wykryto blad" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
}

void main()
{
	Kasyno kasyno1;
	int wyb = 0;
	int ludzie, boty, x;
	int wydane_karty = 0;
	bool koniec = 0;


	while (wyb < 9)
	{
		std::cout << "Menu" << std::endl;
		std::cout << "1.Zacznij gre" << std::endl;
		std::cout << "9.Wyjdz" << std::endl;
		std::cin >> wyb;
		sprawdz();
		switch (wyb)
		{
		case 1:
			std::cout << "Podaj ilosc graczy ludzkich" << std::endl;
			while (1)
			{
				std::cin >> ludzie;
				if (std::cin.fail() == true)
				{
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			std::cout << "Podaj ilosc botow" << std::endl;
			while (1)
			{
				std::cin >> boty;
				if (std::cin.fail() == true)
				{
					std::cout << "wykryto blad" << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
				}
				else break;
			}
			if (ludzie + boty <= 6 && ludzie > 0 && boty <= 3 && ludzie <= 3)
			{
				kasyno1.tasuj();
				int ilosc_graczy = boty + ludzie;
				kasyno1.dodaj_graczy(ilosc_graczy, ludzie);
				for (int i = 0; i < ilosc_graczy; i++)
				{
					for (int j = 0; j < 2; j++)
					{
						kasyno1.dajKarte(wydane_karty, i);
						wydane_karty++;
					}
				}

				//kasyno1.wypisz_talie();

				while (koniec == 0)
				{
					for (int i = 0; i < ilosc_graczy; i++)
					{

						system("cls");
						int decyzja = 0;
						if (kasyno1.sprawdz_pas(i) == 0)
						{

							kasyno1.wyswietl_gracza(i);
							std::cout << "1. Dobeirz karte" << std::endl;
							std::cout << "2. Pasuj" << std::endl;
							while (decyzja != 9)
							{
								std::cin >> decyzja;
								sprawdz();
								switch (decyzja)
								{
								case 1:
									kasyno1.dajKarte(wydane_karty, i);
									wydane_karty++;
									x = kasyno1.sprawdz_wartosc(i);
									if (x > 21)
									{
										kasyno1.g_pasuj(i);
									}
									decyzja = 9;
									break;
								case 2:
									kasyno1.g_pasuj(i);
									decyzja = 9;
									break;
								default:
									kasyno1.g_pasuj(i);
									decyzja = 9;
									break;
								}

							}
						}

						koniec = kasyno1.sprawdz_koniec(ilosc_graczy);
					}
				}

				system("cls");
				kasyno1.wyswietl_wyniki(ilosc_graczy);
				kasyno1.zapisz(ilosc_graczy);
				kasyno1.nowa_talia();
				std::cout << "Zrobione" << std::endl;

			}
			else
			{
				std::cout << "Podano niewlasciwa liczbe graczy. Maksymalna liczba graczy to 3, jeden z graczy musi byc czlowiekiem" << std::endl;
			}
			
			break;
		case 9:
			break;
		default:
			break;
		}

	}
}