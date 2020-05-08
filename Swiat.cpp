#include "Swiat.h"
#include <iostream>
#include <iomanip>

Swiat::Swiat(const int rozmiarX, const int rozmiarY): rozmiarX(rozmiarX), rozmiarY(rozmiarY)
{
}

void Swiat::Rysuj() {
	system("cls");
	std::cout << "Piotr Wolinski - s180297\n";
	for (int i = 0; i < this->rozmiarY + 2; ++i) {
		for (int j = 0; j < this->rozmiarX + 2; ++j) {
			if (i == 0 || j == 0 || i == this->rozmiarY + 1 || j == this->rozmiarX + 1) {
				std::cout << std::setw(2) << '#' << ' ';
			}
			else {
				std::cout << std::setw(2) << '.' << ' ';
			}
		}
		std::cout << std::endl;
	}
}
