#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long int func(long int *vetor, long int inicio, long int fim)
{
    long int mid = floor((fim + inicio)/2);
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
    long int qtdTestes;
    long int *tamanhos;
    signed long int **vetores;

    // Le as entradas
    setbuf(stdin, NULL);
    scanf("%ld", &qtdTestes);
    tamanhos = (long int*)malloc(qtdTestes * sizeof(long int));
    vetores = (signed long int**)malloc(qtdTestes * sizeof(signed long int*));
    for (int i = 0; i < qtdTestes; i++){
        scanf("%ld", &tamanhos[i]);
        vetores[i] = (signed long int*)malloc(tamanhos[i] * sizeof(signed long int));
        for (long int n = 0; n < tamanhos[i]; n++){
            scanf("%ld", &vetores[i][n]);
        }
    }

    // Chama funcao recursiva para todos os casos
    for (long int i = 0; i < qtdTestes; i++){
        printf("%ld\n", func(vetores[i], 0, tamanhos[i] - 1) + 1);
    }

    // Liberando memoria alocada
    free(tamanhos);
    for (long int i = 0; i < qtdTestes; i++){
        free(vetores[i]);
    }
    free(vetores);

    return 0;
}
