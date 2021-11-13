#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int subMid(signed int *vetor, int mid, int inicio, int fim)
{
    int soma = vetor[mid], somaTotal = 0;
    int subPares = 0, subImpares = 0, subConquista = 0;
    for (int i = mid-1; i >= inicio; i--){
        soma += vetor[i];
        if (soma % 2 == 0)
            subPares++;
        else
            subImpares++;
    }
    subConquista = subPares;
    somaTotal = soma;
    for (int i = mid+1; i <= fim; i++){
        somaTotal += vetor[i];
        if (vetor[i] % 2 == 0)
            subConquista += subPares;
        else{
            int aux = subPares;
            subPares = subImpares;
            subImpares = aux;
            subConquista += subPares;
        }
    }
    if (somaTotal % 2 == 0){
        if (subPares == 0 && subImpares == 0)
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

    int mid = (int)floor((fim+inicio)/2);
    int esq = func(vetor, inicio, mid);
    int dir = func(vetor, mid+1, fim);
    int meio = subMid(vetor, mid, inicio, fim);

    return dir + esq + meio;
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
