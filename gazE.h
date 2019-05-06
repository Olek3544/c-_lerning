#include <iostream>
#include<stdio.h>
#include"gazy.h"
//#include"zapiski.h"

using namespace std;
class gazyDane :public gazy // tu dziedziczy

{
    friend class ciagi_wyrazow;
    float LHVE, LHVLS, LHVW; // atrybut musi byæ przysloniety bo inaczej ci klasa nie odziedziczy
    public:
    float dane_gazy_wz(char znaczek); // tutaj  znak sterujacy :)


};
