#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

long int fibonacci(int i, TADFib *f){
    if(i == 0){
        return 0;
    }
    if(i == 1){
        return 1;
    }
    
    else{
        f->chamadas += 2;
        return fibonacci(i - 1, f) + fibonacci(i - 2, f);
    }
}

