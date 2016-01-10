#include "stdafx.h"
#include "Wektor.h"
#include "stdafx.h"
#include <vector>
#include <cstdarg>
#include <iostream>
using namespace std;

Wektor::Wektor()
{
}

Wektor::Wektor(char* nr)
{
	cout << "TWORZENIE WEKTORA "<<nr<<"\nPodaj wymiar:\n";
	cin >> wymiar;
	cout << "Podaj " << wymiar << " wspolrzednych:\n";
	double temp;
	for (int i = 0; i < wymiar; i++)
	{
		cin >> temp;
		w.push_back(temp);
	}
}

Wektor::Wektor(int wymiar)
{
	this->wymiar = wymiar;
	for (int i = 0; i < wymiar; i++) w.push_back(0.0);

}

Wektor::Wektor(unsigned int wymiar, ...)
{
	this->wymiar = wymiar;
	va_list argument;
	va_start(argument, wymiar);

	for (int i = 0; i < wymiar; i++)
		w.push_back(va_arg(argument, double));

	va_end(argument);
}

void Wektor::wyswietl_wektor()
{
	cout << "[ ";
	for (int i = 0; i < (this->w).size(); i++)
	{
		if (i == this->w.size() - 1)	cout << w[i] << " ]";
		else							cout << w[i] << "; ";
	}
}

unsigned int Wektor::zwroc_wymiar()
{
	return this->w.size();
}

void Wektor::dodaj_wektory(Wektor & w1, Wektor & w2, Wektor & w3)
{
		w3.wymiar = w1.zwroc_wymiar();
		for (int i = 0; i < w3.wymiar; i++)
		{
			w3.w[i] = w1.w[i] + w2.w[i];
		}
};

void Wektor::odejmij_wektory(Wektor & w1, Wektor & w2, Wektor & w3)
{
	w3.wymiar = w1.zwroc_wymiar();
	for (int i = 0; i < w3.wymiar; i++)
	{
		w3.w[i]=w1.w[i] - w2.w[i];
	}
};

void Wektor::pomnoz_wektory(Wektor & w1, Wektor & w2, Wektor & w3)
{
	w3.wymiar = w1.zwroc_wymiar();
	for (int i = 0; i < w3.wymiar; i++)
	{
		w3.w[i] = w1.w[i] * w2.w[i];
	}
};

double Wektor::iloczyn_skalarny(Wektor & w1, Wektor & w2)
{
	double skalarny = 0;
	for (int i = 0; i < w1.wymiar; i++)
	{
		skalarny += w1.w[i] * w2.w[i];
	}
	return skalarny;
};

double Wektor::dlugosc_wektora()
{
	double dlugosc = 0;
	for (int i = 0; i < this->wymiar; i++)
	{
		dlugosc += this->w[i] * this->w[i];
	}
	return sqrt(dlugosc);
};

double Wektor::dlugosc_wektora(Wektor & w1)
{
	double dlugosc = 0;
	for (int i = 0; i < this->wymiar; i++)
	{
		dlugosc += w1.w[i] * w1.w[i];
	}
	return sqrt(dlugosc);
};

double Wektor::kat_pomiedzy_wektorami(Wektor & w1, Wektor & w2)
{
	if (w1.wymiar != w2.wymiar || w1.wymiar != 2) return -1;
	double l1 = dlugosc_wektora(w1);
	double l2 = dlugosc_wektora(w2);
	double kat = iloczyn_skalarny(w1, w2);
	kat /= (l1*l2);
	return acos(kat) * 180 / 3.14159265359;
}

Wektor::~Wektor()
{
}