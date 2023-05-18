#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int filas=2;
const int filasC=3;
const int columnas=2;
const int columnasC=30;
const int dim=5;

void cargarMatriz(int matriz[filas][columnas]);
void mostrarMatriz(int matriz[filas][columnas]);
void cargarMatrizRandom(int matriz[filas][columnas], int random[filas][columnas]);
float promedioMatriz(int matriz[filas][columnas]);
int buscarMatriz(int matriz[filas][columnas], int dato);
int cargarArregloSt(char arreglo[filasC][columnasC], int dim);
void mostrarArregloSt(char arreglo[filasC][columnasC], int val);

int main()
{
    int matriz[filas][columnas];
    int matrizRandom[filas][columnas];
    int matrizFloat[filas][columnas];
    char arreglo[filasC][columnasC];
    char palabra[columnasC];
    int suma;
    int flag;
    int dato;
    int validos;
    float promedio;

//    cargarMatriz(matriz);
//    printf("\n\nMatriz de orden 'mxn': \n");
//    mostrarMatriz(matriz);
//
//    cargarMatrizRandom(matriz, matrizRandom);
//    printf("\nMatriz(rand) de orden 'mxn': \n");
//    mostrarMatriz(matrizRandom);
//
//    suma = sumarMatriz(matriz);
//    printf("\nLa suma de la matriz de orden 'mxn' es de: %d", suma);
//
//    promedio = promedioMatriz(matriz);
//    printf("\n\nEl promedio de la matriz de orden 'mxn' es de: %.2f", promedio);
//
//
//    printf("\nIngrese un dato para buscar en la matriz:");
//    fflush(stdin);
//    scanf("%d", &dato);
//    flag = buscarMatriz(matriz, dato);
//
//
//
//    if(flag == 1)
//    {
//
//        printf("\nEl dato se encuentra dentro de la matriz");
//
//    }
//    else
//    {
//
//        printf("\nEl dato no se encuentra dentro de la matriz\n\n");
//
//    }

    int val = cargarArregloSt(arreglo, dim);
    mostrarArregloSt(arreglo,val);

    //cargarArregloSt(palabra, dim);
    printf("\ningrese palabra a buscar: ");
    fflush(stdin);
    gets(palabra);

    flag = encontrarPalabra(arreglo, val, palabra);

        if(flag == -1){

            printf("La palabra no fue encontrada");


        }else{

            printf("La palabra se encuentra en la fila %d", flag);

        }



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

int sumarMatriz(int matriz[filas][columnas])
{

    int i;
    int j;
    int suma = 0;
    int num = 1;

    for(i = 0; i < filas; i++)
    {

        for(j = 0; j < columnas; j++)
        {

            suma = suma + matriz[i][j];
        }

        num++;
    }
    return suma;
}

float promedioMatriz(int matriz[filas][columnas])
{

    int i;
    int j;
    float suma = 0;
    float promedio = 0;

    for(i = 0; i < filas; i++)
    {

        for(j = 0; j < columnas; j++)
        {

            suma = suma + matriz[i][j];

        }

    }

    promedio = suma / (filas * columnas);

    return promedio;
}

int buscarMatriz(int matriz[filas][columnas], int dato)
{

    int i,j;
    int flag = 0;

    for(i = 0; i < filas; i++)
    {

        for(j = 0; j < columnas; j++)
        {

            if(dato == matriz[i][j])
            {

                flag = 1;

            }
            else
            {

                flag = 0;

            }
        }
    }

    return flag;

}

int cargarArregloSt(char arreglo[filasC][columnasC], int dim){

    int i = 0;
    char letra = 's';
    char palabra[columnasC];


    while(i < filasC && letra =='s'){

        printf("\nIngresa una palabra: ");
        fflush(stdin);
        scanf("%s", &palabra);

        strcpy(arreglo[i], palabra);

        printf("\nIngresa 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &letra);
        i++;
    }
    return i;

}



void mostrarArregloSt(char arreglo[filasC][columnasC], int val){

    int i = 0;

    for(i = 0; i < val; i++){

        printf("%s ", arreglo[i]);

    }
}

int encontrarPalabra(char arreglo[filasC][columnasC], int validos, char palabra[]){

    int i = 0;
    int flag = 0;
    int pos;

    while(i < filasC && flag != 1){

        if(strcmp(arreglo[i],palabra) == 0){


             pos = i;
             flag = 1;

        }else{

            flag = -1;

        }

        i++;

    }
    if(flag == 1){
        flag = pos;
    }

    return flag;
}
