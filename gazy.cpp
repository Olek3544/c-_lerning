#include"gazy.h"
#include"zapiski.h"
void gazy::pokazSie()
{ float nnLHV;
//    wprowadzanie_dancyh();
}
void gazy::wprowadzanie_dancyh(float jakasLHV)
{

    float moc_cieplna, strumien_gm3h, strumien_gm3s;
     this->strumien_gm3h = strumien_gm3h;
    this->moc_cieplna = moc_cieplna;

    cout << "Enter the gas flow in Nm3/h \n";
    cin >> strumien_gm3h;
    strumien_gm3s = na_m3s(strumien_gm3h);
    moc_cieplna = moc_cieplna_obl(jakasLHV, strumien_gm3s); // ³adujesz ze swojej funckji tylko obliczenia :)
    cout << "Wyznaczona moc ciplna " << moc_cieplna << " kW" << endl;
    ciagi_wyrazow k;
    // tu by musiał dostać zmienne do transmisji
   k.graTypa();
   k.nazwa_miejsca1(strumien_gm3s, moc_cieplna);
}
float gazy::moc_cieplna_obl(float jakas_LHV, float jakis_strsek)
{
return jakas_LHV*jakis_strsek; // to ma tylko policzyć
}
float gazy::na_m3s( float gm3h)
{
    return  gm3h/3600;
}
