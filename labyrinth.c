#include <stdio.h>

 /* Función que convierte número a carácter para imprimir*/
char showMap(int tipo){
    switch(tipo) {
        case 0: return ' ';  // libre
        case 1: return '#';  // pared
        case 2: return '~';  // agua, por ejemplo
        default: return '?'; // desconocido
    }
}

int main(){

    int map[15][15];
    int i, j;

    /* Inicializar los bordes del mapa como paredes (1) y el resto como libre (0) */
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            if(j==0 || i == 0 || j==14 || i==14){
                map[i][j] = 1;
            }
            else if((i>=3 && i<=11) && (j==1 || j==3 || j==4 || j==6 || j==7 || j==8 || j==10 || j==11 || j==13)){
                map[i][j] = 1;
            }
            else map[i][j] = 0;
        }
    }
    map[3][2] = 1; map[3][12] = 1;


    printf("Mapa ( ' '= libre, '#'= pared, '~'= agua):\n");
    for(i = 0; i < 15; ++i){
        for(j = 0; j < 15; ++j){
            /* usar formato "%d" para imprimir un entero */
            printf("%c ", showMap(map[i][j]));
        }
        printf("\n");
    }

    return(0);
}