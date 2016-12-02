#include <string.h>
#include "btree.h"

//Insere uma chave e o ponteiro para o filho da direita em um n�
void insere_chave(arvoreB *raiz, char info[], arvoreB *filhodir,int NRR)
{
  int k, pos;

  //busca para obter a posi��o ideal para inserir a nova chave
  pos = busca_binaria(raiz, info);
  k = raiz->num_chaves;

  //realiza o remanejamento para manter as chaves ordenadas
  while (k > pos && strcmp(info < raiz->chaves[k-1]) == -1)
  {
    strcpy(raiz->chaves[k],raiz->chaves[k-1]);
    raiz->filhos[k+1] = raiz->filhos[k];
    raiz->NRR[k] = raiz->NRR[k-1];
    k--;
  }
  //insere a chave na posi��o ideal
  strcpy(raiz->chaves[pos],info);
  raiz->filhos[pos+1] = filhodir;
  raiz->NRR[pos] = NRR;
  raiz->num_chaves++;
}

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
                       *h = FALSE;
                     }
                   else { //Overflow. Precisa subdividir
                    temp = (arvoreB *) malloc (sizeof(arvoreB));
                    temp->num_chaves = 0;

                         //inicializa filhos com NULL
                    for (i = 0; i < MAX_FILHOS; i++)
                     temp->filhos[i] = NULL;

                         //elemento mediano que vai subir para o pai
                   strcpy(info_mediano,raiz->chaves[MIN_OCUP]);

                         //insere metade do n� raiz no temp (efetua subdivis�o)
                   temp->filhos[0] = raiz->filhos[MIN_OCUP+1];
                   for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++)
                     insere_chave(temp, raiz->chaves[i], raiz->filhos[i+1],NRR);

                         //atualiza n� raiz. 
                   for (i = MIN_OCUP; i<MAX_CHAVES; i++)
                   {
                     raiz->chaves[i] = 0;
                     raiz->filhos[i+1] = NULL;
                   }
                   raiz->num_chaves = MIN_OCUP;

                         //Verifica em qual n� ser� inserida a nova chave
                   if (pos <= MIN_OCUP)
                    insere_chave(raiz, *info_retorno, filho_dir,NRR);
                  else 
                    insere_chave(temp, *info_retorno, filho_dir,NRR);

                         //retorna o mediano para inser�-lo no n� pai e o temp como filho direito do mediano.
                  strcpy(*info_retorno,info_mediano);
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

  filho_dir = insere(raiz,&info,&h,&info_retorno,NRR);
  if (h)
   { //Aumetar� a altura da �rvore
     nova_raiz = (arvoreB *) malloc (sizeof(arvoreB));
     nova_raiz->num_chaves = 1;
     nova_raiz->NRR[0] = NRR;
     strcpy(nova_raiz->chaves[0],info_retorno);
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
    if (strcmp(no->chaves[meio],info))
       return(meio); //Encontrou. Retorna a pos���o em que a chave est�.
    else if (strcmp(no->chave[meio],info)==1)
      f = meio - 1;
    else 
      i = meio + 1;
  }
  return(i); //N�o encontrou. Retorna a posi��o do ponteiro para o filho.
}

int busca(arvoreB *raiz, char info[])
{
  arvoreB *no;
  int pos; //posi��o retornada pelo busca bin�ria.

  no = raiz;
  while (no != NULL)
   {
     pos = busca_binaria(no, &info);
     if (pos < no->num_chaves && strcmp(no->chaves[pos],info))
         return(no->NRR[pos]);
     else 
      no = no->filhos[pos];
   }
  return(FALSE);
}