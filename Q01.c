#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int func(signed int *vetor, int inicio, int fim)
{
    int mid = floor((fim + inicio)/2);
    if (inicio == fim)
        return inicio;
    if (vetor[inicio] >= vetor[inicio+1])
        return inicio;
    if (vetor[fim] >= vetor[fim-1])
        return fim;
    if (vetor[mid-1] <= vetor[mid] && vetor[mid] >= vetor[mid+1])
        return mid;

    if (vetor[mid-1] > vetor[mid])
        return func(vetor, inicio, mid);
    else if (vetor[mid] < vetor[mid+1])
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
    for (int i = 0; i < qtdTestes; i++){
        scanf("%d", &tamanhos[i]);
        vetores[i] = (signed int*)malloc(tamanhos[i] * sizeof(signed int));
        for (long int n = 0; n < tamanhos[i]; n++){
            scanf("%d", &vetores[i][n]);
        }
    }

    // Chama funcao recursiva para todos os casos
    for (int i = 0; i < qtdTestes; i++){
        printf("%d\n", func(vetores[i], 0, tamanhos[i] - 1) + 1);
    }

    // Liberando memoria alocada
    free(tamanhos);
    for (int i = 0; i < qtdTestes; i++){
        free(vetores[i]);
    }
    free(vetores);

    return 0;
}
