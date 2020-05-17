#include "Czlowiek.h"
#include "Swiat.h"

#include <iostream>
#include <iomanip>
#include <string>

Czlowiek::Czlowiek(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 5;
	this->inicjatywa = 4;
	this->wiek = 1;
	this->zywy = true;
	this->lastX = X;
	this->lastY = Y;
	this->rozmnozylSie = false;
	this->umiejetnosc = false;
	this->ileAktywna = 0;
	this->kiedyReset = 0;
	this->lastInput = ' ';
	this->input = ' ';
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

void Czlowiek::Rysowanie() {
	std::cout << std::setw(2) << 'C' << ' ';
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

		std::string komentarz = "Moja specjalna umiejetnosc jest teraz aktywna i bedzie jeszcze przez " + std::to_string(ileAktywna) + " tury!";

		this->swiat->DodajKomentarz(komentarz);

		if (ileAktywna == 0) {
			umiejetnosc = false;
			kiedyReset = 5;
		}
	}
	else {
		if (kiedyReset > 0) kiedyReset--;
	}
}

void Czlowiek::SetInput(char input) {
	this->input = input;
}

char Czlowiek::GetInput() const {
	return this->input;
}

void Czlowiek::Aktywuj() {
	if (ileAktywna == 0 && kiedyReset == 0) {
		umiejetnosc = true;
		ileAktywna = 5;
	}
}

void Czlowiek::Ruch(char dir) {
	switch (dir) {
	case 'w':
		if (this->Y > 0) {
			this->Y--;
		}
		break;
	case 'd':
		if (this->X < this->swiat->GetRozmiarX() - 1) {
			this->X++;
		}
		break;
	case 's':
		if (this->Y < this->swiat->GetRozmiarY() - 1) {
			this->Y++;
		}
		break;
	case 'a':
		if (this->X > 0) {
			this->X--;
		}
		break;
	}
}