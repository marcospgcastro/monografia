/*
        UNIVERSIDADE FEDERAL FLUMINENSE
        INSTITUTO DE FÍSICA
        DISCIPLINA - MONOGRAFIA
        PROFESSOR:  NUNO CROKIDAKIS PEREGRINO
        ALUNO:  MARCOS PAULO GOMES DE CASTRO
        PRORAMA:  CARLO -  REALIZA SIMULAÇÕES DE MONTE CARLO PARA CAMPO MÉDIO, APLICADAS
                           AO MODELO DE ESPALHAMENTO DE RUMORES D.K., NO ÂMBITO DA INTERAÇÃO
                           LIVRE ENTRE INDIVÍDUOS, CAMPO MÉDIO.
        MÉTODO:  CARLO
        DATA: 01/03/2018
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX32 16807
#define MAX64 4294967295

typedef struct{         //DEFINE TIPO DE VARIAVEL "NUMBER" QUE DARÁ FORMA AS ESTRUTURAS DE NUMEROS RANDÔMICOS

  int long seed;        // DECLARAÇÃO DE INTEIRO LONGO
  float numb;           // DECLARAÇÃO DE PONTO FLUTUANTE
} number;               // NOME DA ESTRUTURA


number random(int long val){            // FUNÇÃO QUE RETORNA UMA VARIAVEL DO TIPO "NUMBER"

  number rnd;                           // DEFINIÇÃO DE "RND" COMO UMA VARIAVEL "NUMBER"
  rnd.seed = ( MAX32*val ) % MAX64;     // SEQUENCIA PSEUDO-ALEATÓRA
  rnd.numb = (float)rnd.seed/MAX64;     // VALOR NORMALIZADO

  return rnd;                           // RETORNA VALOR "RND"
}


int main(void) {                        // PROGRAMA PRINCIPAL

 int L = 10e5;				// DECLARAÇÃO DA DIMENSÃO DO VECTOR POPULAÇÃO
 char pop[L];				// DECLARAÇÃO DE VECTOR DE POPULAÇÃO

 number cont;                           // DEFINE UM "CONTADOR" AUXILIAR PARA CONTROLE DAS SEMENTES
 cont.seed = (time)NULL;                // DEFINIÇÃO DE SEMENTE ALEATÓRIA

 for(int i=1; i<=L; i++) {

   pop[i] = 'I';			// VECTOR DE POPULAÇÃO RECEBENDO INDIVÍDUOS IGNORANTES
   cont = random(cont.seed);            // ESTRUTURA DE AUTO REFERENCIAMENTO ORIUNDA DO PROGRAMA RANDO
   if(cont.numb <= 0.01) pop[i] = 'S';	// VECTOR DE POPULAÇÃO RECEBENDO INDIVÍDUOS ESPALHADORES
 }

 int n = 0;
 for(int i=1; i<=L; i++) {
   if(pop[i] == 'S') n++;
 }

 printf("\n	Percentual de indivíduos espalhadores no início das simulações: %.10f %%\n\n ",100*(float)n/L);

 return 0;
}

