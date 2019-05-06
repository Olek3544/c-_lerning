#include"gazE.h"


float gazyDane::dane_gazy_wz(char znaczek)
{ // funkcja z baz¹ gazów
    float LHVE = 35500;
    float LHVLS =27900;
    float LHVLW = 31000;
    this->LHVE = LHVE;
    this->LHVLS = LHVLS;
    this->LHVW = LHVLW;
    if(znaczek=='1')
    {

        wprowadzanie_dancyh(LHVE);  // tu trza ładować znowu wartosc opałowa gazów :(

    }
    if(znaczek=='2')
    {

        wprowadzanie_dancyh(LHVLS);

    }
    if(znaczek=='3')
    {

        wprowadzanie_dancyh(LHVLW);

    }
    else {
        return 0;
    }

}
