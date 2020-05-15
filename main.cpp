#include <iostream> 
#include "Swiat.h"
#include <ctime>

#define SIZE 10

int main() {
	srand(time(NULL));
	Swiat swiat(SIZE, SIZE);
	swiat.Input();

	return 0;
}