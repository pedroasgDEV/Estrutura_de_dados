#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>

void ordena(TLista *pLista, int n) {
    int min;
    TAluno t1, t2, aux;
    TCelula *c1, *c2; 
	for(int i = 0; i < n; i++){
        min = i;
        
        for(int j = i + 1; j < n; j++){

            TListaAcessa(pLista, j, &t1);
            TListaAcessa(pLista, min, &t2);

            if(compare(t1, t2) < 0){
                min = j;
            }
        }

        if(i != min){
            c1 = apontadorPosicao(pLista, i);
            c2 = apontadorPosicao(pLista, min);

            aux = c1->item;
            c1->item = c2->item;
            c2->item = aux;
        }
    }
}

int compare(const TAluno t1, const TAluno t2) {
    return strcmp(t1.nome, t2.nome);
}
