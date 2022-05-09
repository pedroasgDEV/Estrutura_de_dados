#include "pilha.h"

#include <stdio.h>

int main() {

    char ch;
    TItem item;
    TPilha pilha;

    TPilhaInicia(&pilha);

    while (scanf("%c", &ch)!=EOF) {
        item.c = ch;
        if(item.c == '(' ) TPilhaPush(&pilha, item);
        else if (item.c == ')') {
            if(!TPilhaPop(&pilha)){
                printf("incorreto\n");
                TPilhaEsvazia(&pilha);
                return 0;
            } 
        }
    }

    if(TPilhaEhVazia(&pilha)) printf("correto\n");
    else printf("incorreto\n");

    TPilhaEsvazia(&pilha);

    return 0;//nao remova
}
