#include "Pessoa.h"

Pessoa::Pessoa(string nome, int nusp) : Participante(nome)
{
    this->nome = nome;
    this->nusp = nusp;
}

Pessoa::~Pessoa()
{
    //dtor
}

int Pessoa::getNusp(){
    return nusp;
}

string Pessoa::getNome(){
    return nome;
}
