#pragma once
#include <iostream>
#include <map>
#include <string>
#include <conio.h>
class plansza 
{
	public:
	void rysowanie_planszy();
	std::map<int, std::string> pola = { {1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"} };
	void ruch(int ruchGraczaPrim);
	bool czyWygrana();
	char czyjaTura();
};


