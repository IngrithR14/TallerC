#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void menu();

int pPunto();

int **matrizMagica();

int **multiplicacionM();
int getValue(char letra);
int validateRomanNumeral(const char* roman);
int romanNumerals(char* romano);
void infoRomanNumerals();
void primeNumbers(int num);
void infoPrimeNumbers();
void deleteGaps(char* texto);
void infoDeleteGaps();

int main() {
    menu();
    return 0;
}

void menu() {
    int num = 0;
    while (num == 0) {
        printf("Bienvenido al Menu Matematico por favor elija la opcion que desea\n");
        printf("1. Numeros Romanos\n");
        printf("2. Factores Primos\n");
        printf("3. Borrar Espacios\n");
        printf("4. Numeros Egolatras\n");
        printf("5. Numero Magico\n");
        printf("6. Fechas\n");
        printf("7. Producto Punto\n");
        printf("8. Multiplicacion de Matrices\n");
        printf("9. Matriz Magica\n");
        printf("0. Salir\n");
        int num1;
        scanf("%d", &num1);
        switch (num1) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:

                pPunto();
                break;
            case 8:
                multiplicacionM();
                break;
            case 9:
                matrizMagica();
                break;
            case 0:
                printf("Gracias por utilizar nuestro Menu Matematico lo esperamos de vuelta pronto");
                num = 1;
                break;
            default:
                printf("Lo sentimos la opcion ingresada es invalida");
                break;

        }
    }
}

int pPunto() {
    int num, num1;
    printf("Actualmente se encuentra en la opcion 7 Producto Punto\n");
    printf("Para esto debe ingresar dos arreglos a continuacion:\n");
    printf("Ingrese la cantidad de datos del arreglo\n");
    scanf("%d", &num);
    int v1[num];
    for (int i = 0; i < num; i++) {
        printf("Ingrese el dato n %d:  ", i + 1);
        scanf("%d", &num1);
        v1[i] = num1;
    }
    printf("Ingrese la cantidad de datos del arreglo\n");
    scanf("%d", &num);
    int v2[num];
    for (int i = 0; i < num; i++) {
        printf("Ingrese el dato n %d:  ", i + 1);
        scanf("%d", &num1);
        v2[i] = num1;
    }
    int tam1 = sizeof(v1) / sizeof(v1[0]);
    int tam2 = sizeof(v2) / sizeof(v2[0]);
    if (tam1 == tam2) {
        int sum = 0;
        for (int i = 0; i < tam1; i++) {
            sum = (v1[i] * v2[i]) + sum;
        }
        printf("El producto punto es: %d \n", sum);
        return sum;
    } else {
        printf("No es posible calcular el producto punto\n");
    }
    return (int) NULL;
}
int **multiplicacionM() {
    int f1, f2;
    int c1, c2;
    int x, s, r;
    srand(time(NULL));
    printf("A continuacion a ingresado a la funcion de multiplicacion de matrices\n");
    printf("Por favor ingrese el numero de filas de la primera matriz:\n");
    scanf("%d", &f1);
    printf("Por favor ingrese el numero de columnas de la primera matriz: \n");
    scanf("%d", &c1);
    int matriz[f1][c1];
    for (int i = 0; i < f1; i++) {
        for (int j = 0; j < c1; j++) {
            x = rand() % 25;
            matriz[i][j] = x;
        }
    }
    printf("Matriz 1:\n");
    for (int i = 0; i < f1; i++) {
        for (int j = 0; j < c1; j++) {
            printf(" %d |", matriz[i][j]);

        }
        printf("\n");
    }

    printf("Por favor ingrese el numero de filas de la segunda matriz:\n");
    scanf("%d", &f2);
    printf("Por favor ingrese el numero de columnas de la segunda matriz: \n");
    scanf("%d", &c2);
    int matriz2[f2][c2];
    for (int i = 0; i < f2; i++) {
        for (int j = 0; j < c2; j++) {
            s = rand() % 15;
            matriz2[i][j] = s;
        }
    }
    printf("Matriz 2:\n");
    for (int i = 0; i < f2; i++) {
        for (int j = 0; j < c2; j++) {
            printf(" %d |", matriz2[i][j]);
        }
        printf("\n");
    }

    if (c1 == f2) {
        int resultado[f1][c2];
        for (int i = 0; i < f1; i++) {
            for (int j = 0; j < c2; j++) {
                r = 0;
                for (int k = 0; k < c2; k++) {
                    r = r + matriz[i][k] * matriz2[k][j];

                }
                resultado[i][j] = r;
            }

        }

        printf("Multiplicacion de las matrices: \n");
        for (int i = 0; i < f1; i++) {
            for (int j = 0; j < c2; j++) {
                printf(" %d |", resultado[i][j]);
            }
            printf("\n");
        }
        return resultado;
    } else {
        printf("No es posible realizar esta operacion\n");
    }

    return NULL;
}

int **matrizMagica() {
    int c;
    int f;
    int x = 0;
    int num = 0;
    printf("A continuacion a ingresado a la funcion de matriz magica\n");
    while (num == 0) {
        printf("Por favor ingrese el numero de filas recuerde que debe ser impar:\n");
        scanf("%d", &c);
        if (c % 2 != 0) {
            printf("Por favor ingrese el numero de columnas recuerde que debe ser impar: \n");
            scanf("%d", &f);
            if (f % 2 != 0) {
                int matriz[c][f];
                for (int i = 0; i < c; i++) {
                    for (int j = 0; j < f; j++) {
                        matriz[i][j] = x + 1;
                        x += 1;
                    }
                }
                int fila = sizeof(matriz) / sizeof(matriz[0]);
                int columna = sizeof(matriz[0]) / sizeof(matriz[0][0]);
                printf("Matriz Magica: \n");
                for (int i = 0; i < fila; i++) {
                    for (int j = 0; j < columna; j++) {
                        printf(" %d |", matriz[i][j]);
                    }
                    printf("\n");
                }
                num = 1;
                return matriz;
            } else {
                printf("El numero no es impar intente de nuevo\n");
            }
        } else {
            printf("El numero no es impar intente de nuevo\n");
        }
    }
    return NULL;

}

