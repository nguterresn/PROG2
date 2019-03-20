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
    if(vtr == NULL) 
        return NULL;

    jogo * jogo1 = (jogo*)malloc(sizeof(jogo));
    if(jogo1 == NULL) 
        return NULL;

    if (file != NULL) 
    {   
        while (fgets(buffer, 255, (FILE*) file))
        {
            strcpy((char*)jogo1, buffer);
            vetor_insere(vtr, *jogo1, -1);
	    }

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

    char * buffer = (char*) malloc (255 * sizeof(buffer));
    if (buffer == NULL) {
        perror("Erro:");
        return -1;
    }

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

    //jogo * jg;
    equipa * equip;
    char* buffer = (char*)malloc(sizeof(buffer)*100);
    if (buffer == NULL) {
        perror("Erro:");
        return NULL;
    }

    char* aloc = (char*)malloc(sizeof(aloc)*100);
    if (aloc == NULL) {
        perror("Erro:");
        return NULL;
    }

    char *flux[] = {};
    int diff_golos;
    int marcados_casa = 0;
    int sofridos_casa = 0;
    int marcados_fora = 0;
    int sofridos_fora = 0;
    uint8_t vermelho_casa_1 = 0;
    uint8_t vermelho_casa_2 = 0;
    uint8_t vermelho_casa_3 = 0;
    uint8_t vermelho_fora_1 = 0;
    uint8_t vermelho_fora_2 = 0;
    uint8_t vermelho_fora_3 = 0;
    char nome_equipa[30];
    float vermelhos[3];

    char *esp1;
    char *esp2;
    char *esp3;
    char *esp4;
    char *esp5;
    char *esp6;


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
            
        }
    }

    printf("Marcados: %d\n", (marcados_casa+marcados_fora));
    printf("Sofridos: %d\n", (sofridos_casa+sofridos_fora));
    printf("Diff: %d\n", diff_golos);
    printf("Vermlhso 15/16: %f\n", vermelhos[0]);
    printf("Vermlhso 16/17: %f\n", vermelhos[1]);
    printf("Vermlhso 17/18: %f\n", vermelhos[2]);

    free(buffer);
    free(aloc);
    
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







