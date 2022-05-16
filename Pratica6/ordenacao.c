#include "ordenacao.h"

//Manter como especificado
TTime *alocaVetor(int n){
    TTime *aux = (TTime*) malloc(n * sizeof(TTime));

    //Inicializa os valores de cada celula
    for(int i = 0; i < n; i++){
        aux[i].n_time = i+1;
        aux[i].pts_marc = 0;
        aux[i].pts_recb = 0;
        aux[i].pts_geral = 0;
        aux[i].num_insc = 0;
    }

    return aux;
}

//Manter como especificado
void desalocaVetor(TTime **vetor){
    free(*vetor);
}

//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(TTime *vetor, int n){
    quicksort(vetor, 0, n - 1);
}

//Ultiliza o quicksort recursivo para ordenar o vetor
void quicksort(TTime *vetor, int l, int r){
    int q; //Pivo
	if(l < r){
		q = partition(vetor, l, r); //Particiona e mostra o pivo
		quicksort(vetor, l, q - 1); //Recursão
		quicksort(vetor, q + 1, r); //Recursão
	}
}

//Particiona o vetor
int partition(TTime *vetor, int l, int r){
	TTime x = vetor[r], aux;//Pivo
	int i = l - 1;
	for(int j = l; j < r; j++){ //Varre o vetor procurando alguem menor que x
		if(compare(vetor[j], x) >= 0){ //Faz a troca das posições
			aux = vetor[++i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		}
	}
	//Troca o pivo
	aux = vetor[++i];
	vetor[i] = vetor[r];
	vetor[r] = aux;

	//Retorna a posição do pivo
	return i;
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const TTime t1, const TTime t2){
    // -1  se o t2 tiver prioridade
	// 0  se ambos forem iguais
	// 1  se o t1 tiver prioridade
    float saldo1, saldo2;

    //Calcula o saldo de cestas
    if(!t1.pts_recb) saldo1 = t1.pts_marc;
    else saldo1 = (float) t1.pts_marc/ (float) t1.pts_recb;

    if(!t2.pts_recb) saldo2 = t2.pts_marc;
    else saldo2 = (float) t2.pts_marc/ (float) t2.pts_recb;

    //Compara a pontuação geral
    if(t1.pts_geral > t2.pts_geral) return 1;
    else if(t1.pts_geral < t2.pts_geral) return -1;

    //Compara o saldo de cestas
    else if(saldo1 > saldo2) return 1;
    else if(saldo1 < saldo2) return -1;

    //Compara as cestas feitas
    else if(t1.pts_marc > t2.pts_marc) return 1;
    else if(t1.pts_marc < t2.pts_marc) return -1;

    //Compara a quantidade de inscrições
    else if(t1.num_insc < t2.num_insc) return 1;
    else if(t1.num_insc > t2.num_insc) return -1;

    else return 0;
}