#include <iostream>
#include <string>
#include <fstream>

#include "Equipe.h"

#ifndef PERSISTENCIAEQUIPE_H
#define PERSISTENCIAEQUIPE_H
// inclua aqui as diretivas de compilacao necessarias

using namespace std;

class PersistenciaEquipe {
private:
    //inclua aqui os atributos necessarios
    ifstream leituraArq;
    ofstream escritaArq;
    Equipe *e;
    int x;
    string y;
    double total = 0;
    int quantidade = 0;
    string arquivo;

public:

    PersistenciaEquipe(string arquivo);
    virtual ~PersistenciaEquipe();

    void inserir(Equipe *e);
};
#endif // PERSISTENCIAEQUIPE_H
