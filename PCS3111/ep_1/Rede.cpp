#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

Rede::Rede(Roteador** roteadores, int quantidadeDeRoteadores){
  this->quantidadeDeRoteadores = quantidadeDeRoteadores;
  this->roteadores = roteadores;
}

Rede::~Rede(){

}

Roteador* Rede::getRoteador(int endereco){

  for (int i = 0; i < quantidadeDeRoteadores; i++){
      if(roteadores[i]->getEndereco() == endereco){
        return roteadores[i];
      }
  }
  return NULL;
}

void Rede::enviar(string texto, Roteador* origem, int destino, int ttl){
  Datagrama* datagrama = new Datagrama(origem->getEndereco(),destino,ttl,texto);
  origem->receber(datagrama);
}

void Rede::passarTempo(){
  for (int i = 0; i < quantidadeDeRoteadores; i++){
    roteadores[i]->processar();
  }
}

void Rede::imprimir(){
  cout << "Voce esta imprimindo uma rede\n" << endl;
}
