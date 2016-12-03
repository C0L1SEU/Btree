<<<<<<< HEAD
#define TRUE 0
#define FALSE 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "btree.h"

//Insere uma chave e o ponteiro para o filho da direita em um nó
=======
#include <string.h>
#include "btree.h"

//Insere uma chave e o ponteiro para o filho da direita em um n�
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
void insere_chave(arvoreB *raiz, char info[], arvoreB *filhodir,int NRR)
{
  int k, pos;

<<<<<<< HEAD
  //busca para obter a posicão ideal para inserir a nova chave
=======
  //busca para obter a posi��o ideal para inserir a nova chave
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
  pos = busca_binaria(raiz, info);
  k = raiz->num_chaves;

  //realiza o remanejamento para manter as chaves ordenadas
<<<<<<< HEAD
  while (k > pos && strcmp(info,raiz->chaves[k-1].chave) == -1)
  {
    strcpy(raiz->chaves[k].chave,raiz->chaves[k-1].chave);
=======
  while (k > pos && strcmp(info < raiz->chaves[k-1]) == -1)
  {
    strcpy(raiz->chaves[k],raiz->chaves[k-1]);
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
    raiz->filhos[k+1] = raiz->filhos[k];
    raiz->NRR[k] = raiz->NRR[k-1];
    k--;
  }
<<<<<<< HEAD
  //insere a chave na posicão ideal
  strcpy(raiz->chaves[pos].chave,info);
=======
  //insere a chave na posi��o ideal
  strcpy(raiz->chaves[pos],info);
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
  raiz->filhos[pos+1] = filhodir;
  raiz->NRR[pos] = NRR;
  raiz->num_chaves++;
}

<<<<<<< HEAD
//Realiza a busca do nó para inserir a chave e faz as subdivis�es quando necessárias
arvoreB *insere(arvoreB *raiz, char info[], int *h, char info_retorno[],int NRR)
{
  int i, j, pos;
  char info_mediano[7]; //auxiliar para armazenar a chave que irá subir para o pai
  arvoreB *temp, *filho_dir; //ponteiro para o filho à direita da chave 

  if (raiz == NULL)
  {
     //O nó anterior é o ideal para inserir a nova chave (chegou em um nó folha)
   *h = TRUE;
   strcpy(info_retorno,info);
   return(NULL);
 }
 else {
   pos = busca_binaria(raiz,info);
   if (raiz->num_chaves > pos && strcmp(raiz->chaves[pos].chave,info))
   {
     printf("Chave já contida na árvore");
     *h = FALSE;
   }
   else {
                               //desce na árvore até encontrar o nó folha para inserir a chave.
     filho_dir = insere(raiz->filhos[pos],info,h,info_retorno,NRR);
               if (*h) //Se TRUE deve inserir a info_retorno no nó.
               {
                     if (raiz->num_chaves < MAX_CHAVES) //Tem espaço na página
                     {
                       insere_chave(raiz, info_retorno, filho_dir,NRR);
=======
//Realiza a busca do n� para inserir a chave e faz as subdivis�es quando necess�rias
arvoreB *insere(arvoreB *raiz, char info[], int *h, char *info_retorno,int NRR)
{
  int i, j, pos;
  char info_mediano[7]; //auxiliar para armazenar a chave que ir� subir para o pai
  arvoreB *temp, *filho_dir; //ponteiro para o filho � direita da chave 

  if (raiz == NULL)
  {
     //O n� anterior � o ideal para inserir a nova chave (chegou em um n� folha)
   *h = TRUE;
   strcpy(*info_retorno,info);
   return(NULL);
 }
 else {
   pos = busca_binaria(raiz,&info);
   if (raiz->num_chaves > pos && strcmp(raiz->chaves[pos],info))
   {
     printf("Chave j� contida na �rvore");
     *h = FALSE;
   }
   else {
                               //desce na �rvore at� encontrar o n� folha para inserir a chave.
     filho_dir = insere(raiz->filhos[pos],&info,h,&info_retorno,NRR);
               if (*h) //Se TRUE deve inserir a info_retorno no n�.
               {
                     if (raiz->num_chaves < MAX_CHAVES) //Tem espa�o na p�gina
                     {
                       insere_chave(raiz, *info_retorno, filho_dir,NRR);
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
                       *h = FALSE;
                     }
                   else { //Overflow. Precisa subdividir
                    temp = (arvoreB *) malloc (sizeof(arvoreB));
                    temp->num_chaves = 0;

                         //inicializa filhos com NULL
                    for (i = 0; i < MAX_FILHOS; i++)
                     temp->filhos[i] = NULL;

                         //elemento mediano que vai subir para o pai
<<<<<<< HEAD
                   strcpy(info_mediano,raiz->chaves[MIN_OCUP].chave);

                         //insere metade do nó raiz no temp (efetua subdivisão)
                   temp->filhos[0] = raiz->filhos[MIN_OCUP+1];
                   for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++)
                     insere_chave(temp, raiz->chaves[i].chave, raiz->filhos[i+1],NRR);

                         //atualiza nó raiz. 
                   for (i = MIN_OCUP; i<MAX_CHAVES; i++)
                   {
                     strcpy(raiz->chaves[i].chave,"Vazia");
=======
                   strcpy(info_mediano,raiz->chaves[MIN_OCUP]);

                         //insere metade do n� raiz no temp (efetua subdivis�o)
                   temp->filhos[0] = raiz->filhos[MIN_OCUP+1];
                   for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++)
                     insere_chave(temp, raiz->chaves[i], raiz->filhos[i+1],NRR);

                         //atualiza n� raiz. 
                   for (i = MIN_OCUP; i<MAX_CHAVES; i++)
                   {
                     raiz->chaves[i] = 0;
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
                     raiz->filhos[i+1] = NULL;
                   }
                   raiz->num_chaves = MIN_OCUP;

<<<<<<< HEAD
                         //Verifica em qual nó será inserida a nova chave
                   if (pos <= MIN_OCUP)
                    insere_chave(raiz, info_retorno, filho_dir,NRR);
                  else 
                    insere_chave(temp, info_retorno, filho_dir,NRR);

                         //retorna o mediano para inserí-lo no nó pai e o temp como filho direito do mediano.
                  strcpy(info_retorno,info_mediano);
=======
                         //Verifica em qual n� ser� inserida a nova chave
                   if (pos <= MIN_OCUP)
                    insere_chave(raiz, *info_retorno, filho_dir,NRR);
                  else 
                    insere_chave(temp, *info_retorno, filho_dir,NRR);

                         //retorna o mediano para inser�-lo no n� pai e o temp como filho direito do mediano.
                  strcpy(*info_retorno,info_mediano);
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
                  return(temp);
                }
              }
            }
          }
        }

arvoreB *insere_arvoreB(arvoreB *raiz, char info[],int NRR)
{
  int h,i;
  char info_retorno[7];
  arvoreB *filho_dir, *nova_raiz;

<<<<<<< HEAD
  filho_dir = insere(raiz,info,&h,info_retorno,NRR);
  if (h)
   { //Aumetará a altura da árvore
     nova_raiz = (arvoreB *) malloc (sizeof(arvoreB));
     nova_raiz->num_chaves = 1;
     nova_raiz->NRR[0] = NRR;
     strcpy(nova_raiz->chaves[0].chave,info_retorno);
=======
  filho_dir = insere(raiz,&info,&h,&info_retorno,NRR);
  if (h)
   { //Aumetar� a altura da �rvore
     nova_raiz = (arvoreB *) malloc (sizeof(arvoreB));
     nova_raiz->num_chaves = 1;
     nova_raiz->NRR[0] = NRR;
     strcpy(nova_raiz->chaves[0],info_retorno);
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
     nova_raiz->filhos[0] = raiz;
     nova_raiz->filhos[1] = filho_dir;
     for (i = 2; i <= MAX_CHAVES; i++)
       nova_raiz->filhos[i] = NULL;
     return(nova_raiz);
   }
  else return(raiz);
}

int busca_binaria(arvoreB *no, char info[]) 
{ 
  int meio, i, f; 
  i = 0;
  f = no->num_chaves-1;

  while (i <= f)
  {
    meio = (i + f)/2;
<<<<<<< HEAD
    if (strcmp(no->chaves[meio].chave,info))
       return(meio); //Encontrou. Retorna a posicão em que a chave está.
    else if (strcmp(no->chaves[meio].chave,info)==1)
=======
    if (strcmp(no->chaves[meio],info))
       return(meio); //Encontrou. Retorna a pos���o em que a chave est�.
    else if (strcmp(no->chave[meio],info)==1)
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
      f = meio - 1;
    else 
      i = meio + 1;
  }
<<<<<<< HEAD
  return(i); //Não encontrou. Retorna a posição do ponteiro para o filho.
=======
  return(i); //N�o encontrou. Retorna a posi��o do ponteiro para o filho.
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
}

int busca(arvoreB *raiz, char info[])
{
  arvoreB *no;
<<<<<<< HEAD
  int pos; //posicão retornada pelo busca binária.
=======
  int pos; //posi��o retornada pelo busca bin�ria.
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e

  no = raiz;
  while (no != NULL)
   {
<<<<<<< HEAD
     pos = busca_binaria(no, info);
     if (pos < no->num_chaves && strcmp(no->chaves[pos].chave,info))
=======
     pos = busca_binaria(no, &info);
     if (pos < no->num_chaves && strcmp(no->chaves[pos],info))
>>>>>>> c9243a9a38ee7437840b3143e415bc2e0f4c136e
         return(no->NRR[pos]);
     else 
      no = no->filhos[pos];
   }
  return(FALSE);
}