#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
public:
	Lis(int Y, int X);

	void Akcja() override;
};

