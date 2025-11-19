#ifndef LISTAENCADEADA
#define LISTAENCADEADA

typedef struct No{
    int chave;
    struct No* proximo;
    struct No* anterior;
}No;

typedef struct Lista{
    No* cabeca;
}Lista;

void criaFila();
No* acessa(Lista* l, int i);
No* busca(Lista* l, int chave);
void insere(Lista* l, int i);
void removeValor(Lista* l, int valor);
void removeIndice(Lista* l, int i);

#endif
