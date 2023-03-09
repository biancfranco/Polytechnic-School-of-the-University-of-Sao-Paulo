/***************************************************************/
/**                                                           **/
/**   Nome: Bianca Vieira Franco      Numero USP: 11808724    **/
/**   Exercicio-Programa: EP1                                 **/
/**   Professor: Marcel Kenji de Carli Silva                  **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>

int main() {

    int num,a,b,c,d,soma,div,composto,prox,primo;
    primo = 0; composto = 0;
    a = 2; b = 3; c = 5; d = 7;
    /*a,b,c,d sao os menores numeros primos possiveis*/
    printf("EP1: Soma dos quadrados de quatro numeros primos consecutivos\n");
    printf("Digite um numero (0 < n < 10^8): ");
    scanf("%d", &num);

    while (num != 0){

        soma = (a*a) + (b*b) + (c*c) + (d*d);

        if (soma > num){
            printf("O numero %d nao pode ser escrito!\n", num);
            scanf("%d", &num);
            a = 2; b = 3; c = 5; d = 7;
            soma = (a*a) + (b*b) + (c*c) + (d*d);
            /*a,b,c,d,soma retornam para seus menores valores possiveis*/
        }

        if (soma == num){
            printf("%d = %d^2 + %d^2 + %d^2 + %d^2\n", num,a,b,c,d);
            a = 2; b = 3; c = 5; d = 7; soma=0;
            /*a,b,c,d,soma retornam para seus menores valores possiveis*/
            scanf("%d", &num);

        } else {
            prox = d + 1;
            /*prox ira resultar no proximo numero primo*/

            while (primo==0){

                for (div = 2; div < prox; div++){

                    if (prox % div == 0){
                    composto = 1;
                    /*composto=1 indica que o numero encontrado nao eh primo*/
                    }

                }

                if (!composto==1){
                    a = b; b = c; c = d; d = prox;
                    primo = 1;
                    /*primo=1 indica que o numero encontrado foi primo*/
                }
            composto = 0;
            prox++;
        }
        primo = 0;
    }
    }
    return 0;
}
