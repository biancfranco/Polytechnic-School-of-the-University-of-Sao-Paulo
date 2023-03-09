#include "TabelaDeRepasse.h"
#include "Roteador.h"
#include "Rede.h"

TabelaDeRepasse::TabelaDeRepasse(){
    quantidadeDeAdjacentes = 0;
    adjacentes = new Roteador*[MAXIMO_TABELA];
    destinos = new int [MAXIMO_TABELA];
    padrao = NULL;
}

// Destrutor
TabelaDeRepasse::~TabelaDeRepasse()
{
    delete[] adjacentes;
}


// Imprimir:

void TabelaDeRepasse::imprimir(){
    cout << "Voce esta imprimindo uma Tabela De Repasse\n" << endl;
}


bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente){
    if(getQuantidadeDeAdjacentes()>=MAXIMO_TABELA){
      return false;
    }
    else{
    for (int i = 0; i < MAXIMO_TABELA; i++){

      if(destinos[i] == endereco){
        adjacentes[i] = adjacente;
      }
    }

    destinos[getQuantidadeDeAdjacentes()] = endereco;
    this->adjacentes[getQuantidadeDeAdjacentes()] = adjacente;
    return true;
}
}



Roteador** TabelaDeRepasse::getAdjacentes(){
    return adjacentes;
}




int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
  for(int i = 0; i < MAXIMO_TABELA; i++){
    quantidadeDeAdjacentes = i;
    if(adjacentes[i]==NULL){
      return quantidadeDeAdjacentes;
    }
}
    return MAXIMO_TABELA;
}



void TabelaDeRepasse::setPadrao(Roteador* padrao) {
  this->padrao = padrao;
}




Roteador* TabelaDeRepasse::getDestino(int endereco) {
  for(int i = 0; i < MAXIMO_TABELA; i++){
    if(destinos[i] == endereco){
      return adjacentes[i];
    }
  }
  return padrao;
}
