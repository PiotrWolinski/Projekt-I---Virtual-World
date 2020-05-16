#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Organizmy.h"
#include <typeinfo>

#include <iomanip>
#include <iostream>

BarszczSosnowskiego::BarszczSosnowskiego(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 10;
	this->inicjatywa = 0;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;
}

void BarszczSosnowskiego::Rysowanie() {
	std::cout << std::setw(2) << 'B' << ' ';
}

void BarszczSosnowskiego::Akcja() {

	std::string komentarz = "";

	if (this->Y > 0) {											// w gore
		if (!this->swiat->SprawdzCzyWolne(this->Y - 1, this->X) && 
			this->swiat->GetOrganizmNaPolu(this->Y - 1, this->X)->GetInicjatywa() != 0) {
			
			swiat->GetOrganizmNaPolu(this->Y - 1, this->X)->SetStatus(false);

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zabil "
				+ GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y - 1, this->X))).name())
				+ " na polu " + std::to_string(this->X) + ' ' + std::to_string(this->Y - 1);

			/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " zabil " 
				<< GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y - 1, this->X))).name()) 
				<< " na polu " << this->X << ' ' << this->Y - 1 << '\n';*/
		}
	}
	if (this->X < this->swiat->GetRozmiarX() - 1 ) {		// w prawo
		if (!this->swiat->SprawdzCzyWolne(this->Y, this->X + 1) && 
			this->swiat->GetOrganizmNaPolu(this->Y, this->X + 1)->GetInicjatywa() != 0){
			
			swiat->GetOrganizmNaPolu(this->Y, this->X + 1)->SetStatus(false);

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zabil "
				+ GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y, this->X + 1))).name())
				+ " na polu " + std::to_string(this->X + 1) + ' ' + std::to_string(this->Y);
			
			/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " zabil "
				<< GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y, this->X + 1))).name()) 
				<< " na polu " << this->X + 1 << ' ' << this->Y << '\n';*/
		}
	}
	if (this->Y < this->swiat->GetRozmiarY() - 1) {		// w dol
		if (!this->swiat->SprawdzCzyWolne(this->Y + 1, this->X) && this->swiat->GetOrganizmNaPolu(this->Y + 1, this->X)->GetInicjatywa() != 0) {
			
			swiat->GetOrganizmNaPolu(this->Y + 1, this->X)->SetStatus(false);

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zabil "
				+ GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y + 1, this->X))).name())
				+ " na polu " + std::to_string(this->X) + ' ' + std::to_string(this->Y + 1);
			
			/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " zabil "
				<< GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y + 1, this->X))).name()) << " na polu " << this->X << ' ' << this->Y << '\n';*/
		}
	}
	if (this->X > 0) {										// w lewo
		if (!this->swiat->SprawdzCzyWolne(this->Y, this->X - 1) && this->swiat->GetOrganizmNaPolu(this->Y, this->X - 1)->GetInicjatywa() != 0) {
			
			swiat->GetOrganizmNaPolu(this->Y, this->X - 1)->SetStatus(false);

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zabil "
				+ GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y, this->X - 1))).name())
				+ " na polu " + std::to_string(this->X - 1) + ' ' + std::to_string(this->Y);
			
			/*std::cout << GetNazwaKlasy(typeid(*this).name()) << " zabil "
				<< GetNazwaKlasy(typeid(*(this->swiat->GetOrganizmNaPolu(this->Y, this->X - 1))).name()) << " na polu " << this->X << ' ' << this->Y << '\n';*/
		}
	}

	this->swiat->DodajKomentarz(komentarz);

	this->swiat->OdswiezPole();

	int rozmnoz_sie = rand() % 100;

	if (rozmnoz_sie < SPAWN_RATE_R) {

		int newX = this->X;
		int newY = this->Y;

		int dir = rand() % 4;
		bool zasiane = false;
		int tmp = dir;

		do {
			if (dir == 0) {
				if (this->Y > 0 && this->swiat->SprawdzCzyWolne(this->Y - 1, this->X)) {										// sprawdzam gore
					newY--;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 1) {
				if (this->X < this->swiat->GetRozmiarX() - 1 && this->swiat->SprawdzCzyWolne(this->Y, this->X + 1)) {		// sprawdzam prawo
					newX++;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 2) {

				if (this->Y < this->swiat->GetRozmiarY() - 1 && this->swiat->SprawdzCzyWolne(this->Y + 1, this->X)) {		// sprawdzam dol
					newY++;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
			else if (dir == 3) {
				if (this->X > 0 && this->swiat->SprawdzCzyWolne(this->Y, this->X - 1)) {									// sprawdzam lewo
					newX--;
					zasiane = true;
				}
				else {
					dir = (++dir) % 4;
				}
			}
		} while (!zasiane && dir != tmp);

		if (zasiane && this->rozmnozylSie == false) {
			this->swiat->DodajRosline(this->GetNazwaKlasy(typeid(*this).name()), newY, newX);

			komentarz = GetNazwaKlasy(typeid(*this).name()) + " zasial dziecko na polu "
				+ std::to_string(newX) + ' ' + std::to_string(newY);

			//std::cout << GetNazwaKlasy(typeid(*this).name()) << " zasial dziecko na polu " << newX << ' ' << newY << '\n';

			this->swiat->DodajKomentarz(komentarz);
		}
	}


}

void BarszczSosnowskiego::Kolizja(Organizm* atakujacy) {

	std::string na_polu = GetNazwaKlasy(typeid(*this).name());

	std::string wchodzacy = GetNazwaKlasy(typeid(*atakujacy).name());

	std::string komentarz = "";

	komentarz = wchodzacy + " probowal zjesc i nie dal rady " + na_polu + " na polu " 
		+ std::to_string(this->GetX()) + " " + std::to_string(this->GetY());

	atakujacy->SetStatus(false);
	//std::cout << wchodzacy << " probowal zjesc i nie dal rady " << na_polu << " na polu " << this->GetX() << ' ' << this->GetY() << '\n';

	this->swiat->DodajKomentarz(komentarz);
}