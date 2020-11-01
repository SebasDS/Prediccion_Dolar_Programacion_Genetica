/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: SEBAS
 *
 * Created on 1 de noviembre de 2020, 04:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
 * 
 */

void mepx(double *x /*inputs*/, double *outputs, char *variables[])
{
  double prg[19];
  prg[0] = x[2];                                            char *rama0 = variables[2];
  prg[1] = x[0];                                            char *rama1 = variables[0];
  prg[2] = x[2];                                            char *rama2 = variables[2];
  prg[3] = x[1];                                            char *rama3 = variables[1];
  prg[4] = x[2];                                            char *rama4 = variables[2];
  prg[5] = sin(prg[1]);                                     char* rama5 = (char *) malloc(7+strlen(rama1)); strcpy(rama5,"sin("); strcat(rama5,rama1); strcat(rama5,")");
  prg[6] = tan(prg[0]);                                     char* rama6 = (char *) malloc(6+strlen(rama0)); strcpy(rama6,"tan("); strcat(rama6,rama0); strcat(rama6,")");
  prg[7] = cos(prg[3]);                                     char* rama7 = (char *) malloc(6+strlen(rama3)); strcpy(rama7,"cos("); strcat(rama7,rama3); strcat(rama7, ")");
  prg[8] = sqrt(prg[0]);                                    char* rama8 = (char *) malloc(7+strlen(rama0)); strcpy(rama8,"sqrt("); strcat(rama8,rama0); strcat(rama8,")");
  prg[9] = prg[7] + prg[3];                                 char* rama9 = (char *) malloc(2+strlen(rama7)+strlen(rama3)); strcpy(rama9,rama7); strcat(rama9,"+"); strcat(rama9,rama3);
  prg[10] = prg[6] + prg[9];                                char* rama10 = (char *) malloc(2+strlen(rama6)+strlen(rama9)); strcpy(rama10,rama6); strcat(rama10,"+"); strcat(rama10,rama9);
  prg[11] = cos(prg[5]);                                    char* rama11 = (char *) malloc(6+strlen(rama5)); strcpy(rama11,"cos("); strcat(rama11,rama5); strcat(rama11, ")");
  prg[12] = prg[8] + prg[10];                               char* rama12 = (char *) malloc(2+strlen(rama8)+strlen(rama10)); strcpy(rama12,rama8); strcat(rama12,"+"); strcat(rama12,rama10);
  prg[13] = x[0];                                           char *rama13 = variables[0];
  prg[14] = prg[12] < prg[13]?prg[4] : prg[11];             char* rama14 = prg[12] < prg[13]?rama4 : rama11; 
  prg[15] = prg[9] < prg[14]?prg[10] : prg[2];              char* rama15 = prg[9] < prg[14]?rama10 : rama2;
  prg[16] = prg[15] * prg[15];                              char* rama16 = (char *) malloc(5+strlen(rama15)); strcpy(rama16,"("); strcat(rama16,rama15); strcat(rama16,")^2");
  prg[17] = prg[16] / prg[0];                               char* rama17 = (char *) malloc(6+strlen(rama16)+strlen(rama0)); strcpy(rama17,"("); strcat(rama17,rama16); strcat(rama17, ")/("); strcat(rama17,rama0); strcat(rama17,")");
  prg[18] = floor(prg[17]);                                 char* formula = (char *) malloc(5+strlen(rama17)); strcpy(formula,"floor("); strcat(formula, rama17); strcat(formula,")");

  outputs[0] = prg[18];
  
  printf("%s",formula);
}


int main(int argc, char** argv) {
    char *continuar = 'Y';
    while (continuar=='Y'){
    double x[3];
    char *prompt="\n Ingrese el valor del Dolar en los dias anteriores a la prediccion:\n";
    
    int cantV = sizeof(x)/sizeof(x[0]);
    char *variables[cantV];
    char *namesV[]={"Dolar antier: ", "Dolar ayer: ", "Dolar hoy: "};
    printf(prompt);
    for (int i=0; i<cantV; i++){
        switch(i){
            case 0:
                variables[i]="x0";
                break;
            case 1:
                variables[i]="x1";
                break;
            case 2:
                variables[i]="x2";
                break;
        }
        printf("%s", namesV[i]);
        scanf("%lf", &x[i]);
    }
    

    double outputs[1];
    printf("\nEl resultado de la formula encontrada es:\n");
    mepx(x, outputs, variables);
    printf(" = %lf\n", outputs[0]);
    printf("\nIntentar de nuevo? Y(Si) - N(No): ");
    scanf("%c",continuar);
    }
    return (EXIT_SUCCESS);
}

