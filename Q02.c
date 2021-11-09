#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int func(long int *vetor, long int inicio, long int fim)
{
    int mid = floor((inicio + fim)/2);
    if (inicio == fim){
        if (vetor[inicio] == inicio + 1)
            return TRUE;
        else
            return FALSE;
    }
    if (vetor[mid] == mid+1)
        return TRUE;

    if (mid+1 < vetor[mid])
        return func(vetor, inicio, mid);
    else if (mid+1 > vetor[mid])
        return func(vetor, mid+1, fim);
}

int main()
{
    // Inicializa as variaveis
    long int qtdTestes;
    long int *tamanhos;
    signed long int **vetores;

    // Le as entradas
    setbuf(stdin, NULL);
    scanf("%ld", &qtdTestes);
    tamanhos = (long int*)malloc(qtdTestes * sizeof(long int));
    vetores = (signed long int**)malloc(qtdTestes * sizeof(signed long int*));
    for (long int i = 0; i < qtdTestes; i++){
        scanf("%ld", &tamanhos[i]);
        vetores[i] = (signed long int*)malloc(tamanhos[i] * sizeof(signed long int));
        for (long int n = 0; n < tamanhos[i]; n++){
            scanf("%ld", &vetores[i][n]);
        }
    }

    // Chama funcao recursiva para todos os casos
    for(long int i = 0; i < qtdTestes; i++){
        if(func(vetores[i], 0, tamanhos[i] - 1))
            printf("sim\n");
        else
            printf("nao\n");
    }

    // Liberando memoria alocada
    free(tamanhos);
    for (long int i = 0; i < qtdTestes; i++){
        free(vetores[i]);
    }
    free(vetores);

    return 0;
}
