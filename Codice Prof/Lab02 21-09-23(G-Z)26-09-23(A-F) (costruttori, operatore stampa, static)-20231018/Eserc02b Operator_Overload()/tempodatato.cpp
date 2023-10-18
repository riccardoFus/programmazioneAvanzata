#include "tempodatato.h"

tempodatato::tempodatato()
{giorno=1;
 mese=1;
 anno=2000;
}

tempodatato::tempodatato(int _g,int _m,int _a,
                       int _o, int _mi, int _s)
                       :tempo(_o,_mi,_s) //chiama il cos. di tempo
{giorno=_g; 
 mese=_m;
 anno=_a;
}                       

void tempodatato::AggiungiOra()
{ if (Ore()>=23) { //sec=sec+3600; normalize(); // Si se sec protected
                  tempo::AggiungiOra();
                  giorno++;
                  //occorre normalizzare la data opportunamente
                  }
  else tempo::AggiungiOra();
};


ostream& operator<<(ostream& os, const tempodatato& td)
{os<<td.giorno<<"/"<<td.mese<<"/"<<td.anno<<"ore: ";
 os<<td.Ore()<<":"<<td.Minuti()<<":"<<td.Secondi();
 return os;
}

void test_tempodatato()
{tempodatato td;
cout<<td;
tempo t;
t=td;
cout<<t;
//td=t; non si puo' fare
tempodatato td2(27,10,2015,12,29,00);
cout<<endl<<td2;
td2.AggiungiOra();
cout<<endl<<td2;
tempodatato td3(26,10,2015,23,15,00);
cout<<endl<<td3;
td3.AggiungiOra();
cout<<endl<<td3;
tempodatato td4(27,10,2015,23,45,00);
cout<<endl<<td4;
tempo* pt;
pt=&td4;
pt->AggiungiOra(); //chiama il metodo della classe base se NOn definito virtual
                   //chiama il metodo della classe derivata se definito virtual
cout<<endl<<td4;
tempodatato* ptd;
//ptd=&t; non si puo' fare
}
