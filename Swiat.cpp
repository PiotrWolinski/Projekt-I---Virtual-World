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

	for (int i = 0; i < zwierzeta.size(); ++i) {
		zwierzeta[i]->SetSwiat(this);
	}

	this->tura = 0;
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
	srand(time(NULL));
	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			int rand1 = rand() % 100;
			if (rand1 < SPAWN_RATE) {
				int rand2 = rand() % SUMA_ORGANIZMOW / 2;
				switch (rand2) {
				case WILK:
					this->pole[i][j] = new Wilk(i, j);
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case OWCA:
					this->pole[i][j] = new Owca(i, j);
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case LIS:
					this->pole[i][j] = new Lis(i, j);
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case ZOLW:
					this->pole[i][j] = new Zolw(i ,j);
					zwierzeta.push_back(this->pole[i][j]);
					break;
				case ANTYLOPA:
					this->pole[i][j] = new Antylopa(i ,j);
					zwierzeta.push_back(this->pole[i][j]);
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

void Swiat::OdswiezPole() {

	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			this->pole[i][j] = NULL;
		}
	}

	for (int i = 0; i < zwierzeta.size(); ++i) {
		this->pole[zwierzeta[i]->GetY()][zwierzeta[i]->GetX()] = zwierzeta[i];
	}

}

void Swiat::WykonajTure() {
	for (int i = 0; i < zwierzeta.size(); ++i) {
		zwierzeta[i]->Akcja();
	}

	OdswiezPole();
}

void Swiat::Input() {
	char i = ' ';
	do {
		if (i == 'q') break;

		system("cls");
		Rysuj();
		WykonajTure();


	
	} while (std::cin >> i);

}

int Swiat::GetRozmiarX() const {
	return this->rozmiarX;
}

int Swiat::GetRozmiarY() const {
	return this->rozmiarY;
}

void Swiat::SetRozmiarX(const int X) {
	this->rozmiarX = X;
}

void Swiat::SetRozmiarY(const int Y) {
	this->rozmiarY = Y;
}