#include <stdio.h>
#include <stdlib.h>

const int filas=3;
const int columnas=2;

void cargar(int matriz[filas][columnas]);

int main()
{
    int matriz[filas][columnas];


    cargar(matriz);


}

void cargar(int matriz[filas][columnas])
{

    int i;
    int j;
    int num = 1;

    for(i = 0; i < filas; i++)
    {

        printf("Datos ingresados en la fila numero: %i \n", num);

        for(j = 0; j < columnas; j++)
        {

            printf("Ingrese el dato que desea (columna): ");
            fflush(stdin);
            scanf("%i", &matriz[i][j]); // Importante los corchetes para esto. Es para poner el dato el la posicion que querramos.

        }
        num++;
    }
}
