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
    No *no = cria_no(valor);
    int tipo = c->estrutura_id;
    if(tipo == LISTA_ORDENADO){
        
        if(c->inicio->valor >= valor){
            no->dir = c->inicio;
            c->inicio->esq = no;
            c->inicio = no;
            return;
        }else{
            No *it;
            it = c->inicio;
            while(it->dir){
                if(it->dir->valor >= valor){
                    it->dir->esq = no;
                    no->dir = it->dir;
                    it->dir = no;
                    no->esq = it;
                    return;
                }
            }
            it->dir = no;
            no->esq = it;
            return;
        }

    }else if(tipo == LISTA_PRIMEIRO){
        No* no = cria_no(valor);
        c->inicio->esq =  no;
        no->dir = c->inicio;
        c->inicio = no;
        c->inicio->esq = NULL;
        printf("[¨] Inserido no inicio\n");

    }else if(tipo == LISTA_ULTIMO){
        No* no = cria_no(valor);
        No* aux = c->inicio;
        while(aux->dir != NULL) {
            aux = aux->dir;
        }
        aux->dir = no;
        no->esq = aux;
        no->dir = NULL;
        printf("[¨] Inserido no fim\n");

    }else if(tipo ==  ARVORE_BINARIA){

    }else if(tipo == ARVORE_AVL){

    }else{
        printf("[!] Invalid structure_id @ void adiciona()\n");
    }
}

int existe(Colecao* c, int valor)
{
    int tipo = c->estrutura_id;
    if(tipo == LISTA_ORDENADO){
        No *it;
        it = c->inicio;
        while(it){
            if(it->valor == valor){
                return 1;
            }
            if(it->valor>valor){
               return 0; 
            }
            it = it->dir;
        }
        return 0;
    }else if(tipo == LISTA_PRIMEIRO || tipo == LISTA_ULTIMO){
        No *it;
        it = c->inicio;
        while (it){
            if(it->valor == valor){
                return 1;
            }
        }
        return 0;
    }else if(tipo == ARVORE_AVL){

    }else if(tipo == ARVORE_BINARIA){

    }else{
        printf("[!] Invalid structure_id @ int existe()\n");
    }
}

void destroi(Colecao* c)
{
    int tipo = c->estrutura_id;
    if(tipo == LISTA_ULTIMO || tipo == LISTA_PRIMEIRO || tipo == LISTA_ORDENADO){
        No *it = c->inicio;
        No *last;
        it = it->dir;
        while(it){
            it->esq->dir = NULL;
            free(it->esq);
            it->esq = NULL;
            if(it->dir == NULL) last = it;
            it = it->dir;
        }
        free(last);
    }else if(){

    }else{
        printf("[!] Invalid structure_id @ int existe()\n");
    }
}