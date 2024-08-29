/**
 
 * created on Aug, 24th 2024
 * Author: Gabriel Albuquerque - 3ºB
 * Questão 2 - 28/08/2024 22:59
 
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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
    if (base == 16)
    {
        for(j; j >= 0; j--){
            revertArray[k] = newNumber[j];
            if (revertArray[k] == 'A' || revertArray[k] == 'B' ||revertArray[k] == 'C' ||revertArray[k] == 'D' ||revertArray[k] == 'E' ||revertArray[k] == 'F')
            {
                printf("%c", revertArray[k]);
            }
            else{

            printf("%d", revertArray[k]);
            }
            
            
            k++;
        }
    }
    else{
        for(j; j >= 0; j--){
            revertArray[k] = newNumber[j];
            printf("%d", revertArray[k]);
            k++;
        }
        printf("\n\n");
    }
    
    
    return revertArray;
}


void printBinary(int value, int n) {

    for (int i = n; i >= 0; i--) {
        printf("%d", (value >> i) & 1);

    }

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

unsigned int toComplementoA2(int num) {
    printf("colocando numero para 16 bits...\n");
    sleep(1);

    return (unsigned int)(num & 0xFFFF);
}

void convertToFloatPoint(double number, int floatPoints){
        int somaExpoente;
        int bitsParaInterira;
        double bitsParaFracao;
        char sinal = ( number > 0) ? '0' : '1';
        printf("separando bit de sinal: [%d]\n\n", sinal);
        sleep(1);
        int parteInteira = (int) number;
        printf("separando parte inteira: [%d]\n\n", parteInteira);
        sleep(1);
        double parteFracao = number - parteInteira;
        printf("separando parte fracionaria: [%lf]\n\n", parteFracao);
        sleep(1);
    if (floatPoints == 32){
        somaExpoente = 127;
        bitsParaInterira = 8;
        bitsParaFracao = 23;
    }
    else if (floatPoints == 64){
        somaExpoente = 1023;
        bitsParaInterira = 11;
        bitsParaFracao = 52;
    }
    int bitNumber;
    printf("achando binario da parte inteira... \n\n");
    sleep(1);
    int * integrerArray =  conversor(parteInteira, 2);
    int tam = sizeof(integrerArray) / sizeof(integrerArray[0]);
    int expo = 0;

    for (int j = 0; j < tam; j++){
        bitNumber = bitNumber * 10 + integrerArray[j];
    }
    int temp = bitNumber;
    for (int i = bitsParaInterira; i > 0; i--){
        if (integrerArray[i] == 1 && bitNumber < 9){
            break;
        }
        bitNumber/=10;
        expo++;
    }

    printf("expoente da notação cientifica = %d\n\n", expo);
    sleep(1);
    printf("%d + %d = %d\n\n", expo, somaExpoente, expo+somaExpoente);
    sleep(1);
    expo += somaExpoente;
    int * fracArray = calloc(bitsParaFracao, sizeof(int));
    printf("achando parte fracionada = ");
    sleep(1);
    
    for (int i = 0; i < bitsParaFracao; i++) {
        parteFracao *= 2;
        
        int bit = (int)parteFracao;
        
        fracArray[i] = bit;
        printf("%d", fracArray[i]);
        parteFracao -= bit;
    }
    printf("\n\n");
    printf("achando parte inteira final...\n\n");
    sleep(1);
    
    int * finalArray = conversor(expo, 2);

   printf("%c", sinal);

    for (int e = 0; e < bitsParaInterira; e++)
    {
        printf("%d", finalArray[e]);
    }
    printf(".");
    printf("%d", temp);
    for (int e = 0; e < bitsParaFracao ; e++)
    {
        printf("%d", fracArray[e]);
    }
    
    free(finalArray);
    free(fracArray);
    free(integrerArray);
    

}

int main(){
    printf("=========================================================================================================================\n\n\n");
    printf("Ola, bem-vindo(a) a calculadora conversora didatica\n\n");
    printf("Por favor, insira um numero, na base 10, que deseja ver convertido para as outras bases disponiveis:  ");
    double number;
    int choice;
    int a2 = 0;
    int flutuante = 0;
    int bitsFlutuante;
    scanf("%lf", &number);

    printf("\nPara qual base voce deseja converter\n [1] para binario\n [2] para octal\n [3] para hexadecimal\n [4] para BCD\n [5] para complemento A2 \n [6] para float\n [7] para double\n");

    scanf("%d", &choice);
    int base, bcd = 0;
    switch(choice){

        case 1:
            base = 2;
            printf("iniciando conversao para binario...\n");
            sleep(1);
            break;
        case 2:
            base = 8;
            printf("iniciando conversao para octal...\n");

            break;
        case 3:
            base = 16;
            printf("iniciando conversao para hexadecimal...\n");

            break;
        case 4:
            base = 2;
            bcd = 1;
            printf("iniciando conversao para BCD...\n");

            break;
        case 5:
            a2 = 1;
            printf("iniciando conversao para complemento a2...\n");
            sleep(1);
            break;
        case 6:
            flutuante = 1;
            bitsFlutuante = 32;
            printf("iniciando conversao para float...\n");
            break;
        case 7:
            flutuante = 1;
            bitsFlutuante = 64;
            printf("iniciando conversao para double...\n");
            break;



    }   
    if (bcd == 0  && a2 == 0 && flutuante == 0)
    {
        int *array = conversor(number, base); 
        free(array);
    }
    

    else if (bcd == 1){

        int num  = (int)number;
        char *bcdArray = toBCD(num);
        int size = 0;
        printf("separando digitos...\n\n");
        sleep(1);
        while (num > 0) {
            num /= 10;
            size++;
        }

        printf("Achando binario dos digitos separadamente...\n\n");
        sleep(1);

        for (int i = 1; i < size + 1; i++) {
            printBinary(bcdArray[i], 3);
            printf(" ");

        }
            printf("\n");
        free(bcdArray);
    }
        
    else if (a2 == 1){

        unsigned int result = toComplementoA2(number);
        printf("invertendo os digitos apos o primeiro 1...\n");
        sleep(1);
        printBinary(result, 15);
    }
    else if (flutuante == 1){
        convertToFloatPoint(number, bitsFlutuante);
    }


    return 0;
}
