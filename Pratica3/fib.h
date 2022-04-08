# ifndef fib_h
# define fib_h

typedef struct{
  int chamadas; //Numero das chamadas das funções
} TADFib;

long int fibonacci(int i, TADFib *f);

# endif
