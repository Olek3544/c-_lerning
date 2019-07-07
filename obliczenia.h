#include<iostream>
#include<cstdlib>

using namespace std;
class obliczenia
    {
        double budzet, mieszkanie, prad, gaz, dziecko, interentTV, wydatki_dodatkowe;
        double wydatki_biezace=0,  paliwo=0, wydatki_nieprzewidziane=0;
        double waqrtosci_kasy[3] = {mieszkanie, prad, gaz};
        string abecede[3]={"Uzyj", "a", "b"};
        // wartosci wynikowe
        double pozostalo, budzet_na_zmienne;
        // wartosci dla trzeciej i czwartej czesci
        string data, nazwa_sklepu;
        double wartosc_zakupow;
        double *wsk_w_zak = &wartosc_zakupow;
        // zmienne tylko do testu
        int xx1= 10;
public:
        obliczenia();
        //  funkcje główne :)
        void wprowadzanie_danych();
        void czesc_1_plan(char skier); // użyta do planu i realizacji
        //void czesc_2_real(); // nie użyta
        void czesc_3_rachunki(char skier); // użyta do paliwa i rachunków
        void czesc_4_paliwo(); // nie użyta
        // funkcje pomocnicze
        double ilenaBiezWyd_1(double * biezace);
        double ilenaBiezWyd_1(int o1, double * oszczedzanie); // to liczy ile pozostalo tylko jest przeładowane
        double suma_paliw_rachunkow();// nie użyta

    };
class testowa
{   int a; int b; int c;
    int tablica[3];
public:
    void wprowadz_dane();
    void wynikWynik();
    int dodaj_liczby();
    void pierwsza(string c1);
    void druga(string c2);
    void trzecia(string c3);
    void pokaz_wynik();

};
