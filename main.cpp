#include <iostream> 
#include "Swiat.h"
#include <ctime>

int main() {
	srand(time(NULL));

	std::cout << "Witam w projekcie pierwszym z Programowania Obiektowego. Ponizej krotki opis funkcjonalnosci:\n\n";
	std::cout << "\tt - przechodzi do nastepnej tury.\n\n";
	std::cout << "\tx - aktywuje specjalna umiejetnosc czlowieka.\n\n";
	std::cout << "\tq - wyjscie z symulacji.\n\n";
	std::cout << "\tp - wcisniecie p, a nastepnie uzycie strzalek przypisze Czlowiekowi kierunek ruchu na najblizsza ture.\n\n";
	std::cout << "\tz - zapis aktualnego stanu symulacji do pliku.\n\n";
	std::cout << "\tc - wczytanie ostatniego zapisu symulacji i nadpisanie aktualnego stanu symulacji.\n\n";
	std::cout << "W celu rozpoczecia symulacji prosze podac szerokosc i wysokosc planszy: ";
	int szerokosc = 0;
	int wysokosc = 0;
	std::cin >> szerokosc >> wysokosc;

	Swiat swiat(wysokosc, szerokosc);
	swiat.Symuluj();

	return 0;
}