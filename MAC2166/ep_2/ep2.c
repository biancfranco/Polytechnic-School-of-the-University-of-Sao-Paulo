/***************************************************************/
/**                                                           **/
/** Nome: Bianca Vieira Franco - Numero USP: 11808724         **/
/** Exercıcio-Programa: 02                                    **/
/** Professor: Marcel Kenji de Carli Silva                    **/
/** Turma: 02                                                 **/
/**                                                           **/
/***************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BISSEC_TOL (1e-6)
/*#define RANDOM_SEED 12348*/
#define FALHA 1 /* FALHA == voto com erro */

/* Prototipos */
void ativa_sorteador();
double sorteia_real();
int sorteia_voto_com_falha (double f);
double bissecta (int N, double a, int T, double tol);
double prob_erro (int N, double a, double f, int T);

/* "Da partida" no gerador de numeros aleatorios */
void ativa_sorteador()
{
#ifdef RANDOM_SEED
srand(RANDOM_SEED);
#else
srand(time(NULL));
#endif
}

/* devolve um real sorteado uniformemente no intervalo [0,1] */
double sorteia_real()
{
return (double) rand() / RAND_MAX;
}

int main ( )
{
    int N, T;
    double a, tol, f;
    ativa_sorteador();

    printf("Digite o numero de votantes (0 < N <= 2x10^9): ");
    scanf("%d", &N);

    printf("Digite a porcentagem de votos do candidato A (0.5 < a <= 1): ");
    scanf("%lf", &a);

    printf("Digite o numero de simulacoes (0 < T <= 2x10^9): ");
    scanf("%d", &T);

    printf("Digite a probabilidade toleravel de erros (0 <= tol <= 1): ");
    scanf("%lf", &tol);

    f = bissecta(N,a,T,tol);

    printf("Maior falha das urnas toleravel: %f",f);

    return 0;
}

/* Calculo do metodo da bisseccao */
double bissecta (int N, double a, int T, double tol)
{
    double f, fa, fb;
    f = 0; fa = 0.0; fb = 1.0;

    do {
        f = (fa + fb)/2;

        if (prob_erro(N,a,f,T) > tol){
            fb = f;

        } else {
            fa = f;
        }

    } while (fb-fa > BISSEC_TOL);

    return f;

}

/* Calculo da probabilidade de erro */
double prob_erro (int N, double a, double f, int T)
{
    int A, B, iA, iB, votosA, votosB, iT, Erro;
    double prob_erro;
    prob_erro = 0; Erro=0;

    /*  A, B == votos em A e B sem considerar possiveis falhas;
        iA, iB == contadores de votos que ja foram conferidos;
        votosB, votosB == votos em A e B atualizados;
        iT == contador de simulações já realizadas;
        Erro == contador de eleicoes com erros;
        prob_erro == probabilidade de erro;                */

    for(iT = 0; iT<T; iT++){
        votosA=0; votosB=0;
        /*Calculo dos votos sem considerar as possiveis falhas*/
        A= N*a;
        B= N-A;

        /*Calculo dos votos considerando falhas nos votos*/
        for(iA=0; iA<A; iA++){
            if (sorteia_voto_com_falha(f)==FALHA){
                votosB++;
            } else {
                votosA++;
            }
        }

         for(iB=0; iB<B; iB++){
            if (sorteia_voto_com_falha(f)==FALHA){
                votosA++;
            } else {
                votosB++;
            }
        }

        if (votosA<=votosB){
            Erro++;
        }
    }

    prob_erro = (double) Erro/T;

    return prob_erro;
}

/* Verifica um voto aleatorio */
int sorteia_voto_com_falha (double f)
{
    if (sorteia_real() < f){
        return FALHA;
    }
}
