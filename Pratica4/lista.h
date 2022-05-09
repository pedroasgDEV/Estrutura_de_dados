# ifndef lista_h
# define lista_h

typedef struct item{
   char c;
} TItem;

typedef struct celula{
    struct celula *before, *after;
    TItem c;
} TCelula;

typedef struct lista{
    TCelula *first, *last;
} TLista;

// Inicializa a lista e retorna se foi possivel
int TListaInicia(TLista *pLista);

// Retorna se a lista esta vazia
int TListaEhVazia(TLista *pLista);

// Insere um item no final da lista e retorna se a insercao ocorreu
int TListaInserePrimeiro(TLista *pLista, TItem item);

// Retira o primeiro item da lista e retorna se foi possivel ou nao
int TListaRetiraPrimeiro(TLista *pLista);

// Imprime os elementos da lista
void TListaImprime(TLista *pLista);

// Remove e libera memória de cada elemento de uma lista
void TListaEsvazia(TLista *pLista);

#endif