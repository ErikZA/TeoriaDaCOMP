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

link buscaNoSeguinte(link l,int item){
    while(l!=NULL){
        if(l->item==item)
            return l->next;
        l=l->next;
    }
    return NULL;
}

void imprimeLista(link l){
    int i=0;
    if(l==NULL)
        printf("Lista Vazia");
    while(l!=NULL){
        printf("Item %d: %d\n", ++i,l->item);
        l = l->next;
    }
}

link quebraLista(link l, int item){
    link p = buscaNoSeguinte(l,item);
    while(l!=NULL){
        if(l->item==item)
            l->next= NULL;
        l = l->next;
    }
    if(p==NULL)
        return NULL;
    else
        if(p->next==NULL)
            return p->prev=NULL;

    if(p->next!=NULL){
        p->prev = NULL;
        return p;
    }
    return NULL;
}

link concatenaListas(link l1, link l2){
    link p = l1;
    if(l1==NULL){
        printf("\nLisata 1 Vazia\n");
        return NULL;
    }
    if(l2==NULL){
        printf("\nLisata 2 Vazia\n");
        return NULL;
    }
    while(p!=NULL){
        p = p->next;
        if(p->next==NULL){
            p->next = l2;
            l2->prev = p;
            break;
        }
    }
    return l1;
}

link constroiListaVetor(int tamanho, int *vet){
    if(tamanho == 0){
        printf("\n Vetor com 0 elemnetos");
        return NULL;
    }
        link lista = inicializa();
        lista= novoNo(lista,vet[0]);
         lista= novoNo(lista,vet[1]);
          lista= novoNo(lista,vet[2]);
           lista= novoNo(lista,vet[3]);
            lista= novoNo(lista,vet[4]);
            return lista;
}

link retiraPrefixo(link l, int item){
    link p = l;
    int cont = 0;
    if(item<0){
        printf("\nimpossivel executar a funcao\n");
    return(l);
    }
    while(p!=NULL){
        cont++;
        p = p->next;
    }
    if(cont<=item){
        printf("\nparameto para exclusao maior do que a lista atual\nToda a lista sera apagada");
        free(l);
        free(p);
        return  NULL;
    } else {
        while(item>0){
            l->next->prev = NULL;
            p = l;
            l = l->next;
            free(p);
            item--;
        }
        return l;
    }
    return NULL;
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
    printf("\n");
    printf("Quebra Lista\n");
    link l2 = quebraLista(listaDupla,34);
    imprimeLista(listaDupla);
    printf("\n");
    imprimeLista(l2);
    link conc = concatenaListas(listaDupla,l2);
    printf("\nLista Concatenada\n");
    //system("pause");
    imprimeLista(conc);
    int vet[] = {1,2,3,4,5};
    link listvet = constroiListaVetor(5,vet);
    printf("\nLista apartir de vetor\n");
    imprimeLista(listvet);
    printf("\nExcluindo N elementos\n");
    imprimeLista(conc);
    conc = retiraPrefixo(conc,4);
    printf("\nExcluindo\n");
    imprimeLista(conc);

    return 0;
}
