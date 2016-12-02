#include <stdio.h>
#include <stdlib.h>
#include "btree2.h"


/*void FAVazia(TipoLista *Lista)
{
    Arvore->Primeiro = (Apontador) malloc(sizeof(Page));
    for(int i=0; i<D; i++){
        Arvore->Primeiro.filha[i]=NULL;
    }
}

int Vazia(TipoLista Lista)
{
    return (Arvore->Primeiro);
}

void Insere(int x, TipoLista *Lista)
{
    Apontador Aux;
    Aux=Lista->Ultimo;
    Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Page));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->chave = x;
    Lista->Ultimo->Prox = NULL;
    Lista->Ultimo->Ant=Aux;
    Lista->Ultimo->Indice=Lista->Ultimo->Ant->Indice+1;
}

void InserirRegistro(TipoArvore Arvore, FILE *fp, int r){
    if(r==1){
        unsigned char registro[1000];
        scanf("%s",&registro);
        fprintf(fp,"%s \n", registro);
    }else{
        unsigned char registro[122];
        gets(registro);
        fprintf(fp,"%s \n", registro);
    }
}

void Insercao (Apontador ponteiroRaiz, Chave chave, Chave chavePromovida){
    if(ponteiroRaiz == NULL){
        chavePromovida=chave;
        return (flag) //flag que indica se teve promoção de chave 
    }else{

    }
}

void Busca(Registro Reg, Apontador Ap, Chave chave)
{
  int i;

  if (Ap == NULL) //
  {
    printf("chave nao encontrada: %d\n", chave);
    return;  
  }
  i = 1;
  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    i++;
  if (Reg.chave == Ap->r[i - 1].chave)
  {
    printf("chave: %d \n", Reg.chave);
    buscainFile(Ap->r[i-1],Ap);
    return;
  }
  if (Reg.chave < Ap->r[i - 1].chave)
    Busca(Reg, Ap->p[i-1]);
  else
    Busca(Reg, Ap->p[i]);
} 

void buscainFile(Registro Reg, Apontador pagina)
{
  Registro reg[2*ORDEM];
  int i;
  FILE *arq = fopen(namefile,"rb");
  if (arq == NULL)
  exit(1);
  fseek(arq, pagina->pageNum*(2*ORDEM*sizeof(Registro)), SEEK_SET);
  fread(reg, (2*ORDEM*sizeof(Registro)),1,arq);
  fclose(arq);
  for(i = 0; i < 2*ORDEM; i++){
    if (Reg.chave == reg[i].chave)
    printf("%s%d\n",reg[i].nome,reg[i].idade);
      }
  }

  const 
T = 2,
     MAX_CHAVES = 2 * T - 1, //Quantidade m�xima de chaves
     MAX_FILHOS = 2 * T, //Quantidade m�xima de filhos
     MIN_OCUP = T - 1; //Ocupa��o m�nima em cada n�
     
     typedef struct no_arvoreB arvoreB;

struct no_arvoreB {
   int num_chaves; //Quantidades de chaves contida no nó
   int chaves[MAX_CHAVES]; //Chaves armazenadas no nó
   arvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
 };*/

//Insere uma chave e o ponteiro para o filho da direita em um n�
 void insere_chave(Apontador *raiz, Chave novaChave, Apontador *filhodir, int NRR)
 {
  int k, pos;

  //busca para obter a posição ideal para inserir a nova chave
  pos = busca_binaria(raiz, novaChave);
  k = raiz->totalChaves;

  //realiza o remanejamento para manter as chaves ordenadas
  while (k > pos && info < raiz->chaves[k-1])
  {
    raiz->chave[k] = raiz->chave[k-1];
    raiz->filha[k+1] = raiz->filha[k];
    k--;
  }
  //insere a chave na posição ideal
  raiz->chave[pos] = novaChave;
  raiz->chave[pos].NRR=NRR;
  raiz->filha[pos+1] = filhodir;
  raiz->totalChaves++;
}

//Realiza a busca do nó para inserir a chave e faz as subdivisões quando necessárias
Apontador *insere(Apontador *raiz, Chave novaChave, bool *h, int *chave_retorno, int NRR)
{
  int i, j, pos,chave_mediano; //auxiliar para armazenar a chave que ir� subir para o pai
  Apontador *temp, *filho_dir; //ponteiro para o filho � direita da chave 

  if (raiz == NULL)
  {
    //O nó anterior é o ideal para inserir a nova chave (chegou em um nó folha)
    *h = true;
    *chave_retorno = novaChave;
    return(NULL);
  } else {
    pos = busca_binaria(raiz,info);
    if (raiz->totalChaves > pos && raiz->chave[pos] == novaChave) {
      printf("Chave j� contida na �rvore");
      *h = false;
    } else {   //desce na árvore até encontrar o nó folha para inserir a chave.
    filho_dir = insere(raiz->filha[pos],novaChave,h,chave_retorno);
      if (*h) {//Se true deve inserir a info_retorno no nó.
        if (raiz->totalChaves < MAX_CHAVES) {//Tem espa�o na p�gina
          insere_chave(raiz, *chave_retorno, filho_dir);
          *h = false;
        } else { //Overflow. Precisa subdividir
          temp = (Apontador *) malloc (sizeof(Page));
          temp->totalChaves = 0;
          //inicializa filhos com NULL
          for (i = 0; i < MAX_FILHOS; i++)
            temp->filha[i] = NULL;
          //elemento mediano que vai subir para o pai
          chave_mediano = raiz->chave[MIN_OCUP];
          //insere metade do n� raiz no temp (efetua subdivis�o)
          temp->filha[0] = raiz->filha[MIN_OCUP+1];
          for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++)
            insere_chave(temp, raiz->chave[i], raiz->filha[i+1]);
          //atualiza n� raiz. 
          for (i = MIN_OCUP; i<MAX_CHAVES; i++) {
            raiz->chave[i] = 0;
            raiz->filha[i+1] = NULL;
          }
          raiz->totalChaves = MIN_OCUP;
          //Verifica em qual nó será inserida a nova chave
          if (pos <= MIN_OCUP)
            insere_chave(raiz, *chave_retorno, filho_dir);
          else 
            insere_chave(temp, *chave_retorno, filho_dir);
          //retorna o mediano para inser�-lo no n� pai e o temp como filho direito do mediano.
          *chave_retorno = chave_mediano;
          return(temp);
        }
      }
    }
  }
}

Apontador *insere_arvoreB(Apontador *raiz, Chave novaChave, int NRR)
{
  bool h;
  int chave_retorno, i;
  Apontador *filho_dir, *nova_raiz;

  filho_dir = insere(raiz,novaChave,&h,&chave_retorno,NRR);
  if (h)
   { //Aumetar� a altura da �rvore
     nova_raiz = (Apontador *) malloc (sizeof(Page));

     nova_raiz->num_chaves = 1;
     nova_raiz->chave[0] = chave_retorno;
     nova_raiz->filha[0] = raiz;
     nova_raiz->filha[1] = filho_dir;
     for (i = 2; i <= MAX_CHAVES; i++)
       nova_raiz->filha[i] = NULL;
     return(nova_raiz);
   }
   else return(raiz);
 }

int busca_binaria(Apontador *no, Chave novaChave) 
{ 
  int meio, i, f; 
  i = 0;
  f = no->totalChaves-1;

  while (i <= f)
  {
    meio = (i + f)/2;
    if (no->chave[meio] == novaChave)
       return(meio); //Encontrou. Retorna a pos���o em que a chave est�.
    else if (no->chave[meio] > novaChave)
        f = meio - 1;
     else 
        i = meio + 1;
  }
  return(i); //N�o encontrou. Retorna a posi��o do ponteiro para o filho.
}

int busca(Apontador *raiz, Chave novaChave)
{
  Apontador *no;
  int pos; //posi��o retornada pelo busca bin�ria.

  no = raiz;
  while (no != NULL)
   {
     pos = busca_binaria(no, novaChave);
     if (pos < no->totalChaves && no->chave[pos] == novaChave)
         return(no->Chave.NRR);
     else 
        no = no->filha[pos];
   }
  return(-1);
}

void em_ordem(Apontador *raiz)
{
  int i;
  if (raiz != NULL)
   {
     for (i = 0; i < raiz->totalChaves; i++)
      {
        em_ordem(raiz->filha[i]);
        printf("\n%c", raiz->chave[i]);
      }
     em_ordem(raiz->filha[i]);
      }
}

