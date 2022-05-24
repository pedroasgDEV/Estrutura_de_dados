#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
	TAluno aluno;
	TLista lista;

	// ler as quantidades
	scanf("%d %d", &n, &k);

	// criar a lista encadeada
	TListaCria(&lista);

	// preencher a lista encadeada
	for(i = 0; i < n; i++){
		scanf("%s", aluno.nome);
		TListaInsereInicio(&lista, aluno);
	}

	// ordenar a lista
	ordena(&lista, lista.tamanho);

	// imprimir o resultado
	TListaAcessa(&lista, k - 1, &aluno);
	printf("%s\n", aluno.nome);
	
	// desalocar o vetor
	TListaDestroi(&lista);

  	return 0;
}
