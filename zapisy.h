#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<time.h>
#include<dirent.h>
using namespace std;
class zapisy {
    friend class obliczenia;
ofstream plikiB; // zapis do pliku :)
ifstream plikiA; // odczyt z plików dla innych kals te¿
string skladniki_sc[7] = {"D:\\tea\\", "\\", "_plan.txt", "_real.txt", "_rachunki.txt",
 "_paliwo.txt", "_temp.txt" };
 string miesiac; string nazwa_sciezki123; string nazwa_sciezki_temp;
public:
    void utworz_folder (); // do utworzenia folderu w nowym katalogu :0
    string kreator_scieznkiF(int zamien);
    string kreator_nazwy_msc(); // tu będzie sie ładować miesiać
    void dla_planu_realizacji(string *wsk_nazwy, double *wsk_wartPlan, double *zost); // w uzyciu plan ?
    void dla_planu_realizacji(string *wsk_nazwy, double *wsk_wartPlan, double *wsk_wartReal, double *zost); // w uzyciu
    void czytaj_plan_real(string *wsk_nazwy, double *wsk_wartPlan);
    double czytaj_sumuj_rachunki(); // dla racunku 3 pozycje :)
    double czytaj_sumuj_rachunki(double *litry);
    void dla_rachunku_paliwa(string kiedy, string gdzie, double ile);
    void dla_rachunku_paliwa(string kiedy, string gdzie, double ile, double ile_litr); // przeladowana   funkcja
    void zmien_jedna_wartosc(string *biezace, double *sum_rekordy, string *pozostalosc, double *wartosc_rachunku);
    void funfun();




};
