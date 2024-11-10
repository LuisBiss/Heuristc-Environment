#include "Places.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "");  
    int quantidadePontos, i, j;
    printf("Primeiro escreva com quantos pontos deseja trabalhar (máximo 10):");
    scanf("%d", &quantidadePontos);

    if (quantidadePontos > 10) {
        printf("Número máximo de pontos permitido é 10.\n");
        return 1;
    }

    ponto pontos[quantidadePontos];
    float dist[10][10] = {0}; 

    iniciar_funcao_srand();
    for (i = 0; i < quantidadePontos; i++) {
        pontos[i].ID = i;
        pontos[i].Px = gerar_coordenada(1, 360);
        pontos[i].Py = gerar_coordenada(1, 360);
        printf("ponto %d: ID -> %d ; Px -> %.2f ; Py -> %.2f \n", i, pontos[i].ID, pontos[i].Px, pontos[i].Py);
    }

    for (i = 0; i < quantidadePontos; i++) {
        for (j = 0; j < quantidadePontos; j++) {
            if (i != j) {
                dist[i][j] = calcular_distancia(pontos[i], pontos[j]);
            }
        }
    }

    printf("\nMatriz de Distâncias:\n");
    printf("       ");
    for (j = 0; j < quantidadePontos; j++) {
        printf("   P%d    ", pontos[j].ID);
    }
    printf("\n");

    for (i = 0; i < quantidadePontos; i++) {
        printf("P%d  ", pontos[i].ID);
        for (j = 0; j < quantidadePontos; j++) {
            if (i != j) {
                printf("%8.2f ", dist[i][j]);
            } else {
                printf("   0.00   ");
            }
        }
        printf("\n");
    }

    registro populacao[100];
    for (i = 0; i < 100; i++) {
        populacao[i].Individuo = malloc(quantidadePontos * sizeof(int));
        gerar_individuo(populacao[i].Individuo, quantidadePontos);
        populacao[i].Valor = 0;
        for (j = 0; j < quantidadePontos - 1; j++) {
            int inicio = populacao[i].Individuo[j] - 1;
            int fim = populacao[i].Individuo[j + 1] - 1;
            populacao[i].Valor += dist[inicio][fim];
        }
        int indiceUltimoPonto = populacao[i].Individuo[quantidadePontos - 1] - 1;
        int indicePrimeiroPonto = populacao[i].Individuo[0] - 1;
        populacao[i].Valor += dist[indiceUltimoPonto][indicePrimeiroPonto];
    }

    qsort(populacao, 100, sizeof(registro), comparar_registro);
    printf("\nPopulação Ordenada pelo Valor:\n");
    for (i = 0; i < 100; i++) {
        printf("Indivíduo %d: [", i + 1);
        for (j = 0; j < quantidadePontos; j++) {
            printf("%d", populacao[i].Individuo[j]);
            if (j < quantidadePontos - 1)
                printf(", ");
        }
        printf("] - Valor: %.2f\n", populacao[i].Valor);
    }

    for (i = 0; i < 100; i++) {
        free(populacao[i].Individuo);
    }

    return 0;
}
