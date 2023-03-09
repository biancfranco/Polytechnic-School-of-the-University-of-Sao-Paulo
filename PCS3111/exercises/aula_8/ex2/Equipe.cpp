#include "Equipe.h"
#include "Pessoa.h"

Equipe::Equipe(string nome, int maxValor) : Participante(nome){
    this->nome = nome;
    this->maxValor = maxValor;
    int quantidadeDePessoas = 0;
    
    pessoas = new Pessoa*[maxValor];
    nusps = new int[maxValor];
    
    quantidadeDeNusps = 0;

}

Equipe::~Equipe()
{

}


bool Equipe::adicionar(Pessoa* p){
    if(quantidadeDePessoas >= maxValor) return false;
    for(int i = 0; i < quantidadeDePessoas; i++){
        if(pessoas[i] == p) return false;
    }
    pessoas[quantidadeDePessoas] = p;
    quantidadeDePessoas++;
    return true;
}


bool Equipe::adicionar(int usp){
    if(quantidadeDeNusps >= maxValor) return false;
    for(int i = 0; i < quantidadeDeNusps; i++){
        if(nusps[i] == usp) return false;
    }
    nusps[quantidadeDeNusps] = usp;
    quantidadeDeNusps++;
    return true;
}


Pessoa** Equipe::getPessoas(){
    return pessoas;
}

string Equipe::getNome(){
    return nome;
}

