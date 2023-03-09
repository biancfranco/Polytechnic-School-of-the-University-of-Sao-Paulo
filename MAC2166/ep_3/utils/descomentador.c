#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FNMAX 262

int abre_arquivo (FILE **f, char modo[]);
void leia_nome (char fn[]);
  
int main()
{
  FILE *fin, *fout;
  int c, cc;
  enum { FIGURA, COMENT } estado = FIGURA;

  printf("Digite o nome do arquivo .pgm a ser descomentado: ");
  if (abre_arquivo(&fin, "r")) {
    return 1;
  }

  printf("Digite o nome do arquivo .pgm a ser salvo: ");
  if (abre_arquivo(&fout, "w")) {
    return 1;
  }

  c = fgetc(fin);
  cc = fgetc(fin);
  if (!(c == 'P' && cc == '2')) {
    fprintf(stderr, "Arquivo nao esta' no formato especificado.\n");
    return 1;
  }

  fputc('P', fout);
  fputc('2', fout);

  estado = FIGURA;
  while ((c = fgetc(fin)) != EOF) {
    if (estado == FIGURA) {
      if (c == '#') {
        estado = COMENT;
      } else {
        fputc(c, fout);
      }
    } else {                    /* estado == COMENT */
      if (c == '\n') {
        estado = FIGURA;
        fputc(c, fout);
      }
    }
  }

  fclose(fin);
  fclose(fout);

  return 0;
}

void leia_nome (char fn[])
{
  int len;
  fgets(fn, FNMAX, stdin);
  len = strlen(fn);
  if (fn[len-1] != '\n') { /* detecta se o nome do arquivo passou do tamanho */
    fprintf(stderr, "Nome de arquivo longo demais.\n");
    exit(1);
  } else {
    fn[--len] = '\0';
  }
}

int abre_arquivo (FILE **f, char modo[])
{
  char fn[FNMAX];
  leia_nome(fn);

  if (!strcmp(modo, "w"))
    while ((*f = fopen(fn, "r"))) {
      fclose(*f);
      printf("Arquivo existe.  Digite um novo nome: ");
      leia_nome(fn);
    }

  if (!(*f = fopen(fn, modo))) {
    fprintf(stderr, "Nao foi possivel abrir esse arquivo.\n");
    return 1;
  }

  return 0;
}
