/* UNIVERSIDADE FEDERAL FLUMINENSE
   INSTITUTO DE FÍSICA
   PROGRAMADOR: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115
   PROGRAMA: RUMOR.C - PROGRAMA QUE REALIZA POR MEIO ITERATIVO A SOLUÇÃO
                       NUMERICA PARA CONJUNTO DE EQUAÇÕES QUE COMPREEDEM
                       O SISTEMA DE RUMOR COM RUIDOS.
   MÉTODO: TRIVIAL
   DATA: 25/10/2017
*/

#include <stdio.h>
#include <stdlib.h>

int main (int arg, char *data[])
{

//float alfa = 0.2,beta = 0.3,gama =0.4;			 // CONSTANTES

  float alfa,beta,gama,delta;                         // CONSTANTES
  float L[4][10000];				 		 // VETOR LAMBDA

  alfa = atof(data[1]);
  beta = atof(data[2]);
  gama = atof(data[3]);
  delta= atof(data[4]);

  int passo=10000, limite=2000;

  L[0][0]=0.9800;
  L[1][0]=0.0100;
  L[2][0]=0.0100;

  float sum = 0;						 // CONFERÊNCIA DE NORALIZAÇÃO DOS PARAMETROS DO PROGRAMA
  for (int i=0; i<=3; i++)
  {
    sum =+L[i][0];
    if(sum > 1.00)
    {
      printf("SOMA DE PARAMETROS INCOMPATÍVEL, TOTAL = %.4f\n",sum);
      return 1;
    }
  }

  float h = (float)1/passo;

  for(int k=0; k<=limite; k++)
  {
    for(int j=1; j<=passo; j++)
    {
      L[0][k]=L[0][k]-h*(alfa*L[0][k]*L[1][k]+beta*L[0][k]*L[2][k]+delta*L[3][k]);
      L[1][k]=L[1][k]+h*(alfa*L[0][k]*L[1][k]+(alfa-beta)*L[1][k]*L[2][k]-gama*L[1][k]*(L[1][k]+L[3][k]));
      L[2][k]=L[2][k]+h*(beta*L[0][k]*L[2][k]+(beta-alfa)*L[1][k]*L[2][k]-gama*L[2][k]*(L[2][k]+L[3][k]));
      L[3][k]=L[3][k]+h*(gama*L[1][k]*(L[1][k]+L[3][k])+gama*L[2][k]*(L[2][k]+L[3][k])-delta*L[3][k]);

      sum = 0;
      for(int i=0; i<=3; i++)
      {
        sum +=L[i][k];
      }
    }
    for(int j=0; j<=3; j++)
    {
      printf("%.10f\t",L[j][k]);
    }
    printf("%.10f\n",sum);

    for(int j=0; j<=3; j++)
    {
      L[j][k+1] = L[j][k];
    }
  }

  return 0;
}
