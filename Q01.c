#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int func(int *vetor, int inicio, int fim)
{
    if (inicio == fim)
        return vetor[inicio];
    int mid = floor((inicio + fim) / 2);
    int esq = func(vetor, inicio, mid);
    int dir = func(vetor, mid + 1, fim);
    if (esq >= dir)
        return esq;
    else
        return dir;
}

int main()
{
    // Inicializa as variaveis
    int qtdTestes;
    int *tamanhos;
    int **vetores;

    // Le as entradas
    setbuf(stdin, NULL);
    scanf("%d", &qtdTestes);
    tamanhos = (int*)malloc(qtdTestes * sizeof(int));
    vetores = (int**)malloc(qtdTestes * sizeof(int*));
    for (int i = 0; i < qtdTestes; i++){
        scanf("%d", &tamanhos[i]);
        vetores[i] = (int*)malloc(tamanhos[i] * sizeof(int));
        for (int n = 0; n < tamanhos[i]; n++){
            scanf("%d", &vetores[i][n]);
        }
    }

    // Chama funcao recursiva para todos os casos
    for (int i = 0; i < qtdTestes; i++){
        printf("%d\n", func(vetores[i], 0, tamanhos[i] - 1));
    }

    return 0;
}
