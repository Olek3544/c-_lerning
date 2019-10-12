#include"rach.h"
void rachunek::bazaNazw()
{
	  string nRachSQL[3] = { "DataZakupow ", "NazwaSklepu ", "wartoscZakupow " };
	  string NazwyObliczeñ[3] = { "Suma ", "Srednia ", "IloscRach " };

	
	bazaTabel1(); // ok dobrze ze jest powinno dzialac 
	for (int i = 0; i < 3; i++)
	{
		this->nRachSQL[i] = nRachSQL[i];
		this->NazwyObliczeñ[i] = NazwyObliczeñ[i]; 
	}
	

}
void rachunek::wprowadzRachunek()
{
	string strwartoscZakupow;
	this->strwartoscZakupow = strwartoscZakupow; 
	bazaNazw(); // jak na razie to jest bez sensu :) 
	cout << "Podaj " << nRachSQL[0].c_str() << endl;
	cin >> dataZakupow;
	cout << "Podaj " << nRachSQL[1].c_str() << endl;
	cin >> nazwaSklepu;
	cout << "Podaj " << nRachSQL[2].c_str() << endl;
	cin >> wartoscZakupow;
	strwartoscZakupow = to_string(wartoscZakupow);
	doSQLbaza(30); 
	
	nazwaMiesiaca();
}
string rachunek::generatorPytan(int cznak)
{
	string strwartoscZakupow;  /*string nRachSQL[3] = {"DataZakupow ", "NazwaSklepu ", "wartoscZakupow " };
	this->strwartoscZakupow = strwartoscZakupow;  */
	strwartoscZakupow = to_string(wartoscZakupow); 
	bazaTabel1();
	
	for (int i = 0; i < 3; i++)
	{
		this->nRachSQL[i] = nRachSQL[i]; 
	}
	if (cznak==30)
	{// generowanie rekordu wsuwajacego dane z jednego rachunka
		
		genNazwaTabeli(3);
		zapytanieSQL = poleceniaSQL[2] + poleceniaSQL[3] + pNazwaTabeli + poleceniaSQL[4] + znaki[9] + znaki[1] +dataZakupow+znaki[1] + znaki[0]+ znaki[1]+nazwaSklepu+znaki[1] +znaki[0]+strwartoscZakupow +znaki[8] + znaki[10];
		
	}
	else if (cznak == 31)
	{ // wyciaga sume rekordów z rachunków ale ale musi jeszcze byc warunek daty 
		stwzakresDaty(); // niby zainicjue gnenerator sql 
		//zapytanieSQL = poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli+znaki[10]; 
		zapytanieSQL = selektorSQL; 
	}
	cout << zapytanieSQL.c_str() << endl;
	return zapytanieSQL; 

}
string rachunek::stwzakresDaty()
{ // funkcje potrzebne do ¿ycia funkcji 
	terazData();
	bazaNazw();
	genNazwaTabeli(3);
	
	/*int tmiesiac; //  = 1;
	cout << "Pdaj znak testowy \n"; 
	cin >> tmiesiac; */
	switch (miesiac) // generuje sie z klasy plan
	{
	case 1:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-01-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		break;
	case 2:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-02-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 3:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-03-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 4:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-04-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 5:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-05-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 6:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-06-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 7:
		selektorSQL= poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-07-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 8:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-08-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 9:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] +znaki[0]+ poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] +znaki[0]+ poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-09-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 10:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-10-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	case 11:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-11-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
	
		break;
	case 12:
		selektorSQL =  poleceniaSQL[0] + poleceniaSQL[12] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-12-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		
		break;
	default:
		cout << "Nie ma takiego miesiaca \n";
		break;
	} // koniec switch
	cout << "Nasza nazwa miesiaca to jest \n";
	cout << miesiac << endl;
	cout << selektorSQL.c_str() << endl;
	
	
	return zakresDaty; 
}
string rachunek::stwzakresDaty(int c) // zwraca œredni¹ daty 
{
	switch (miesiac) // generuje sie z klasy plan
	{
	case 1:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-01-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		break;
	case 2:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-02-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 3:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-03-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 4:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-04-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 5:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-05-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 6:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-06-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 7:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-07-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 8:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-08-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 9:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-09-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 10:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-10-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 11:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-11-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 12:
		sredniarekordow = poleceniaSQL[0] + poleceniaSQL[11] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-12-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	default:
		cout << "Nie ma takiego miesiaca \n";
		break;
	} // koniec switch
	cout << "Nasza nazwa miesiaca to jest \n";
	cout << miesiac << endl;
	cout << sredniarekordow.c_str() << endl;


	return zakresDaty;
}
string rachunek::stwzakresDaty(int c, int d)
{
	switch (miesiac) // generuje sie z klasy plan
	{
	case 1:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-01-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];
		break;
	case 2:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-02-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 3:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-03-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 4:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-04-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 5:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-05-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 6:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-06-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 7:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-07-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 8:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-08-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 9:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] +znaki[0] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-09-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 10:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-10-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 11:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-11-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	case 12:
		selektorSQL = poleceniaSQL[0] + poleceniaSQL[10] + znaki[9] + nRachSQL[2] + znaki[8] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + nRachSQL[0] + poleceniaSQL[13] + znaki[1] + strrok + "-12-01" + znaki[1] + " and " + znaki[1] + terazDataZ + znaki[1] + znaki[10];

		break;
	default:
		cout << "Nie ma takiego miesiaca \n";
		break;
	} // koniec switch
	cout << "Nasza nazwa miesiaca to jest \n";
	cout << miesiac << endl;
	cout << selektorSQL.c_str() << endl;


	return zakresDaty;
 }
string rachunek::uaktualnijWD()
{ 
	nazwaMiesiaca(); 

	zapytanieSQL = poleceniaSQL[14] + pNazwaTabeli + poleceniaSQL[5] + kolumnySQL[8]+ znaki[6] + "30.99" + poleceniaSQL[9] + kolumnySQL[0] + znaki[6] + znaki[1] + nazwa_msc + znaki[1]+znaki[10];
	cout << zapytanieSQL.c_str() << endl; 
	return zapytanieSQL; 
}
void rachunek::doSQLbaza(int vznak)
{// funkcja do odptytania bazy danych 
	generatorPytan(30); // wsuniecie pojadynczego rachunku
	stwzakresDaty(); // odpytanie o 
					 //stwzakresDaty(1);
	bazaNazw(); 
	/*if (vznak == 30)
	{
		generatorPytan(30); // wsuniecie pojadynczego rachunku 
	}
	else if (vznak == 31)
	{
		generatorPytan(31); // wsuniecie realizacji  
	} */
	
	cout << "Z dwujka \n";
	cout << zapytanieSQL.c_str() << endl;
	cout << selektorSQL.c_str() << endl; 
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Lad10Lad20", "testdb", 3306, 0, 0);
	if (conn)
	{
		puts("Polaczono z baza danych");
		const char* q = zapytanieSQL.c_str();
		const char* q1 = selektorSQL.c_str();
		//const char* q2 = sredniarekordow.c_str(); // zaczo³eœ od zminy œredniej rekordów tzn "wyci¹gniêcie œredni¹ z rekordów " 
		// 1. Wstaw nowy rekord z rachunkiem  do sql 
		// 2. odpytaj z sumy, ilosci rekordów oraz sredniej 
		// 3. Wykoonaj aktualizacje wydatkow biezacych 
		// 4. Wykonaj aktualiazcje pozosta³o 
		status1 = mysql_query(conn, q); // wsuwasz do bazy danych sql 
		status2 = mysql_query(conn, q1);
		//status3 = mysql_query(conn, q2); 
		
		if (!status2) // tutaj ju¿ odczytujesz to co chcesz z bazy danych 
		{

			res = mysql_store_result(conn);
			unsigned int num_fields;
			unsigned int i;
			num_fields = mysql_num_fields(res);
			while (row = mysql_fetch_row(res))
			{
				unsigned long *lengths;
				lengths = mysql_fetch_lengths(res);
				for (i = 0; i < num_fields; i++)
				{

					cout << NazwyObliczeñ[i]<< " " << row[i] << endl;
				}

			}



			mysql_close(conn);
		}

		else
		{
			cout << "Blad polaczenia \n " << mysql_error(conn) << endl;
		}
		

	}
	else
	{
		puts("Nie polaczono z baza SQL \n");
		puts("Sprawdz haslo do bazy\n");
		cout << mysql_error(conn) << endl;
	}

}