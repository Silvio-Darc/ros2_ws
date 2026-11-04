#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Crie uma função que percorra um vetor de inteiros utilizando exclusivamente aritmética de
ponteiros. É estritamente proibido utilizar índices ou a notação de acesso por colchetes 
(`[]`) para percorrer o vetor. A função deve encontrar o menor e o maior valor do vetor e
armazenar os resultados nas variáveis fornecidas pelos parâmetros de saída `menor` e 
`maior`, recebidos por ponteiro.*/

void encontraExtremos(int *vetor, int tamanho, int *menor, int *maior){
    if(tamanho <= 0){return;}

    *menor = *vetor;
    *maior = *vetor;
    for(int i = 0; i < tamanho; i ++){
        if(*(vetor + i) < *menor)    {*menor = *(vetor + i);}
        if(*(vetor + i) > *maior)    {*maior = *(vetor + i);}
    }
    return;
}

/*Escreva uma função recursiva que, dada uma string contendo `n` caracteres e um inteiro
`k`, imprima todas as sequências de comprimento `k` que podem ser formadas utilizando os
caracteres da string. A repetição de caracteres é permitida e a ordem dos caracteres importa. 
Portanto, cada uma das `k` posições da sequência pode receber qualquer caractere da string 
original. Considere `k >= 1`. Exemplo: Entrada: str = "abc", k = 2
Saída: aa, ab, ac, ba, bb, bc, ca, cb, cc */

void k_str_recursivo(char *str, char *buffer, int k, int posicao) {
    if (posicao == k) {
        buffer[k] = '\0';
        printf("%s\n", buffer);
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        buffer[posicao] = str[i];
        k_str_recursivo(str, buffer, k, posicao + 1);
    }
}

void k_str(char *str, int k) {
    char buffer[k + 1];
    k_str_recursivo(str, buffer, k, 0);
}

/*Escreva uma função estritamente recursiva que receba um número inteiro `n` 
(onde `n >=0`) e retorne o n-ésimo termo da sequência de Fibonacci, considerando 
F(0) = 0 e F(1) = 1. A implementação da função deve ser estritamente recursiva: 
não utilize `for`, `while`, `do-while` ou outra forma de iteração para calcular o resultado.*/

int fibonacci(int n, int f0, int f1){
    if(n <= 0) {return f0;}
    
    n--;

    int aux = f0;
    f0 = f1;
    f1 = f1 + aux;

    fibonacci(n, f0, f1);
}

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);}

int main(){
    //int menor;
    //int maior;
    //int tamanho = 9;
    //int vetor[] = {9,2,11,8,67,23,72,99,10};
    //encontraExtremos(vetor, tamanho, &menor, &maior);
    //printf("Maior: %d   Menor: %d\n",maior, menor);

    //char string[] = "acbdefgh";
    //int k = 3;
    //k_str(string, k);

    int numero = 10;
    int f0 = 0;
    int f1 = 1;
    printf("%d \n",fibonacci(numero,f0,f1));
    printf("%d \n",fib(numero));

    return 0;
}
