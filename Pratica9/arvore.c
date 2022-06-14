#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void TArvore_Inicia (TNo **pRaiz){
  *pRaiz = NULL;
}

// Manter como especificado
int TArvore_Insere (TNo **ppR, TItem item){
  if(*ppR == NULL){
    *ppR = TNo_Cria(item);
    return 1;
  }

  if(compara(item, (*ppR)->item) == PRIMEIRO_MENOR) return TArvore_Insere (&((*ppR)->esq), item);
  if(compara(item, (*ppR)->item) == PRIMEIRO_MAIOR) return TArvore_Insere (&((*ppR)->dir), item);

  return 0;
}

// Manter como especificado
TNo *TNo_Cria (TItem x){
  TNo *aux = (TNo*) malloc(sizeof(TNo));
  aux->item = x;
  aux->esq = NULL;
  aux->dir = NULL;
  return aux;
}

// Realizar o caminhamento adequado na arvore
void Central(TNo *p){
  if (p == NULL ) return ;
  Central (p->esq) ;
  printf ("%s\n", p->item.chave) ;
  Central (p->dir) ;
}

// Função para realizar a comparação entre dois itens
ENUM_RESPOSTA compara(const TItem item1, const TItem item2) {
  if(strcmp(item1.chave, item2.chave) < 0) return PRIMEIRO_MENOR;
  else if(strcmp(item1.chave, item2.chave) > 0) return PRIMEIRO_MAIOR; 
  else return IGUAIS;
}

