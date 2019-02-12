// Neste arquivo todas as variáveis globais do programa são declaradas

/*
// Define um valor inteiro para cada evento
#define a1 11
#define a2 21
#define a3 23
#define a4 31
#define a5 33
#define a6 41
#define b1 12
#define b2 22
#define b3 24
#define b4 32
#define b5 34
#define b6 42
#define bp 62
#define bg 64
#define ba 54
#define bv 52
*/
volatile int cor = 5;
volatile int tam; 

// Variavel que recebe a informacao de qual botao foi acionado no modo manual
char botao;

//Variavel que define a prioridade de execucao dos eventos:
//prioridade[0] é a prioridade de a1, prioridade[1] é a prioridade de a2, e assim sucessivamente...
//Quanto maior o valor correspondente ao evento, maior é a prioridade dele 
//Indica-se usar valores de 1 a 6 para definir-se a prioridade dos eventos
//Os valores das prioridades devem ser diferentes
//int prioridade[] = {1,2,3,4,5,6};

//variavel temporária que guarda qual é o evento de maior prioridade enquanto compara com as outras posicoes do vetor prioridade
//int maior = 0;

//Vetor em que é verificado quais eventos estão habilitados
int vetor_escolha[6];

