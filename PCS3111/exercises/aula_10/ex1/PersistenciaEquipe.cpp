#include "PersistenciaEquipe.h"

using namespace std;

PersistenciaEquipe::PersistenciaEquipe(string arquivo){
    this-> arquivo = arquivo;
}

void PersistenciaEquipe::inserir(Equipe *e){
      leituraArq.open (arquivo);

      if (leituraArq.fail()) {//Arquivo nao encontrado//(entrada.fail()==0 && entrada.bad() == 0)
        leituraArq.close();
        escritaArq.open (arquivo);
          if (escritaArq.fail())
            cout << "Erro ao escrever" << endl;
          else
            escritaArq << e->getNome() << "\n";
            escritaArq << e->getMembros() << "\n";
      }

      leituraArq >> y;
       do{
        quantidade++;
        if(quantidade%2==0){
            leituraArq >> x;
        }
        else{
            leituraArq >> y;
        }
      }while (leituraArq);

      if (!leituraArq.eof()){
        cout << "Erro de leitura" << endl;
        leituraArq.close();
      }
      
      else if (quantidade == 1)  {
        leituraArq.close();
        escritaArq.open (arquivo);
        if (escritaArq.fail())
            cout << "Erro ao escrever" << endl;
        else
            escritaArq << e->getNome() << "\n";
            escritaArq << e->getMembros() << "\n";
      }
      else{
         escritaArq.open (arquivo, ios_base::app);
            if (escritaArq.fail())
                cout << "Erro ao escrever" << endl;
            else
              escritaArq << e->getNome() << "\n";
              escritaArq << e->getMembros() << "\n";
      }

}

PersistenciaEquipe::~PersistenciaEquipe()
{
    //dtor
}
