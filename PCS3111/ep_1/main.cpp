#include <iostream>
#include <string>

#include "Datagrama.h"
#include "Fila.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

using namespace std;

int menu (){
  int opcao;
    while (opcao > 3 || opcao <= 0){
    cout << "Simulador de Rede\n";
    cout << "---\n";
    cout << "1) Enviar um datagrama\n";
    cout << "2) Passar tempo\n";
    cout << "3) Sair\n";
    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << endl;
}
  return opcao;
}


int main()
{
    int opcao, origem, destino, ttl, tempo;
    string mensagem;

    Roteador* r1 = new Roteador(1);
    Roteador* r2 = new Roteador(2);
    Roteador* r3 = new Roteador(3);
    Roteador* r4 = new Roteador(4);
    Roteador* r5 = new Roteador(5);
    Roteador* r6 = new Roteador(6);


    r1->getTabela()->setPadrao(r2);
    r2->getTabela()->setPadrao(r5);
    r3->getTabela()->setPadrao(r2);
    r4->getTabela()->setPadrao(r5);
    r5->getTabela()->setPadrao(r2);
    r6->getTabela()->setPadrao(r5);

    r1->getTabela()->mapear(4,r4);
    r2->getTabela()->mapear(1,r1);
    r2->getTabela()->mapear(3,r3);
    r3->getTabela()->mapear(6,r6);
    r4->getTabela()->mapear(1,r1);
    r5->getTabela()->mapear(4,r4);
    r5->getTabela()->mapear(6,r6);
    r6->getTabela()->mapear(3,r3);

    Roteador** roteadores = new Roteador*[6];
    roteadores[0]=r1;
    roteadores[1]=r2;
    roteadores[2]=r3;
    roteadores[3]=r4;
    roteadores[4]=r5;
    roteadores[5]=r6;

    Rede* rede = new Rede(roteadores, 6);

    opcao = menu();

    while (opcao != 3){

        if (opcao == 1){
        cout << "Endereco do roteador de origem: ";
        cin >> origem;

        cout << "Endereco de destino: ";
        cin >> destino;

        cout << "TTL: ";
        cin >> ttl;

        cout << "Mensagem: ";
        cin >> mensagem;
        cout << endl;

        rede->enviar(mensagem,roteadores[origem-1],destino,ttl);

        opcao = menu();
    }
    
        if (opcao == 2){
        cout << "Quantidade de tempo: ";
        cin >> tempo;
        cout << endl;

        for(int i=1; i <= tempo; i++){
          cout << "arroz1";
          cout << "Instante " << i << endl;
          cout << "arroz2";
          rede->passarTempo();
          cout << "arroz3";
        }

        opcao = menu();
    }

    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    delete r6;

    delete[] roteadores;

    delete rede;

 }
    return 0;
}
