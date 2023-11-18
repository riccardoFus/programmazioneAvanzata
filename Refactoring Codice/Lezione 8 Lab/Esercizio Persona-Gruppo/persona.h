#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona{
    private:
        string nome;
    public:
        Persona();
        Persona(string nome);
        Persona(const Persona& persona);
        ~Persona();
        bool operator < (const Persona& persona) const;
        friend ostream& operator << (ostream& os, const Persona& p);
    protected:
};

ostream& operator << (ostream& os, const Persona& p);

#endif