#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


link novoNo(int item, link next) {
  link t = malloc(sizeof *t);
  if (t == NULL) {
    printf ("Erro no malloc \n");
    exit(-1);
  }
  t->item = item;
  t->next = next;
  return t;
}

FILA novaFila() {
  FILA f = malloc(sizeof *f);
  f->maisNovo = f->maisAntigo = NULL;
  return f;
}

void inserir(FILA f, int e) {
  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL);
  } else {
    f->maisNovo->next = novoNo(e, NULL);
    f->maisNovo = f->maisNovo->next;
  }
}

int remover(FILA f){
  int x;
  link t;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  
  x = f->maisAntigo->item;
  t = f->maisAntigo;
  f->maisAntigo = f->maisAntigo->next;
 
  if(f->maisAntigo == NULL)
    f->maisNovo = NULL;

  free(t);
  return x;
}
int filaVazia(FILA f) {
  return ((f->maisNovo == NULL) || (f->maisAntigo == NULL));
}
void imprimirFila(FILA f) {
  link t;
  for(t = f->maisAntigo; t != NULL; t = t->next) 
    printf ("%d ", t->item);
  printf ("\n");
}
void destroiFila(FILA f) {
  while (!filaVazia(f))
    remover(f);
  free(f);
}

int remover2(FILA f){
  int x, y=0;
  link t, l, lf;
  if(filaVazia(f)){
    printf ("Erro, a fila esta vazia\n");
    return 0;
  }
  l = f->maisAntigo;
  x = f->maisNovo->item;
  t = f->maisNovo;

  while(f->maisAntigo != f->maisNovo)
  {
        f->maisAntigo = f->maisAntigo->next;
      if(f->maisAntigo->next == f->maisNovo){
            system("pause");
         lf = f->maisAntigo;
         f->maisAntigo = f->maisAntigo->next;
      } else {
          if(f->maisAntigo == f->maisNovo){
         lf = l;
      }
    }
    y++;
  }

  if ( y != 0 ) {
  f->maisNovo = lf;
  f->maisNovo->next = NULL;
  f->maisAntigo = l;
  }

    if( y==0 ){
  if(f->maisAntigo == f->maisNovo)
    f->maisAntigo = NULL;
    }



 if(f->maisAntigo == NULL)
    f->maisNovo = NULL;


  free(t);
  return x;
}

void inserir2(FILA f, int e) {
    link t;
  if(f->maisAntigo == NULL) {
    f->maisAntigo = f->maisNovo = novoNo(e, NULL);
  } else {
    t = novoNo(e, NULL);
    t->next = f->maisAntigo->next;
    f->maisAntigo->next = t;
  }
}
