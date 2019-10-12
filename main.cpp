

#include<limits>
#include <iostream>
#include"bdg_plan.h" 
#include"rach.h"
//#include"rach.h"
using namespace std; 
#define RACHUNKI 1
#define PLANR 2 
#define DOLOWY 3
#define LICZBA_WYBORU RACHUNKI 
int main()
{
	rachunek r1;
r1.wprowadzRachunek(); 
	//r1.doSQLbaza(); 
//	r1.stwzakresDaty(); // nic średnia , suma , ilość rekordów 
	/*
	r1.stwzakresDaty();  // tworzy zapytanie o sume z tabeli rachunki od początku dnaego miesiaca do teraz
	r1.stwzakresDaty(1); // tworzy zapytanie o srednia z tabeli rachunki od początku dnaego miesiaca do teraz
	r1.stwzakresDaty(1, 1);   // tworzy zapytanie o ilosć rekordów w tabeli z tabeli rachunki od początku dnaego miesiaca do teraz
	r1.uaktualnijWD();  // tworzy zapytanie o uaktualnienie wb wydatki biezace 
	*/
	return 0; 
}
#if(LICZBA_WYBORU == RACHUNKI)


#elif(LICZBA_WYBORU ==DOLOWY )
bool checkInputData(int &liczba)
{

	cin >> liczba;
	if (cin.fail())
	{
		cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max) '\n';
		cin.ignore();
		return false;
	}
	else
	{
		return true;
	}


}
// dla tabeli 
bool checkTableInput(int *wsk_table)
{
	for (int i = 0; i < 3; i++)
	{
		cin >> *(wsk_table + i);
		if (cin.fail())
		{
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max) '\n';
			cin.ignore();
			return false;
		}
		else
		{
			return true;
		}
	}

}
char *tr(char *str)
{
	static char buff[256];
	char cp[] = "\245\206\251\210\344\242\230\276\253\244\217\250\235\343\340\227\275\215ąćęłńóśżźĄĆĘŁŃÓŚŻŹ";
	if (strlen(str) >= sizeof(buff)) return str;
	char *bf = buff;
	while (*str)
	{
		char *pos = strchr(cp + 18, *str);
		*(bf++) = pos ? *(pos - 18) : *str;
		++str;
	}
	*bf = 0;
	return buff;
}
#define RACHUNKI 1
#define PLANR 2 
int main()
{
	//plan p1;
	//p1.nazwaMiesiaca(); 
	//p1.generatorPytan('2'); 
	//p1.inSQLdata();
	//p1.entshdane();
	//realizacja r1;
	//r1.entshdane(); 
	/*rachunek ra1;
	ra1.sdrach();*/
	//string napis = "Zażółć gęślą jaźń";
	//char *z = 'ś';
	//cout << tr(z) << endl;
	//bdg_plan plan; 
	//plan.sklejka();
	/*plan.enterData();
	plan.showData(); */
	string pomoc;
	//rachunek rach1;
	//rach1.bazaTabel1;
	//pomoc = plan.sklejka(); 
	//puts("wynik dzilania sklejki \n");
	//cout << pomoc << endl; 

	/*int x;  int Tablica[3];
	int *wsk_tab = &Tablica[0];

	do
	{
		cout << "Podaj x \n";
	} while (checkInputData(x) == false);
	cout << "Podales liczbe  " << x << endl;
	for (int i = 0; i < 3; i++)
	{
		do
		{
			cout << "Podaj element tabeli  \n";
		} while (checkInputData(Tablica[i]) == false);
		cout << "Podales " << Tablica[i] << endl;
	}
	//cout << "Podales liczbe  " << x << endl; */
	return 0;
}
#endif // 




