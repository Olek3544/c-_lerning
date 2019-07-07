#include"zapisy.h"
void zapisy::funfun()
{
    string c1="1234"; string c2;
    miesiac = kreator_nazwy_msc();

    c2 = miesiac+c1;
    cout << c2 << endl;
    nazwa_sciezki123 = kreator_scieznkiF(1);
    cout << "Z funfun \n";
    cout << nazwa_sciezki123<< endl;

    /*plikiB.open(nazwa_sciezki123.c_str(), ios::out);
    plikiB<<c2; // << endl;
    plikiB.close();*/
}
void zapisy::utworz_folder()
{
    string fold_msc, fld_dysk, calosc;
    fld_dysk =  "D:\\tea\\";
    fold_msc  =  kreator_nazwy_msc();
    calosc = fld_dysk+fold_msc;
    mkdir(calosc.c_str()); // tak jest ok tworzy folder trzeba gdzieś to zapakować
    cout << "Utworzono folder   " <<fold_msc << endl;
}
string zapisy::kreator_nazwy_msc()
{
 int miesiac; string nazwa_msc;
 time_t now = time(0);
    char* dt =ctime(&now);
    tm *ltm = localtime(&now);
    miesiac = (1+ ltm->tm_mon);
    switch(miesiac) // to musi pójść do funkcji kreującej ściżkli do folderów
    {
 case 1:
     nazwa_msc = "styczen";
    break;
 case 2:
    nazwa_msc = "luty";
    break;
 case 3:
    nazwa_msc = "marzec";
    break;
 case 4:
    nazwa_msc = "kwiecien";
    break;
 case 5:
    nazwa_msc = "maj";
    break;
 case 6:
    nazwa_msc = "czerwiec";
    break;
 case 7:
    nazwa_msc = "lipiec";
    break;
 case 8:
    nazwa_msc = "sierpien";
    break;
 case 9:
    nazwa_msc = "wrzesien";
    break;
 case 10:
    nazwa_msc = "pazdziernik";
    break;
 case 11:
    nazwa_msc = "listopad";
    break;
 case 12:
    nazwa_msc = "grudzien";
    break;
 default:
    cout << "Nie ma takiego miesiaca \n";
    break;
    } // koniec switch
    return nazwa_msc;
}
string zapisy::kreator_scieznkiF(int zamien) // GENEROWANIE NAZWY MIESIACA JEST TU POTRZEBNE !!!!
{ // czy przeładować czy na if case ? za krótkie to
    int miesiac; string nazwa_msc; // nazwa miesiaca
    nazwa_msc=kreator_nazwy_msc();

    string skladniki_sc[7] = {"D:\\tea\\", "\\", "_plan.txt", "_real.txt", "_rachunki.txt",
 "_paliwo.txt", "_temp.txt" };
 string wytwor;
if(zamien==1){ // tylko dla planu
 wytwor=  skladniki_sc[0]+nazwa_msc+skladniki_sc[1]+nazwa_msc+skladniki_sc[2];
    cout << wytwor << endl;
}
else if(zamien==2){ // tylko dla realizacji i palnu
 wytwor=  skladniki_sc[0]+nazwa_msc+skladniki_sc[1]+nazwa_msc+skladniki_sc[3];
    cout << wytwor << endl;
}
else if(zamien==3){ // tylko dla realizacji i rachunków
 wytwor=  skladniki_sc[0]+nazwa_msc+skladniki_sc[1]+nazwa_msc+skladniki_sc[4];
    cout << wytwor << endl;
}
else if(zamien==4){ // tylko dla realizacji i paliwa
 wytwor=  skladniki_sc[0]+nazwa_msc+skladniki_sc[1]+nazwa_msc+skladniki_sc[5];
    cout << wytwor << endl;
}
else if(zamien==5){ // tylko dla realizacji i pliku tymczsowego
 wytwor=  skladniki_sc[0]+nazwa_msc+skladniki_sc[1]+nazwa_msc+skladniki_sc[6];
 //cout "Z samego kreatora sciezki \n ";
    cout << wytwor << endl;
}
else { cout << "Blad: nie odpowiedni znak sterujacy \n"; }
return wytwor;
} // koniec funkcji
// 1. DLA PLANU ZAPIS
void zapisy::dla_planu_realizacji(string *wsk_nazwy, double *wsk_wartPlan, double *zost)
 {

// zapisuje plan ale musi mieć funkcje do tworzenia folderu
//utworz_folder(); // musi mieć miesiac z czasu systemowego
     nazwa_sciezki123 = kreator_scieznkiF(1); // char 1 żeby dla plany
     cout << "Z funkcji dla planu zapis \n ";
     cout << nazwa_sciezki123 << endl;
     plikiB.open(nazwa_sciezki123.c_str(), ios::out) ;
     for(int i = 0; i <=10; i++)
    {
        if(i==10){
        plikiB <<*(wsk_nazwy+i)<<"\t"<<*zost ; // << endl;
        }
        else{
             plikiB <<*(wsk_nazwy+i)<<"\t"<<*(wsk_wartPlan +i) << endl;
        }
    }
     plikiB.close();

 }
 //2 DLA REALIZACJI ZAPIS
 void zapisy::dla_planu_realizacji(string *wsk_nazwy, double *wsk_wartPlan, double *wsk_wartReal, double *zost)
 {
     nazwa_sciezki123 = kreator_scieznkiF(2);
     plikiB.open(nazwa_sciezki123.c_str(), ios::app) ;
     for(int i = 0; i <=10; i++)
    {
        if(i==10){
        plikiB <<*(wsk_nazwy+i)<<"\t"<<*(wsk_wartPlan +i)<<"\t"<<*zost ; // << endl;
        }
        else{
             plikiB <<*(wsk_nazwy+i)<<"\t"<<*(wsk_wartPlan +i)<<"\t"<<*(wsk_wartReal +i) << endl;
        }
    }
     plikiB.close();
 }
 // 3 PLAN ODCZYT
void zapisy::czytaj_plan_real(string *wsk_nazwy, double *wsk_wartPlan)
{
    nazwa_sciezki123=kreator_scieznkiF(1);
  plikiA.open(nazwa_sciezki123.c_str(), ios::in);
  for(int i = 0; i <=10; i++)
  {
   plikiA >>*(wsk_nazwy+i)>>*(wsk_wartPlan +i); //  << endl;
  cout  <<*(wsk_nazwy+i)<<"\t"<<*(wsk_wartPlan +i) << endl;
  }

  plikiA.close();
}
// 4 DO SUMAOWANIA REKORDOW W PLIKU RACHUNKI ;0
double zapisy::czytaj_sumuj_rachunki()
{ double xsum; string kiedy; string gdzie; double ile; // sa zmienne do odczytnika
nazwa_sciezki123 = kreator_scieznkiF(3);
plikiA.open(nazwa_sciezki123.c_str());
while(plikiA >> kiedy >> gdzie >> ile){
        // test czytaj
        cout << kiedy << " " << gdzie << " " << ile << endl;
    xsum = xsum + ile;
}
plikiA.close();
cout << "Po naszej ksumie jest  " << xsum << endl;
    return xsum;
}
// 5 do czytania paliwa
double zapisy::czytaj_sumuj_rachunki(double *litry)
{
 double xsum; string kiedy; string gdzie; double ile; // sa zmienne do odczytnika
nazwa_sciezki123 = kreator_scieznkiF(4);
plikiA.open(nazwa_sciezki123.c_str());
while(plikiA >> kiedy >> gdzie >> ile>>*litry){
        // test czytaj
        cout << kiedy << " " << gdzie << " " << ile <<" "<<*litry << endl;
    xsum = xsum + ile;
}
plikiA.close();
cout << "Suma litrow jest  "<<xsum<<endl;

cout << "Po naszej ksumie jest  " << xsum << endl;
    return xsum;
}
// 6 zapis pojedynczego rachunku  - sklepy
void zapisy::dla_rachunku_paliwa(string kiedy, string gdzie, double ile)
{
    nazwa_sciezki123  = kreator_scieznkiF(3);
    plikiB.open(nazwa_sciezki123.c_str(), ios::app);
    plikiB<<kiedy<<' ' <<gdzie<<' '<< ile << endl;
    // koniec funckji
    plikiB.close();
}
// 7 zapis pojedynczego rachunku za tankowanie
void zapisy::dla_rachunku_paliwa(string kiedy, string gdzie, double ile, double ile_litr)
{ // zapis rekordów do paliwa :) funkcja przeładowana
nazwa_sciezki123 = kreator_scieznkiF(4);
 plikiB.open(nazwa_sciezki123.c_str(), ios::app);
    plikiB<<kiedy<<' ' <<gdzie<<' '<< ile <<' '<<ile_litr <<endl;
    // koniec funckji
    plikiB.close();
}

void zapisy::zmien_jedna_wartosc(string *biezace, double *sum_rekordy, string *pozostalosc, double *wartosc_rachunku)
{ // lokalsi do odczytu i zmiany
    string pozycja; double plan; double realizacja;
    cout << "Zmieniam \n";
    cout << *biezace << endl; // z wydatkami bieżącymi
    cout << "Suma rekordow :: \n";
    cout << *sum_rekordy << endl ; // suma rekordów
    cout << *pozostalosc << endl; // ile nam pozostało
    // wywoływana z panelu trzeciego
     // musi dostaæ np sumê rekordów do zmiany
     // teksty, przy których trzeba coœ zmieniæ
     // musi sama funkcja na bieżąco obliczać ile zostało pieniędzy
     nazwa_sciezki123 = kreator_scieznkiF(2);
     nazwa_sciezki_temp = kreator_scieznkiF(5);
plikiA.open(nazwa_sciezki123.c_str(), ios::in);
plikiB.open(nazwa_sciezki_temp.c_str(),ios::out);
     while(plikiA >> pozycja>>plan >>realizacja ){
            if(pozycja==*biezace){ // aktualizuje sume rekordow
        cout << pozycja << " " << plan << " " << *sum_rekordy << endl;
        plikiB << pozycja << "\t" << plan << "\t" << *sum_rekordy << endl;
        }
     else if(pozycja==*pozostalosc){ // aktualizuje ile pozostlo
            cout << pozycja << " " << plan << " " << realizacja - *wartosc_rachunku << endl; // czyli dobrze jest sprawdz na
            plikiB << pozycja << "\t" << plan << "\t" << realizacja - *wartosc_rachunku; // << endl;
     }
     else // jak normalnie :)
     {
       cout << pozycja << " " << plan << " " << realizacja << endl;
       plikiB << pozycja << "\t" << plan << "\t" << realizacja << endl;

     }
     }// koniec while
     plikiA.close();
     plikiB.close();
     remove(nazwa_sciezki123.c_str());
      rename(nazwa_sciezki_temp.c_str(), nazwa_sciezki123.c_str()); // powrót do starego ;)
} // koniec funkcji
