#include <stdio.h>
#include <string.h>

#define MAX_LINGUAS 20
#define MAX_K 100

int main(void) {
    int num_testes;
    scanf("%d", &num_testes);

    while (num_testes--) {
        int K;
        scanf("%d", &K);

        char linguas[MAX_K][MAX_LINGUAS + 1];
        int contagem_idioma[26] = {0};

        for (int i = 0; i < K; i++) {
            scanf("%s", linguas[i]);
            contagem_idioma[linguas[i][0] - 'a']++;
        }

        int todos_mesma_lingua = 1;
        for (int i = 1; i < K; i++) {
            if (strcmp(linguas[i], linguas[0]) != 0) {
                todos_mesma_lingua = 0;
                break;
            }
        }

        if (todos_mesma_lingua) {
            printf("%s\n", linguas[0]);
        } else {
            printf("ingles\n");
        }
    }

    return 0;
}