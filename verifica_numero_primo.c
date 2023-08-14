#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (is_prime(num)) {
        printf("%d --> 1\n", num);
    } else {
        printf("%d --> 0\n", num);
    }
    
    return 0;
}