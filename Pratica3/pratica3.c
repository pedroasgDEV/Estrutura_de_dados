#include "fib.h"
#include <stdio.h>

int main()
{   
    int n, i;
    TADFib f;

    scanf("%d", &n); //Entrada da quantidade de valores

    for(int j = 0; j < n; j++){
        scanf("%d", &i); //Entrada do numero da sequencia
        f.chamadas = 0;
        printf("fib(%d) = %d chamadas = %ld\n", i, f.chamadas, fibonacci(i, &f));
    }

    return 0;//nao remova
}
