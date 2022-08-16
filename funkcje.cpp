#include "funkcje.h"

#include "funkcje.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


void wypisywanie_strzalow()
{
    int i, j;


    printf("  |");
    for (i = int('A'); i <= int('J'); i++) printf(" %c |", char(i));
    printf("\n---");
    for (i = int('A'); i <= int('J'); i++) printf("----");
    printf("\n");

    for (i = 1; i <= 9; i++)
    {
        printf("%d |", i);
        for (j = 1; j <= 10; j++)
        {
            if (strzaly[i][j] == '0') printf("   |");
            else if (strzaly[i][j] == '2') printf(" # |");
            else printf(" x |");
        }
        printf("\n");
    }
    printf("%d|", 10);
    for (j = 1; j <= 10; j++)
    {

        if (strzaly[10][j] == '0') printf("   |");
        else if (strzaly[10][j] == '2') printf(" # |");
        else printf(" x |");
    }
}

void wypisywanie_pozycji_statkow()
{
    int i, j;
    printf("Pomoc:\n");
    printf("    ");
    for (i = int('A'); i <= int('J'); i++) printf("%c ", char(i));
    printf("\n");

    for (i = 1; i < 11; i++)
    {
        if (i != 10) printf("%d | ", i);
        else printf("%d| ", i);
        for (j = 1; j < 11; j++)
        {
            if (plansza[i][j] != '0' && plansza[i][j] != '6')
                printf("%c ", plansza[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}

void wyznaczanie_otoczenia_statku(int ilu_komorkowy, int x_poczatokwy, int y_poczatkowy, int kierunek)
{
    int i;
    if (kierunek == 1)
    {
        if (plansza[x_poczatokwy + 1][y_poczatkowy] == '0') plansza[x_poczatokwy + 1][y_poczatkowy] = '6';
        if (plansza[x_poczatokwy - ilu_komorkowy][y_poczatkowy] == '0') plansza[x_poczatokwy - ilu_komorkowy][y_poczatkowy] = '6';
        for (i = x_poczatokwy + 1; i > x_poczatokwy - ilu_komorkowy - 1; i--)
        {
            if (plansza[i][y_poczatkowy - 1] == '0') plansza[i][y_poczatkowy - 1] = '6';
            if (plansza[i][y_poczatkowy + 1] == '0') plansza[i][y_poczatkowy + 1] = '6';
        }
    }

    if (kierunek == 2)
    {
        if (plansza[x_poczatokwy][y_poczatkowy - 1] == '0') plansza[x_poczatokwy][y_poczatkowy - 1] = '6';
        if (plansza[x_poczatokwy][y_poczatkowy + ilu_komorkowy] == '0') plansza[x_poczatokwy][y_poczatkowy + ilu_komorkowy] = '6';
        for (i = y_poczatkowy - 1; i < y_poczatkowy + ilu_komorkowy; i++)
        {
            if (plansza[x_poczatokwy - 1][i] == '0') plansza[x_poczatokwy - 1][i] = '6';
            if (plansza[x_poczatokwy + 1][i] == '0') plansza[x_poczatokwy + 1][i] = '6';
        }

    }

    if (kierunek == 3)
    {
        if (plansza[x_poczatokwy - 1][y_poczatkowy] == '0') plansza[x_poczatokwy - 1][y_poczatkowy] = '6';
        if (plansza[x_poczatokwy + ilu_komorkowy][y_poczatkowy] == '0') plansza[x_poczatokwy + ilu_komorkowy][y_poczatkowy] = '6';
        for (i = x_poczatokwy - 1; i < x_poczatokwy + ilu_komorkowy + 1; i++)
        {
            if (plansza[i][y_poczatkowy - 1] == '0') plansza[i][y_poczatkowy - 1] = '6';
            if (plansza[i][y_poczatkowy + 1] == '0') plansza[i][y_poczatkowy + 1] = '6';
        }
    }
    if (kierunek == 4)
    {
        if (plansza[x_poczatokwy][y_poczatkowy + 1] == '0') plansza[x_poczatokwy][y_poczatkowy + 1] = '6';
        if (plansza[x_poczatokwy][y_poczatkowy - ilu_komorkowy] == '0') plansza[x_poczatokwy][y_poczatkowy - ilu_komorkowy] = '6';
        for (i = y_poczatkowy + 1; i > y_poczatkowy - ilu_komorkowy - 1; i--)
        {
            if (plansza[x_poczatokwy - 1][i] == '0') plansza[x_poczatokwy - 1][i] = '6';
            if (plansza[x_poczatokwy + 1][i] == '0') plansza[x_poczatokwy + 1][i] = '6';
        }

    }

}

int sprawdzanie_kierunku_czterokomorkowca(int wiersz, int kolumna)
{
    int kierunek;
    kierunek = rand() % 4 + 1;


    if (kierunek == 1)          //gora
    {
        if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0' && plansza[wiersz - 3][kolumna] == '0') return 1;
        else
        {
            if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0' && plansza[wiersz][kolumna + 3] == '0') return 2;
            else
            {
                if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0' && plansza[wiersz + 3][kolumna] == '0') return 3;
                else
                {
                    if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0' && plansza[wiersz][kolumna - 3] == '0') return 4;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 2)     //prawo
    {
        if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0' && plansza[wiersz][kolumna + 3] == '0') return 2;
        else
        {
            if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0' && plansza[wiersz + 3][kolumna] == '0') return 3;
            else
            {
                if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0' && plansza[wiersz][kolumna - 3] == '0') return 4;
                else
                {
                    if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0' && plansza[wiersz - 3][kolumna] == '0') return 1;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 3)     //dol
    {
        if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0' && plansza[wiersz + 3][kolumna] == '0') return 3;
        else
        {
            if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0' && plansza[wiersz][kolumna - 3] == '0') return 4;
            else
            {
                if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0' && plansza[wiersz - 3][kolumna] == '0') return 1;
                else
                {
                    if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0' && plansza[wiersz][kolumna + 3] == '0') return 2;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 4)     //lewo
    {
        if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0' && plansza[wiersz][kolumna - 3] == '0') return 4;
        else
        {
            if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0' && plansza[wiersz - 3][kolumna] == '0') return 1;
            else
            {
                if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0' && plansza[wiersz][kolumna + 3] == '0') return 2;
                else
                {
                    if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0' && plansza[wiersz + 3][kolumna] == '0') return 3;
                    else return 0; //brak mozliwosci
                }
            }
        }
    }
}



void generowanie_czterokomorkowca()

{
    int min = 1, max = 10, prawidlowo_ustawiony = 0;
    srand(time(NULL));

    int x, y, kierunek;

    /*
        x - wiersz
        y - kolumna

        KIERUNEK:
        1 - góra
        2 - prawo
        3 - dó³
        4 - lewo
    */

    while (prawidlowo_ustawiony == 0)
    {
        x = rand() % max + min;
        y = rand() % max + min;

        //printf("\nx: %d\ny: %d\n\n", x, y);
        //printf("Zawartosc: %c", plansza[1][1]);
        //printf("\nKierunek: ");


        if (plansza[x][y] == '0')
        {
            int kierunek;
            kierunek = sprawdzanie_kierunku_czterokomorkowca(x, y);

            if (kierunek == 1)
            {
                plansza[x][y] = '4';
                plansza[x - 1][y] = '4';
                plansza[x - 2][y] = '4';
                plansza[x - 3][y] = '4';
                wyznaczanie_otoczenia_statku(4, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 2)
            {
                plansza[x][y] = '4';
                plansza[x][y + 1] = '4';
                plansza[x][y + 2] = '4';
                plansza[x][y + 3] = '4';
                wyznaczanie_otoczenia_statku(4, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 3)
            {
                plansza[x][y] = '4';
                plansza[x + 1][y] = '4';
                plansza[x + 2][y] = '4';
                plansza[x + 3][y] = '4';
                wyznaczanie_otoczenia_statku(4, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 4)
            {
                plansza[x][y] = '4';
                plansza[x][y - 1] = '4';
                plansza[x][y - 2] = '4';
                plansza[x][y - 3] = '4';
                wyznaczanie_otoczenia_statku(4, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
        }
    }
    //printf("\nx: %d\ny: %d\n\n", x,y);
    //printf("Komrka: %c", plansza[x][y]);
}

int sprawdzanie_kierunku_trojkomorkowca(int wiersz, int kolumna)
{
    int kierunek;
    kierunek = rand() % 4 + 1;


    if (kierunek == 1)          //gora
    {
        if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0') return 1;
        else
        {
            if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0') return 2;
            else
            {
                if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0') return 3;
                else
                {
                    if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0') return 4;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 2)     //prawo
    {
        if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0') return 2;
        else
        {
            if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0') return 3;
            else
            {
                if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0') return 4;
                else
                {
                    if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0') return 1;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 3)     //dol
    {
        if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0') return 3;
        else
        {
            if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0') return 4;
            else
            {
                if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0') return 1;
                else
                {
                    if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0') return 2;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 4)     //lewo
    {
        if (plansza[wiersz][kolumna - 1] == '0' && plansza[wiersz][kolumna - 2] == '0') return 4;
        else
        {
            if (plansza[wiersz - 1][kolumna] == '0' && plansza[wiersz - 2][kolumna] == '0') return 1;
            else
            {
                if (plansza[wiersz][kolumna + 1] == '0' && plansza[wiersz][kolumna + 2] == '0') return 2;
                else
                {
                    if (plansza[wiersz + 1][kolumna] == '0' && plansza[wiersz + 2][kolumna] == '0') return 3;
                    else return 0; //brak mozliwosci
                }
            }
        }
    }
}

void generowanie_trojkomorkowca()

{
    int min = 1, max = 10, prawidlowo_ustawiony = 0;
    srand(time(NULL));

    int x, y, kierunek;

    /*
        x - wiersz
        y - kolumna

        KIERUNEK:
        1 - góra
        2 - prawo
        3 - dó³
        4 - lewo
    */

    while (prawidlowo_ustawiony == 0)
    {
        x = rand() % max + min;
        y = rand() % max + min;

        //printf("\nx: %d\ny: %d\n\n", x, y);
        //printf("Zawartosc: %c", plansza[1][1]);
        //printf("\nKierunek: ");


        if (plansza[x][y] == '0')
        {
            int kierunek;
            kierunek = sprawdzanie_kierunku_trojkomorkowca(x, y);

            if (kierunek == 1)
            {
                plansza[x][y] = '3';
                plansza[x - 1][y] = '3';
                plansza[x - 2][y] = '3';
                wyznaczanie_otoczenia_statku(3, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 2)
            {
                plansza[x][y] = '3';
                plansza[x][y + 1] = '3';
                plansza[x][y + 2] = '3';
                wyznaczanie_otoczenia_statku(3, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 3)
            {
                plansza[x][y] = '3';
                plansza[x + 1][y] = '3';
                plansza[x + 2][y] = '3';
                wyznaczanie_otoczenia_statku(3, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 4)
            {
                plansza[x][y] = '3';
                plansza[x][y - 1] = '3';
                plansza[x][y - 2] = '3';
                wyznaczanie_otoczenia_statku(3, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }

        }

    }
    //printf("\nx: %d\ny: %d\n\n", x,y);
    //printf("Komrka: %c", plansza[x][y]);
}

int sprawdzanie_kierunku_dwukomorkowca(int wiersz, int kolumna)
{
    int kierunek;
    kierunek = rand() % 4 + 1;


    if (kierunek == 1)          //gora
    {
        if (plansza[wiersz - 1][kolumna] == '0') return 1;
        else
        {
            if (plansza[wiersz][kolumna + 1] == '0') return 2;
            else
            {
                if (plansza[wiersz + 1][kolumna] == '0') return 3;
                else
                {
                    if (plansza[wiersz][kolumna - 1] == '0') return 4;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 2)     //prawo
    {
        if (plansza[wiersz][kolumna + 1] == '0') return 2;
        else
        {
            if (plansza[wiersz + 1][kolumna] == '0') return 3;
            else
            {
                if (plansza[wiersz][kolumna - 1] == '0') return 4;
                else
                {
                    if (plansza[wiersz - 1][kolumna] == '0') return 1;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 3)     //dol
    {
        if (plansza[wiersz + 1][kolumna] == '0') return 3;
        else
        {
            if (plansza[wiersz][kolumna - 1] == '0') return 4;
            else
            {
                if (plansza[wiersz - 1][kolumna] == '0') return 1;
                else
                {
                    if (plansza[wiersz][kolumna + 1] == '0') return 2;
                    else return 0;  //brak mozliwosci
                }
            }
        }
    }


    if (kierunek == 4)     //lewo
    {
        if (plansza[wiersz][kolumna - 1] == '0') return 4;
        else
        {
            if (plansza[wiersz - 1][kolumna] == '0') return 1;
            else
            {
                if (plansza[wiersz][kolumna + 1] == '0') return 2;
                else
                {
                    if (plansza[wiersz + 1][kolumna] == '0') return 3;
                    else return 0; //brak mozliwosci
                }
            }
        }
    }
}

void generowanie_dwukomorkowca()

{
    int min = 1, max = 10, prawidlowo_ustawiony = 0;
    srand(time(NULL));

    int x, y, kierunek;

    /*
        x - wiersz
        y - kolumna

        KIERUNEK:
        1 - góra
        2 - prawo
        3 - dó³
        4 - lewo
    */

    while (prawidlowo_ustawiony == 0)
    {
        x = rand() % max + min;
        y = rand() % max + min;

        //printf("\nx: %d\ny: %d\n\n", x, y);
        //printf("Zawartosc: %c", plansza[1][1]);
        //printf("\nKierunek: ");


        if (plansza[x][y] == '0')
        {
            int kierunek;
            kierunek = sprawdzanie_kierunku_dwukomorkowca(x, y);

            if (kierunek == 1)
            {
                plansza[x][y] = '2';
                plansza[x - 1][y] = '2';
                wyznaczanie_otoczenia_statku(2, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 2)
            {
                plansza[x][y] = '2';
                plansza[x][y + 1] = '2';
                wyznaczanie_otoczenia_statku(2, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 3)
            {
                plansza[x][y] = '2';
                plansza[x + 1][y] = '2';
                wyznaczanie_otoczenia_statku(2, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }
            else if (kierunek == 4)
            {
                plansza[x][y] = '2';
                plansza[x][y - 1] = '2';
                wyznaczanie_otoczenia_statku(2, x, y, kierunek);
                prawidlowo_ustawiony = 1;
            }

        }

    }
    //printf("\nx: %d\ny: %d\n\n", x,y);
    //printf("Komrka: %c", plansza[x][y]);
}

void generowanie_jednokomorkowca()

{
    int min = 1, max = 10, prawidlowo_ustawiony = 0;
    srand(time(NULL));

    int x, y, kierunek;

    /*
        x - wiersz
        y - kolumna

        KIERUNEK:
        1 - góra
        2 - prawo
        3 - dó³
        4 - lewo
    */

    while (prawidlowo_ustawiony == 0)
    {
        x = rand() % max + min;
        y = rand() % max + min;

        //printf("\nx: %d\ny: %d\n\n", x, y);
        //printf("Zawartosc: %c", plansza[1][1]);
        //printf("\nKierunek: ");


        if (plansza[x][y] == '0')
        {
            plansza[x][y] = '1';
            wyznaczanie_otoczenia_statku(1, x, y, 1);
            prawidlowo_ustawiony = 1;
        }

    }
    //printf("\nx: %d\ny: %d\n\n", x,y);
    //printf("Komrka: %c", plansza[x][y]);
}





void zczytywanie_wspolrzednych(int* wiersz_ost, int* kolumna_ost)
{
    char wspolrzedne[4], pierwszy, drugi, trzeci, czwarty, koniec;
    int wiersz, kolumna, wiersz1, wiersz2, kolumna1;

    printf_s("\nStrzal: ");

    do
    {
        fgets(wspolrzedne, sizeof(wspolrzedne), stdin);

        kolumna = int(*wspolrzedne);
        wiersz = int(*(wspolrzedne + 1));

        kolumna1 = int(*wspolrzedne);
        wiersz1 = int(*(wspolrzedne + 1));
        wiersz2 = int(*(wspolrzedne + 2));
        koniec = *(wspolrzedne + 3);

        if (kolumna < 97) kolumna -= 65 - 1;
        else kolumna -= 97 - 1;

        if (wiersz1 == 49 && wiersz2 == 48)
        {
            wiersz = 10;
        }
        else wiersz -= 49 - 1;



    } //while (!((kolumna >= 'A' && kolumna <= 'J') || (kolumna >= 'a' && kolumna <= 'j') && (wiersz >= '1' && wiersz <= '9') && wiersz2 == '0') && strzaly[wiersz][kolumna] != '0');
    while ((((kolumna1 < 'A' && kolumna1 > 'J') && (kolumna1 >= 'a' && kolumna1 <= 'j')) || (wiersz1 < '1' && wiersz1 > '9') || (wiersz2 >= '1' && wiersz2 <= '9') || strzaly[wiersz][kolumna] != '0') && ((((kolumna1 < 'A' && kolumna1 > 'J') && (kolumna1 >= 'a' && kolumna1 <= 'j')) || (wiersz1 != '1' || wiersz2 != '0')) || strzaly[wiersz][kolumna] != '0'));
    //( ((kolumna < 'A' && kolumna > 'J') && (kolumna >= 'a' && kolumna <= 'j')) || (wiersz1 != '1' || wiersz2 != '0') || strzaly[wiersz][kolumna] != '0')    );

    //printf("Wiersz1: %d\nWiersz2: %d", wiersz1, wiersz2);
    //printf("\n\nWiersz: %d\nKolumna: %d\n", wiersz, kolumna);

    *wiersz_ost = wiersz;
    *kolumna_ost = kolumna;
}

void rezultat_strzalu(int* wiersz_ost, int* kolumna_ost)
{
    int wiersz, kolumna;

    wiersz = *wiersz_ost;
    kolumna = *kolumna_ost;

    strzaly[wiersz][kolumna] = '1';
    if (plansza[wiersz][kolumna] == '4')
    {
        strzaly[wiersz][kolumna] = '2';
        zycie[4]--;
        if (zycie[4] == 0)
        {
            printf("-------------------------->>> Trafiony zatopiony! <<<-------------------------------\n\n");
            ilosc_statkow[4]--;
        }
        else printf("-------------------------->>>>>>>>> Trafiony! <<<<<<<<-------------------------------\n\n");
    }
    else if (plansza[wiersz][kolumna] == '3')
    {
        strzaly[wiersz][kolumna] = '2';
        zycie[3]--;
        if (zycie[3] == 0)
        {
            printf("-------------------------->>> Trafiony zatopiony! <<<-------------------------------\n\n");
            ilosc_statkow[3]--;
            zycie[3] = 3;
        }
        else printf("-------------------------->>>>>>>>> Trafiony! <<<<<<<<-------------------------------\n\n");
    }
    else if (plansza[wiersz][kolumna] == '2')
    {
        strzaly[wiersz][kolumna] = '2';
        zycie[2]--;
        if (zycie[2] == 0)
        {
            printf("-------------------------->>> Trafiony zatopiony! <<<-------------------------------\n\n");
            ilosc_statkow[2]--;
            zycie[2] = 2;
        }
        else printf("-------------------------->>>>>>>>> Trafiony! <<<<<<<<-------------------------------\n\n");
    }
    else if (plansza[wiersz][kolumna] == '1')
    {
        strzaly[wiersz][kolumna] = '2';
        zycie[1]--;
        if (zycie[1] == 0)
        {
            printf("-------------------------->>> Trafiony zatopiony! <<<-------------------------------\n\n");
            ilosc_statkow[1]--;
            zycie[1] = 1;
        }
        else printf("-------------------------->>>>>>>>> Trafiony! <<<<<<<<-------------------------------\n\n");
    }
    else printf(" ------------------------->>>      Pudlo!         <<<------------------------------\n\n");
    //printf("Kolumna: %d \nWiersz: %d", kolumna, wiersz);


}

void ile_zostalo()
{
    printf("\n\nZostalo:\n");
    printf("%d x 1-komorkowcow\n", ilosc_statkow[1]);
    printf("%d x 2-komorkowcow\n", ilosc_statkow[2]);
    printf("%d x 3-komorkowcow\n", ilosc_statkow[3]);
    printf("%d x 4-komorkowcow\n", ilosc_statkow[4]);
}

void poczatek_gry()
{
    printf("\nWitam w grze 'Statki' stworzonej przez Pana Przemyslawa!\n\n");
    printf("Pierwsza i najwazniejsza zasada gry w statki jest obecnosc i zaangazowanie \ndwoch osob - nie da sie zagrac w te gre w pojedynke (chyba, ze z komputerowym przeciwnikiem) :). \nNalezy przygotowac niezbedne akcesoria: ekran, klawiature, czas, cierpliwosc i wiecej cierpliwosci :)");
    printf("\n\nCelne strzaly gracza prosze podawac w formacie LiteraCyfra, inaczej zle to sie skonczy :(  Oczywiscie do momentu az sie nie zreflektujesz\n\n\nPowodzenia!!!");

    getchar();
    system("cls");
}

void koniec_gry(int licznik)
{
    wypisywanie_strzalow();
    printf("\n\nGratulacje!!! Udalo ci sie zatopic wszystkie statki w %d ruchach\n\n", licznik);
}
