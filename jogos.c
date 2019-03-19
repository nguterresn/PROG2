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
   
   /* este valor tem de ser mudado para algo mais eficiente, para já funciona */

    if (file != NULL) 
    {   
        while (fgets(buffer, 255, (FILE*) file))
        {
            /* strlen x 1 byte (255bits) */
            vtr->elementos = (jogo * )malloc (strlen(buffer)*sizeof(char)); 
            games_counter++;
	    }

        vtr->tamanho = games_counter;
        memcpy (vtr->elementos, buffer, vtr->tamanho);
        return vtr;
    } 
    else return NULL;
}


int jogos_save(vetor *vec, const char *nomef){

    FILE *file;
    file = fopen(nomef,"r");
    char buffer[255];
    int games_counter = 0;

    if (vec != NULL) {

    } else {

    }
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







