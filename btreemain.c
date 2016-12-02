#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "btree.c"


int main(int argc, char const *argv[])
{
    arvoreB raiz;
    FILE *fp;
    int TipoDeRegistro, NRR;
    char Chave[7],;

    if (argc != 4) //Caso seja inserido mais ou menos argumentos na linha de comando
    {
        printf("\nNúmero de argumentos inválido!\n ");
        return 1;
    }
    
    fp = fopen(argv[2], "r"); //Abre o arquivo de entrada para leitura
    TipoDeRegistro = atoi(argv[4]); //Vê o tipo de registro

    if (fp == NULL) //Caso o arquivo nao exista ou o nome esteja incorreto
    {
        printf("O arquivo '%s' nao pôde ser encontrado.\n", argv[1]); 
        return 1;
    }

    if(TipoDeRegistro == 1){//tamanho variável

        raiz = (arvoreB *) malloc (sizeof(arvoreB));
        while(!feof){
            for(i=0;i<7;i++) {   
                ch=getc(fp);
                Chave[i] = ch;
            }
            fscanf(fp, "\n");//pula linha
            NRR=j;
            j++;
            insere_arvoreB(&raiz,&Chave,NRR);
        }
        fclose(fp);
    }

    else if(TipoDeRegistro == 2){//tamanho fixo

        raiz = (arvoreB *) malloc (sizeof(arvoreB));
        while(!feof){
            for(i=0;i<4;i++) {   
                ch=getc(fp);
                Chave[i] = ch;
            }
            fscanf(fp, "\n");//pula linha
            NRR=j;//pega o NRR
            j++;//incrementa o NRR
            insere_arvoreB(&raiz, &Chave, NRR);
        }
        fclose(fp)
    }

    else{
        printf("O tipo de registro '%d' nao pôde ser definido.\n", TipoDeRegistro);
        fclose(fp);
        exit(1);
    }

            /*printf("1 - Buscar Registro\n2 - Inserir Registro\n3 - Mostrar árvore-B\n");
            scanf("%d", &opcao);
            if(opcao == 1){
                printf("Digite a chave primária a qual deseja buscar");
                scanf("%s",chavePrimaria.chave);
                NRR = busca(raiz, chavePrimaria);
                for(i=0; i<NRR; i++){
                     fscanf(fp, "\n");//pula linha
                }
            }else if(opcao == 2){

            }else if(opcao == 3){

            }else{
                printf("Opcao invalida.\n");
            }
    

            printf("1 - Buscar Registro\n2 - Inserir Registro\n3 - Mostrar árvore-B\n");
            scanf("%d", &opcao);
            if(opcao == 1){
                printf("Digite a chave primária a qual deseja buscar");
            }else if(opcao == 2){

            }else if(opcao == 3){

            }else{
                printf("Opcao invalida.\n");
            }
        */
    return 0;
}