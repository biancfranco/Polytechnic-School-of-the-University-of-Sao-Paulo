#ifndef ROTEADOR_H
#define ROTEADOR_H
#include <iostream>

#include "TabelaDeRepasse.h"
#include "Fila.h"

#define TAMANHO_FILA 3

using namespace std;

class TabelaDeRepasse;

class Roteador
{
    public:
        Roteador(int endereco); // eh o mesmo do datagrama?
        ~Roteador();

        TabelaDeRepasse* getTabela();
        Fila* getFila();

        int getEndereco();
        void receber(Datagrama* d);
        void processar(); //comparar se o endereço do datagrama é o mesmo do roteador
        // quando retirar um datagrama da fila, usamos o processar do datagrama (ttl-1)
        string getUltimoDadoRecebido();
        void imprimir();

    protected:

    private:
    int endereco;
    Datagrama* datagrama;
    string ultimoDadoRecebido;
    TabelaDeRepasse* tabela;
    Fila* fila;

};

#endif // ROTEADOR_H
