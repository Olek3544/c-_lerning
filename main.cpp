
#include"obliczenia.h"
#include"zapisy.h"
#include <iostream>
#include<time.h>
#include"spr.h"

using namespace std;
void zadaj();
void zobacz(void *y1, void *y2);
class sterownia {
char znaKK_con;
public:
    void zmieniarka();
    void welcomeF();
    sterownia();
};
sterownia::sterownia()
{

    welcomeF();
}
void sterownia::zmieniarka()
{
    cout << "Wprowadza co chcesz zrobic \n";
    do
    {
    znaKK_con = getchar();
    if(znaKK_con=='1')
    {// wywoluje plan
    obliczenia zamek1;
    zamek1.czesc_1_plan(znaKK_con);
    // załadowana wartość
    }
    else if(znaKK_con=='2')
    {// wywoluje  realizacje
    obliczenia zamek1;
    zamek1.czesc_1_plan(znaKK_con);
    }
    else if(znaKK_con=='3')
    { // wywoluje spis rachunków
    obliczenia zamek1;
    zamek1.czesc_3_rachunki(znaKK_con);
    }
    else if(znaKK_con=='4')
    { // wywoluje spis paliwa
    obliczenia zamek1;
    zamek1.czesc_3_rachunki(znaKK_con);
    }
    else if(znaKK_con=='0')
    { // tworzy folder
    zapisy stw_folder;
    stw_folder.utworz_folder();}
    else {
        cout << "Nie wybrano zadnej opcji \n";
    }
    }while((znaKK_con !='1') and (znaKK_con !='2') and (znaKK_con !='3') and (znaKK_con !='4'));
}
void sterownia::welcomeF()
{
    int miesiac;
    cout << "Hello dear user \n";
    cout << "Press 0 to create folder\n";
    cout << "Press 1 for planning \n";
    cout << "Press 2 for enter real month costs  \n";
    cout << "Press 3 for enter bills form shop and calculate fuel costs \n";

    time_t now = time(0);
    char* dt =ctime(&now);
    tm *ltm = localtime(&now);

    cout << "Data " << ltm->tm_mday << "-" << 1+ ltm->tm_mon << "-" << 1900+ltm->tm_year << endl;

    cout << "Godzina " << 1+ltm->tm_hour << ":" << 1+ltm->tm_min <<":" << 1+ltm->tm_sec << endl;


}
int main()
{

sterownia wyst1;
wyst1.zmieniarka();

 return 0;
}
void zadaj()
{
    char znaKK_con;
    int liczna;

do
{
    cout << "podaj znak \n";
    znaKK_con=getchar();
 cout << "Wykonuje do kiedy nie wpiszesz 1 lub 2 \n";
        if(znaKK_con=='1') //||(znaKK_con=='3'))
        {
            cout << "Wpr jednen lub trzy kolwa \n";

        }
        else if (znaKK_con=='2')
        {
          cout << "Wpr dwa \n";
        }
        else
        {
            cout << "Nie prwawidlowy znak, prosze podaj prawidlowy znak \n";
        }

}while((znaKK_con !='1') and (znaKK_con !='2'));
    cout << "Jestem po za petla \n";
    void *w1;  void *w2; int *p1; int *p2;
    w1 = p1;
    w2 = p2;

}
void zobacz(void *y1, void *y2)
{
int x1=4; int x2=6;
int *wx1 = &x1;
int *wx2 = &x2;
y1 = wx1;
y2 = wx2;
}
