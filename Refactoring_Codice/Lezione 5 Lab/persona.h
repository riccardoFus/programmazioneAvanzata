#ifndef PERSONA_H
#define PERSONA_H
using namespace std;

class Persona{
    private:
    protected:
        int eta;
        string nome, cognome;
    public:
        Persona(string nome, string cognome, int eta = 0);
        virtual ~Persona();
        virtual void stampa() const;
        virtual ostream& stampa_operator(ostream& os) const;
        friend ostream& operator << (ostream& os, const Persona& p);
};

ostream& operator << (ostream& os, const Persona& p);

#endif