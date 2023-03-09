#include "Modalidade.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

Modalidade::Modalidade(string nome, int maximoEquipes) :
        nome(nome), maximoEquipes(maximoEquipes) {
    if (nome.empty() ) throw new invalid_argument ("Nome vazio");
    else if(maximoEquipes <= 1) throw new invalid_argument ("Maximo de Equipes Invalido");
    quantidade = 0;
    equipes = new Equipe*[maximoEquipes];
}

Modalidade::~Modalidade() {
    delete[] equipes;
}

void Modalidade::adicionar(Equipe* e) {
    if(quantidade >= maximoEquipes) throw new overflow_error ("Equipes esta cheio");
    equipes[quantidade] = e;
    quantidade++;
}


string Modalidade::getNome() {
    return nome;
}

int Modalidade::getQuantidade() {
    return quantidade;
}

void Modalidade::imprimir() {
    for(int i = 0; i < quantidade; i++) {
        equipes[i]->imprimir();
    }
}
