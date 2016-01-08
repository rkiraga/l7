// wektory.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include<iostream>
#include "Wektor.h"
using namespace std;

int main()
{
	
	Wektor w1("1"), w2("2");

	if (w1.zwroc_wymiar() != w2.zwroc_wymiar()) cout << "Niezgodnie wymiary, nie moge przeprowadzic dzialan na wektorach!\n";
	else
	{
	Wektor w3(w1.zwroc_wymiar());
	w3.dodaj_wektory(w1, w2, w3);
	cout << "\nPO DODANIU:\n";
	w3.wyswietl_wektor();

	w3.odejmij_wektory(w1, w2, w3);
	cout << "\nPO ODJECIU:\n";
	w3.wyswietl_wektor();

	w3.pomnoz_wektory(w1, w2, w3);
	cout << "\nPO POMNOZENIU:\n";
	w3.wyswietl_wektor();

	cout << "\nKAT POMIEDZY:\n";
	cout<< w3.kat_pomiedzy_wektorami(w1, w2)<<endl;
	}

    return 0;
}

