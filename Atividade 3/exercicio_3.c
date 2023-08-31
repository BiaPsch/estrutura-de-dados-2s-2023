#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int busca_string(const char *arr[], int tamanho, const char *busca) {
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(arr[i], busca) == 0) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int tamanho;

    printf("Digite o tamanho do array de strings: ");
    scanf("%d", &tamanho);
    
    while (getchar() != '\n');

    const char *array[tamanho];
    
    for (int i = 0; i < tamanho; i++) {
        char buffer[100]; 
        printf("Digite a string %d: ", i + 1);
        fgets(buffer, sizeof(buffer), stdin);
        
        buffer[strcspn(buffer, "\n")] = '\0';
        
        array[i] = strdup(buffer);
    }

    char busca[100];
    printf("Digite a string de busca: ");
    fgets(busca, sizeof(busca), stdin);
    busca[strcspn(busca, "\n")] = '\0'; 

    int resultado = busca_string(array, tamanho, busca);

    printf("Resultado: %d\n", resultado);

    for (int i = 0; i < tamanho; i++) {
        free((char *)array[i]);
    }

    return 0;
}
