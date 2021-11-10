#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int func(signed int *vetor, int inicio, int fim)
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
    int qtdTestes;
    int *tamanhos;
    signed int **vetores;

    // Le as entradas
    setbuf(stdin, NULL);
    scanf("%d", &qtdTestes);
    tamanhos = (int*)malloc(qtdTestes * sizeof(int));
    vetores = (signed int**)malloc(qtdTestes * sizeof(signed int*));
    for (long int i = 0; i < qtdTestes; i++){
        scanf("%d", &tamanhos[i]);
        vetores[i] = (signed int*)malloc(tamanhos[i] * sizeof(signed int));
        for (int n = 0; n < tamanhos[i]; n++){
            scanf("%d", &vetores[i][n]);
        }
    }

    // Chama funcao recursiva para todos os casos
    for(int i = 0; i < qtdTestes; i++){
        if(func(vetores[i], 0, tamanhos[i] - 1))
            printf("sim\n");
        else
            printf("nao\n");
    }

    // Liberando memoria alocada
    free(tamanhos);
    for (int i = 0; i < qtdTestes; i++){
        free(vetores[i]);
    }
    free(vetores);

    return 0;
}
