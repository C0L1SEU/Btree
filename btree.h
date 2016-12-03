
#include <stdlib.h>
#include <stdio.h>
#define D  5
#define MAX_CHAVES  4 //Quantidade máxima de chaves
#define MAX_FILHOS  5 //Quantidade máxima de filhos
#define MIN_OCUP  3 //Ocupação mínima em cada nó


typedef struct no_arvoreB arvoreB;
typedef struct TipoChave
{
	char chave[7];	
}Chave;

struct no_arvoreB {
   int num_chaves; //Quantidades de chaves contida no nó
   Chave chaves[MAX_CHAVES]; //Chaves armazenadas no nó
   int NRR[MAX_CHAVES];
   arvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
};

void insere_chave(arvoreB *raiz, char info[], arvoreB *filhodir,int NRR);

arvoreB *insere(arvoreB *raiz, char info[], int *h, char *info_retorno,int NRR);

arvoreB *insere_arvoreB(arvoreB *raiz, char info[],int NRR);

int busca_binaria(arvoreB *no, char info[]);

int busca(arvoreB *raiz, char info[]);
