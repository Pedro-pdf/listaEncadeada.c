#include "listaEncadeada.h"
#include <stdlib.h>
#include <stdio.h>

Lista* criaLista(){
    Lista* novaLista = malloc(sizeof(Lista));
    novaLista->cabeca = NULL;
    return novaLista;
}

No* acessa(Lista* l, int i){
    No* no = l->cabeca;
    int j = 0;
    while(no->proximo!=NULL && j!=i){
        no = no->proximo;
        j++;
    }
    return no;
}

No* busca(Lista* l, int chave){
    No* no = l->cabeca;
    int j = 0;
    while(no->proximo != NULL && no->chave != chave){
        no = no->proximo;
        j++;
    }
    if(no == NULL){
        printf("Nao encontrado");
        return NULL;
    }
    return no;
}

void insere(Lista* l, int i, int valor){
    No* novo = malloc(sizeof(No));
    novo -> chave = valor;
    if(i == 0){
        novo->proximo = l->cabeca;
        novo->anterior = NULL;
        l->cabeca = novo;
        if(novo->proximo != NULL){
            novo->proximo->anterior = novo;
        }
    }
    else{
        int j = 1;
        No* anterior = l->cabeca;
        while(anterior != NULL && j < i){
            anterior = anterior->proximo;
            j++;
        }
        if(anterior == NULL){
            printf("Indice invalido");
            return;
        }
        novo->proximo = anterior->proximo;
        novo->anterior = anterior;
        anterior->proximo = novo;
        if(novo->proximo != NULL){
            novo->proximo->anterior = novo;
        }
    }
}

void removeValor(Lista* l, int valor){
    No* atual = l->cabeca;
    No* anterior = NULL;
    while(atual != NULL && atual->chave != valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("Valor nao encontrado");
        return;
    }
    if(anterior == NULL){
        l->cabeca = atual->proximo;
        if(l->cabeca != NULL){
            l->cabeca->anterior = NULL;
        }
        return;
    }
    
    anterior->proximo = atual->proximo;
    if(atual->proximo != NULL){
        atual->proximo->anterior = anterior;
    }
    free(atual);
}

void removeIndice(Lista* l, int i){
    No* atual = l->cabeca;
    No* anterior = NULL;
    int j = 0;
    while(atual != NULL && j != i){
        anterior = atual;
        atual = atual->proximo;
        j++;
    }
    if(atual == NULL){
        printf("Valor nao encontrado");
        return;
    }
    if(anterior == NULL){
        l->cabeca = atual->proximo;
        if(l->cabeca != NULL){
            l->cabeca->anterior = NULL;
        }
        return;
    }
    
    anterior->proximo = atual->proximo;
    if(atual->proximo!=NULL){
        atual->proximo->anterior = anterior;
    }
    free(atual);
}
void imprimeIterativo(Lista *l){
    No *nozes = l->cabeca;
    while (nozes != NULL){
        printf("%d ", nozes->chave);
        nozes = nozes->proximo;
    }
    printf("\n");
}
