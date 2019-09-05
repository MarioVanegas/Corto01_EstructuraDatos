#include <stdio.h>
#define columna 5
#define fila 5

int main(){

    double cinesala[5][5];
    int disponibilidad[5][5];

    //se ocuparan estas variables globales para cada opcion del menu.
    int opciones;
    int bandera = 0;
    double ganancia = 0;
    int fil, col;

    //Establecer precios utilizando for para simplificar.
    for(int i = 0; i < columna; i++){
        cinesala[0][i] = 5;
    }
    for(int i = 0; i < columna; i++){
        cinesala[fila - 1][i] = 2.5;
    }
    for(int i = 1; i < fila - 1; i++){
        for(int j = 0; j < fila; j++){
            cinesala[i][j] = 3.5;
        }
    }
    //Para ver disponiblidad
    for(int i = 0; i < fila; i++)
        for(int j = 0; j < columna; j++)
            disponibilidad[i][j] = 1;

    //Creacion del menu, usando while, switch y break.
    while(1){

        printf("-------Elige una opcion de tu preferencia----------------\n");
        printf("1.Venta de entradas.\n");
        printf("2.Verificar asiento.\n");
        printf("3.Ganancias.\n");
        printf("4.Salir.\n");

        scanf("%d",&opciones);

        printf("Opcion %d seleccionada\n", opciones);

        switch(opciones){
            //si la opcion es invalida
            default:
                printf("Seleccione una opcion valida.\n");
                break;

            case 1:

                //Ventas
                printf("\n");
                printf("Selecciones fila y columna \n");
                printf("fila: (1-%d)\n",fila);
                scanf("%d",&fil);
                printf("columna: (1-%d)\n",columna);
                scanf("%d",&col);

                fil--,col--;

                //si esta disponible para vender
                if(disponibilidad[fil][col]){

                    printf("El precio es: %f\n",cinesala[fil][col]);

                    ganancia += cinesala[fil][col];
                    disponibilidad[fil][col] = 0;
                }else{
                    printf("Asiento no disponible.\n");
                }
                break;
            case 2:
                //Para mostrar
                printf("P:");
                for(int i = 0; i < columna; i++){
                    printf("_");
                }
                printf("\n");
                for(int i = fila-1; i >= 0; i--){
                    printf("%d:",i+1);
                    for(int j = 0; j < columna; j++){
                        printf("%d",disponibilidad[i][j]);
                    }
                    printf("\n");
                }
                printf("C:");
                for(int i = 1; i <= columna; i++)
                    printf("%d",i);
                printf("\n");
                break;
            case 3:
                //VENTAS
                printf("Las ganancias  son: %f$\n",ganancia);
                break;
            case 4:
             //Salir
                bandera = 1;
                break;
        }
        if(bandera)
            break;
    }
    return 0;
}