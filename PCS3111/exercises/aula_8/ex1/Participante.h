#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <iostream>
#include <string>

using namespace std;

class Participante {
public:
    Participante(string nome);
    virtual ~Participante();

    virtual void imprimir();
    virtual string getNome() = 0;

private:
    string nome;
    
};

#endif // PARTICIPANTE_H

