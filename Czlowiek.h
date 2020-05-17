#pragma once
#include "Zwierze.h"
class Czlowiek :
	public Zwierze
{
private:
	bool umiejetnosc;
	int ileAktywna;
	int kiedyReset;
	char lastInput;
	char input;
public:
	Czlowiek(int Y, int X);

	void Akcja();

	void Akcja(char input);

	void Rysowanie();

	void Umiejetnosc();

	void Aktywuj();

	void Ruch(char dir);

	void SetInput(char input);

	char GetInput() const;
};

