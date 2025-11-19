#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inserirInicio(Lista *l, int valor)
{
    No *nozes = malloc(sizeof(No));
    nozes->chave = valor;
    nozes->proximo = l->cabeca;
    nozes->anterior = NULL;
    l->cabeca = nozes;
    if (nozes->proximo != NULL)
    {
        nozes->proximo->anterior = nozes;
    }
}

int contaNosInterativo(Lista *l)
{
    int contador = 0;
    No *nozes = l->cabeca;
    while (nozes != NULL)
    {
        nozes = nozes->proximo;
        contador++;
    }
    return contador;
}

int contarNosRecursivo(No *noAtual)
{
    if (noAtual == NULL)
    {
        return 0;
    }

    return 1 + contarNosRecursivo(noAtual->proximo);
}

int contarNosRecursivosWrapper(Lista *l)
{
    return contarNosRecursivo(l->cabeca);
}

void imprimeIterativo(Lista *l)
{
    No *nozes = l->cabeca;
    while (nozes != NULL)
    {
        printf("%d ", nozes->chave);
        nozes = nozes->proximo;
    }
    printf("\n");
}

void imprimeRecursivo(No *noAtual)
{
    if (noAtual == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", noAtual->chave);
    return imprimeRecursivo(noAtual->proximo);
}

void imprimeRecursivoWrapper(Lista *l)
{
    imprimeRecursivo(l->cabeca);
}

void imprimirInvertidaRecursivo(No* noAtual){
    
}

int main()
{
    Lista *l = criaLista();
    inserirInicio(l, 5);
    inserirInicio(l, 4);
    inserirInicio(l, 3);
    insere(l, 2, 7);
    imprimeRecursivoWrapper(l);
    printf("%d\n", contaNosInterativo(l));
    printf("%d\n", contarNosRecursivosWrapper(l));
    return 0;
}
