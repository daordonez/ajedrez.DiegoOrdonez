//
//  main.c
//  ajedrez.DiegoOrdonez
//
//  Created by Diego Ordóñez Morales on 10/12/14.
//  Copyright (c) 2014 Diego Ordóñez Morales. All rights reserved.
//

#include <stdio.h>
//Constantes
#define MAX_COL 8
#define MAX_FIL 8
#define MAX_COR 2
#define LUG '_' //Lugar de juego
#define SEP '|' //Separador Tablero
#define MOV '+' //Posibles Movimientos

//Funciones
char selecPieza(){
    
    char pieza;
    int slc;
    
    printf("––––––––––––––––––––\n");
    printf("Seleccione Pieza\n");
    printf("––––––––––––––––––––\n");
    printf("1.Torre\n");
    printf("2.Caballo\n");
    printf("3.Alfil\n");
    printf("4.Dama\n");
    printf("5.Rey\n");
    printf("––––––––––––––––––––\n");
    printf("Introduza seleccion: ");
    scanf("%i",&slc);
    
    switch (slc) {
        case 1:
            pieza = 'T';
            break;
        case 2:
            pieza = 'C';
            break;
        case 3:
            pieza = 'A';
            break;
        case 4:
            pieza = 'D';
            break;
        case 5:
            pieza = 'R';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
    }
    
    return pieza;
}
void limpiaBuffer(){
    while( getchar() != '\n');
}
void creaTablero(char tablero[][ MAX_COL + 1]){
    
    //Inicializa todas las posiciones como vacias
    for (int fil = 1; fil <= MAX_FIL; fil++) {
        for (int col = 1; col <= MAX_COL; col++) {
            tablero[fil][col] = LUG;
        }
    }
}
void muestraTablero(char tablero[][MAX_COL +1]){
    printf("––––––––––––––––––––\n");
    printf("  ");
    //Numeros columna
    for (int num = 1; num <= MAX_COL; num++) {printf(" %i", num);}
    
    printf("\n");
    //Muestra lo que exista en la matriz y añade separador
    for (int fil = 1; fil <= MAX_FIL; fil++) {
        printf("%i%c",fil,SEP);
        for (int col = 1; col <= MAX_COL; col++) {
            printf("%c%c",tablero[fil][col],SEP);
        }
        printf("%i\n",fil);
    }
    printf("  ");
    for (int num = 1; num <= MAX_COL; num++) {printf(" %i", num);}
    printf("\n––––––––––––––––––––\n");
}
void cordenadasFi( int conjCord[]){
    //Recolectores desde teclado
    int tmpY, tmpX;
    
    printf("\n");
    do {
        printf("\t");
        printf("Cordenada X:");
        scanf("%i",&tmpX);
        limpiaBuffer();
    } while (tmpX < 0 && tmpX > 8 );
    
    do {
        printf("\t");
        printf("Cordenada X:");
        scanf("%i",&tmpY);
        limpiaBuffer();
    } while (tmpY < 0 && tmpY > 8 );
    
    //Introduccion en vector de cordenadas
    conjCord[0] = tmpY, conjCord[1] = tmpX;
}
void colocaFi(char pieza, char tablero[][MAX_COL + 1], int ubiFi[]){
    tablero[ubiFi[0]][ubiFi[1]] = pieza;
}
void movLineales(char tablero[][MAX_COL +1], int ubiFi[]){
    //origen_Arriba(Filas)
    for (int fil = ubiFi[0] - 1; fil >= 1; fil--) {
        if (tablero[fil][ubiFi[1]] == LUG) {tablero[fil][ubiFi[1]] = MOV;}
    }
    //origen_Abajo(Filas)
    for (int fil = ubiFi[0] + 1; fil <= MAX_FIL; fil++) {
        if (tablero[fil][ubiFi[1]] == LUG) {tablero[fil][ubiFi[1]] = MOV;}
    }
    //origen_Derecha (Columnas)
    for (int col = ubiFi[1] + 1; col <= MAX_COL; col++) {
        if (tablero[ubiFi[0]][col] == LUG) {tablero[ubiFi[0]][col] = MOV;}
    }
    //origen_izquierda (Columnas)
    for (int col = ubiFi[1] - 1; col >= 1; col--) {
        if (tablero[ubiFi[0]][col] == LUG) {
            tablero[ubiFi[0]][col] = MOV;
        }
    }
}
void movDiagonal(char tablero[][MAX_COL +1], int ubiFi[]){}

int main(int argc, const char * argv[]) {
    
    //Pieza
    char pieza;
    
    //Evitar posiciones 0
    int filasT = MAX_FIL + 1, columT = MAX_COL + 1;
    
    //Tablero de juego y cordenadas rango máximo 0,0 - 8,8
    char tableroJ[filasT][columT];
    int ubiFich[MAX_COR];
    
    //Inicializa Tablero
    creaTablero(tableroJ);
    /*---------------------Repetir---------------------------*/
    //Pide tipo de pieza
    pieza =  selecPieza();
    //Pide Cordenadas
    cordenadasFi(ubiFich);
    //Coloca Ficha
    colocaFi(pieza, tableroJ, ubiFich);
    
    //Muestra contenido
    muestraTablero(tableroJ);
    
    
    return 0;
}
