#include <stdio.h>
#include <stdlib.h>
#define D 5 //árvore de ordem 5
#define minimo 3 //mínimo de filhos

typedef struct BTPage *Apontador;

typedef struct ChavePrimaria
{
	char chave[7];
}Chave;

typedef struct BTPage
{
	//armazena numero de chaves na pagina
	short int totalChaves;
	
	//vetor de chaves
	Chave chave[D-1];
	int NRR[D-1];
	//Ponteiros das paginas filhas, -1 aponta para NULL
	Apontador filha[D];
	
	//struct BTPage filha[D];	
}Page;

typedef struct
{
    Apontador Primeiro;
} TipoArvore;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Insere(int x, TipoLista *Lista);

void ImprimeListaNoArquivo(TipoLista Lista,FILE *fp);

void EncheLista(TipoLista *Lista, int N, int semente);

void EncheVetor(int *Vetor, int N, int semente);

void quick_vetor(int *Vetor,int comeco, int fim, int *Contador);

void quick_lista(TipoLista *Lista, int comeco, int fim, Apontador Auxi, int *Contador);

int mediana_vetor(int *Vetor,int i,int j);

int mediana_lista(TipoLista *Lista,Apontador Auxi, Apontador Auxj);

void ZeraLista(TipoLista *lista);

void DeletaLista(TipoLista *lista);

void ImprimeVetorNoArquivo(int *Vetor,FILE *fp, int N);