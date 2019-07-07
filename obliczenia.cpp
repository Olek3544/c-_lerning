#include"obliczenia.h"
#include"zapisy.h"
obliczenia::obliczenia()
{ //dobry konstruktor
    cout << "Welcome in SZARUCH 4.2 \n";
    cout << "Program ";
}
void obliczenia::wprowadzanie_danych(){
int i;


}
double obliczenia::ilenaBiezWyd_1(double * biezace){
// obliczam ile zostaje na bieżące weydakti czesc plan
return  *biezace -(*(biezace+1)+*(biezace+2)+*(biezace+3)+*(biezace+4)+*(biezace+5));

}
double obliczenia::ilenaBiezWyd_1(int o1, double * oszczedzanie){
// obliczam ile zostaje na oszczednosci czesc plan
return  *oszczedzanie -(*(oszczedzanie+1)+*(oszczedzanie+2)+*(oszczedzanie+3)+*(oszczedzanie+4)+*(oszczedzanie+5)+*(oszczedzanie+6)+*(oszczedzanie+7)+*(oszczedzanie+8)+*(oszczedzanie+9));

}
void obliczenia::czesc_1_plan(char skier) // palny i realizacje
{
    char wygoda;
    double wartosci_plan[12], wartosci_wczytane[12], wartosci_realizacja[12];
    double *wsk_wplan = &wartosci_plan[0]; double *wsk_wreal = &wartosci_realizacja[0];

  string doZmiany[4]= {"BudzetWB", "Savains_________", "Paliwo__________", "WydatkiBiezace__"};

string nazwyKoszt[11] = {"Budzet__________","Mieszkanie______", "Prad____________",
"Gaz_____________", "Internet_TV_____", "Dziecko ", "WydatkiDodatkowe ",
 "Paliwo__________", "WydatkiBiezace__", "Wydatki_nieprzewidziane ", "Pozostalo_________"};
string *wsk_NK = nazwyKoszt;
double *wsk_pozost =&pozostalo;
string *wsk_wydB = &nazwyKoszt[8];
cout << "Podaj wygodę 1 lub 2 \n";

if(skier=='0'){
    cout << "Witamy w sferze testow \n ";
    zapisy test1;
       exit(0);
}
else if(skier=='1'){
    cout << "Zaplanuj swoj budzet na najblizszy miesaic \n" ;
}
else if(skier=='2')
{
    cout << "Wprowadz realne wartosci rachunkow jakie zaplaciles \n ";
}
cout << "Wprowadz wartosc zapalnowanego budzetu  ";
    cin>>budzet;
    cout << "Wydatki ponoszone raz w miesiacu \n";
    cout << "Wprowadz ile planujesz wydac/zaplacic za: \n";
    cout << "Mieszkanie: ";
    cin>> mieszkanie; cout << "zl \n";
    cout << "Prad: ";
    cin>> prad; cout << " zl \n";
    cout << "Gaz: ";
    cin>> gaz; cout << " zl \n";
    cout << "InternetTV: ";
    cin>> interentTV; cout << " zl \n";
    cout << "Dziecko: ";
    cin>> dziecko; cout << " zl \n";
    cout << "Wydatki_dodatkowe: ";
    cin>> wydatki_dodatkowe; cout << " zl \n";
    if(skier=='1'){
    cout << "Wydatki ponoszone kilka krotnie w miesiacu \n ";
     cout << "Wprowadz ile planujesz wydawac/placic za: \n";
        cout << "Wydatki_biezace: ";
    cin>> wydatki_biezace; cout << " zl \n";
    cout << "Paliwo: ";
    cin>> paliwo; cout << " zl \n";
    cout << "Wydatki_nieprzewidziane: ";
    cin>> wydatki_nieprzewidziane; cout << " zl \n";}
    else {cout << "Na wszystkie wydatki zmienne przyjeto zero \n";}

    // wartosci stałe
    wartosci_plan[0] = budzet;
    wartosci_plan[1] = mieszkanie;
    wartosci_plan[2] = prad;
    wartosci_plan[3] = gaz;
    wartosci_plan[4] = interentTV;
    wartosci_plan[5] =  dziecko; // tu doszło :)
    wartosci_plan[6] = wydatki_dodatkowe;
    // wartosci zmienne (rachunki kilka razy na miesiac, tu planujemy wydatki)
    wartosci_plan[7] = wydatki_biezace;
    wartosci_plan[8] = paliwo;
    wartosci_plan[9] = wydatki_nieprzewidziane;
    // wartosci realizacja
    wartosci_realizacja[0] = budzet;
    wartosci_realizacja[1] = mieszkanie;
    wartosci_realizacja[2] = prad;
    wartosci_realizacja[3] = gaz;
    wartosci_realizacja[4] = interentTV;
    wartosci_realizacja[5] =  dziecko; // tu doszło :)
    wartosci_realizacja[6] = wydatki_dodatkowe;
    // wartosci zmienne (rachunki kilka razy na miesiac domyślna wartośc zero dla realizacji na poczatku )
    wartosci_realizacja[7] = wydatki_biezace;
    wartosci_realizacja[8] = paliwo;
    wartosci_realizacja[9] = wydatki_nieprzewidziane;

    if(skier=='1'){ // tu jest realizacja
pozostalo = ilenaBiezWyd_1(10,wsk_wreal);
    for(int i = 0; i <=10; i++)
    {
        if(i==10){
        cout <<nazwyKoszt[i]<<"\t"<<pozostalo << endl;
        }
        else{
             cout <<nazwyKoszt[i]<<"\t"<<wartosci_plan[i] << endl;
        }


    }

    zapisy plan;
    plan.dla_planu_realizacji(wsk_NK,wsk_wplan, wsk_pozost);
   cout << "Tutaj wyswietalmy wartosci odczytane z pliku z funkcji  \n" << endl;
   plan.czytaj_plan_real(wsk_NK,wsk_wplan); // wczytuje dane na powrót z planu
   cout << "Z funkjci obliczenia.cpp wowlam \n ";
   for(int i = 0; i <=10; i++)
    {

             cout <<nazwyKoszt[i]<<"\t"<<wartosci_plan[i] << endl;



    }
    }// koniec if pi

     else if(skier=='2'){
      pozostalo = ilenaBiezWyd_1(10, wsk_wreal); // uwaga musi być wskaźnik od realizacji wsk_wreal
      zapisy real;
      real.czytaj_plan_real(wsk_NK,wsk_wplan); // odczyty planu
    for(int i = 0; i <=10; i++)
    {
        if(i==10){
        cout <<nazwyKoszt[i]<<"\t"<<wartosci_plan[i]<<"\t"<<pozostalo << endl;
        }
        else{
             cout <<nazwyKoszt[i]<<"\t"<<wartosci_plan[i]<<"\t"<<wartosci_realizacja[i] << endl;
        }
//zapisy plan;


    }

// zapis realizacji do pliku :)


real.dla_planu_realizacji(wsk_NK,wsk_wplan, wsk_wreal,  wsk_pozost); // przeladowana funkcja
    }// koniec ilifi
    else if(skier=='0')
    {
        cout << "Wybrales testy \\\  wybrales zero \n ";

    }
}
void obliczenia::czesc_3_rachunki(char skier)
{ double xsum; double *wsk_xs = &xsum; // tez na razie lokal
double ilosc_litrow;
double *wsk_ilit = &ilosc_litrow;
string paliwo_dz="Paliwo__________";
string *wsk_paliwo_dz = &paliwo_dz;
    string testchar; string wb_dz = "WydatkiBiezace__"; // - na razie do zmniany zobaczymy jeszcze z  ładowaniem argumentów do
string *wsk_dz = &wb_dz; // ukryte wydatki bize
string poz_dz = "Pozostalo_________";
string *wsk_poz  = &poz_dz;
    cout << "czesc rachunki Podaj liczbe 3 lub 4 \n ";
  //  cout << "Podaj liczbe startowa \n ";
    //cin>>testchar;


    if(skier=='3'){
    cout << "Podaj date zakupów \n" ;
    cin>>data;
    cout << "Podaj nazwe sklepu \n ";
    cin >> nazwa_sklepu;
    cout << "Podaj wartosc zakupow \n";
    cin >> wartosc_zakupow ;
    zapisy drekord;
    drekord.dla_rachunku_paliwa(data, nazwa_sklepu, wartosc_zakupow); // dodajemy rekord
    xsum = drekord.czytaj_sumuj_rachunki(); // produkuje xsum też trzeba przeładaować
    drekord.zmien_jedna_wartosc(wsk_dz, wsk_xs, wsk_poz, wsk_w_zak); // jesli chodzi o pozostalo
    // jesli chodzi o paliwo ładujesz po prostu wskaźniki do innych nazw
    // call funckjones czy ta funckja istnieje :)
    }
    // funkcja do ewidnencji paliwa można by stosować dzidziczenie
    else if(skier=='4'){
   cout << "Podaj date tankowania \n" ;
    cin>>data;
    cout << "Podaj nazwe stacji \n ";
    cin >> nazwa_sklepu;
    cout << "Podaj wartosc zakupow \n";
    cin>>wartosc_zakupow; //  globalne atrybuty
    cout<< "Podaj ile litrów zatankowales \n";
    cin>>ilosc_litrow;
    zapisy npaliwo;
    npaliwo.dla_rachunku_paliwa(data, nazwa_sklepu, wartosc_zakupow, ilosc_litrow);
    xsum = npaliwo.czytaj_sumuj_rachunki(wsk_ilit); // produkuje xsum też trzeba przeładaować
    npaliwo.zmien_jedna_wartosc(wsk_paliwo_dz/* -tu jest paliwo literki*/, wsk_xs, wsk_poz, wsk_w_zak); // jesli chodzi o pozostalo
    }




}
/*UWAGA TU ZNAJDUJE SIE INNA KLASA DO TESTOW */
void testowa::wprowadz_dane()
{
    cout << "Daj a \n";
    cin >>a;
    cout << "Daj b \n";
    cin >>b;
cout << "Daj c \n";
    cin >>c;
    int loksTable[3] = {a,b,c};
   // tablica[3] = {a,b,c};
   void *putolW;
    for(int i = 0; i<=3; i++)
    {
        cout << loksTable[i] << endl;
    }
}
int testowa::dodaj_liczby()
{
    int suma; int o1;
   // suma = tablica[0]+tablica[1]+tablica[2];
    suma =a+b+c;
    return suma;  // kończymy tu :)


}
void testowa::wynikWynik()
{
    int show_wynik;
    show_wynik = dodaj_liczby();
    cout<< "Wynik naszej dodawaniki to jest  " << show_wynik << endl;

}
void testowa::pierwsza(string c1)
{

    cout << "Wywolanie pierwszej ";
    cout << c1 << endl;
    druga(c1);
}
void testowa::druga(string c2)
{
    cout << "Z drugiej warstwy \n";
    cout << c2 << endl;
    trzecia(c2);
}
void testowa::trzecia(string c3)
{
    cout << "Trzeba warstwa - ostatnia \n";
    cout << c3 << endl;
}
void testowa::pokaz_wynik()
{
    cout <<"Bla " << endl;
}
