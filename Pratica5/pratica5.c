#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int i;
	int n, k;
	TipoAluno *alunos;

	scanf("%d %d", &n, &k);
	
	alunos = alocaAlunos(n);

	for(i = 0; i < n; i++)
		scanf("%s", alunos[i].alunos);
	
	ordena(alunos, n);

	printf("%s\n", alunos[k].alunos);
	
	alunos = desalocaAlunos(alunos);

	return 0;
}
