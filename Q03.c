#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


char *func(char *bits, int dimensao)
{
    if (dimensao == 0 || dimensao == 1){
        char *mapaBits = (char*)malloc(6 * sizeof(char));
        if (strcmp(bits, "1111") == 0 || strcmp(bits, "1") == 0)
            strcpy(mapaBits, "1");
        else if (strcmp(bits, "0000") == 0 || strcmp(bits, "0") == 0)
            strcpy(mapaBits, "0");
        else{
            strcpy(mapaBits, "D");
            strcat(mapaBits, bits);
        }
        return mapaBits;
    }

    char *d1 = (char*)malloc((int)pow(4, dimensao-1)+1 * sizeof(char));
    char *d2 = (char*)malloc((int)pow(4, dimensao-1)+1 * sizeof(char));
    char *d3 = (char*)malloc((int)pow(4, dimensao-1)+1 * sizeof(char));
    char *d4 = (char*)malloc((int)pow(4, dimensao-1)+1 * sizeof(char));
    d1[0] = '\0';
    d2[0] = '\0';
    d3[0] = '\0';
    d4[0] = '\0';
    int count = 0, aux = 1, indices[4] = {0, 0, 0, 0};

    for (int i = 0; i < (int)pow(4, dimensao); i++){
        if (i < pow(4, dimensao)/2){
            if (count >= (int)pow(2, dimensao-1)){
                aux++;
                count = 0;
            }
            if (aux % 2 != 0){
                d1[indices[0]] = bits[i];
                d1[indices[0] + 1] = '\0';
                indices[0]++;
            }
            else{
                d2[indices[1]] = bits[i];
                d2[indices[1] + 1] = '\0';
                indices[1]++;
            }
        }
        else{
            if (count >= (int)pow(2, dimensao-1)){
                aux++;
                count = 0;
            }
            if (aux % 2 != 0){
                d3[indices[2]] = bits[i];
                d3[indices[2] + 1] = '\0';
                indices[2]++;
            }
            else{
                d4[indices[3]] = bits[i];
                d4[indices[3] + 1] = '\0';
                indices[3]++;
            }
        }
        count ++;
    }

    char *conquista = (char*)malloc(((int)pow(4, dimensao) + 6*dimensao) * sizeof(char));
    char *r1 = (char*)malloc(((int)pow(4, dimensao - 1) + 2) * sizeof(char));
    char *r2 = (char*)malloc(((int)pow(4, dimensao - 1) + 2) * sizeof(char));
    char *r3 = (char*)malloc(((int)pow(4, dimensao - 1) + 2) * sizeof(char));
    char *r4 = (char*)malloc(((int)pow(4, dimensao - 1) + 2) * sizeof(char));
    r1[0] = '\0';
    r2[0] = '\0';
    r3[0] = '\0';
    r4[0] = '\0';

    strcpy(r1, func(d1, dimensao - 1));
    strcpy(r2, func(d2, dimensao - 1));
    strcpy(r3, func(d3, dimensao - 1));
    strcpy(r4, func(d4, dimensao - 1));

    if (r1[0] == r2[0] && r3[0] == r4[0] && r1[0] == r4[0] && r1[0] != 'D'){
        conquista[0] = '\0';
        strcpy(conquista, r1);
    }
    else {
        int count2 = 1, aux2 = 0;;
        conquista[0] = 'D';
        while (r1[aux2] != '\0'){
            conquista[count2] = r1[aux2];
            aux2++;
            count2++;
        }
        aux2 = 0;
        while (r2[aux2] != '\0'){
            conquista[count2] = r2[aux2];
            aux2++;
            count2++;
        }
        aux2 = 0;
        while (r3[aux2] != '\0'){
            conquista[count2] = r3[aux2];
            aux2++;
            count2++;
        }
        aux2 = 0;
        while (r4[aux2] != '\0'){
            conquista[count2] = r4[aux2];
            aux2++;
            count2++;
        }
        conquista[count2] = '\0';
        /*strcat(conquista, r1);
        strcat(conquista, r2);
        strcat(conquista, r3);
        strcat(conquista, r4);*/
    }

    free(d1);
    free(d2);
    free(d3);
    free(d4);
    free(r1);
    free(r2);
    free(r3);
    free(r4);

    return conquista;
}

int main()
{
    // Inicializa as variaveis
    int qtdTestes;
    int *dimensoes;
    char **bits;
    char *conquista;

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
        conquista = func(bits[i], dimensoes[i]);
        printf("%s\n", conquista);
        free(conquista);
    }

    // Liberando memoria alocada
    free(dimensoes);
    for (int i = 0; i < qtdTestes; i++){
        free(bits[i]);
    }
    free(bits);

    return 0;
}
