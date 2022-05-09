#include "pilha.h"
#include <stdlib.h>

// Inicia as variavpilhaeis da lista
int TPilhaInicia(TPilha *pPilha) {
    pPilha->lista = (TLista*) malloc(sizeof(TLista));
    return TListaInicia(pPilha->lista);
}

//Retorna se a pilha esta vazia
int TPilhaEhVazia(TPilha *pPilha) {
    return TListaEhVazia(pPilha->lista);
}

// Insere um item no final da pilha
int TPilhaPush(TPilha *pPilha, TItem item){
    return TListaInserePrimeiro(pPilha->lista, item);
}

// Retira o primeiro item da pilha
int TPilhaPop(TPilha *pPilha) {
    return TListaRetiraPrimeiro(pPilha->lista);
}
    

//Remove cada elemento de uma pilha e libera a memória
void TPilhaEsvazia(TPilha *pPilha) {
    TListaEsvazia(pPilha->lista);
    free(pPilha->lista);
}