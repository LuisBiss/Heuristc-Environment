
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

typedef struct {
    int ID;
    float Px;
    float Py;
} ponto;

typedef struct {
    int *Individuo;
    float Valor;
} registro;

// Declaração das funções
void iniciar_funcao_srand();
float gerar_coordenada(float minimo, float maximo);
float calcular_distancia(ponto a, ponto b);
int comparar_registro(const void *a, const void *b);
void gerar_individuo(int individuo[], int n);
