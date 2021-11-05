#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *func(int *bits, int dimensao)
{
    if (dimensao == 1){
        char *mapaBits = (char*)malloc(6 * sizeof(char));
        if (strcmp(bits, "1111") == 0)
            strcpy(mapaBits, "1");
        else if (strcmp(bits, "0000") == 0)
            strcpy(mapaBits, "0");
        else{
            strcpy(mapaBits, "D");
            strcat(mapaBits, bits);
        }
        return mapaBits;
    }
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
        int x = func(bits[i], dimensoes[i]);
    }

    // Liberando memoria alocada
    free(dimensoes);
    for (int i = 0; i < qtdTestes; i++){
        free(bits[i]);
    }
    free(bits);

    return 0;
}
