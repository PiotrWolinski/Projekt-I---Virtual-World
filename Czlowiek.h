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

	void SetStatus(bool status);

	void SetInput(char input);

	char GetInput() const;

	void SetUmiejetnosc(bool umiejetnosc);

	bool GetUmiejetnosc() const;

	void SetLastInput(char lastInput);

	char GetLastInput() const;

	void SetIleAktywna(int ileAktywna);

	int GetIleAktywna() const;

	void SetKiedyReset(int kiedyReset);

	int GetKiedyReset() const;

	std::string ToString() override;
};

