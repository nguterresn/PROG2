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
    int games_counter = 0;

    vetor *vtr = (vetor *) malloc(sizeof(vetor));
    vtr->elementos = (jogo*)malloc(2000);

    if (file != NULL) 
    {   
        while (fgets(buffer, 255, (FILE*) file))
        {
           games_counter++;
	    }

        vtr->tamanho = games_counter;

        printf("\nCapacidade %d\n", vtr->capacidade);
        
        fclose (file);
        return vtr;
    } 
    else return NULL;
}


int jogos_save(vetor *vec, const char *nomef){
//fsdf
    return -1;
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







