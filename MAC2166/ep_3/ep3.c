/***************************************************************/
/**                                                           **/
/** Nome: Bianca Vieira Franco - Numero USP: 11808724         **/
/** Exercıcio-Programa: 03                                    **/
/** Professor: Marcel Kenji de Carli Silva                    **/
/** Turma: 02                                                 **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 400
#define MAX2 160000
#define FNMAX 200

/*Prototipos*/

int LeArquivo (FILE *arquivo);

int LeDesenho( char nomearq[FNMAX], int M[MAX][MAX], int *pm, int *pn, int *pmax );

int LeTexto( char nomearq[FNMAX], char T[MAX2], int *pk );

int BeDe( int k, int m, int n, int *pb, int *pd );

int ProximosBBits( char T[MAX2], int b, int *pik, int *pib );

void Codifica( int D[MAX][MAX], int m, int n, char T[MAX2], int k, int Dl[MAX][MAX], int b, int d, int modo );

int Maximo( int D[MAX][MAX], int m, int n );

int EscreveDesenho( char nomearq[FNMAX], int M[MAX][MAX], int m, int n, int max );

void DeBeDe( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n, int *pb, int *pd );

int DeCodifica( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n, int b, int d, char T[MAX2], int modo );

int EscreveTexto( char nomearq[FNMAX], char T[MAX2], int k );

int Potencia (int b);

int Menu (int modo);

/*Funcoes*/

int Menu (int modo){
int OPCAO;
printf("Digite a operacao desejada:\n");
printf("   1. Codificar\n");
printf("   2. Decodificar\n");
printf("   3. Mostrar mensagem\n");
if (modo){
printf("   4. Desativar modo verborragico\n");
} else {
printf("   4. Ativar modo verborragico\n");
}
printf("   0. Finalizar\n");

printf("OPCAO: ");
scanf("%d", &OPCAO);

while (OPCAO > 4 || OPCAO <0){
  printf("ERRO: Opcao invalida. Digite novamente: ");
  scanf("%d", &OPCAO);
} 
return OPCAO;

}

/***************************************************************/


int LeArquivo (FILE *arquivo) {
  int valor, i, caractere;
    i = fscanf (arquivo, "%d", &valor);
    if (i == 1){ 
      return valor;
    } 
    caractere = fgetc (arquivo);
    if (caractere == EOF){
      return caractere;
      }
    
    if (caractere != '\n') {
      return EOF;
    }

  return 0;
}

/***************************************************************/

int LeDesenho( char nomearq[FNMAX], int M[MAX][MAX], int *pm, int *pn, int *pmax ) {

  FILE *arq ;
  char v[MAX2] ;
  int  aux, i, j ;
  
  if(!(arq = fopen(nomearq, "r"))) {
        printf("Erro na leitura do arquivo %s", nomearq);
        return 1;
    }
  
  aux = fscanf(arq, "%s", v) ;

  if(aux != 1) {
    printf("Erro na leitura do arquivo %s\n", nomearq) ;
    fclose(arq) ;
    return 1 ;
  }

  if(strcmp(v,"P2") != 0) {
    printf("Formato desconhecido\n") ;
    fclose(arq) ;
    return 1 ;
  }

  *pn = LeArquivo (arq); 

  *pm = LeArquivo (arq);  

  *pmax = LeArquivo (arq);

  if(*pm == EOF || *pn == EOF || *pmax == EOF) {
    printf ("%d %d %d\n", *pn, *pm, *pmax);
    printf("Formato incorreto\n") ;
    fclose(arq) ;
    return 1 ;
  }
 
  if(*pm>MAX || *pn>MAX) {
    printf("Dimensao da matriz maior que o permitido\n") ;
    fclose(arq);
    return 1 ;
  }
 
  for(i=0; i<*pm; i++) {
    for(j=0; j<*pn; j++) {
      aux = M[i][j] = LeArquivo (arq);
      if(aux == EOF) {
        printf("Formato ou dado incorreto\n") ;
        fclose(arq) ;
        return 1 ;
      }
    }
  }
 
  fclose(arq) ;
  return 0 ;
}

/***************************************************************/

int LeTexto(char nomearq[FNMAX], char T[MAX2], int *pk) {
  
  FILE *arq ;
  char caractere;
  int  i ;

  if(!(arq = fopen(nomearq, "r"))) {
    printf("Erro na abertura do arquivo %s\n", nomearq) ;
    return 1 ;
  }

  i = 0 ;
  caractere = fgetc(arq) ;

  while(!feof(arq)) {
    if(i>=MAX2) {
      printf("Mensagem muito longa\n") ;
      fclose(arq) ;
      return 1 ;
    }

    if (caractere < 0) {
      printf ("Caractere %c desconhecido. Codigo do caractere: %d\n", caractere, caractere);
      fclose(arq) ;
      return 1 ;
    }

    T[i] = caractere ;
    i++ ;

    caractere = fgetc(arq) ;
  }
  *pk = i ;

  fclose(arq) ;

  return 0 ;
}

/***************************************************************/

int EscreveDesenho(char nomearq[FNMAX], int M[MAX][MAX], int m, int n, int max) {
 
  FILE *arq ;
  int  i, j ;

  if(!(arq = fopen(nomearq, "w"))) {
    printf("Erro na abertura do arquivo %s\n", nomearq) ;
    return 1 ;
  }

  fprintf(arq, "P2\n") ;
  fprintf(arq, "%d %d\n", n, m) ;
  fprintf(arq, "%d\n", max) ;

  for(i=0; i<m; i++) {
    for(j=0; j<n; j++) {
      fprintf(arq, "%03d ", M[i][j]) ;
    }
    fprintf(arq, "\n") ;
  }

  fclose(arq) ;
  return 0 ;
}

/***************************************************************/

int EscreveTexto(char nomearq[FNMAX], char T[MAX2], int k) {

  FILE *arq ;
  int  i ;
  char caractere;

  if(!(arq = fopen(nomearq, "w"))) {
    printf("Erro na abertura do arquivo %s\n", nomearq) ;
    fclose(arq) ;
    return 1 ;
  }

    i = 0 ;
    while(i<k) {

    caractere = T[i] ;

    if (caractere < 0) {
      printf ("Caractere %c desconhecido. Codigo do caractere: %d\n", caractere, caractere);
      fclose(arq) ;
      return 1 ;
    }

    fprintf(arq, "%c", caractere) ;

    i++;
  }

  fclose(arq) ;

  return 0 ;
}

/***************************************************************/


int BeDe( int k, int m, int n, int *pb, int *pd ){

int b, d, min, bi;
bi = 0;

for (b = 8; b > 0; b--){
if ((m*n-1)*b >= 8 * k){
  *pb = b;
  bi = b;
}

}

if ( m >= n){
  min = n;
} else {
  min = m;
}

for (d = 1; d <= min; d++){
if (((m/d)*(n/d))*bi >= (8*k) + bi){
  *pd = d;
}

}

return 0;
}

/***************************************************************/


void Codifica( int D[MAX][MAX], int m, int n, char T[MAX2], int k, int Dl[MAX][MAX], int b, int d, int modo){

int i, j, pik, pib, bit, soma;
pib = 0; pik = 0;

if (modo){

  for (i = (d-1); i < (m/d); i = i + d){
  for(j=(d-1); j < (n/d); j = j + d){

  if (i <= (d-1) && j <= (d-1)){
    bit = b;
    soma = D[i][j] + b;
        Dl[i][j] = ((D[i][j] / Potencia(b)) * Potencia(b)) + (soma % Potencia(b));
        printf("(%d,%d) bits %d original %02x codificado %02x\n", i, j, bit, D[i][j],  Dl[i][j]);

  } else {
    bit = ProximosBBits(T, b, &pik, &pib);

      soma = D[i][j] + bit;

      if (pib <= 0){
        pik = pik + 1;
        }

    Dl[i][j] = ((D[i][j] / Potencia(b)) * Potencia(b)) + (soma % Potencia(b));
    printf("(%d,%d) bits %d original %02x codificado %02x\n", i, j, bit, D[i][j], Dl[i][j]);
  }
      
}

}

} else {

for (i = (d-1); i < (m/d); i = i + d){
  for(j=(d-1); j < (n/d); j = j + d){

  if (i <= (d-1) && j <= (d-1)){
    bit = b;
   soma = D[i][j] + b;
    Dl[i][j] = ((D[i][j] / Potencia(b)) * Potencia(b)) + (soma % Potencia(b));

  } else {
    bit = ProximosBBits(T, b, &pik, &pib);
      soma = D[i][j] + bit;
      if (pib <= 0){
        pik = pik + 1;
        }
    Dl[i][j] = ((D[i][j] / Potencia(b)) * Potencia(b)) + (soma % Potencia(b));
      
  }
      
}

}
}

}

/***************************************************************/

int ProximosBBits(char T[MAX2], int b, int *pik, int *pib){

int proximos, vet;

vet = T[*pik];

vet = T[*pik] / Potencia(*pib);

proximos = vet % Potencia(b);

*pib = *pib + b;

if (*pib > 8 - b){
*pib = 0;

}

return proximos;
}

/***************************************************************/

int Potencia (int b){
int pot, i;
pot = 1;
  for (i = 0; i < b; i++){
    pot = pot * 2;
  }
return pot;
}

/***************************************************************/


int Maximo( int D[MAX][MAX], int m, int n ){
  
  int i, j, MaxVal;
  i = 1; j = 1;
  MaxVal = D[i-1][j-1];

  for (i = 1; i < m; i++){
    for (j = 1; j < n; j++){
     if (MaxVal < D[i][j]){
       MaxVal = D[i][j];
     }

    }
  }
  
  return MaxVal;
}

/***************************************************************/

void DeBeDe( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n, int *pb, int *pd ){
int i, j, x, z, b, B, aux;

/*Para encontrar valor de *pd*/
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){
    if (Dl[i][j] - D[i][j] != 0){
    aux = i;
    *pd = aux + 1;
    i = m; j = n;
    }
    }

}

/*Para encontrar valor de *pb*/
for(i = 0; i < m; i++){
    for(j = 0; j < n; j++){

        for (b = 1; b <= 8; b++){
        z = Dl[i][j]; x = D[i][j];
        B = Potencia (b);
        if (((z - x + 256) % B) == b){
          *pb = b;
        } 
        }
    }

}
  

}

/***************************************************************/


int DeCodifica( int D[MAX][MAX], int Dl[MAX][MAX], int m, int n, int b, int d, char T[MAX2], int modo ){

  int i, j, k, x, y, z, expoente, bit, soma;
  soma = 0;  k = 0;  expoente = 0;

if (modo){

  for (i = d-1; i < m; i = i + d){
    for (j = d-1; j < n; j = j + d){
      if (!(i <= (d-1) && j <= (d-1))){
    
        x = D[i][j];  z = Dl[i][j];   

        y = (z - x + 256) % Potencia(b);
        
        printf("(%d,%d) bits %d original %02x codificado %02x\n", i, j, y, D[i][j], Dl[i][j]);

        bit = y * Potencia(expoente);
        expoente = expoente + b;
        soma = soma + bit;

        if (expoente > 8 - b){
          expoente = 0;   
          if (soma != 0){
          T[k] = soma;
          k++;
          soma = 0;
          }
        }
      }
    }
  }

} else {

  for (i = d-1; i < m; i = i + d){
    for (j = d-1; j < n; j = j + d){
      if (!(i <= (d-1) && j <= (d-1))){
    
        x = D[i][j];  z = Dl[i][j];   
        y = (z - x + 256) % Potencia(b);
        bit = y * Potencia(expoente);
        expoente = expoente + b;
        soma = soma + bit;

        if (expoente > 8 - b){
          expoente = 0;   
          if (soma != 0){
          T[k] = soma;
          k++;
          soma = 0;
          }
        }
      }
    }
  }
}

  return k;
}


/***************************************************************/


int main() {
  int D[MAX][MAX], Dl[MAX][MAX];
  int m, n, ml, nl, maxl, b, d, max, k, erro, OPCAO, modo;
  char T[MAX2], fname[FNMAX], anome[FNMAX];
  modo = 0;

  OPCAO = Menu(modo);

  while (OPCAO != 0){

    while (OPCAO == 4){
      if(modo == 0){
        modo = 1;
        printf(" Modo verborragico ativado\n");
        printf(" \n ");

      } else {
        modo = 0;
        printf(" Modo verborragico desativado\n");
        printf(" \n ");
      }
      OPCAO = Menu(modo);
    }




    if (OPCAO == 1){
      printf("Arquivo que contem o desenho original: ");
      scanf("%s", fname);

      erro = LeDesenho(fname, D, &m, &n, &max);
      if(erro) {
        printf("\nERRO: Operacao abortada devido a erro na leitura\n");
        return 0;
      }

    printf("m = %d n = %d\n", m, n);

    printf("Arquivo que contém a mensagem a ser ocultada: ");
    scanf("%s", fname);

    erro = LeTexto(fname, T, &k);
    if(erro) {
      printf(" \nERRO: Operacao abortada devido a erro na leitura\n");
      return 0;
    }

    printf("k = %d\n", k);

    erro = BeDe(k, m, n, &b, &d);
    if(erro) {
      printf(" \nERRO: Nao foi possivel calcular b e d\n");
      return 0;
    }

    printf("b = %d d = %d\n", b, d);
    Codifica(D, m, n, T, k, Dl, b, d, modo);
    max = Maximo(Dl, m, n);

    printf("Gravar desenho esteganografado em: ") ;
    scanf("%s", anome) ;

    erro = EscreveDesenho(anome, Dl, m, n, max);
    if(erro) {
      printf(" \nERRO: Operacao abortada devido a erro na escrita\n");
      return 0;
    }
    
    printf(" \n ");
    OPCAO = Menu(modo);
}

  if (OPCAO == 2){
    printf("Arquivo que contem o desenho original: ");
    scanf("%s", fname);

    erro = LeDesenho(fname, D, &m, &n, &max);
    if(erro) {
       printf("\nERRO: Operacao abortada devido a erro na leitura\n");
       return 0;
    }

    printf("m = %d n = %d\n", m, n);

    printf("Arquivo que contem o desenho esteganografado: ");
    scanf("%s", anome);
      
  
    erro = LeDesenho(anome, Dl, &ml, &nl, &maxl);

    if(erro) {
      printf("\nERRO: Operacao abortada devido a erro na leitura\n");
      return 0;
    }

    if (ml != m || nl != n){
      printf("\nERRO: Operacao abortada. Desenhos devem ser do mesmo tamanho\n");
      return 0;
    }

    printf("m = %d n = %d\n", m, n);    
    DeBeDe(D, Dl, m, n, &b, &d);
    printf("b = %d d = %d\n", b, d);
    k = DeCodifica(D, Dl, m, n, b, d, T, modo);
    printf("k = %d\n", k);

    printf("Gravar mensagem decodificada em: ");
    scanf("%s", fname) ;

    erro = EscreveTexto(fname, T, k);
    if(erro) {
      printf(" \nERRO: Operacao abortada devido a erro na escrita\n");
      return 0;
    }

    printf(" \n ");
    OPCAO = Menu(modo);
}


  if (OPCAO == 3){

    printf(" Arquivo que contem a mensagem: ");
    scanf("%s", fname);

    erro = LeTexto(fname, T, &k);
    if(erro) {
      printf(" \nERRO: Operacao abortada devido a erro na leitura\n");
      return 0;
    }

    printf("k = %d\n", k);
    printf("\n MENSAGEM contida no arquivo %s (tudo entre ---> e <---)\n", fname);
    printf("--->%s<---\n", T);

    printf(" \n ");
    OPCAO = Menu(modo);
  }
  }
  return 0;
}