#include "ordenacao.h"
#include <stdio.h>

int main ()
{
    int n, k;
    TipoAluno *alunos;

    //ler as quantidades
    scanf("%d %d", &n, &k);

    //alocar o vetor
    alunos = alocaAlunos(n);

    //preencher o vetor
    for(int i = 0; i < n; i++)
        scanf("%s", alunos[i].nome);

    //ordenar
    heapsort(alunos, n); 

    //imprimir o resultado
    printf("%s", alunos[k-1].nome);

    //desalocar o vetor
    desalocaAlunos(&alunos);
    
    return 0;
}
