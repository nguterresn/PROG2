/*****************************************************************/
/*         Trabalho pratico 1 | PROG2 | MIEEC | 2018/19          */
/*****************************************************************/
/*                    FUNCOES A IMPLEMENTAR                      */
/*****************************************************************/

#include "jogos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


vetor* jogos_load(const char *nomef){

    FILE *file;
    file = fopen(nomef,"r");
    char buffer[255];

    vetor * vtr = vetor_novo();
    jogo * jogo1 = (jogo*)malloc(sizeof(jogo));

    if (file != NULL) 
    {   
        while (fgets(buffer, 255, (FILE*) file))
        {
            strcpy((char*)jogo1, buffer);
            vetor_insere(vtr, *jogo1, -1);
	    }

        /*for (int i= 0; i < vtr->tamanho; i++) {
            jogo * aux = vetor_elemento(vtr, i);
			printf ("Pos %d -> %s", i, aux);
		}*/

        free(jogo1);     
        fclose(file);
        return vtr;
    } 
    else return NULL;
}


int jogos_save(vetor *vec, const char *nomef){

    int len;
    char convert;
    FILE *file;
    file = fopen(nomef,"w");

    char *esp1;
    char *esp2;
    char *esp3;
    char *esp4;
    char *esp5;
    char *esp6;

    jogo * jg = (jogo*)malloc(sizeof(jogo));
    char * buffer = (char*) malloc (255 * sizeof(*buffer));

    /* nao usado, necessario alocar */
    if (vec == NULL) 
    {
        vetor * vec = vetor_novo();
        if (vec == NULL) 
            return -1;
    } 

    for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * jog = vetor_elemento(vec, i);
        fprintf((FILE*) file, "%s", jog);
    }

    fclose(file);

    for(int i = 0; i < vec->tamanho; i++)
    {
        memset(jg->epoca, 0, sizeof(jg->epoca));
        memset(jg->nome_casa, 0, sizeof(jg->nome_casa));
        memset(jg->nome_fora, 0, sizeof(jg->nome_fora));
        jg->golos_casa = 0;
        jg->golos_fora = 0;
        jg->vermelhos_casa = 0;
        jg->vermelhos_fora = 0;

        strcpy(buffer, (const char*)vetor_elemento(vec, i));

        memcpy(jg->epoca, buffer, 5);

        esp1 = memchr(buffer, ' ', strlen(buffer));
        esp2 = memchr(esp1+1, ' ', strlen(esp1));
        esp3 = memchr(esp2+1, ' ', strlen(esp2));
        esp4 = memchr(esp3+1, ' ', strlen(esp3));
        esp5 = memchr(esp4+1, ' ', strlen(esp4));
        esp6 = memchr(esp5+1, ' ', strlen(esp5));

        memcpy(jg->nome_casa, esp1+1, (esp2-esp1));
        memcpy(jg->nome_fora, esp2+1, (esp3-esp2));
        sscanf(esp3+1, "%d", &jg->golos_casa);
        sscanf(esp4+1, "%d", &jg->golos_fora);
        sscanf(esp5+1, "%d", &jg->vermelhos_casa);
        sscanf(esp6+1, "%d", &jg->vermelhos_fora);
      
        //printf("POs %d, Ver: %d\n",i, jg->vermelhos_casa);
    }

    free(jg);
    free(buffer);
    return vec->tamanho;
}


vetor_equipas *stats_equipa(vetor *vec){

    vetor_equipas * vtr_equipas = vetor_equipas_novo();
    if (vtr_equipas == NULL)
        return NULL;
    
    jogo * jg = (jogo*)malloc(sizeof(jogo));
    if (jg == NULL)
        return NULL;

    if (vec == NULL)
        return NULL;

    equipa * equip;
    char* buffer = (char*)malloc(sizeof(buffer));
    int *diff_golos =(int*)malloc(sizeof(diff_golos));
    int *marcados = (int*)malloc(sizeof(marcados));
    int *sofridos = (int*)malloc(sizeof(sofridos));
    char nome_equipa[30];
    float vermelhos[3];

    for(int i = 0; i < vec->tamanho; i++)
    {
        if(strcmp(jg->nome_casa, "West_Ham")) {
            if (jg->golos_casa != 0)
                marcados++;
            if(jg->golos_fora != 0)
                sofridos++;
        }
    }

    printf("Marcados: %d\n", marcados);
    printf("Sofridos: %d\n", sofridos);
    
    // ultimo passo: vetor_equipas_insere()...
    return vtr_equipas;
}


int equipas_ordena(vetor_equipas *v, int criterio){
//fsdf
    return -1;
}


int corrige_jogo(vetor *vec, const char *nomef){
//fsdf
    return -1;
}


int pontos_de_equipa(vetor *vec, char *nome_equipa, char *epoca){
    //fsdf
    return -1;
}







