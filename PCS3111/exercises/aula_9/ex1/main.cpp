#include <iostream>
#include <stdexcept>
#include "Modalidade.h"
using namespace std;

int main()
{

 Equipe *e1 = new Equipe("Poli",5);
 Equipe *e2 = new Equipe("FEA",6);
 
  try {

    Modalidade *m = new Modalidade("Futsal",2);
    //Modalidade *m2 = new Modalidade("Corrida",-1);
    //Modalidade *m3 = new Modalidade("",2);

    

    m->adicionar(e1);
    m->adicionar(e2);
    m->imprimir();
    
  } catch (invalid_argument *e) {
    cout << "Erro: " << e->what();
    delete e; // limpando!
  }
    return 0;
}
