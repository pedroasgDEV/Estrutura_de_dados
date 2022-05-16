# ifndef ordenacao_h
# define ordenacao_h

#include <stdlib.h>

typedef struct time {
    int n_time; //Número do time
    int pts_geral; //Pontuação geral
    int pts_marc; //Pontos de cestas feitas
    int pts_recb; //Pontos de cestas recebidas
    int num_insc; //Jogos inscritos
}TTime;

//Manter como especificado
void ordenacao(TTime *vetor, int n);
//Manter como especificado
TTime *alocaVetor(int n);
//Manter como especificado
void desalocaVetor(TTime **vetor);
//Ultiliza o quicksort recursivo para ordenar o vetor
void quicksort(TTime *vetor, int l, int r);
//Particiona o vetor
int partition(TTime *vetor, int l, int r);
//faz a comparacao utilizada para ordenar os times
int compare(TTime t1, TTime t2);
# endif
