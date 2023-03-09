#include "Roteador.h"
#include "Fila.h"
#include "Datagrama.h"
#include "TabelaDeRepasse.h"

Roteador::Roteador(int endereco)
{
  this->endereco = endereco;
  tabela = new TabelaDeRepasse();
  fila = new Fila(MAXIMO_TABELA);
}

Roteador::~Roteador()
{
  tabela->~TabelaDeRepasse();
  fila->~Fila();
}

TabelaDeRepasse* Roteador:: getTabela(){
  return tabela;
}

Fila* Roteador::getFila(){
  return fila;
}

int Roteador::getEndereco(){
  return endereco;
}

void Roteador::receber(Datagrama *d){

 if(fila->enqueue(d)==0){
   cout<< "\tFila em " << endereco << "estourou" << endl;
 }

}

void Roteador::processar(){
 if(fila->isEmpty() == false){
   Datagrama* datagrama = fila->dequeue();
   datagrama->processar(); // tempo de vida

   cout << "Roteador " << getEndereco() << endl;
    
    if(datagrama->ativo() == false){ //morreu
      cout << "\tDestruido por TTL: " << " Origem: " << datagrama->getOrigem() << ", Destino: " << datagrama->getDestino() << ", TTL: " <<datagrama->getTtl() << ", " << datagrama->getDado()<< endl;

      delete datagrama;
    } else if (datagrama->getDestino() == endereco){ //chegou no destino
      cout << "\tRecebido: " << getUltimoDadoRecebido() << endl;
      delete datagrama;

    } else {
      
      if(tabela->getDestino(datagrama->getDestino()) == NULL){
        delete datagrama;
      } else {
        
      tabela->getDestino(datagrama->getDestino())->receber(datagrama);

      cout << "\tEnviado para " << tabela->getDestino(datagrama->getDestino())->getEndereco() << " Origem: " << datagrama->getOrigem() << ", Destino: " << datagrama->getDestino() << ", TTL: " <<datagrama->getTtl() << ", " << datagrama->getDado()<< endl;
    }
  } 
 
  }
}

string Roteador::getUltimoDadoRecebido(){
  return datagrama->getDado();
}
