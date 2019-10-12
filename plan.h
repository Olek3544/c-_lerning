#include<iostream>
#include<limits>
#include<cstring> 
#include<string>
#include<mysql.h>
#include<ctime>
using namespace std;
class plan {
	
public:
	void bazaTabel1(); 
	string terazData(); 
	string nazwaMiesiaca(); 
	string genNazwaTabeli(int cinznak); 
	void entshdane();
	string generatorPytan(int cznak);
	double ileZost(); 
	void zlaczkaSQL(int cnt);  // to  konektor :) pobiera dane z bazy  
	void inSQLdata(int nct);  // wsuwa dane do bazy 
	bool sprWejscie(); 
protected:
	string tabelaNazw[10]; double tabelaWartosci[10];  string skonWartosci[10]; string errWartosci[10];
	string xsum; string zapytanieSQL; string nazwyTabel[3];  string pNazwaTabeli;  
	double pozostalo; string strPozost;  string nazwa_msc; string kolumnySQL[13]; 
	// do obs³ugi funkcji generujacej daty 
	int dzien,   miesiac,  rok; string strdzien; string strmiesiac; string strrok; string przerwa = "-"; string terazDataZ;
	// obs³uga funkcji z datami  obs³uga do dziedziczenia 
	
	// bazowa obs³uga sql 
	string znaki[11];  string poleceniaSQL[19]; 
	// ob³suga zmiennych SQL na konektor 
	MYSQL* conn;  
	MYSQL_ROW row;
	MYSQL_RES *res;
	int status1; int status2; int status3;  int status4; int status5; 
};