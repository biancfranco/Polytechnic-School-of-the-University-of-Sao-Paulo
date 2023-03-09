#include "Competicao.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

Competicao::Competicao(string nome, int maximoValor) :
        nome(nome), maximoValor(maximoValor) {
    quantidadeDeEquipes = 0;
    quantidadeDeModalidades = 0;
    equipes = new Equipe*[maximoValor];
    modalidades = new Modalidade*[maximoValor];
}

Competicao::~Competicao() {
	delete[] equipes;
	delete[] modalidades;
}

int Competicao::getQuantidadeDeEquipes() {
    return quantidadeDeEquipes;
}

int Competicao::getQuantidadeDeModalidades() {
    return quantidadeDeModalidades;
}

Equipe** Competicao::getEquipes() {
    return equipes;
}

Modalidade** Competicao::getModalidades() {
    return modalidades;
}

bool Competicao::adicionar(Equipe* e) {
    if(quantidadeDeEquipes >= maximoValor) return false;
    for(int i = 0; i < quantidadeDeEquipes; i++) {
        if(equipes[i] == e) return false;
    }
    equipes[quantidadeDeEquipes] = e;
    quantidadeDeEquipes++;
    return true;
}

bool Competicao::adicionar(Modalidade* m) {

    if(quantidadeDeModalidades >= maximoValor) return false;

    for(int i = 0; i < quantidadeDeModalidades; i++) {
        if(modalidades[i] == m) return false;
    }

    modalidades[quantidadeDeModalidades] = m;
    quantidadeDeModalidades++;

    for(int i = 0; i < quantidadeDeEquipes; i++){
       
       try{
           m->adicionar(equipes[i]);
       } catch (EquipeRepetida *e){
           delete e;
       }
    }
    return true;
}

void Competicao::imprimir() {
    cout << nome << endl;
}
