#include"zapiski.h"
void ciagi_wyrazow::findFiles()
{

}
void ciagi_wyrazow::graTypa()
{
 cout << "Eneter the month of calc  \n";
    cin >> tablica_wyrazow[7];
}
string ciagi_wyrazow::nazwa_miejsca()
{
   return tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[2];
}
string ciagi_wyrazow::nazwa_miejsca1(float strs3, float mcpl)
{ string pedroh; ofstream plikiB;
    //pedroh = tablica_wyrazow1[0]+tablica_wyrazow1[1]+tablica_wyrazow1[2]+tablica_wyrazow1[1]+tablica_wyrazow1[2]+tablica_wyrazow1[3];// what ?"
pedroh = tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[3];// sth
cout << pedroh << endl;
cout << dysk_baza1 << endl;
plikiB.open(pedroh.c_str(), ios::out);
plikiB << strs3 << " " << mcpl << endl ;
plikiB.close();
for(int i =  0; i <3; i++)
{
    cout << golden_dust[i] << endl;
}
}
string ciagi_wyrazow::nazwa_miejsca2()
{

    return tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[3];// sth

}
string ciagi_wyrazow::nazwa_miejsca3()
{
   return tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[4];
}
string ciagi_wyrazow::nazwa_miejsca4()
{
   return tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[5];
}
string ciagi_wyrazow :: path_plan(float strs3, float mcpl)
{
    path_names = tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[3];// sth

}
string ciagi_wyrazow::path_real()
{
    path_names = tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[4];
}
string ciagi_wyrazow::path_bills()
{
    path_names = tablica_wyrazow[0]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[1]+tablica_wyrazow[7]+tablica_wyrazow[4];
}



