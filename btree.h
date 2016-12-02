
     #define D  5
     #define MAX_CHAVES  4 //Quantidade m�xima de chaves
     #define MAX_FILHOS  5 //Quantidade m�xima de filhos
     #define MIN_OCUP  3 //Ocupa��o m�nima em cada n�



typedef struct no_arvoreB arvoreB;

struct no_arvoreB {
   int num_chaves; //Quantidades de chaves contida no n�
   char chaves[MAX_CHAVES]; //Chaves armazenadas no n�
   int NRR[MAX_CHAVES];
   arvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
};

void insere_chave(arvoreB *raiz, char info[], arvoreB *filhodir,int NRR);

arvoreB *insere(arvoreB *raiz, char info[], int *h, char *info_retorno,int NRR);

arvoreB *insere_arvoreB(arvoreB *raiz, char info[],int NRR);

int busca_binaria(arvoreB *no, char info[]);

int busca(arvoreB *raiz, char info[]);