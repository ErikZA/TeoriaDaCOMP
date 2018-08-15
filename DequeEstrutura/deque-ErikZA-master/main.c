#include <stdio.h>
#include "fila.h"

int main () {
  FILA alunos = novaFila();
  inserir(alunos, 9);
  inserir(alunos, 8);
  inserir(alunos, 3);
  inserir(alunos, 10);

  imprimirFila(alunos);

  while(!filaVazia(alunos))
    printf ("removido: %d \n", remover(alunos));


  inserir(alunos, 10);
  inserir(alunos, 32);
  
  imprimirFila(alunos);

  destroiFila(alunos);
  return 0;
}
