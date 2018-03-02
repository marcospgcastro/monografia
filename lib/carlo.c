/*
        UNIVERSIDADE FEDERAL FLUMINENSE
        INSTITUTO DE FÍSICA
        DISCIPLINA - MONOGRAFIA
        PROFESSOR:  NUNO CROKIDAKIS PEREGRINO
        ALUNO:  MARCOS PAULO GOMES DE CASTRO
        PRORAMA:  CARLO -  REALIZA SIMULAÇÕES DE MONTE CARLO PARA CAMPO MÉDIO, APLICADAS
                           AO MODELO DE ESPALHAMENTO DE RUMORES D.K., NO ÂMBITO DA INTERAÇÃO
                           LIVRE ENTRE INDIVÍDUOS, CAMPO MÉDIO.
        MÉTODO:  TRIVIAL
        DATA: 02/03/2018
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX32 16807	// MÁXIMO INTEIRO PARA SISTEMAS DE 32 BITS
#define MAX64 4294967295// MÁXIMO INTEIRO PARA SISTEMAS DE 64 BITS

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

int main(int arg, char* line[]) {       // PROGRAMA PRINCIPAL

 float lambda = atof(line[1]);		// VALOR ATRIBUIDO A VARIAVEL LAMBDA
 float alfa   = atof(line[2]);		// VALOR ATRIBUIDO A VARIAVEL ALFA
 float delta  = atof(line[3]);		// VALOR ATRIBUIDO A VARIAVEL DELTA

 int m;					// AUXILIAR PARA CONTAGEM DE INDIVÍDUOS COM ESTATUS 'R'
 int n;					// AUXILIAR PARA CONTAGEM DE INDIVÍDUOS COM ESTATUS 'S'
 int u;					// AUXILIAR PARA CONTROLE DE VARIAVEIS ALEATÓRIAS

 int L = 10e5;				// DECLARAÇÃO DA DIMENSÃO DO VECTOR POPULAÇÃO
 char pop[L];				// DECLARAÇÃO DE VECTOR DE POPULAÇÃO

 srand((time)NULL);			// SEMENTE PARA GERAR SEQUENCIA PSEUDO-ALEATÓRIA PELA FUNÇÃO 'RAND'
 number cont;                           // DEFINE UM "CONTADOR" AUXILIAR PARA CONTROLE DAS SEMENTES
 cont.seed = (time)NULL;                // DEFINIÇÃO DE SEMENTE ALEATÓRIA

typedef struct {			// DEFINIÇÃO DE ESTRUTURA DE DADOS PARA GERENCIAMENTO DE VALORES DE DENSIDADE DE INDIVÍDUOS
   float I;				// VALOR ATRIBUIDO AOS INDIVÍDUOS DE ESTADO 'I' NA ESTRUTURA DE DADOS
   float S;				// VALOR ATRIBUIDO AOS INDIVÍDUOS DE ESTADO 'S' NA ESTRUTURA DE DADOS
   float R;				// VALOR ATRIBUIDO AOS INDIVÍDUOS DE ESTADO 'R' NA ESTRUTURA DE DADOS
 } valores;				// VARIAVEL DO TIPO 'VALORES'

 valores var[500+1];			// DEFINIÇÃO DE 'VAR[]' COMO ESTRUTURA DE DADOS

 for(int i=0; i<=500; i++) {		// LOOPING DE VARREDURA
   var[i].I = 0.00;			// ATRIBUI VALOR NULO PARA VECTOR DE ESTADOS 'I'
   var[i].S = 0.00;			// ATRIBUI VALOR NULO PARA VECTOR DE ESTADOS 'S'
   var[i].R = 0.00;			// ATRIBUI VALOR NULO PARA VECTOR DE ESTADOS 'R'
 }

 for(int simu=0; simu<=100; simu++) {   	// LOOPING QUE REALIZA MÉDIA SOBRE SIMULAÇÕES

   for(int i=1; i<=L; i++) {			// LOOPING DE VARREDURA SOBRE O VECTOR DE POPULAÇÃO

     pop[i] = 'I';				// VECTOR DE POPULAÇÃO RECEBENDO INDIVÍDUOS IGNORANTES
     cont = random(cont.seed);            	// ESTRUTURA DE AUTO REFERENCIAMENTO ORIUNDA DO PROGRAMA RANDO
     if(cont.numb <= 0.01) pop[i] = 'S';	// VECTOR DE POPULAÇÃO RECEBENDO INDIVÍDUOS ESPALHADORES
   }

   n = 0;					// CONTAGEM DE INDIVÍDUOS NO ESTADO 'S'
   for(int i=1; i<=L; i++) {			// LOOPING DE VARREDURA
     if(pop[i] == 'S') n++;			// ATUALIZA VALOR PARA CADA NOVO INDIVÍDUO
   }

   for(int i=0; i<=500; i++) {			// LOOPING SOBRE O TOTAL DE SIMULAÇÕES REALIZADAS SOBRE O SISTEMA

     for(int j=0; j<=L; j++) {			// LOOPING DE VARREDURA SOBRE O VECTOR DE POPULAÇÃO

       cont = random(cont.seed);		// GERADOR CONGRUENCIAL LINEAR, GCL, DE PSEUD-ALEATÓRIOS
       do { u = rand() % L; } while(u == L);	// AUXILIAR PARA SORTEAR INDIVÍDUO SOBRE O QUAL ACONTECERÁ A INTERAÇÃO: PESSOA X PESSOA


       if( pop[j] == 'I' && pop[u] == 'S' ) {	// CONDIÇÃO (1), [I]+[S]--->[S]+[S]: COM PROBABILIDADE LAMBDA
         if( cont.numb <= lambda ) pop[j] = 'S';// TESTA A CONDIÇÃO PELO GCL
       }
       if( pop[j] == 'S' && pop[u] == 'S' ) {	// CONDIÇÃO (2), [S]+[S]--->[S]+[R]: COM PROBABILIDADE ALFA
         if( cont.numb <= alfa ) pop[j] = 'R';	// TESTA A CONDIÇÃO PELO GCL
       }
       if( pop[j] == 'S' && pop[u] == 'R' ) {	// CONDIÇÃO (3), [S]+[R]--->[R]+[R]: COM PROBABILIDADE ALFA
         if( cont.numb <= alfa ) pop[j] = 'R';	// TESTA A CONDIÇÃO PELO GCL
       }
       if( pop[j] == 'S' ) {			// CONDIÇÃO (4), [S]--->[R]: COM PROBABILIDADE DELTA
         if( cont.numb <= delta ) pop[j] = 'R'; // TESTA A CONDIÇÃO PELO GCL
       }
     }

     n = 0;					// CONTAGEM DE INDIVÍDUOS NO ESTADO 'S'
     for(int i=0; i<=L; i++) {			// LOOPING DE VARREDURA
       if(pop[i] == 'S') n++;			// ATUALIZA VALOR PARA CADA NOVO INDIVÍDUO
     }
     m = 0;					// CONTAGEM DE INDIVÍDUOS NO ESTADO 'R'
     for(int i=0; i<=L; i++) {			// LOOPING DE VARREDURA
       if(pop[i] == 'R') m++;			// ATUALIZA VALOR PARA CADA NOVO INDIVÍDUO
     }

     var[i].I = var[i].I + (1-(float)m/L-(float)n/L)/100;	// GUARDA VALOR DE DENSIDADE DE ÍNDIVÍDUOS NO ESTADO 'I' AO FINAL DO PERCORRIMENTO
     var[i].S = var[i].S + (float)n/(L*100);                    // GUARDA VALOR DE DENSIDADE DE ÍNDIVÍDUOS NO ESTADO 'S' AO FINAL DO PERCORRIMENTO
     var[i].R = var[i].R + (float)m/(L*100);                    // GUARDA VALOR DE DENSIDADE DE ÍNDIVÍDUOS NO ESTADO 'R' AO FINAL DO PERCORRIMENTO
   }
 }

 for(int i=0; i<=500; i++) {			// RELATÓRIO DE SAIDA DE DADOS
   printf("%.10f\t",var[i].I);			// DENSIDADE DE ESTADOS 'I'
   printf("%.10f\t",var[i].S);			// DENSIDADE DE ESTADOS 'S'
   printf("%.10f\n",var[i].R);			// DENSIDADE DE ESTADOS 'R'
 }

 return 0;
}

