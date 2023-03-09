#ifndef DATAGRAMA_H
#define DATAGRAMA_H
#include <iostream>
#include <string>

using namespace std;

class Datagrama
{

    public:
        Datagrama(int origem, int destino, int ttl, string dado);
        ~Datagrama();
        int getOrigem();
        int getDestino();
        int getTtl();
        string getDado();
        void processar();
        bool ativo();
        void imprimir();

    protected:

    private:
        int origem; // qual nó o enviou
        int destino; //qual nó deve recebe-lo
        int ttl; //time to live
        string dado; //dado a ser transmitido

};

#endif // DATAGRAMA_H
