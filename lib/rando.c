/*
        UNIVERSIDADE FEDERAL FLUMINENSE
        INSTITUTO DE FÍSICA
        DISCIPLINA - MONOGRAFIA
        PROFESSOR:  NUNO CROKIDAKIS PEREGRINO
        ALUNO:  MARCOS PAULO GOMES DE CASTRO
        PRORAMA:  RANDO -  PROGRAMA TESTE GERADOR DE NÚMEROS PSEUDO-ALEATÓRIOS FAZENDO USO
			   DAS SEGUINTES SEMESNTES COMO PARAMETROS INICIAIS.

        		   a = 85,    m=256;
        		   a = 899,   m=32768;
        		   a = 16807, m=4294967295;
        		   a = 16807, m=2147483647;

        MÉTODO:  TRIVIAL
        DATA: 01/03/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX32 16807
#define MAX64 4294967295

typedef struct{		//DEFINE TIPO DE VARIAVEL "NUMBER" QUE DARÁ FORMA AS ESTRUTURAS DE NUMEROS RANDÔMICOS

  int long seed;	// DECLARAÇÃO DE INTEIRO LONGO
  float	numb;		// DECLARAÇÃO DE PONTO FLUTUANTE
} number;		// NOME DA ESTRUTURA


number random(int long val){		// FUNÇÃO QUE RETORNA UMA VARIAVEL DO TIPO "NUMBER"

  number rnd;				// DEFINIÇÃO DE "RND" COMO UMA VARIAVEL "NUMBER"
  rnd.seed = ( MAX32*val ) % MAX64;	// SEQUENCIA PSEUDO-ALEATÓRA
  rnd.numb = (float)rnd.seed/MAX64;	// VALOR NORMALIZADO

  return rnd;				// RETORNA VALOR "RND"
}


int main(void) {			// PROGRAMA PRINCIPAL

 number cont;				// DEFINE UM "CONTADOR" AUXILIAR PARA CONTROLE DAS SEMENTES
 cont.seed = (time)NULL;		// DEFINIÇÃO DE SEMENTE ALEATÓRIA

 for(int i=1; i<=20; i++) {		// LOOPING DE TESTE

   cont = random(cont.seed);		// ESTRUTURA DE AUTO REFERENCIAMENTO
   printf("%.10f\n",cont.numb);
 }

 return 0;
}
