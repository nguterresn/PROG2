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

    vetor * vetor;
    FILE *file;
    file = fopen(nomef,"r");

    if (file != NULL) 
    {
        file = (FILE *)malloc(sizeof(file));
        return file; 
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







