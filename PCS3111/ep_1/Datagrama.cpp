#include <iostream>
#include <string>
#include "Datagrama.h"

using namespace std;

// getters
int Datagrama::getOrigem() {
	return origem;
}

int Datagrama::getDestino() {
	return destino;
}

int Datagrama::getTtl() {
	return ttl;
}

string Datagrama::getDado() {
	return dado;
}
// Construtor:

Datagrama::Datagrama(int origem, int destino, int ttl, string dado) {
  this->origem = origem;
  this->destino = destino;
  this->ttl = ttl;
  this->dado = dado;
}

// Destrutor:

Datagrama::~Datagrama() {

}

void Datagrama::processar() {
	ttl = ttl - 1;
}

bool Datagrama::ativo() {
    bool ativo;

    if(ttl <= 0){
        ativo = false;
    } else {
        ativo = true;
    }

    return ativo;
}

// imprimir

void Datagrama::imprimir(){

    cout << "Voce esta imprimindo um datagrama\n" << endl;
}
