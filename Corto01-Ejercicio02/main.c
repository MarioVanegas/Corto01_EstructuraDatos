#include <stdio.h>

int main() {
    int i, pos,n, eliminado;
    printf("\n------Programa que elimina una posicion de un array------\n");
    printf("\n");

    //Asignando Tamaño al vector
    printf("Indique el tamaño del vector: ");
    scanf("%i",&n);

    int vector[n];

    //Llenando el vector
    for(i=0;i<n;i++){
        printf("Valor de la posicion %i: ",i+1);
        scanf("%i",&vector[i]);
    }
    printf("\nVector actual:\n");
    //Mostrando vector
    for(i=0;i<n;i++){
        printf("Elemento [%i] Posicion %i = %i\n",i,i+1,vector[i]);
    }

    /*
     * Se elimina el vector para ello se uso el while y sentencias if
     * para validar donde se encuentra para ello se recorre el vector.
     *
     */
    printf("\n¿Que posicion desea eliminar?: ");
    scanf("%i",&pos);

    if(pos>n){
        printf("El valor colocado es mayor que el tamaño del vector.-------");
    }
    else{
        eliminado = vector[pos-1];
        for(i=0;i<n;i++){
            if(i==(pos-1)){
                while(i<n){
                    vector[i] = vector[i+1];
                    i++;
                }
                break;
            }
        }

        /* Recorrer el vector para mostrarlo y luego imprimir el elemento y
         * su posicion.
          */
        printf("\nVector actual :\n");
        n-=1;
        for(i=0;i<n;i++){
            printf("Elemento [%i] Posicion %i = %i\n",i,i+1,vector[i]);
        }

        printf("\nNumero eliminado: %i",eliminado); // Muestra el numero eliminado.
    }

    return 0;
}
