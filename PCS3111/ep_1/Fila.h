#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"


class Fila
{
    public:
        Fila(int tamanho);
        ~Fila();
        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();
        void imprimir();

    protected:

    private:
        int tamanho;
        int quantidade;
        int fim;
        int inicio;
        Datagrama** fila;

};

#endif // FILA_H
