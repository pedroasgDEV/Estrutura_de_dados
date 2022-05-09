#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
int TListaInicia(TLista *pLista) {
    pLista->first = NULL;
    pLista->last = NULL;
    return 1;
}

//Retorna se a lista esta vazia
int TListaEhVazia(TLista *pLista) {
    return (pLista->first == NULL);
}

// Insere um item no inicio da lista
int TListaInserePrimeiro(TLista *pLista, TItem item) {

    if(TListaEhVazia(pLista)){
        pLista->first = (TCelula*) malloc(sizeof(TCelula));
        pLista->last = pLista->first;
        pLista->first->c.c = item.c;
        pLista->first->after = NULL;
        pLista->first->before = NULL;
    }

    else{
        pLista->first->before = (TCelula*) malloc(sizeof(TCelula));
        pLista->first->before->c.c = item.c;
        pLista->first->before->after = pLista->first;
        pLista->first->before->before = NULL;
        pLista->first = pLista->first->before;
    }
    return 0;
}

// Retira o primeiro item da lista
int TListaRetiraPrimeiro(TLista *pLista) {
    if(TListaEhVazia(pLista)) return 0;
    TCelula *pAux = pLista->first;
    pLista->first = pAux->after;
    free (pAux);
    return 1;
}

// Imprime os elementos da lista
void TListaImprime(TLista *pLista) {
    TCelula *aux = pLista->first;
    while (aux != NULL){
        printf("%c ", aux->c.c);
        aux = aux->after;
    }
}

//Remove cada elemento de uma lista e libera a memória
void TListaEsvazia(TLista *pLista) {
    while (TListaRetiraPrimeiro(pLista));
}
