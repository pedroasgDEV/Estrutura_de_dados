#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(int n) {
  TipoAluno *aux = (TipoAluno*) malloc(n * sizeof(TipoAluno));
  return aux;
}

//Manter como especificado
void desalocaAlunos(TipoAluno **alunos) {
  free(*alunos);
  *alunos = NULL;
}

void heap_refaz(TipoAluno *alunos, int esq, int dir){
  int i = esq;
  int j = i * 2 + 1;
  TipoAluno aux = alunos[i];

  while(j <= dir){
    if((j < dir) && strcmp(alunos[j].nome, alunos[j + 1].nome) < 0) j++;
    if(strcmp(aux.nome, alunos[j].nome) >= 0) break;
    alunos[i] = alunos[j];
    i = j;
    j = i * 2 + 1;
  }

  alunos[i] = aux;
}

void heap_constroi(TipoAluno *alunos, int n){
  for(int esq = (n/2) - 1; esq >= 0; esq --)
    heap_refaz(alunos, esq, n - 1);
}

void heapsort(TipoAluno *alunos, int n){
  heap_constroi(alunos, n);
  while (n > 1){
    TipoAluno aux = alunos[n - 1];
    alunos[n - 1] = alunos[0];
    alunos[0] = aux;
    n--;
    heap_refaz(alunos, 0, n - 1);
  }
}