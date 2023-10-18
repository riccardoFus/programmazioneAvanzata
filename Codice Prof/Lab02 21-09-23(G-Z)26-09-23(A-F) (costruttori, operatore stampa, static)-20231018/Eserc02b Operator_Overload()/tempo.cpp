#include "tempo.h"

tempo::tempo()
{sec=0;
}

tempo::tempo(int ore)
{sec=ore*3600;
 normalize();
}

tempo::tempo(int ore, int minuti, int secondi)
{sec=ore*3600+minuti*60+secondi;
 normalize();
}

int tempo::Ore()const
{return sec/3600; // usa la divisione fra interi
}   

int tempo::Minuti()const
{return (sec-Ore()*3600)/60; 
}

int tempo::Secondi()const
{return sec%60; // usa la divisione modulo (cioe' il resto) 
}

void tempo::ImpostaTempo(int ore, int minuti, int secondi)
{sec=ore*3600+minuti*60+secondi;
 sec=sec%(3600*24); //riporto sec nell'ambito delle 24 ore    
}

void tempo::AggiungiOra()
{sec=sec+3600;
 normalize();
}


void tempo::normalize()
{sec=sec%(3600*24);}
 
ostream& operator<<(ostream& os, tempo& t)
{//return os<<t.Ore()<<":"<<t.Minuti()<<":"<<t.Secondi()<<"sec="<<t.sec; //funziona solo se friend
return os<<t.Ore()<<":"<<t.Minuti()<<":"<<t.Secondi();
}
 
void test_tempo()
{tempo t;
 cout<<"ore"<<t.Ore();
 cout<<"minuti"<<t.Minuti();
 cout<<"secondi"<<t.Secondi();
 t.ImpostaTempo(11,51,50);
 cout<<"ore"<<t.Ore();
 cout<<"minuti"<<t.Minuti();
 cout<<"secondi"<<t.Secondi();
 tempo t2(12,18,0); //chiama il costruttore a tre parametri
 cout<<"ore"<<t2.Ore();
 cout<<"minuti"<<t2.Minuti();
 cout<<"secondi"<<t2.Secondi();
 cout<<t2;
 operator<<(cout,t2); // equivalente alla chiamata sopra.
 cout<<endl<<"t="<<t<<"t2="<<t2;
 tempo t3(13);
 cout<<endl<<t3;
 //t=17; //conversione implicita di tipo
 t=tempo(17); //conversione esplicita di tipo
 cout<<endl<<t;
 tempo t4(12,56); //costruttore a due paramtri (tre parametri)
 cout<<endl<<t4;
 //t2=17.50; //non dovrebbe funzionare???
 //cout<<endl<<t2;
 //t.normalize();// non funziona e' privato
 tempo t5(11,19);
 cout<<endl<<t5;
 t5.AggiungiOra();
 cout<<endl<<t5;
}
