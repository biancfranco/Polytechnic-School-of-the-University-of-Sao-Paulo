/***************************************************************/
/**                                                           **/
/**   Nome: Bianca Vieira Franco      Numero USP: 11808724    **/
/**   Exercicio-Programa: EP0                                 **/
/**   Professor: Marcel Kenji de Carli Silva                  **/
/**   Turma: 02                                               **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
int main()
{
    int n, ant, atual, prox, ultimo, cont, tn;

    printf("Digite um numero n>=0 para calcular T(n) na sequencia de Tetranacci.\n");
    scanf("%d", &n);

    if(n<3) {
        printf("T(%d) = 0\n",n);
    } else {
        if(n == 3){
        printf("T(%d) = 1\n",n);
        } else {
            ant=0;
            atual=0;
            prox=0;
            ultimo=1;
            tn = 0;
            for (cont=3; cont<n; cont++) {
                tn= ant + atual + prox + ultimo;
                ant= atual;
                atual= prox;
                prox= ultimo;
                ultimo= tn;
            }
            printf("T(%d) = %d.\n",n,tn);
        }
    }
    return 0;
}
