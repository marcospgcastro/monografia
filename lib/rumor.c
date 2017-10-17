/* UNIVERSIDADE FEDERAL FLUMINENSE
   INSTITUTO DE FÍSICA
   PROGRAMADOR: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115
   PROGRAMA: RUMOR.C - PROGRAMA QUE REALIZA POR MEIO ITERATIVO A SOLUÇÃO
                       NUMERICA PARA CONJUNTO DE EQUAÇÕES QUE COMPREEDEM
                       O SISTEMA DE RUMOR COM RUIDOS.
   MÉTODO: TRIVIAL
   DATA: 17/10/2017
*/

#include <stdio.h>

int main (void) {

  float ;			 // CONSTANTES
  float L[4][10000]; 		 // VETOR LAMBDA

  int passo=10000, limite=500;

  float sum = 0;		 // CONFERÊNCIA DE NORALIZAÇÃO DOS PARAMETROS DO PROGRAMA
  for (int i=0; i<=6; i++) {
    sum =+L[i][0];
    if(sum > 1.00) {
      printf("SOMA DE PARAMETROS INCOMPATÍVEL, TOTAL = %.4f\n",sum);
      return 1;
    }
  }

  float h = (float)1/passo;
  for(int k=0; k<=limite; k++) {
    for(int j=1; j<=passo; j++) {
      L[0][k] = L[0][k] + h*( );
      L[1][k] = L[1][k] + h*( );
      L[2][k] = L[2][k] + h*( );
      L[3][k] = L[3][k] + h*( );

      sum = 0; for (int i=0; i<=3; i++) sum +=L[i][k];
    }
    for(int j=0; j<=3; j++)
    {
      printf("%.10f\t",L[j][k]);
      printf("%.10f\t%.10f\t%.10f\n",L[0][k]+L[1][k]+L[2][k]+L[6][k],L[3][k],sum);
    }
    for(int j=0; j<=3; j++)
    {
      L[j][k+1] = L[j][k];
    }
  }

  return 0;
}
