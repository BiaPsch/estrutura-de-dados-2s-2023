#include <stdio.h>

int soma_array(int arr[], int tamanho) {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += arr[i];
    }
    return total;
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

    int resultado = soma_array(array, tamanho);
    printf("Resultado: %d\n", resultado);

    return 0;
}
