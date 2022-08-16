#pragma once
#pragma once

/*
OZNACZENIA P�L:
0 - pole puste
1 - statek jednokor�rkowy
2 - statek dw�kom�rkowy
3 - statek tr�jkom�rkowy
4 - statek czterokom�rkowy
5 - kra�ce planszy
6 - pole otoczenia
*/

extern char plansza[12][12];
extern char strzaly[11][11];

extern int zycie[5];
extern int ilosc_statkow[5];


//---------------------INTERFEJS------------------------
void wypisywanie_strzalow();
void wypisywanie_pozycji_statkow();


//---------------------GENEROWANIE MAPY------------------------
void wyznaczanie_otoczenia_statku(int ilu_komorkowy, int x_poczatokwy, int y_poczatkowy, int kierunek);
int sprawdzanie_kierunku_czterokomorkowca(int wiersz, int kolumna);
void generowanie_czterokomorkowca();
int sprawdzanie_kierunku_trojkomorkowca(int wiersz, int kolumna);
void generowanie_trojkomorkowca();
int sprawdzanie_kierunku_dwukomorkowca(int wiersz, int kolumna);
void generowanie_dwukomorkowca();
void generowanie_jednokomorkowca();




//---------------------FUNKCJE OBS�UGUJ�CE GR�------------------------
void zczytywanie_wspolrzednych(int* wiersz_ost, int* kolumna_ost);
void rezultat_strzalu(int* wiersz_ost, int* kolumna_ost);
void ile_zostalo();
void poczatek_gry();
void koniec_gry(int licznik);