#include "Pessoa.h"

int Pessoa::nusp = 12345678;

Pessoa::Pessoa(string nome, int nusp) : Participante(nome){
    this->nome = nome;
    this->nusp = nusp;
}

Pessoa::Pessoa(string nome) : Participante(nome){
    this->nome = nome;
}

Pessoa::~Pessoa(){
    //dtor
}

int Pessoa::getNusp(){
    return getNuspAuto();
}

string Pessoa::getNome(){
    return nome;
}

int Pessoa::getNuspAuto(){
    return nusp++;
}
