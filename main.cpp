#include <iostream>
#include<stdio.h>
// #include"gazy.h"
#include"gazE.h"
#include"zapiski.h"
/* this is program for fun with inheritance in c++ */
using namespace std;
class wybor {
char znaKKa;
public:
    wybor()
    {
        cout << "Welcome in simple thermodynamical calculator \n ";
        cout << "Press 1 for gas e \n Press 2 for gas Lw \n Press 3 for gas Ls \n ";
    }
    void wybieracz()
    {
       char znaKKa;
       this->znaKKa = znaKKa;
       cout << "Enter the proper number \n";

       znaKKa = getchar();
       if(znaKKa=='1')
       {
            cout << "Gas E \n";
            gazyDane new1;
            new1.dane_gazy_wz(znaKKa);

       }
       else if(znaKKa=='2')
       {
            cout << "Gas Lw \n";
            gazyDane new2;
            new2.dane_gazy_wz(znaKKa);
       }
        else if(znaKKa=='3')
       {
            cout << "Gas Ls \n";
            gazyDane new3;
            new3.dane_gazy_wz(znaKKa);
       }
       else if(znaKKa=='4')
       { string pathnum; string pathnum1, pathnum2, pathnum3, pathnum4, pathnum5, pathnum6;
            cout << "Cos inne  \n";
            ciagi_wyrazow al1;
           // al1.graTypa();
          //  al1.nazwa_miejsca1();  // pokazanie czegoœæ
          // pathnum2 =  al1.nazwa_miejsca2();
         //  pathnum3 = al1.nazwa_miejsca3();
          // pathnum4  = al1.nazwa_miejsca4();
           al1.findFiles();
        //   cout << pathnum2<< endl;
          // cout << pathnum3<< endl;
         //  cout << pathnum4<< endl;
       }
       else {
        cout << "Please select the proper number again \n ";
        cout << "Not gas specyfied \n";
       }
    }

};


int main()
{

wybor czk;
czk.wybieracz();
    return 0;
}
