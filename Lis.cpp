#include "Lis.h"
#include "Swiat.h"

#include <iostream>
#include <iomanip>

Lis::Lis(int Y, int X) {
	this->Y = Y;
	this->X = X;
	this->sila = 3;
	this->inicjatywa = 7;
	this->wiek = 1;
	this->zywy = true;
	this->rozmnozylSie = false;

	SetLastX(this->X);
	SetLastY(this->Y);
}

void Lis::Rysowanie() {
	std::cout << std::setw(2) << 'L' << ' ';
}

void Lis::Akcja() {
	bool moved = false;
	this->wiek++;

	SetLastX(this->X);
	SetLastY(this->Y);

	int moves = 0;

	while (!moved && moves != 4) {
		int dir = rand() % 4;
		if (dir == 0 && this->Y > 0) {											// w gore
			if (this->swiat->SprawdzSilePola(this->Y - 1, this->X) <= this->sila) {
				this->Y--;
				moved = true;
			}
			else {
				moves++;
			}
		}
		else if (dir == 1 && this->X < this->swiat->GetRozmiarX() - 1) {		// w prawo
			if (this->swiat->SprawdzSilePola(this->Y, this->X + 1) <= this->sila) {
				this->X++;
				moved = true;
			}
			else {
				moves++;
			}
		}
		else if (dir == 2 && this->Y < this->swiat->GetRozmiarY() - 1) {		// w dol
			if (this->swiat->SprawdzSilePola(this->Y + 1, this->X) <= this->sila) {
				this->Y++;
				moved = true;
			}
			else {
				moves++;
			}
		}
		else if (dir == 3 && this->X > 0) {										// w lewo
			if (this->swiat->SprawdzSilePola(this->Y, this->X - 1) <= this->sila) {
				this->X--;
				moved = true;
			}
			else {
				moves++;
			}
		}
	}

	if (!this->swiat->SprawdzCzyWolne(this->Y, this->X)) {
		this->swiat->GetOrganizmNaPolu(this->Y, this->X)->Kolizja(this);
	}
}