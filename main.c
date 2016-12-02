#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "btree2.h"


int main(int argc, char const *argv[])
{
    FILE *fp1;
    Chave chave;
    Apontador raiz;
    int i=0, j=0;

    raiz=(Apontador *) malloc (sizeof(Page));

    if (argc != 4) //Caso seja inserido mais ou menos argumentos na linha de comando
    {
        printf("\nNúmero de argumentos inválido!\n ");
        return 1;
    }
    
    fp1 = fopen(argv[2], "r"); //Abre o arquivo de entrada para leitura
    TipoDeRegistro = atoi(argv[4]); //Vê o tipo de registro

    if (fp1 == NULL) //Caso o arquivo nao exista ou o nome esteja incorreto
    {
        printf("O arquivo '%s' nao pôde ser encontrado.\n", argv[1]); 
        return 1;
    }

    if(TipoDeRegistro == 1){
        while( != feof){
            for(i=0;i<7;i++) {   
                getchar(ch);
                chave.chave[i]=ch;
            }
            chave.NRR=j;
            j++;
            insere_arvoreB(raiz, chave.chave, chave.NRR);
        }
    }else if(TipoDeRegistro == 2){
        while( != feof){
            for(i=0;i<4;i++) {   
                getchar(ch);
                chave.chave[i]=ch;
            }
            chave.NRR=j;
            j++;
            insere_arvoreB(raiz, chave.chave, chave.NRR);
        }
    }else{
        printf("O tipo de registro '%d' nao pôde ser definido.\n", argv[4]); 
        return 1;
    }

    fclose(fp1);
    return 0;
}