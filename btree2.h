#include <stdio.h>
#include <stdlib.h>
#define D 5 //árvore de ordem 5
#define minimo 3 //mínimo de filhos

typedef struct BTPage *Apontador;

typedef struct ChavePrimaria
{
	int NRR;
	char chave[7];
}Chave;

typedef struct BTPage
{
	//armazena numero de chaves na pagina
	short int totalChaves;
	
	//vetor de chaves
	Chave chave[D-1];
	//Ponteiros das paginas filhas, -1 aponta para NULL
	Apontador filha[D];
	//struct BTPage filha[D];	
}Page;

typedef struct
{
    Apontador Raiz;
} TipoArvore;

void FAVazia(TipoArvore *Arvore);

int Vazia(TipoArvore Arvore);

int Busca(TipoArvore Arvore, Chave chave);

void LeArquivo(char NomeArq);