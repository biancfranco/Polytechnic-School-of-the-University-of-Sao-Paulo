#include <iostream>
#include <stdexcept>
#include "Modalidade.h"
#include "EquipeRepetida.h"
using namespace std;

int main()
{
  
 Equipe *e1 = new Equipe("Poli",5);
 Equipe *e2 = new Equipe("FEA",6);

  try {

    Modalidade *m = new Modalidade("Futsal",2);

    m->adicionar(e1);
    m->adicionar(e1);

    m->imprimir();

  } catch (EquipeRepetida *e) {
    cout << "Erro: " << e->what();
    delete e; 
  }
   
    return 0;
}
