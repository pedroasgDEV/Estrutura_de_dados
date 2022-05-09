#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(int n){
  TipoAluno* alunos = (TipoAluno*) malloc(n * sizeof(TipoAluno));
  return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  return alunos;
}

void ordena(TipoAluno *alunos, int n){
  mergesort(alunos, 0, n);
}

void mergesort(TipoAluno *alunos, int l, int r){
  if(l < r){
    int m = (l + r)/2;
    mergesort(alunos, l, m);
    mergesort(alunos, m+1, r);
    merge(alunos, l, m, r);
  }
}

void merge(TipoAluno *alunos, int l, int m, int r){
  int size_l = m - l + 1, size_r = r - m;
  char vet_l[size_l][20], vet_r[size_r][20];

  //Aloca a parte esquerda para o vetor auxiliar
  for(int i = 0; i < size_l; i++)
    strcpy(vet_l[i], alunos[l+i].alunos);

  //Aloca a parte direita para o vetor auxiliar
  for(int i = 0; i < size_r; i++)
    strcpy(vet_r[i], alunos[m+1+i].alunos);

  for(int i = 0, j = 0, k = l; k <= r; k++){
    if(i == size_l)
      strcpy(alunos[k].alunos, vet_r[j++]);
    
    else if(j == size_r)
      strcpy(alunos[k].alunos, vet_l[i++]);

    else if(strcmp(vet_l[i], vet_r[j]) > 0)
      strcpy(alunos[k].alunos, vet_r[j++]);
    
    else
      strcpy(alunos[k].alunos, vet_l[i++]);
  }
}