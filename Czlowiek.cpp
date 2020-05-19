#include "Czlowiek.h"
#include "Swiat.h"

#include <iostream>
#include <iomanip>
#include <string>

Czlowiek::Czlowiek(int Y, int X) {
	this->symbol = 'C';
	this->Y = Y;
	this->X = X;
	this->sila = 5;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->stan = true;
	this->lastX = X;
	this->lastY = Y;
	this->rozmnozylSie = false;
	this->umiejetnosc = false;
	this->ileAktywna = 0;
	this->kiedyReset = 0;
	this->lastInput = ' ';
	this->input = ' ';
}

void Czlowiek::Rysowanie() {
	std::cout << std::setw(2) << this->symbol << ' ';
}

void Czlowiek::Akcja(char input) {
	
	Ruch(input);

	if (input != ' ') {
		this->lastInput = input;
	}

	Umiejetnosc();

	if (!this->swiat->SprawdzCzyWolne(this->Y, this->X)) {
		this->swiat->GetOrganizmNaPolu(this->Y, this->X)->Kolizja(this);
	}
}

void Czlowiek::Akcja() {
	Akcja(this->GetInput());
	this->SetInput(' ');
}

void Czlowiek::Umiejetnosc() {
	if (umiejetnosc) {

		if (ileAktywna > 2) {
			Ruch(lastInput);
		}
		else {
			int chance = rand() % 2;
			if (chance == 0) {
				Ruch(lastInput);
			}
		}
		
		ileAktywna--;

		std::string komentarz = "Moja specjalna umiejetnosc jest teraz aktywna i bedzie jeszcze przez " 
			+ std::to_string(ileAktywna) + " tury!";

		this->swiat->DodajKomentarz(komentarz);

		if (ileAktywna == 0) {
			umiejetnosc = false;
			kiedyReset = TUR_DO_RESETU_UMIEJETNOSCI;
		}
	}
	else {
		if (kiedyReset > 0) kiedyReset--;
	}
}

void  Czlowiek::SetStatus(bool status) {
	this->stan = status;
}

void Czlowiek::SetInput(char input) {
	this->input = input;
}

char Czlowiek::GetInput() const {
	return this->input;
}

void Czlowiek::SetUmiejetnosc(bool umiejetnosc) {
	this->umiejetnosc = umiejetnosc;
}

bool Czlowiek::GetUmiejetnosc() const {
	return this->umiejetnosc;
}

void Czlowiek::SetLastInput(char lastInput) {
	this->lastInput = lastInput;
}

char Czlowiek::GetLastInput() const {
	return this->lastInput;
}

void Czlowiek::SetIleAktywna(int ileAktywna) {
	this->ileAktywna = ileAktywna;
}

int Czlowiek::GetIleAktywna() const {
	return this->ileAktywna;
}

void Czlowiek::SetKiedyReset(int kiedyReset) {
	this->kiedyReset = kiedyReset;
}

int Czlowiek::GetKiedyReset() const {
	return this->kiedyReset;
}

void Czlowiek::Aktywuj() {
	if (ileAktywna == 0 && kiedyReset == 0) {
		umiejetnosc = true;
		ileAktywna = CZAS_DZIALANIA_UMIEJETNOSCI;
	}
}

void Czlowiek::Ruch(char dir) {
	switch (dir) {
	case DO_GORY:
		if (this->Y > 0) {
			this->Y--;
		}
		break;
	case W_PRAWO:
		if (this->X < this->swiat->GetRozmiarX() - 1) {
			this->X++;
		}
		break;
	case W_DOL:
		if (this->Y < this->swiat->GetRozmiarY() - 1) {
			this->Y++;
		}
		break;
	case W_LEWO:
		if (this->X > 0) {
			this->X--;
		}
		break;
	}
}

std::string Czlowiek::ToString() {
	std::string out;
	out = std::to_string(symbol) + " " + std::to_string(X) + " " + std::to_string(Y) + " " + std::to_string(sila) + " "
		+ std::to_string(wiek) + " " + std::to_string(lastX) + " " + std::to_string(lastY) + " " + std::to_string(stan) + " " 
		+ std::to_string(rozmnozylSie) + " " + std::to_string(umiejetnosc) + " " + std::to_string(ileAktywna) + " " 
		+ std::to_string(kiedyReset) + " " + std::to_string(lastInput) + " " + std::to_string(input);
	return out;
}