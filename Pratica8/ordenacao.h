# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome[30];
} TipoAluno;

//Manter como especificado
void heapsort(TipoAluno*, int);

//Manter como especificado//preencher
TipoAluno *alocaAlunos(int);

//Manter como especificado//preencher
void desalocaAlunos(TipoAluno**);

# endif
