#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include <iostream>
#include <string>

#include "Roteador.h"
#include "Rede.h"

#define MAXIMO_TABELA 5

using namespace std;

class Roteador;

class TabelaDeRepasse
{
    public:
        TabelaDeRepasse();
        ~TabelaDeRepasse();

        bool mapear(int endereco, Roteador* adjacente);

        Roteador** getAdjacentes(); //ok
        int getQuantidadeDeAdjacentes(); //ok
        void setPadrao(Roteador* padrao); // eh o contador de padrao?
        Roteador* getDestino(int endereco); // ok

        void imprimir();


    protected:

    private:
    Roteador** adjacentes;
    Roteador* padrao;
    int *destinos;
    int quantidadeDeAdjacentes;
};

#endif // TABELADEREPASSE_H
