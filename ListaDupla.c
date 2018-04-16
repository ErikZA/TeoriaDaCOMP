#include <stdlib.h>
#include <stdio.h>



typedef struct node *link;

struct node{
    int item;
    link next;
    link prev;
};

link inicializa(){
 link l = malloc(sizeof(struct node));
 l = NULL;
 return l;
}

link novoNo(link l, int n){
    link novo = malloc(sizeof(struct node));
    if(novo==NULL){
        printf("Erro no malloc");
        return -1;
    } else{
        novo->item = n;
        novo->next = NULL;
        novo->prev = NULL;
    }
    if(l==NULL){
        return novo;
    } else {
        novo->next = l;
        l->prev = n;
        return novo;
    }
}

void imprimeLista(link l){
    int i=0;
    while(l!=NULL){
        printf("Item %d: %d\n", ++i,l->item);
        l = l->next;
    }
}

int main(){
    link listaDupla = inicializa();
    listaDupla = novoNo(listaDupla,5);
    listaDupla = novoNo(listaDupla,54);
    listaDupla = novoNo(listaDupla,65);
    listaDupla = novoNo(listaDupla,34);
    listaDupla = novoNo(listaDupla,23);
    listaDupla = novoNo(listaDupla,76);
    listaDupla = novoNo(listaDupla,98);
    listaDupla = novoNo(listaDupla,12);
    imprimeLista(listaDupla);


    return 0;
}
