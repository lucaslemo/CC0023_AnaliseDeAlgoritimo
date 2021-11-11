#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int subMid(signed int *vetor, int mid, int inicio, int fim)
{
    int soma = vetor[mid];
    int subConquista = 0;
    for (int i = mid+1; i <= fim; i++){
        soma += vetor[i];
        if (soma % 2 == 0)
            subConquista++;
    }
    soma = vetor[mid] + vetor[mid+1];
    for (int i = mid-1; i <= inicio; i--){
        soma += vetor[i];
        if (soma % 2 ==0)
            subConquista++;
    }

    return subConquista;
}

int func(signed int *vetor, int inicio, int fim)
{
    if (inicio == fim){
        if (vetor[inicio] % 2 == 0)
            return 1;
        else
            return 0;
    }

    int soma = 0, conquista = 0;
    for (int i = inicio; i <= fim; i++){
        soma += vetor[i];
    }
    if (soma % 2 == 0)
        conquista++;

    int mid = (int)floor((fim+inicio)/2);
    int esq = func(vetor, inicio, mid);
    int dir = func(vetor, mid+1, fim);
    int meio = subMid(vetor, mid, inicio, fim);

    conquista += dir + esq + meio;

    return conquista;
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
        printf("%d\n", func(vetores[i], 0, tamanhos[i] - 1));
    }

    // Liberando memoria alocada
    free(tamanhos);
    for (int i = 0; i < qtdTestes; i++){
        free(vetores[i]);
    }
    free(vetores);

    return 0;
}
