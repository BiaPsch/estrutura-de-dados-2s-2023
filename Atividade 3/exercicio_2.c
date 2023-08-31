#include <stdio.h>

void menor_maior_elemento(int arr[], int tamanho, int *menor, int *maior) {
    *menor = arr[0];
    *maior = arr[0];
    
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] < *menor) {
            *menor = arr[i];
        }
        if (arr[i] > *maior) {
            *maior = arr[i];
        }
    }
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int menor, maior;
    menor_maior_elemento(array, tamanho, &menor, &maior);

    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);

    return 0;
}
