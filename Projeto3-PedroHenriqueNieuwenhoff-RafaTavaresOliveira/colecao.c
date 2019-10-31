#include <stdlib.h>
#include "colecao.h"

struct _no {
    int valor;
    struct _no* esq;
    struct _no* dir;
    int altura;
} ;

struct _c {
    No* inicio;
    int estrutura_id;
};

Colecao* cria_colecao(int estrutura_id) 
{
    Colecao *c;
    c = (Colecao*) malloc(sizeof(Colecao));
    c->estrutura_id = estrutura_id;
    c->inicio = NULL;
    return c;
}

No* cria_no(int valor)
{
    No *no;
    no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->altura = 0;
    no->dir = NULL;
    no->esq = NULL;
    return NULL;
}

void adiciona(Colecao* c, int valor)
{
    int tipo = c->estrutura_id;
    if(tipo == LISTA_ORDENADO){

    }else if(tipo == LISTA_PRIMEIRO){

    }else if(tipo == LISTA_ULTIMO){

    }else if(tipo ==  ARVORE_BINARIA){

    }else if(tipo == ARVORE_AVL){

    }else{
        printf("[!] Invalid structure_id @ void adiciona();\n");
    }
}

int existe(Colecao* c, int valor)
{
    // Implementar
    return 1;
}
void destroi(Colecao* c)
{
    // Implementar
}