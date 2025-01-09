#include <stdio.h>

int main() {
    long long int vector[10], i, j, k;
    long long int swap_var;
    int *invalid_pointer;
    int allow_overflow;

    printf("Scegli la modalità:\n1. Sicura\n2. Overflow (Segmentation Fault)\n");
    scanf("%d", &allow_overflow);

    if (allow_overflow == 2) {
        printf("Hai scelto la modalità overflow. Inserisci più di 10 interi per causare un segmentation fault:\n");
        for (i = 0; i < 100; i++) {
            int c = i + 1;
            printf("[%d]:", c);
            scanf("%lld", &vector[i]);
        }

        printf("\nAccedendo alla memoria invalida...\n");
        for (i = 10; i < 100; i++) {
            printf("Memoria invalida [%d]: %lld\n", i, vector[i]);
        }

        printf("\nForzando il segmentation fault...\n");
        invalid_pointer = (int *)(vector + 100000);
        printf("Accesso alla memoria invalida in %p: %d\n", invalid_pointer, *invalid_pointer);
    } else {
        printf("Inserisci 10 interi:\n");
        for (i = 0; i < 10; i++) {
            int c = i + 1;
            printf("[%d]:", c);
            scanf("%lld", &vector[i]);
        }

        printf("Il vettore inserito è:\n");
        for (i = 0; i < 10; i++) {
            int t = i + 1;
            printf("[%d]: %lld", t, vector[i]);
            printf("\n");
        }

        for (j = 0; j < 10 - 1; j++) {
            for (k = 0; k < 10 - j - 1; k++) {
                if (vector[k] > vector[k + 1]) {
                    swap_var = vector[k];
                    vector[k] = vector[k + 1];
                    vector[k + 1] = swap_var;
                }
            }
        }

        printf("Il vettore ordinato è:\n");
        for (j = 0; j < 10; j++) {
            int g = j + 1;
            printf("[%d]:", g);
            printf("%lld\n", vector[j]);
        }
    }

    return 0;
}

