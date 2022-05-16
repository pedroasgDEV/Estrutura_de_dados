#include "ordenacao.h"
#include <stdio.h>

int main()
{
    int instancia = 0;

    while (1) {
        instancia++;
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        TTime *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(!n) break;

        //aloque o vetor
        vetor = alocaVetor(n);

        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            //Add pontuação do jogo
            vetor[time1 - 1].pts_marc += pontos1;
            vetor[time1 - 1].pts_recb += pontos2;
            vetor[time2 - 1].pts_marc += pontos2;
            vetor[time2 - 1].pts_recb += pontos1;

            //Add pontuação geral
            if(pontos1 > pontos2){
                vetor[time1 - 1].pts_geral += 2;
                vetor[time2 - 1].pts_geral++;
            }
            else{
                vetor[time2 - 1].pts_geral += 2;
                vetor[time1 - 1].pts_geral++;
            }

            //Soma o numero de inscrições
            vetor[time1 - 1].num_insc++;
            vetor[time2 - 1].num_insc++;
        }

        //ordenar os times
        ordenacao(vetor, n);

        //imprima o resultado
        if(instancia > 1) printf("\n");
        printf("Instancia %d\n", instancia);
        for(int i = 0; i < n; i++)
            printf("%d ", vetor[i].n_time);
        printf("\n");

        //desaloque o vetor
        desalocaVetor(&vetor);
    }

    return 0;
}
