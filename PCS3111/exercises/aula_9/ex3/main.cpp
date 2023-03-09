#include <iostream>
#include <stdexcept>
#include "Modalidade.h"
#include "EquipeRepetida.h"
#include "Competicao.h"
using namespace std;

int main()
{

 Competicao *c = new Competicao("InterUsp",2);
  
 Equipe *e1 = new Equipe("Poli",5);
 Equipe *e2 = new Equipe("FEA",6);

  c->adicionar(e1);
  c->adicionar(e2);

Modalidade *m = new Modalidade("Futebol",2);
  m->adicionar(e1);
  
  c->adicionar(m);

  m->imprimir();
  c->imprimir();

    return 0;
}
