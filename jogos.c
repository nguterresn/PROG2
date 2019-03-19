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
                
        fclose(file);
        return vtr;
    } 
    else return NULL;
}


int jogos_save(vetor *vec, const char *nomef){

    FILE *file;
    file = fopen(nomef,"w");
    char buffer[255];

    /* nao usado, necessario alocar */
    if (vec == NULL) 
    {
        vetor * vec = vetor_novo();
        if (vec == NULL) 
            return -1;
    } 

    jogo * jogo1 = (jogo*)malloc(sizeof(jogo));

    for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * aux = vetor_elemento(vec, i);
        fprintf((FILE*) file, "%s", aux);
    }

    fclose(file);
    return vec->tamanho;
}


vetor_equipas *stats_equipa(vetor *vec){
//fsdf
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







