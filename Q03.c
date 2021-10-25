#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int func(int *vetor, int inicio, int fim)
{
}

int main()
{
    // Inicializa as variaveis
    int qtdTestes;
    int *dimensoes;
    char **bits;

    // Le as entradas
    setbuf(stdin, NULL);
    scanf("%d", &qtdTestes);
    dimensoes = (int*)malloc(qtdTestes * sizeof(int));
    bits = (char**)malloc(qtdTestes * sizeof(char*));
    for (int i = 0; i < qtdTestes; i++){
        scanf("%d", &dimensoes[i]);
        bits[i] = (char*)malloc(((int)pow(4, dimensoes[i]) + 1) * sizeof(char));
        scanf("%s", bits[i]);
    }

    // Chama funcao recursiva para todos os casos
    for(int i = 0; i < qtdTestes; i++){
        int x = func(bits[i], 0, dimensoes[i] - 1);
    }

    // Liberando memoria alocada
    free(dimensoes);
    for (int i = 0; i < qtdTestes; i++){
        free(bits[i]);
    }
    free(bits);

    return 0;
}
