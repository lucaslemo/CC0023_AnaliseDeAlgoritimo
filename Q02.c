#include <stdio.h>
#include <stdlib.h>


int func(int *vetor, int tamanho)
{
    for (int i=0;i<tamanho; i++){
        if(vetor[i] == i+1){
            return 1;
        }
    }
    return 0;
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

    for(int i = 0; i<qtdTestes; i++){
        int x = func(vetores[i], tamanhos[i]);
        if (x)
            printf("sim\n");
        else
            printf("nao\n");
    }
    return 0;
}
