#include"real.h"
class rachunek : public realizacja {
public: 
	void wprowadzRachunek();  // to wszystko wywo�uje 
	void bazaNazw(); 
	string generatorPytan(int cznak); // przys�ania generator pyta� dziedziczony z poprzednich klas 
	string stwzakresDaty();  // tworzy zapytanie o sume z tabeli rachunki od pocz�tku dnaego miesiaca do teraz "" o 26.09.2019 tworzy wszystkie zapytania 
	string stwzakresDaty(int c); // tworzy zapytanie o srednia z tabeli rachunki od pocz�tku dnaego miesiaca do teraz
	string stwzakresDaty(int c, int d); // tworzy zapytanie o ilos� rekord�w w tabeli z tabeli rachunki od pocz�tku dnaego miesiaca do teraz
	string uaktualnijWD(); // update WD czyli tylko zwraca �ciezk� do odpytania bazy sql 
	void doSQLbaza(int vznak); // funkcja  obs�uguj�ca sql 
protected:
	string dataZakupow; string nazwaSklepu; double wartoscZakupow;  string strwartoscZakupow;
	string nRachSQL[3];  string NazwyOblicze�[3];  string zakresDaty;  string selektorSQL; string iloscrekordow;  string sredniarekordow;
};