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
        fprintf((FILE*) file, "%d\n", jog->vermelhos_fora);
    }

    fclose(file);
    return vec->tamanho;
}

void get_equipas (vetor *vec, vetor_equipas *vec_equipas, const char* nome_equipa) 
{
    uint8_t marcados_casa = 0;
    uint8_t marcados_fora = 0;
    uint8_t sofridos_casa = 0;
    uint8_t sofridos_fora = 0;
    uint8_t vermelho_casa_1 = 0;
    uint8_t vermelho_casa_2 = 0;
    uint8_t vermelho_casa_3 = 0;
    uint8_t vermelho_fora_1 = 0;
    uint8_t vermelho_fora_2 = 0;
    uint8_t vermelho_fora_3 = 0;
    int diff_golos = 0;
    float vermelhos[3];

    equipa equipa;

    for (int i = 0; i < vec->tamanho; i++) 
    {
        jogo * jg = vetor_elemento(vec, i);
        
        if ((!(strncmp(jg->nome_casa, nome_equipa, strlen(nome_equipa)))) || (!(strncmp(jg->nome_fora, nome_equipa, strlen(nome_equipa)))))
        {
            if (!(strncmp(jg->nome_casa, nome_equipa, strlen(nome_equipa)))) {
                if (jg->golos_casa != 0)
                    marcados_casa += jg->golos_casa;
                if (jg->golos_fora != 0)
                    sofridos_casa += jg->golos_fora;

                if (!(strcmp(jg->epoca, "15/16"))) {
                    //19jogos
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_1 += jg->vermelhos_casa;
                }
                if (!(strcmp(jg->epoca, "16/17"))) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_2 += jg->vermelhos_casa;
                }
                if (!(strcmp(jg->epoca, "17/18"))) {
                    if (jg->vermelhos_casa != 0)
                        vermelho_casa_3 += jg->vermelhos_casa;
                }
            }

            if (!(strncmp(jg->nome_fora, nome_equipa, strlen(nome_equipa)))) {
                if (jg->golos_fora != 0 )
                    marcados_fora += jg->golos_fora;
                if (jg->golos_casa != 0 )
                    sofridos_fora += jg->golos_casa;

               if (!(strcmp(jg->epoca, "15/16"))) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_1 += jg->vermelhos_fora;
                }
                if (!(strcmp(jg->epoca, "16/17"))) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_2 += jg->vermelhos_fora;
                }
                if (!(strcmp(jg->epoca, "17/18"))) {
                    if (jg->vermelhos_fora != 0)
                        vermelho_fora_3 += jg->vermelhos_fora;
                }
            }
        }
    }

    diff_golos = (marcados_casa + marcados_fora) - (sofridos_casa + sofridos_fora);
    vermelhos[0] = (double)(vermelho_casa_1 + vermelho_fora_1)/38;
    vermelhos[1] = (double)(vermelho_casa_2 + vermelho_fora_2)/38;
    vermelhos[2] = (double)(vermelho_casa_3 + vermelho_fora_3)/38;

    strcpy(equipa.nome_equipa,nome_equipa);
    equipa.diff_golos = diff_golos;
    equipa.vermelhos[0] = vermelhos [0];
    equipa.vermelhos[1] = vermelhos [1];
    equipa.vermelhos[2] = vermelhos [2];

    printf("\nDiff %s: %d\n", equipa.nome_equipa, equipa.diff_golos);  
    printf("Vermelhos: %f\n", equipa.vermelhos[0]);
    printf("Vermelhos: %f\n", equipa.vermelhos[1]);
    printf("Vermelhos: %f\n", equipa.vermelhos[2]);

    vetor_equipas_insere(vec_equipas, equipa, -1);
}

vetor_equipas *stats_equipa(vetor *vec)
{

    vetor_equipas * vtr_equipas = vetor_equipas_novo();
    equipa equipa;

    get_equipas(vec, vtr_equipas,"Arsenal");
    get_equipas(vec, vtr_equipas,"Stoke");
    get_equipas(vec,vtr_equipas,"Bournemouth");
    get_equipas(vec, vtr_equipas,"Aston_Villa");
    get_equipas(vec, vtr_equipas,"Chelsea");
    get_equipas(vec, vtr_equipas,"Swansea");
    get_equipas(vec, vtr_equipas,"Everton");
    get_equipas(vec, vtr_equipas,"Watford");
    get_equipas(vec, vtr_equipas,"Leicester");
    get_equipas(vec, vtr_equipas,"Sunderland");
    get_equipas(vec, vtr_equipas,"Man_United");
    get_equipas(vec, vtr_equipas,"Tottenham");
    get_equipas(vec, vtr_equipas,"Norwich");
    get_equipas(vec, vtr_equipas,"Crystal_Palace");
    get_equipas(vec, vtr_equipas,"West_Ham");
    get_equipas(vec, vtr_equipas,"Newcastle");
    get_equipas(vec, vtr_equipas,"Southampton");
    get_equipas(vec, vtr_equipas,"Liverpool");
    get_equipas(vec, vtr_equipas,"West_Brom");
    get_equipas(vec, vtr_equipas,"Man_City");
    get_equipas(vec, vtr_equipas,"Middlesbrough");
    get_equipas(vec, vtr_equipas,"Hull");
    get_equipas(vec, vtr_equipas,"Burnley");
    get_equipas(vec, vtr_equipas,"Brighton");
    get_equipas(vec, vtr_equipas,"Huddersfield");

    
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







