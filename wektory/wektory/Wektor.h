#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>
using namespace std;

class Wektor
{
private:
	vector <double> w;
	unsigned int wymiar;

public:
	Wektor();
	Wektor(unsigned int, ...);
	Wektor(int);
	Wektor(char* nr);

	void wyswietl_wektor();
	unsigned int zwroc_wymiar();

	void dodaj_wektory(Wektor &, Wektor &, Wektor &);
	void odejmij_wektory(Wektor &, Wektor &, Wektor &);
	void pomnoz_wektory(Wektor &, Wektor &, Wektor &);
	double dlugosc_wektora();
	double dlugosc_wektora(Wektor &);
	double iloczyn_skalarny(Wektor & w1, Wektor & w2);
	double kat_pomiedzy_wektorami(Wektor &, Wektor &);

	~Wektor();
};