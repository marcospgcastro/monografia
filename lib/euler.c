/* UNIVERSIDADE FEDERAL FLUMINENSE
   INSTITUTO DE FÍSICA
   PROGRAMADOR: MARCOS PAULO GOMES DE CASTRO - MATRÍCULA: 113.025.115
   PROGRAMA: EULER.C - SOLUCIONA EQUAÇÕES DIFERENCIAIS POR MÉTODO SIMPLES
   MÉTODO: TRIVIAL
   DATA: 15/09/2017
*/

#include <stdio.h>

int main (void) {

  float alfa=0.10, gama=0.10, beta=0.50, delta=0.10, xi=0.10, psi=0.10, zeta=0.10, L[7][10000];
  int passo=10000, limite=200;

  L[0][0] = 0.40;
  L[1][0] = 0.10;

  L[3][0] = 0.60;
  L[4][0] = 0.01;

  L[2][0] = L[2][0] = L[5][0] = L[6][0] = 0.00;

  float h = 0.0001;
  for(int k=0; k<=limite; k++) {
    for(int j=1; j<=passo; j++) {
      L[0][k] = L[0][k] + h*( -alfa*L[0][k]*L[1][k] -beta*L[0][k]*L[4][k] -beta*L[0][k]*L[6][k] );
      L[1][k] = L[1][k] + h*( -gama*L[1][k]*L[1][k] -gama*L[1][k]*L[2][k] -delta*L[1][k] -xi*L[1][k]*L[6][k] +alfa*L[0][k]*L[1][k] );
      L[2][k] = L[2][k] + h*( +gama*L[1][k]*L[1][k] +gama*L[1][k]*L[2][k] +delta*L[1][k] +xi*L[1][k]*L[6][k] +gama*L[1][k]*L[6][k] +gama*L[2][k]*L[6][k] +xi*L[4][k]*L[6][k] +xi*L[5][k]*L[6][k] +xi*L[6][k]*L[6][k] +psi*L[6][k] );
      L[3][k] = L[3][k] + h*( -beta*L[3][k]*L[4][k] -beta*L[3][k]*L[6][k] );
      L[4][k] = L[4][k] + h*(   -xi*L[4][k]*L[4][k]   -xi*L[4][k]*L[5][k] -delta*L[4][k] -xi*L[4][k]*L[6][k] +beta*L[3][k]*L[4][k] +beta*L[3][k]*L[6][k] );
      L[5][k] = L[5][k] + h*(   +xi*L[4][k]*L[4][k]   +xi*L[4][k]*L[5][k]  +zeta*L[4][k] +xi*L[4][k]*L[6][k] );
      L[6][k] = L[6][k] + h*( -gama*L[1][k]*L[6][k] -gama*L[2][k]*L[6][k] -xi*L[4][k]*L[6][k] -xi*L[5][k]*L[6][k] -xi*L[6][k]*L[6][k] -psi*L[6][k] +beta*L[0][k]*L[4][k] +beta*L[0][k]*L[6][k] );
    }
    for(int j=0; j<=6; j++) printf("%.10f\t",L[j][k]); printf("\n");
    for(int j=0; j<=6; j++) L[j][k+1] = L[j][k];
  }

  return 0;
}
