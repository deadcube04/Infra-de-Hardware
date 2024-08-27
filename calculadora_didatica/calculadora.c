/**
 
 * created on Aug, 24th 2024
 * Author: Gabriel Albuquerque - 3ºB
 * questões didaticas - 27/08/2024 11:07
 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int * conversor(int number, int base){
    // int size = (int) log10(number) + 1;
    int newNumber[100] = {0};
    int j = 0;
    int pNum = number;
    char hexaArray[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    printf("dividindo %d por %d\n\n\n", number, base);
    sleep(1);
    for(number; number > 0; number/=base){
        if (number%base >= 10){
            newNumber[j] = hexaArray[(number%base)-10];
            printf("modulo de %d por %d = %c\n\n", number, base , hexaArray[(number%base)-10]);

        }
        else{
            newNumber[j] = number%base;
            printf("modulo de %d por %d = %d\n\n", number, base , number%base);

        }
        
        sleep(1);
       j++;
    }

    j-=1;
    int k = 0;
    int *revertArray = malloc(j * sizeof(int));
    printf("invertendo restos da divisao...\n\n");
    sleep(1);
    printf(" %d na base %d = ", pNum, base);
    
    for(j; j >= 0; j--){
        revertArray[k] = newNumber[j];
        printf("%c", revertArray[k]);
        k++;
    }
    
    
    return revertArray;
}


char * toBCD(int number){

    char *temp = (char*) malloc(sizeof(char));
    int i = 0;
    while (number > 0) {
        int rest = number % 10;
        temp[i] = rest;
        number /= 10;
        i++;
    }
    char *temp2 = (char*) malloc(i * sizeof(char));

    int k = i;
    for (int j = 0; j <= i; j++) {
        temp2[k] = temp[j];
        k--;
    }
    return temp2;
}

int main(){
    printf("=========================================================================================================================\n\n\n");
    printf("Ola, bem-vindo(a) a calculadora conversora didatica\n\n");
    printf("Por favor, insira um numero, na base 10, que deseja ver convertido para as outras bases disponiveis:  ");
    int number;
    int choice;
    int a2 = 0;

    scanf("%d", &number);

    printf("\nPara qual base voce deseja converter\n [1] para decimal\n [2] para octal\n [3] para hexadecimal\n [4] para BCD\n\n\n");

    scanf("%d", &choice);
    int base, bcd = 0;
    switch(choice){

        case 1:
            base = 2;
            printf("inicuiando conversao para binario...\n");
            sleep(1);
            break;
        case 2:
            base = 8;
            printf("inicuiando conversao para octal...\n");

            break;
        case 3:
            base = 16;
            printf("inicuiando conversao para hexadecimal...\n");

            break;
        case 4:
            base = 2;
            bcd = 1;
            printf("inicuiando conversao para BCD...\n");

            break;


    }   
    if (bcd == 0  && a2 == 0)
    {
        int *array = conversor(number, base); 
        free(array);
    }
    

    else if (bcd == 1){

        
        char *bcdArray = toBCD(number);
        int size = 0;
        printf("separando digitos...\n\n");
        sleep(1);
        while (number > 0) {
            number /= 10;
            size++;
        }

        printf("Achando binario dos digitos separadamente...\n\n");
        sleep(1);

        
        for (int i = 1; i < size + 1; i++) {
            printBinary(bcdArray[i], 3);
            printf(" ");
            sleep(1);

        }
            printf("\n");
        free(bcdArray);
    }


    return 0;
}
