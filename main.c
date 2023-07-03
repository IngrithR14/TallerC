#include <stdio.h>
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
                break;
            case 8:
                break;
            case 9:
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
int main() {
    menu();
    return 0;

}
