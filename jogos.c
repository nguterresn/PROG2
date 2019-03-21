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
    if(!file){
        perror("Error:");
        return NULL;
    }
    vetor * vtr = vetor_novo();
    if(vtr == NULL) 
        return NULL;

    jogo jogo1;

    while (fscanf(file,"%s %s %s %d %d %d %d", jogo1.epoca, jogo1.nome_casa, jogo1.nome_fora, &jogo1.golos_casa, &jogo1.golos_fora, &jogo1.vermelhos_casa, &jogo1.vermelhos_fora) != EOF)
    {   
        vetor_insere(vtr, jogo1, -1);
	}

    fclose(file);
    return vtr;
}


int jogos_save(vetor *vec, const char *nomef){

    FILE *file;
    file = fopen(nomef,"w");
    if (!file) 
    {
        perror("Error: ");
        return -1;
    }

    for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * jog = vetor_elemento(vec, i);
        fprintf((FILE*) file, "%s ", jog->epoca);
        fprintf((FILE*) file, "%s ", jog->nome_casa);
        fprintf((FILE*) file, "%s ", jog->nome_fora);
        fprintf((FILE*) file, "%d ", jog->golos_casa);
        fprintf((FILE*) file, "%d ", jog->golos_fora);
        fprintf((FILE*) file, "%d ", jog->vermelhos_casa);
        fprintf((FILE*) file, "%d ", jog->vermelhos_fora);
    }

    fclose(file);
    return vec->tamanho;
}


vetor_equipas *stats_equipa(vetor *vec)
{
    uint8_t marcados_casa;
    uint8_t marcados_fora;
    uint8_t sofridos_casa;
    uint8_t sofridos_fora;
    uint8_t vermelho_casa_1;
    uint8_t vermelho_casa_2;
    uint8_t vermelho_casa_3;
    uint8_t vermelho_fora_1;
    uint8_t vermelho_fora_2;
    uint8_t vermelho_fora_3;
    int diff_golos;

    float vermelhos[3];

    vetor_equipas * vtr_equipas = vetor_equipas_novo();
    equipa equipa;

    for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * jg = vetor_elemento(vec, i);

        if ((strstr(jg->nome_casa,"Tottenham") != NULL) || (strstr(jg->nome_fora,"Tottenham") != NULL)) 
        {
            if (strstr(jg->nome_casa,"Tottenham") != NULL) {
                if (jg->golos_casa != 0)
                    marcados_casa += jg->golos_casa;
                if (jg->golos_fora != 0)
                    sofridos_casa += jg->golos_fora;

                if (strstr(jg->epoca,"15/16") != NULL) {
                    //19jogos
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_1 += jg->vermelhos_casa;
                }
                if (strstr(jg->epoca,"16/17") != NULL) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_2 += jg->vermelhos_casa;
                }
                if (strstr(jg->epoca,"17/18") != NULL) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_3 += jg->vermelhos_casa;
                }
            }

            if (strstr(jg->nome_fora,"Tottenham") != NULL) {
                if (jg->golos_fora != 0 )
                    marcados_fora += jg->golos_fora;
                if (jg->golos_casa != 0 )
                    sofridos_fora += jg->golos_casa;

                if (strstr(jg->epoca,"15/16") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_1 += jg->vermelhos_fora;
                }
                if (strstr(jg->epoca,"16/17") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_2 += jg->vermelhos_fora;
                }
                if (strstr(jg->epoca,"17/18") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_3 += jg->vermelhos_fora;
                }
            }

            diff_golos = (marcados_casa + marcados_fora) - (sofridos_casa + sofridos_fora);
            vermelhos[0] = (double)(vermelho_casa_1 + vermelho_fora_1)/38;
            vermelhos[1] = (double)(vermelho_casa_2 + vermelho_fora_2)/38;
            vermelhos[2] = (double)(vermelho_casa_3 + vermelho_fora_3)/38;

            strcpy(equipa.nome_equipa,jg->nome_casa);
            equipa.diff_golos = diff_golos;
            equipa.vermelhos[0] = vermelhos [0];
            equipa.vermelhos[1] = vermelhos [1];
            equipa.vermelhos[2] = vermelhos [2];
                    
        }

        if ((strstr(jg->nome_casa,"Arsenal") != NULL) || (strstr(jg->nome_fora,"Arsenal") != NULL)) 
        {
            if (strstr(jg->nome_casa,"Arsenal") != NULL) {
                if (jg->golos_casa != 0)
                    marcados_casa += jg->golos_casa;
                if (jg->golos_fora != 0)
                    sofridos_casa += jg->golos_fora;

                if (strstr(jg->epoca,"15/16") != NULL) {
                    //19jogos
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_1 += jg->vermelhos_casa;
                }
                if (strstr(jg->epoca,"16/17") != NULL) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_2 += jg->vermelhos_casa;
                }
                if (strstr(jg->epoca,"17/18") != NULL) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_3 += jg->vermelhos_casa;
                }
            }

            if (strstr(jg->nome_fora,"Arsenal") != NULL) {
                if (jg->golos_fora != 0 )
                    marcados_fora += jg->golos_fora;
                if (jg->golos_casa != 0 )
                    sofridos_fora += jg->golos_casa;

                if (strstr(jg->epoca,"15/16") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_1 += jg->vermelhos_fora;
                }
                if (strstr(jg->epoca,"16/17") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_2 += jg->vermelhos_fora;
                }
                if (strstr(jg->epoca,"17/18") != NULL) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_3 += jg->vermelhos_fora;
                }
            }

            diff_golos = (marcados_casa + marcados_fora) - (sofridos_casa + sofridos_fora);
            vermelhos[0] = (double)(vermelho_casa_1 + vermelho_fora_1)/38;
            vermelhos[1] = (double)(vermelho_casa_2 + vermelho_fora_2)/38;
            vermelhos[2] = (double)(vermelho_casa_3 + vermelho_fora_3)/38;

            strcpy(equipa.nome_equipa,jg->nome_casa);
            equipa.diff_golos = diff_golos;
            equipa.vermelhos[0] = vermelhos [0];
            equipa.vermelhos[1] = vermelhos [1];
            equipa.vermelhos[2] = vermelhos [2];

            printf("Diff: %d\n", diff_golos);
                    
        }
    }
    
    /*
    if (strstr(equipa.nome_equipa,"Tottenham") != NULL) {
        printf("Equipa: %s\n", equipa.nome_equipa);
        printf("Diff: %d\n", equipa.diff_golos);
        printf("Vermelhos: %f\n", equipa.vermelhos[0]);
    }*/
    
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







