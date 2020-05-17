#include "Swiat.h"
#include "Organizmy.h"
#include "Czlowiek.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>
#include <string>
#include <fstream>

Swiat::Swiat(int const rozmiarX, int const rozmiarY): rozmiarX(rozmiarX), rozmiarY(rozmiarY)
{
	this->pole = new Organizm**[this->rozmiarY];
	for (int i = 0; i < this->rozmiarY; ++i) {
		this->pole[i] = new Organizm * [this->rozmiarX]{};
	}

	this->czlowiek = new Czlowiek(rand() % this->rozmiarY, rand() % this->rozmiarX);
	this->czlowiek->SetSwiat(this);

	this->pole[this->czlowiek->GetY()][this->czlowiek->GetX()] = this->czlowiek;

	zwierzeta.push_back(this->czlowiek);

	DodajOrganizmy();

	for (int i = 0; i < zwierzeta.size(); ++i) {
		zwierzeta[i]->SetSwiat(this);
	}

	for (int i = 0; i < rosliny.size(); ++i) {
		rosliny[i]->SetSwiat(this);
	}

	this->tura = 0;
	
	SortujZwierzeta();
	SortujRosliny();
}

void Swiat::Rysuj() {
	std::cout << "Piotr Wolinski - s180297\n";
	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			if (pole[i][j] != NULL) {
				//wywolaj metode danego organizmu
				pole[i][j]->Rysowanie();
			}
			else {
				std::cout << std::setw(2) << '.' << ' ';
			}
		}
		std::cout << std::endl;
	}
}

void Swiat::DodajOrganizmy() {
	for (int i = 0; i < this->rozmiarY; ++i) {
		for (int j = 0; j < this->rozmiarX; ++j) {
			if (this->pole[i][j] != NULL) continue;

			int rand1 = rand() % 100;
			if (rand1 < SPAWN_RATE_Z) {
				int rand2 = rand() % SUMA_ORGANIZMOW;
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
				case TRAWA:
					this->pole[i][j] = new Trawa(i, j);
					rosliny.push_back(this->pole[i][j]);
					break;
				case MLECZ:
					this->pole[i][j] = new Mlecz(i, j);
					rosliny.push_back(this->pole[i][j]);
					break;
				case GUARANA:
					this->pole[i][j] = new Guarana(i, j);
					rosliny.push_back(this->pole[i][j]);
					break;
				case WILCZE_JAGODY:
					this->pole[i][j] = new WilczeJagody(i, j);
					rosliny.push_back(this->pole[i][j]);
					break;
				case BARSZCZ_SOSNOWSKIEGO:
					this->pole[i][j] = new BarszczSosnowskiego(i ,j);
					rosliny.push_back(this->pole[i][j]);
					break;
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
		if (zwierzeta[i]->GetStatus()) {
			this->pole[zwierzeta[i]->GetY()][zwierzeta[i]->GetX()] = zwierzeta[i];
		}
	}

	for (int i = 0; i < rosliny.size(); ++i) {
		if (rosliny[i]->GetStatus()) {
			this->pole[rosliny[i]->GetY()][rosliny[i]->GetX()] = rosliny[i];
		}
	}
}

void Swiat::SortujRosliny() {
	if (rosliny.size() > 0) {
		for (int i = 0; i < rosliny.size() - 1; ++i) {
			for (int j = 0; j < rosliny.size() - i - 1; ++j) {
				if (rosliny[j]->GetWiek() < rosliny[j + 1]->GetWiek()) {
					std::swap(rosliny[j], rosliny[j + 1]);
				}
			}
		}
	}	
}

void Swiat::SortujZwierzeta() {
	if (zwierzeta.size() > 0) {
		for (int i = 0; i < zwierzeta.size() - 1; ++i) {
			for (int j = 0; j < zwierzeta.size() - i - 1; ++j) {
				if (zwierzeta[j]->GetInicjatywa() < zwierzeta[j + 1]->GetInicjatywa()) {
					std::swap(zwierzeta[j], zwierzeta[j + 1]);
				}
				else if (zwierzeta[j]->GetWiek() < zwierzeta[j + 1]->GetWiek() &&
					zwierzeta[j]->GetInicjatywa() == zwierzeta[j + 1]->GetInicjatywa()) {
					std::swap(zwierzeta[j], zwierzeta[j + 1]);
				}
			}
		}
	}	
}

void Swiat::DodajZwierze(std::string klasa, int const newY, int const newX) {

	Organizm* w = NULL;

	if (klasa == "Wilk") {							// dziecko to wilk
		w = new Wilk(newY, newX);
	}
	else if (klasa == "Owca") {						// dziecko to owca
		w = new Owca(newY, newX);
	}
	else if (klasa == "Lis") {						// dziecko to lis
		w = new Lis(newY, newX);
	}
	else if (klasa == "Zolw") {						// dziecko to zolw
		w = new Zolw(newY, newX);
	}
	else if (klasa == "Antylopa") {					// dziecko to antylopa
		w = new Antylopa(newY, newX);
	}

	if (w != NULL) {
		w->SetRozmnozylSie(true);
		w->SetSwiat(this);
		zwierzeta.push_back(w);
		SortujZwierzeta();
	}
}

void Swiat::DodajRosline(std::string klasa, int const newY, int const newX) {

	Organizm* w = NULL;

	if (klasa == "Trawa") {							// sadzi trawe
		w = new Trawa(newY, newX);
	}
	else if (klasa == "Mlecz") {					// sadzi mlecza
		w = new Mlecz(newY, newX);
	}
	else if (klasa == "Guarana") {					// sadzi guarane
		w = new Guarana(newY, newX);
	}
	else if (klasa == "WilczeJagody") {				// sadzi wilcze jagody
		w = new WilczeJagody(newY, newX);
	}
	else if (klasa == "BarszczSosnowskiego") {		// dziecko to barszcz sosnowskiego
		w = new BarszczSosnowskiego(newY, newX);
	}

	if (w != NULL) {
		w->SetRozmnozylSie(true);
		w->SetSwiat(this);
		rosliny.push_back(w);
		SortujRosliny();
	}
}


void Swiat::UsunMartwe() {
	for (int i = 0; i < zwierzeta.size(); ++i) {
		if (zwierzeta[i]->GetStatus() == false) {
			delete zwierzeta[i];
			zwierzeta.erase(zwierzeta.begin() + i);
		}
	}

	for (int i = 0; i < rosliny.size(); ++i) {
		if (rosliny[i]->GetStatus() == false) {
			delete rosliny[i];
			rosliny.erase(rosliny.begin() + i);
		}
	}
}

void Swiat::WykonajTure() {

	SortujZwierzeta();
	SortujRosliny();

	system("cls");

	for (int i = 0; i < zwierzeta.size(); ++i) {
		zwierzeta[i]->Akcja();

		UsunMartwe();

		OdswiezPole();
	}
	for (int i = 0; i < rosliny.size(); ++i) {
		rosliny[i]->Akcja();

		UsunMartwe();

		OdswiezPole();
	}

	Rysuj();

	Skomentuj();

	KolejnaTura();
}

void Swiat::Input() {
	char i = ' ';
	do {
		if (this->tura == 0) {
			std::cout << "Witam w projekcie pierwszym z Programowania Obiektowego. Ponizej krotki opis funkcjonalnosci:\n\n";
			std::cout << "\tt - przechodzi do nastepnej tury.\n\n";
			std::cout << "\tx - aktywuje specjalna umiejetnosc czlowieka.\n\n";
			std::cout << "\tq - wyjscie z symulacji.\n\n";
			std::cout << "\tp - wcisniecie p, a nastepnie podanie jednego z klawiszy wasd przypisze Czlowiekowi kierunek ruchu na najblizsza ture.\n\n";
			std::cout << "\tz - zapis aktualnego stanu symulacji do pliku.\n\n";
			std::cout << "\tc - wczytanie ostatniego zapisu symulacji i nadpisanie aktualnego stanu symulacji.\n\n";
			std::cout << "\tPoczatkowy stan planszy: \n\n";

			Rysuj();

			std::cout << "Nacisnij klawisz t i enter, zeby przejsc do symulacji\n";
		}

		i = ' ';
		while (i != 't') {

			std::cin >> i;

			if (i == 'p' && this->czlowiek->GetStatus() == true) {
				char tmp = ' ';
				std::cin >> tmp;

				dynamic_cast<Czlowiek*>(this->czlowiek)->SetInput(tmp);
			}
			else if (i == 'x') {
				dynamic_cast<Czlowiek*>(this->czlowiek)->Aktywuj();
			}
			else if (i == 'z') {
				Zapisz();
			}
			else if (i == 'q') break;
		}

		WykonajTure();
	} while (i != 'q');
}

int Swiat::SprawdzSilePola(int const Y, int const X) const {
	if (this->pole[Y][X] == NULL) {
		return 0;
	}
	else {
		return this->pole[Y][X]->GetSila();
	}
}

int Swiat::GetTura() const {
	return this->tura;
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

	for (int i = 0; i < zwierzeta.size(); ++i) {
		zwierzeta[i]->SetRozmnozylSie(false);
	}

	for (int i = 0; i < rosliny.size(); ++i) {
		rosliny[i]->SetRozmnozylSie(false);
	}
}

bool Swiat::SprawdzCzyWolne(int const Y, int const X) const {
	if (this->pole[Y][X] == NULL) {
		return true;
	} 
	else {
		return false;
	}
}

Organizm* Swiat::GetOrganizmNaPolu(int const Y, int const X) const {
	return this->pole[Y][X];
}

void Swiat::DodajKomentarz(std::string komentarz) {
	this->komentarze.push_back(komentarz);
}

void Swiat::Skomentuj() {
	for (int i = 0; i < komentarze.size(); ++i) {
		if (komentarze[i] != "") {
			std::cout << komentarze[i] << std::endl;
		}
	}

	komentarze.clear();
	komentarze.shrink_to_fit();
}

void Swiat::Zapisz() {
	std::ofstream out;
	out.open("zapis.txt");

	out << rozmiarY << " " << rozmiarX << tura << std::endl;

	out.close();
}

void Swiat::Wczytaj() {





}

Swiat::~Swiat() {
	for (int i = 0; i < zwierzeta.size(); ++i) {
		delete zwierzeta[i];
	}
	zwierzeta.clear();
	zwierzeta.shrink_to_fit();

	for (int i = 0; i < rosliny.size(); ++i) {
		delete rosliny[i];
	}
	rosliny.clear();
	rosliny.shrink_to_fit();

	komentarze.clear();
	komentarze.shrink_to_fit();

	for (int i = 0; i < rozmiarY; ++i) {
		delete[] pole[i];
	}
	delete[] pole;
}