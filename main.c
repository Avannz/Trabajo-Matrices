#include <stdio.h>
#include <stdlib.h>

const int filas=3;
const int columnas=3;

void cargarMatriz(int matriz[filas][columnas]);
void mostrarMatriz(int matriz[filas][columnas]);
void cargarMatrizRandom(int matriz[filas][columnas], int random[filas][columnas]);
float promedioMatriz(int matriz[filas][columnas]);

int main()
{
    int matriz[filas][columnas];
    int matrizRandom[filas][columnas];
    int matrizFloat[filas][columnas];
    int suma;
    float promedio;


    cargarMatriz(matriz);
    printf("\n\nMatriz de orden 'mxn': \n");
    mostrarMatriz(matriz);

    cargarMatrizRandom(matriz, matrizRandom);
    printf("\nMatriz(rand) de orden 'mxn': \n");
    mostrarMatriz(matrizRandom);

    suma = sumarMatriz(matriz);
    printf("La suma de la matriz de orden 'mxn' es de: %d", suma);

    promedio = promedioMatriz(matriz);
    printf("El promedio de la matriz de orden 'mxn' es de: %f", promedio);

}

void cargarMatriz(int matriz[filas][columnas])
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

void mostrarMatriz(int matriz[filas][columnas])
{

    int i;
    int j;
    int num = 1;

    for(i = 0; i < filas; i++)
    {

        for(j = 0; j < columnas; j++)
        {
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void cargarMatrizRandom(int matriz[filas][columnas], int random[filas][columnas])
{

    int i;
    int j;
    int num = 1;

    for(i = 0; i < filas; i++)
    {
        for(j = 0; j < columnas; j++)
        {
            random [i][j] = rand ()% 100+1;
        }
        num++;
    }
}

int sumarMatriz(int matriz[filas][columnas]){

    int i;
    int j;
    int suma = 0;
    int num = 1;

    for(i = 0;i < filas; i++){

        for(j = 0;j < columnas; j++){

            suma = suma + matriz[i][j];
        }

        num++;
    }
    return suma;
}

float promedioMatriz(int matriz[filas][columnas]){

    int i;
    int j;
    float suma = 0;
    float promedio = 0;

    for(i = 0; i < filas; i++){

        for(j = 0; j < columnas; j++){

            suma = suma + matriz[i][j];

        }

    }

    promedio = suma / (filas * columnas);

    return promedio;
