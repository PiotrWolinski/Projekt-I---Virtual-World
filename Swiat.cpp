#include "Swiat.h"
#include "Organizmy.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

Swiat::Swiat(const int rozmiarX, const int rozmiarY): rozmiarX(rozmiarX), rozmiarY(rozmiarY)
{
	this->pole = new Organizm**[this->rozmiarY];
	for (int i = 0; i < this->rozmiarY; ++i) {
		this->pole[i] = new Organizm * [this->rozmiarX]{};
	}
	DodajZwierzeta();
}

void Swiat::Rysuj() {
	std::cout << "Piotr Wolinski - s180297\n";
	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			if (pole[i][j] != NULL) {
				//wywolaj metode danego zwierzatka
				pole[i][j]->Rysowanie();
			}
			else {
				std::cout << std::setw(2) << '.' << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void Swiat::DodajZwierzeta() {
	pole[3][6] = new Wilk();
	srand(time(NULL));
	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			int rand1 = rand() % 100;
			if (rand1 < SPAWN_RATE) {	//20% szans na dodanie jakiegoœ organizmu - typ losowany w dalszej czêœci
				int rand2 = rand() % SUMA_ORGANIZMOW;
				switch (rand2) {
				case WILK:
					this->pole[i][j] = new Wilk();
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case OWCA:
					this->pole[i][j] = new Owca();
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case LIS:
					this->pole[i][j] = new Lis();
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case ZOLW:
					this->pole[i][j] = new Zolw();
					break;
				case ANTYLOPA:
					this->pole[i][j] = new Antylopa();
					break;
				/*case WILK:
					this->pole[i][j] = new Wilk();
					break;
				case WILK:
					this->pole[i][j] = new Wilk();
					break;
				case WILK:
					this->pole[i][j] = new Wilk();
					break;
				case WILK:
					this->pole[i][j] = new Wilk();
					break;
				case WILK:
					this->pole[i][j] = new Wilk();
					break;*/
				}

			}
		}
	}

}



void Swiat::WykonajTure() {

}

void Swiat::Input() {
	char i = ' ';
	do {
		if (i == 'q') break;
		system("cls");
		Rysuj();
	} while (std::cin >> i);

}
