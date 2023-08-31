#include <stdio.h>

void multiplica_array(const int arr1[], const int arr2[], int resultado[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        resultado[i] = arr1[i] * arr2[i];
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &tamanho);

    int array1[tamanho];
    int array2[tamanho];
    int resultado[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor do elemento %d do primeiro array: ", i + 1);
        scanf("%d", &array1[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor do elemento %d do segundo array: ", i + 1);
        scanf("%d", &array2[i]);
    }

    multiplica_array(array1, array2, resultado, tamanho);

    printf("Resultado da multiplicação: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", resultado[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
