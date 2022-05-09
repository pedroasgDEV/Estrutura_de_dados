# ifndef pilha_h
# define pilha_h

#include "lista.h"

typedef struct pilha{
    TLista *lista;
}TPilha;

// Inicializa a pilha e retorna se foi possivel ou nao
int TPilhaInicia(TPilha *pPilha);

// Retorna se a pilha esta vazia
int TPilhaEhVazia(TPilha *pPilha);

// Insere um item na pilha
int TPilhaPush(TPilha *pPilha, TItem item);

// Retira um item da pilha
int TPilhaPop(TPilha *pPilha);

// Remove e libera memoria de cada elemento de uma pilha
void TPilhaEsvazia(TPilha *pPilha);
# endif