#include"real.h"


void realizacja::entshdane()
{
	bazaTabel1(); 
	  tabelaWartosci[8] = 0; tabelaWartosci[9] = 0; tabelaWartosci[10] = 0;
	for (int i = 0; i < 7; i++)
	{
		cout << "Podaj wartosci dla realizacji  \n";
		cout << tabelaNazw[i].c_str() << endl;
		cin >> tabelaWartosci[i];
		

	}
	ileZost();
	cout << "A Pozostalo tyle az " << pozostalo << endl;
	inSQLdata(2);
	zlaczkaSQL(20); 

	
}