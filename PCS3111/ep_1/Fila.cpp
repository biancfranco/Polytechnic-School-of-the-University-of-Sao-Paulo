#include <iostream>
#include <string>

#include "Fila.h"

using namespace std;

// Construtor:
Fila::Fila(int tamanho) : tamanho(tamanho){
  inicio = 0;
  fim = 0; //pois o fim da lista ligada circular é sempre o anterior ao inicio;
  quantidade = 0;
  fila = new Datagrama*[tamanho];
}

// Destrutor:
Fila::~Fila(){

}

// Imprimir:

void Fila::imprimir(){

}


// Outras funcoes:

bool Fila::enqueue(Datagrama* d) {

   if (quantidade >= tamanho) return false;
    else {

        for(int i = 0; i < quantidade; i++) {
            if(d == fila[i]) return false;
        }        
        fila[fim] = d;
        fim=fim+1;
        fim = (fim + 1) % tamanho;
      // fila[quantidade] = d; <----- Essa pode ser uma outra forma de resolver
        quantidade++;
        return true;
    }
    return false;
}


Datagrama* Fila::dequeue(){

    Datagrama* elemento;

    if (isEmpty()){
        elemento = NULL;
    } else{      
        elemento = fila[inicio];
        inicio = (inicio + 1) % tamanho;
        quantidade--;
    }
    return elemento;
}

bool Fila::isEmpty(){
  
    if (quantidade == 0){
      return true;
    } else {
      return false;
      }
}
