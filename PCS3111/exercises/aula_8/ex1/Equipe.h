#ifndef EQUIPE_H
#define EQUIPE_H
#include <string>
#include <iostream>
#include "Pessoa.h"
#include "Participante.h"

using namespace std;

class Equipe: public Participante{
public:
    Equipe(string nome, int maxValor);
    virtual ~Equipe();

    virtual bool adicionar(Pessoa* p); //
    virtual Pessoa** getPessoas(); //

    virtual bool adicionar(int nusp);

    string getNome();

private:
    string nome;
    int maxValor;
    
    int quantidadeDePessoas;
    int quantidadeDeNusps;

    int* nusps;//adicionar no metodo adicionar nusps
    Pessoa** pessoas;//utilizar no metodo adicionar pessoas
};

#endif // EQUIPE_H
