#include <iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<dirent.h>
//#include<filesystem>
using namespace std;
class ciagi_wyrazow {
    friend class gazy;
string dysk_baza, lacznik, miesiac, koncowkaPlan_txt , koncowkarealizacja_txt, koncowkapaliwo_txt, koncowarachunki_txt;
// above non used variables do not worry
string tablica_wyrazow[7] = {"D:\\olko", "\\", "_plan.txt", "_real.txt", "_bills.txt", "_fuel.txt"};
string  path_names; // returned value :)
// tablica wyrazów 7 jest wczytywana
string dysk_baza1 = "space_echo";
string golden_dust[4] = {"Dream ", "Go ", "Have "};

public: // here is the variable sever :)
    string path_plan(float strs3, float mcpl);
    string path_real();
    string path_bills();
    string path_fuel();
    string nazwa_miejsca();
    string nazwa_miejsca1();
    string nazwa_miejsca2();
    string nazwa_miejsca3();
    string nazwa_miejsca4();
    void graTypa();
    void findFiles();
};
//ofstream plikiB; // zapis do pliku :)
//ifstream plikiA; // odczyt z plików dla innych kals te¿

