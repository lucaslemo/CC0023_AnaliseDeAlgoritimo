#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//return vetor[inicio];
int func(int *vetor, int inicio, int fim)
{
    if (inicio == fim){
        printf("%d\n", vetor[inicio]);
        return 0;
    }
    int mid = floor(fim / 2);
    int esq = func(vetor, inicio, mid);
    int dir = func(vetor, mid+1, fim);
    //printf("Inicio: %d\tFim: %d\tMid: %d\n", inicio, fim, mid);
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

    // Chama funcao recursiva
    for (int i = 0; i < qtdTestes; i++){
        func(vetores[i], 0, tamanhos[i] - 1);
        //printf("%d\n", func(vetores[i], 0, tamanhos[i] - 1));
    }

    return 0;
}
