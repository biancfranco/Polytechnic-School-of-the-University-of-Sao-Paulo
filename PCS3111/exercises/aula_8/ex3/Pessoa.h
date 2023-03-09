#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "Participante.h"

using namespace std;
class Pessoa: public Participante{
    public:
        Pessoa(string nome);
        Pessoa(string nome, int nusp);
        virtual ~Pessoa();

        virtual int getNusp();
        static int getNuspAuto();

        string getNome();

    protected:

    private:
    string nome;
    static int nusp;
};

#endif // PESSOA_H
