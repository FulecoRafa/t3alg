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

//Destroi recursivamente todos os itens da arvore
void destroiArvore(Colecao *c , No *it){
    if(it->dir)destroiArvore(c , it->dir);
    if(it->esq)destroiArvore(c , it->esq);
    it->esq=NULL;
    it->dir=NULL;
    free(it);
    return;
}

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

//Faz as rotações da árvore AVL. Retorna sempre o fator de balanceamento.
int balancearArvore(Colecao *c , No *it){
    
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
        c->inicio->esq =  no;
        no->dir = c->inicio;
        c->inicio = no;
        c->inicio->esq = NULL;
        printf("[¨] Inserido no inicio\n");

    }else if(tipo == LISTA_ULTIMO){
        No* aux = c->inicio;
        while(aux->dir != NULL) {
            aux = aux->dir;
        }
        aux->dir = no;
        no->esq = aux;
        no->dir = NULL;
        printf("[¨] Inserido no fim\n");

    }else if(tipo ==  ARVORE_BINARIA || tipo == ARVORE_AVL){
        if(!(c->inicio)){
            c->inicio=cria_no(valor);
            return;
        }else{
            int altura = 0;   
            No* it = c->inicio;
            while(1){
                if(valor > it->valor){
                    if(it->dir){
                        it=it->dir;
                        altura++;
                    }else{
                        it->dir=no;
                        it->dir->altura=altura+1;
                        return;
                    }
                }else{
                    if(it->esq){
                        it=it->esq;
                        altura++;
                    }else{
                        it->esq=no;
                        it->esq->altura=altura+1;
                        return;
                    }
                }
            }
        }
        printf("[¨] Inserido na árvore\n");
        if(tipo == ARVORE_AVL){
            balancearArvore(c, c->inicio, NULL);
            printf("[¨] Arvore balanceada\n");
        }
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
    }else if(tipo == ARVORE_AVL || tipo == ARVORE_BINARIA){
        No *it = c->inicio;
        while(1){
            if(!it){
                return 0;
            }else if(it->valor==valor){
                return 1;
            }else if(valor>it->valor){
                it=it->dir;
            }else{
                it=it->esq;
            }
        }

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
    }else if(tipo==ARVORE_BINARIA || tipo==ARVORE_AVL){
        destroiArvore(c , c->inicio);
        free(c);
    }else{
        printf("[!] Invalid structure_id @ int existe()\n");
    }
}