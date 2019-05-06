#include <iostream>
#include<stdio.h>
#include"gazy.h"
//#include"zapiski.h"

using namespace std;
class gazyDane :public gazy 

{
    friend class ciagi_wyrazow;
    float LHVE, LHVLS, LHVW;
    public:
    float dane_gazy_wz(char znaczek); 


};
