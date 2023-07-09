#include <stdio.h>
#include <string.h>
#include <ctype.h>

void menu();

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
                infoRomanNumerals();
                break;
            case 2:
                infoPrimeNumbers();
                break;
            case 3:
                infoDeleteGaps();
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



int getValue(char letra) {
    switch (letra) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:

            return 0;
    }
}
int validateRomanNumeral(const char* roman) {
    int longitud = strlen(roman);

    //validacion: no puede tener mas de 3 letras seguidas iguales
    for (int i = 0; i < longitud - 2; i++) {
        if (roman[i] == roman[i + 1] && roman[i] == roman[i + 2]) {
            return 0; // No es un  numero romano
        }
    }

    //validacion: no puede tener mas de una V, L o D seguidas
    for (int i = 0; i < longitud - 1; i++) {
        if ((roman[i] == 'V' || roman[i] == 'L' || roman[i] == 'D') &&
            (roman[i + 1] == 'V' || roman[i + 1] == 'L' || roman[i + 1] == 'D')) {
            return 0; //  No es un  numero romano
        }
    }
    //validacion: no puede tener un grupo de letras repetidas
    for (int i = 0; i < longitud - 4; i++) {
        int j = i + 2;
        while (j < longitud - 1) {
            if (roman[i] == roman[j] && roman[i + 1] == roman[j + 1] &&
                roman[i + 2] == roman[j + 2] && roman[i + 3] == roman[j + 3]) {
                return 0; // No cumple la regla
            }
            j += 2;
        }
    }



    return 1; // Si es un numero romano
}
int romanNumerals(char* romano) {
    int decimal = 0;

    for (int i = 0; i < strlen(romano); i++) {

        if(getValue(romano[i])==0){
            return 0;
        }

        int currentValue = getValue(romano[i]);
        int nextValue = getValue(romano[i + 1]);

        if (nextValue > currentValue) {
            decimal += nextValue - currentValue;
            i++;
        } else {
            decimal += currentValue;
        }
    }

    return decimal;
}

void infoRomanNumerals(){
    //  HACER VALIDACIONES ANTES DE EMPEZAR
    int again=1;

    while (again==1){

        char roman[100] ;
        printf("Ingrese un número romano: \n");
        scanf("%s", roman);
        int valido= validateRomanNumeral(roman);
        if(valido){
            for (int i = 0; i < strlen(roman); i++) {
                roman[i] = toupper(roman[i]);
            }

            int decimal = romanNumerals(roman);
            if(decimal==0){
                printf("Entrada invalida\n");
            }else {
                printf("El número romano %s es equivalente a %d en decimal.\n", roman, decimal);
            }
        } else{
            printf("Entrada invalida\n");
        }

        printf("Quiere intentar con otro número?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);
    }
}

void primeNumbers(int num){
    int factor = 2;
    int exp = 0;

    while (num > 1) {
        if (num % factor == 0) {
            exp++;
            num = num / factor;
        } else {
            if (exp > 0) {
                printf("%d^%d ,", factor, exp);
                exp = 0;
            }
            factor++;
        }
    }

    if (exp > 0) {
        printf("%d^%d ,", factor, exp);
    }
}

void infoPrimeNumbers(){
    int again=1;
    while (again==1){
        int num;

        printf("Ingrese un número: ");
        scanf("%d", &num);

        printf("Los factores primos de %d en descomposicion: ", num);
        primeNumbers(num);
        printf("\n");
        printf("Quiere intentar con otro número?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);
    }
}

void deleteGaps(char* texto){
    int start = 0;
    int end = strlen(texto) - 1;

    while (isspace(texto[start])) {
        start++;
    }

    while (end >= start && isspace(texto[end])) {
        end--;
    }
    int i;
    for (i = start; i <= end; i++) {
        texto[i - start] = texto[i];
    }

    texto[i - start] = '\0';

    //////////////////////////////////////////////////////////////
    int longitud = strlen(texto);
    int indexCleaned = 0;
    int isSpace = 0;

    for (int i = 0; i < longitud; i++) {
        if (isspace(texto[i])) {
            if (!isSpace) {
                texto[indexCleaned++] = ' ';
                isSpace = 1;
            }
        } else {
            texto[indexCleaned++] = texto[i];
            isSpace = 0;
        }
    }

    texto[indexCleaned] = '\0';

}

void infoDeleteGaps(){
    int again=1;

    while (again==1){
        char text[100] ;
        printf("Ingrese un texto: \n");
        //scanf("%s", text);
        scanf("%[^\n]", text);

        deleteGaps(text);

        printf("El texto sin espacios extra es %s.\n",text );


        printf("\n");
        printf("Quiere intentar con otro texto?\n"
               "1. Si\n"
               "2. No\n");

        scanf("%d",&again);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }

    }
}