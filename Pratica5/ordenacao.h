# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char alunos[100];
} TipoAluno;

//Manter como especificado
void ordena(TipoAluno *alunos, int n);
//Manter como especificado
TipoAluno *alocaAlunos(int n);
//Manter como//preencher especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos);
//Criadas
void mergesort(TipoAluno *alunos, int l, int r);
void merge(TipoAluno *alunos, int l, int m, int r);
# endif//preencher
