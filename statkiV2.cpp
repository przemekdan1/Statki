#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "funkcje.h"

char plansza[12][12] =
{
    {'5','5','5','5','5','5','5','5','5','5','5','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','0','0','0','0','0','0','0','0','0','0','5'},
    {'5','5','5','5','5','5','5','5','5','5','5','5'}

};
char strzaly[11][11] =
{
    {'5','5','5','5','5','5','5','5','5','5','5'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},
    {'5','0','0','0','0','0','0','0','0','0','0'},

};

int zycie[5] = { 0,1,2,3,4 };
/*
    zycie[0] - puste
    zycie[1] - jednokomorkowe
    zycie[2] - dwukomorkowe
    zycie[3] - trojkomorkowe
    zycie[4] - czterokomorkowe

    Ilosc potrzebnych trafien do zatopienia danego typu statku
*/
int ilosc_statkow[5] = { 0,4,3,2,1 };
/*
    zycie_statku[0] - puste
    zycie_statku[1] - jednokomorkowe
    zycie_statku[2] - dwukomorkowe
    zycie_statku[3] - trojkomorkowe
    zycie_statku[4] - czterokomorkowe

    Gra do momentu zatopienia wszystkich typow statkow
*/


int main()
{
    int i, kolumna_ost = 0, wiersz_ost = 0, licznik = 0;

    poczatek_gry();

    generowanie_czterokomorkowca();
    for (i = 0; i < 2; i++) generowanie_trojkomorkowca();
    for (i = 0; i < 3; i++) generowanie_dwukomorkowca();
    for (i = 0; i < 4; i++) generowanie_jednokomorkowca();
    //wypisywanie_pozycji_statkow();


    while (ilosc_statkow[1] > 0 || ilosc_statkow[2] > 0 || ilosc_statkow[3] > 0 || ilosc_statkow[4] > 0)
    {
        //wypisywanie_pozycji_statkow();
        wypisywanie_strzalow();
        ile_zostalo();
        zczytywanie_wspolrzednych(&wiersz_ost, &kolumna_ost);
        licznik++;
        system("cls");
        rezultat_strzalu(&wiersz_ost, &kolumna_ost);
    }
    system("cls");
    koniec_gry(licznik);

    return 0;
}

