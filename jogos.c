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

    jogo * jg = (jogo*)malloc(sizeof(jogo));
    memset(jg->epoca, 0, sizeof(jg->epoca));
    memset(jg->nome_casa, 0, sizeof(jg->nome_casa));
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

    for(int i = 0; i < 10; i++)
    {
        strcpy(buffer, (const char*)vetor_elemento(vec, i));
        /* Mais tarde, substituir o buffer por jg com memória, não esta a dar neste momento 
        for (int j = 0; j < strlen (buffer); j++) {
            printf("%c", buffer[j]);
        }*/

        len = 0;
        memcpy(jg->epoca, buffer, 5);

        printf ("\n\n\nEpoca: ");
        for (int j = 0; j < 10; j++) {
            printf("%c", jg->epoca[j]);
        }

        while (buffer[len] != ' ') len++;

        printf ("\nLen: %d", len);

        while (buffer[len+1] != ' ') len++;
        
        printf ("\nLen2: %d", len);

        while (buffer[len] != ' ') len++;
        
        printf ("\nLen3: %d", len);

        while (buffer[len+1] != ' ') len++;
        
        printf ("\nLen4: %d", len);

        while (buffer[len] != ' ') len++;
        
        printf ("\nLen5: %d", len);

        while (buffer[len+1] != ' ') len++;
        
        printf ("\nLen6: %d", len);

    }
    
    fclose(file);
    return vec->tamanho;
}


vetor_equipas *stats_equipa(vetor *vec){

    vetor_equipas * vtr_equipas = vetor_equipas_novo();
    if (vtr_equipas == NULL)
        return NULL;
    
    /*for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * aux = vetor_elemento(vec, i);
    }*/
    
    // ultimo passo: vetor_equipas_insere()...
    return NULL;
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







