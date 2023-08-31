#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Ponto;

void regressao_linear(Ponto pontos[], int tamanho) {
    double soma_x = 0, soma_y = 0;
    
    for (int i = 0; i < tamanho; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }

    double media_x = soma_x / tamanho;
    double media_y = soma_y / tamanho;

    double soma_xy = 0, soma_x2 = 0;

    for (int i = 0; i < tamanho; i++) {
        soma_xy += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        soma_x2 += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }

    double a = soma_xy / soma_x2;
    double b = media_y - a * media_x;

    printf("Equação da regressão linear: y = %.4fx + %.4f\n", a, b);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <arquivo.csv>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int tamanho = 0;
    while (!feof(arquivo)) {
        char linha[100];
        if (fgets(linha, sizeof(linha), arquivo)) {
            tamanho++;
        }
    }
    fseek(arquivo, 0, SEEK_SET);  

    Ponto *pontos = (Ponto *)malloc(tamanho * sizeof(Ponto));

    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%lf,%lf", &pontos[i].x, &pontos[i].y);
    }

    fclose(arquivo);

    regressao_linear(pontos, tamanho);

    free(pontos);

    return 0;
}
