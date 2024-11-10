#include "Places.h"

// Função para inicializar o gerador de números aleatórios com semente baseada no tempo.
void iniciar_funcao_srand() {
    srand(time(NULL));
}

// Gera um número pseudoaleatório do tipo float dentro de um intervalo especificado.
float gerar_coordenada(float minimo, float maximo) {
    float escala = rand() / (float)RAND_MAX;
    return minimo + escala * (maximo - minimo);
}

// Calcula a distância entre dois pontos.
float calcular_distancia(ponto a, ponto b) {
    return sqrt(pow(a.Px - b.Px, 2) + pow(a.Py - b.Py, 2));
}

// Função de comparação para ordenação com qsort().
int comparar_registro(const void *a, const void *b) {
    registro *regA = (registro *)a;
    registro *regB = (registro *)b;
    return (regA->Valor > regB->Valor) - (regA->Valor < regB->Valor);
}

// Gera um indivíduo (permutação) embaralhando números de 1 até n.
void gerar_individuo(int individuo[], int n) {
    int i, j, temporario;
    for (i = 0; i < n; i++) {
        individuo[i] = i + 1;
    }
    for (i = 0; i < n; i++) {
        j = rand() % n;
        temporario = individuo[i];
        individuo[i] = individuo[j];
        individuo[j] = temporario;
    }
}
