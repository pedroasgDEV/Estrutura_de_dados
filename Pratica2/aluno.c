#include "aluno.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno{
  char nome[20];
  char curso[20];
  float nota;
};

struct turma {
  TAluno** aluno;
  int qdt;
};

// Manter como especificado
void lerInfos(int *qtd, char *option) {
  scanf("%c %d", option, qtd);
}

// Manter como especificado
void alocaAluno(TAluno **pAluno) {
  *pAluno = (TAluno*) malloc(sizeof(TAluno));
}

// Manter como especificado
void alocaTurma(TTurma **pTurma, int qtd) {
  *pTurma = (TTurma*) malloc(sizeof(TTurma));

  (*pTurma)->qdt = qtd;

  (*pTurma)->aluno = (TAluno**) malloc(qtd * sizeof(TAluno*));

  for(int i = 0; i < qtd; i++)
    alocaAluno(&(*pTurma)->aluno[i]);
}

// Manter como especificado
void desalocaAluno(TAluno **pAluno) {
  free(*pAluno);
}

// Manter como especificado
void desalocaTurma(TTurma **pTurma) {
  for(int i = 0; i < (*pTurma)->qdt; i++){
    desalocaAluno(&(*pTurma)->aluno[i]);
  }
  
  free((*pTurma)->aluno);
  free(*pTurma);
}

// Manter como especificado
void lerTurma(TTurma *pTurma) {
  for(int i = 0; i < (*pTurma).qdt; i++){
    scanf("%s %s %f", (*pTurma).aluno[i]->nome, (*pTurma).aluno[i]->curso, &(*pTurma).aluno[i]->nota);
  }
}

// Manter como especificado
float calcularMetrica(TTurma *pTurma, char* curso, char option) {
  
  float soma = 0;
  int j = 0;
  
  for(int i = 0; i < pTurma->qdt; i++){
    if(strcmp(curso, pTurma->aluno[i]->curso) == 0){soma += pTurma->aluno[i]->nota; j++;}
  }

  if(option == 'M'){soma /= j;}

  return soma;
}

// Manter como especificado
void printMetrica(char* curso, float metrica, char option) {
  printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}