#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link maisAntigo;
  link maisNovo;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserir(FILA f, int e);
int remover(FILA f);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f); 
int remover2(FILA f);
void inserir2(FILA f, int e);

#endif 
