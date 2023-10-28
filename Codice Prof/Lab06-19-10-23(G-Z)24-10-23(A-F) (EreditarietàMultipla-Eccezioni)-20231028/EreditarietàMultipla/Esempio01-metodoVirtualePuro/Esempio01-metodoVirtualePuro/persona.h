#ifndef __PERSONA_H__
#define __PERSONA_H__

class Persona{
 private:
   char* nome;
   char* cognome;      
   int eta;      
 public:      
   Persona(char* _nome,char* _cognome,int _eta=0); 
   //stesso discorso per il distruttore sull'uso del virtual
   //virtual ~Persona(){}
   virtual void stampa()const;  
   virtual void test()=0; /*in questo caso non posso più creare istanze della classe!!!*/
};


#endif
