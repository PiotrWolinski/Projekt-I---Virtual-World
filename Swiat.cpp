#include "Swiat.h"
#include "Organizmy.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>


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
				/*case TRAWA:
					this->pole[i][j] = new Wilk();
					break;
				case MLECZ:
					this->pole[i][j] = new Wilk();
					break;
				case GUARANA:
					this->pole[i][j] = new Wilk();
					break;
				case WILCZE_JAGODY:
					this->pole[i][j] = new Wilk();
					break;
				case BARSZCZ_SOSNOWSKIEGO:
					this->pole[i][j] = new Wilk();
					break;*/
				}

			}
		}
	}

}

// metoda zmienia wskazniki na polu
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

void Swiat::SortujRosliny() {
	for (int i = 0; i < rosliny.size(); ++i) {
		for (int j = 0; j < rosliny.size(); ++j) {
			if (rosliny[i]->GetWiek() < rosliny[j]->GetWiek()) {
				std::swap(rosliny[i], rosliny[j]);
			}
		}
	}
}

void Swiat::SortujZwierzeta() {
	for (int i = 0; i < zwierzeta.size(); ++i) {
		for (int j = 0; j < zwierzeta.size(); ++j) {
			if (zwierzeta[i]->GetInicjatywa() < zwierzeta[j]->GetInicjatywa()) {
				std::swap(zwierzeta[i], zwierzeta[j]);
			}
			else if (zwierzeta[i]->GetWiek() < zwierzeta[j]->GetWiek()) {
				std::swap(zwierzeta[i], zwierzeta[j]);
			}
		}
	}
}

void Swiat::SortujOrganizmy() {
	SortujRosliny();
	SortujZwierzeta();
}

void Swiat::UsunMartwe() {
	for (int i = 0; i < zwierzeta.size(); ++i) {
		if (zwierzeta[i]->GetStatus() == false) {
			zwierzeta.erase(zwierzeta.begin() + i);
		}
	}

	for (int i = 0; i < rosliny.size(); ++i) {
		if (rosliny[i]->GetStatus() == false) {
			rosliny.erase(rosliny.begin() + i);
		}
	}
}

void Swiat::WykonajTure() {

	SortujOrganizmy();

	system("cls");

	Rysuj();

	if (this->tura != 0) {

		for (int i = 0; i < zwierzeta.size(); ++i) {
			zwierzeta[i]->Akcja();

			if (pole[zwierzeta[i]->GetY()][zwierzeta[i]->GetX()] != NULL) {
				pole[zwierzeta[i]->GetY()][zwierzeta[i]->GetX()]->Kolizja(zwierzeta[i]);
			}
		}
	}

	
	UsunMartwe();

	OdswiezPole();
	KolejnaTura();
}

void Swiat::Input() {
	char i = ' ';
	do {
		if (i == 'q') break;

		WykonajTure();
	
	} while (std::cin >> i);
}

int Swiat::SprawdzSilePola(int const Y, int const X) {
	if (this->pole[Y][X] == NULL) {
		return 0;
	}
	else {
		return this->pole[Y][X]->GetSila();
	}
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

void Swiat::KolejnaTura() {
	this->tura++;
}