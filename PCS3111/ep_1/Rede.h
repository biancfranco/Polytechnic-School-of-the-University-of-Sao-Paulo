#ifndef REDE_H
#define REDE_H
#include <iostream>
#include <string>

#include "Roteador.h"

using namespace std;

class Roteador;

class Rede
{
    public:
      Rede(Roteador** roteadores, int quantidadeDeRoteadores);
      ~Rede();

      Roteador* getRoteador(int endereco);

      void enviar(string texto, Roteador* origem, int destino, int ttl);
      void passarTempo();
      void imprimir();

    // a rede em si é criada na main com todos os endereços dos roteadores
    protected:

    private:
    int quantidadeDeRoteadores;

    Roteador** roteadores;



};

#endif // REDE_H
