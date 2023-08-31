#include <stdio.h>

int conta_int_array(const int arr[], int tamanho, int busca) {
    int contador = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == busca) {
            contador++;
        }
    }
    
    return contador;
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

    int numeroBusca;
    printf("Digite o número de busca: ");
    scanf("%d", &numeroBusca);

    int resultado = conta_int_array(array, tamanho, numeroBusca);
    printf("Quantidade de vezes que o número aparece: %d\n", resultado);

    return 0;
}
