#include"plan.h"
string plan::terazData()
{
	/*int dzien, miesiac, rok;
	string strdzien; string strmiesiac; string strrok; string przerwa = "-";
	this->dzien = dzien;
	this->miesiac = miesiac; 
	this->rok = rok; 
	
	this->strdzien = strdzien; 
	this->strmiesiac = strmiesiac;
	this-> strrok = strrok;
	this->przerwa = przerwa;  */
	struct  tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	dzien = newtime.tm_mday;
	miesiac = 1 + newtime.tm_mon;
	rok = 1900 + newtime.tm_year;
	//int dzien = 1 + newtime.tm_mday;
	cout << "Numer miesiaca \n";
	strrok = to_string(rok); 
	strmiesiac = to_string(miesiac);
	strdzien = to_string(dzien); 

	cout << dzien << "-" << miesiac << "-" << rok << endl;
	terazDataZ = strrok + przerwa + strmiesiac + przerwa + strdzien; 
	cout << terazDataZ.c_str() << endl; 
	return terazDataZ;
}
void plan::bazaTabel1()
{
	string tabelaNazw[10] = { "Budzet: ", "Mieszkanie: ", "Prad: ", "Gaz: ", "IneternetTV: ", "Dziecko: ",
		"Wydatki dodatkowe: ", "Wydatki biezace: ", "Paliwo: ", "Wydatki nieprzewidziane: " };
	for (int i = 0; i < 10; i++)
	{
		this->tabelaNazw[i] = tabelaNazw[i];
		this->tabelaWartosci[i] = tabelaWartosci[i];

	}
	string znaki[11] = { ", ", "'", "'", "* ", " - ", " + ", " = ","/", ")", "(", ";" };
	for (int i = 0; i < 11; i++)
	{
		this->znaki[i] = znaki[i];
		//cout << i << "  " << znaki[i] << endl;
	}
	string poleceniaSQL[19] = { "select ", " from ", "insert ", "into ", "values", "set ", "as ", "alter ", "table ",
			" where " , "Count", "Avg", "Sum",
	   "between ", "Update ", "Delete ", "inner join ", "left join ", "right join " };
	for (int i = 0; i < 19; i++)
	{
		this->poleceniaSQL[i] = poleceniaSQL[i];
		//cout << i << " " << poleceniaSQL[i] << endl;
	}
	string kolumnySQL[13] = { "Miesiac", "BudzetP", "MieszkanieP", "PradP", "GazP", "InternetTVP", "DzieckoP",
"WydatkiDodatkoweP", "WydatkiBiezaceP", "PaliwoP", "WydatkiNieprzewidzianeP", "RataKredytP", "PozostaloP" };
	for (int i = 0; i < 13; i++)
	{
		this->kolumnySQL[i] = kolumnySQL[i];
		//cout << i << " " << kolumnySQL[i] << endl; 
	}
}

void plan::entshdane()
{ 
	//string tabelaNazw[10] = { "Budzet: ", "Mieszkanie: ", "Prad: ", "Gaz: ", "IneternetTV: ", "Dziecko: ",
		//"Wydatki dodatkowe: ", "Wydatki biezace: ", "Paliwo: ", "Wydatki nieprzewidziane: " };
	//double tabelaWartosci[10];*/
	bazaTabel1(); 
	
	
	
	for (int i = 0; i < 10; i++)
	{
		cout << "Podaj wartosci dla planu \n";
		cout << tabelaNazw[i].c_str() << endl; 
		cin >> tabelaWartosci[i];

	}
	ileZost(); 
	cout << "A Pozostalo tyle az " << pozostalo << endl; 
	inSQLdata(1);  // wsuwa dane sql 
	zlaczkaSQL(10);  // pobiera dane 
}
double plan::ileZost()
{
	double sumka=0; 
	for (int i = 0; i < 10; i++)
	{
		cout <<tabelaNazw[i] <<tabelaWartosci[i] << endl;
	}
	for (int i = 1; i < 10; i++)
	{
		sumka = sumka+tabelaWartosci[i];
	}
	pozostalo  =  tabelaWartosci[0] - sumka;
	return pozostalo;
}
string plan::nazwaMiesiaca()
{
	int dzien, miesiac, rok;
	struct  tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	dzien = newtime.tm_mday;
	miesiac = 1 + newtime.tm_mon;
	rok = 1900 + newtime.tm_year;
	//int dzien = 1 + newtime.tm_mday;
	cout << "Numer miesiaca \n";
	cout << dzien << "-" << miesiac << "-" << rok << endl;
	switch (miesiac) // to musi pójœæ do funkcji kreuj¹cej œci¿kli do folderów
	{
	case 1:
		nazwa_msc = "styczen";
		break;
	case 2:
		nazwa_msc = "luty";
		break;
	case 3:
		nazwa_msc = "marzec";
		break;
	case 4:
		nazwa_msc = "kwiecien";
		break;
	case 5:
		nazwa_msc = "maj";
		break;
	case 6:
		nazwa_msc = "czerwiec";
		break;
	case 7:
		nazwa_msc = "lipiec";
		break;
	case 8:
		nazwa_msc = "sierpien";
		break;
	case 9:
		nazwa_msc = "wrzesien";
		break;
	case 10:
		nazwa_msc = "pazdziernik";
		break;
	case 11:
		nazwa_msc = "listopad";
		break;
	case 12:
		nazwa_msc = "grudzien";
		break;
	default:
		cout << "Nie ma takiego miesiaca \n";
		break;
	} // koniec switch
	cout << nazwa_msc << endl;
	return nazwa_msc;
}
string plan::genNazwaTabeli(int cinznak)
{
	string m, xt;  string nazwyTabel[4] = { "planbud " , "realbud ", "rachunki ", "paliwo " }; // string n// string pNazwaTabeli; // = "planbud";  // nazwa tymczasowa 
	for (int i = 0; i < 4; i++)
	{
		this->nazwyTabel[i] = nazwyTabel[i]; 
 	 }

	//m = nazwaMiesiaca();
	if (cinznak == 1)
	{
		pNazwaTabeli = nazwyTabel[0]; 
		cout << pNazwaTabeli << endl;
		
	}
	else if (cinznak == 2)
	{
		pNazwaTabeli = nazwyTabel[1];
		cout << pNazwaTabeli << endl;
	}
	else if (cinznak == 3)
	{
		pNazwaTabeli = nazwyTabel[2];
		cout << pNazwaTabeli << endl;
	}
	 
	return pNazwaTabeli;
}
string plan::generatorPytan(int cznak)
{
	// pomocnicze lokalne 
	string sumWyraz;  string skonWartosci[11]; string strPozost;
	bazaTabel1(); 
	
	
	
	 this->pozostalo = pozostalo;
	 this->strPozost = strPozost; 
	 	for (int  i = 0; i < 11; i++)
	{
		 
		this->skonWartosci[i] = skonWartosci[i]; 
	}
	strPozost = to_string(pozostalo); 
	nazwaMiesiaca();  // wywolano nazwe !!!!! MIESIACA
	
	 
	
	for (int i = 0; i < 11; i++)
	{
	
		//this->znaki[i] = znaki[i];
		skonWartosci[i] = to_string(tabelaWartosci[i]);  //  valueTab[i];
		
			sumWyraz = sumWyraz + skonWartosci[i]+znaki[0]; // +przecinek;
	}
	cout << sumWyraz << endl;
	cout << "Z naszej generecji \n"; 
	cout << pNazwaTabeli << endl;
	if (cznak == 1)
	{ // zapytanie wsun do bazy  plan 
		genNazwaTabeli(1);
		zapytanieSQL = poleceniaSQL[2] + poleceniaSQL[3] + pNazwaTabeli + poleceniaSQL[4] + znaki[9] + znaki[1] + nazwa_msc + znaki[2] + znaki[0] + sumWyraz+strPozost + znaki[8] + znaki[10] ;
		cout << zapytanieSQL << endl;
	}
	else if(cznak == 10)
	{  // zapytanie pobierz dane z bazy plan 
		genNazwaTabeli(1);
		zapytanieSQL = poleceniaSQL[0] + znaki[3] + poleceniaSQL[1] + pNazwaTabeli+poleceniaSQL[9]+kolumnySQL[0]+znaki[6]+znaki[1]+nazwa_msc+znaki[2] + znaki[10];
		cout << zapytanieSQL << endl; 
	}
	else if (cznak == 2)
	{  // zapytanie wsun do tabeli realizacja 
		genNazwaTabeli(2);
		zapytanieSQL = poleceniaSQL[2] + poleceniaSQL[3] + pNazwaTabeli + poleceniaSQL[4] + znaki[9] + znaki[1] + nazwa_msc + znaki[2] + znaki[0] + sumWyraz + strPozost + znaki[8] + znaki[10];
		//zapytanieSQL = poleceniaSQL[0] + znaki[3] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + kolumnySQL[0] + znaki[6] + znaki[1] + nazwa_msc + znaki[2] + znaki[10];
		cout << zapytanieSQL << endl;
	}
	else if (cznak == 20)
	{  // zapytanie pobierz dane z bazy realizacja 
		genNazwaTabeli(2); // i tu musi byæ druga funkcja z nazwa tabeli 
		zapytanieSQL = poleceniaSQL[0] + znaki[3] + poleceniaSQL[1] + pNazwaTabeli + poleceniaSQL[9] + kolumnySQL[0] + znaki[6] + znaki[1] + nazwa_msc + znaki[2] + znaki[10];
		cout << zapytanieSQL << endl;
	}
	return zapytanieSQL;  // to jest naj naj wa¿niejsze ¿eby zwróci³o zapytanie sql :) 
}
void plan::inSQLdata(int nct)
{
	if (nct == 1)
	{
		generatorPytan(1); // wsuniecie planu 
	}
	else if (nct==2)
	{
		generatorPytan(2); // wsuniecie realizacji  
	}
	
	cout << "Z jedynka gen \n"; 
	cout << zapytanieSQL.c_str() << endl;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Lad10Lad20", "testdb", 3306, 0, 0);
	if (conn)
	{
		puts("Polaczono z baza danych");
		const char* q = zapytanieSQL.c_str();


		status1 = mysql_query(conn, q);
		if (!status1) // tutaj ju¿ odczytujesz to co chcesz z bazy danych 
		{
			//mysql_query(conn, q);
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
void plan::zlaczkaSQL( int cnt)
{
	//string kolumnySQL[12]= { "miesiac", "BudzetP", "MieszkanieP", "PradP", "GazP", "InternetTVP", "DzieckoP",
 //"WydatkiDodatkoweP", "WydatkiBiezaceP", "PaliwoP", "WydatkiNieprzewidzianeP", "RataKredytP" };
	if (cnt ==10) //  pokaz danych z planu 
	{
		generatorPytan(10);
	}
	else if (cnt = 20)
	{
		generatorPytan(20); // pokaz danych z realizacji ??
	}
	
	cout << "Z dwujka \n";
	cout << zapytanieSQL.c_str() << endl;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "Lad10Lad20", "testdb", 3306, 0, 0);
	if (conn)
	{
		puts("Polaczono z baza danych");
	const char* q = zapytanieSQL.c_str();
		
		
		status1 = mysql_query(conn, q);
		if (!status1) // tutaj ju¿ odczytujesz to co chcesz z bazy danych 
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

					cout << kolumnySQL[i] << " " << row[i] << endl;
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