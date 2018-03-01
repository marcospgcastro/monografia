/*
	UNIVERSIDADE FEDERAL FLUMINENSE
	INSTITUTO DE FÍSICA
	DISCIPLINA - MONOGRAFIA
	PROFESSOR:  NUNO CROKIDAKIS PEREGRINO
	ALUNO:  MARCOS PAULO GOMES DE CASTRO
	PRORAMA:  EULER -  RESOLVE EQUAÇÕES DIFERENCIAIS NÃO LINEARES PELO MÉTODO DE EULER,
			   FAZENDOP USO DE UM ALGORÍTMO DE MESMO NOME. AQUI É EMPREGADO EM
			   UM SISTEMA DE ESPALHAMENTO DE RUMORES, COMO PRÉVIA DE SOMULAÇÕES
			   MAIS COMPLEXAS COMO MONTE CARLO POR CAMPO MÉDIO.
	MÉTODO:  EULER
	DATA: 24/02/2018
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main (int cont, char* data[]) {

 int l=100;	// ITERAÇÕES DE H

 float alfa;	// TAXA DE MIGRAÇÃO DE [S] -> [R]
 float lambda;	// TAXA DE MIGRAÇÃO DE [I] -> [S]

 float h=0.0;	// PASSO DE TEMPO NA ITERAÇÃO

 float in=1.0000;	// INDICES DE CONTAGEM PARA [I]
 float sn=0.0010;	// INDICES DE CONTAGEM PARA [S]
 float rn=0.0000;	// INDICES DE CONTAGEM PARA [R]

 float auxi, auxs;	// VALORES AUXILIARES

 alfa  = atof(data[1]);	// ALFA RECEBE O VALOR DA LINHA DE COMANDO
 lambda= atof(data[2]); // LAMBDA RECEBE O VALOR DA LINHA DE COMANDO

 for(int i=1;i<=10;i++) {	// LOOPING DE PASSO
   for(int j=1;j<=l;j++) {	// LOOPING DE TEMPO

     h=h+(float)1/l;	// ATUALIZA DO VALOR DE H

     auxi = in - h*lambda*in*sn;
     auxs = sn + h*lambda*in*sn - h*alfa*sn*(sn+rn); in = auxi;
     rn = rn + h*alfa*sn*(sn+rn); sn = auxs;

     printf("%2.10f       %2.10f  %2.10f  %2.10f\n",in,sn,rn,in+sn+rn);

   }	// ENCERRA O LOOPING DE PASSO
 }	// ENCERRA O LOOPING DE TEMPO

 return 0;
}
