#include <stdio.h>
#include <stdint.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_inverso_densidade(unsigned long int populacao, float area) {
    if (area == 0 || populacao == 0) {
        return 0; // Evitar divisão por zero
    }
    return area / populacao;
}

void calcular_atributos(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0;
    }
    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / carta->populacao;
    } else {
        carta->pib_per_capita = 0;
    }
    carta->super_poder = (float)carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + calcular_inverso_densidade(carta->populacao, carta->area);
}

void comparar_cartas(Carta carta1, Carta carta2) {
    printf("Comparação:\n");

    printf("População: Carta 1 = %lu, Carta 2 = %lu, Vencedor = Carta %d\n", carta1.populacao, carta2.populacao, carta1.populacao > carta2.populacao ? 1 : 2);
    printf("Área: Carta 1 = %.2f, Carta 2 = %.2f, Vencedor = Carta %d\n", carta1.area, carta2.area, carta1.area > carta2.area ? 1 : 2);
    printf("PIB: Carta 1 = %.2f, Carta 2 = %.2f, Vencedor = Carta %d\n", carta1.pib, carta2.pib, carta1.pib > carta2.pib ? 1 : 2);
    printf("Pontos Turísticos: Carta 1 = %d, Carta 2 = %d, Vencedor = Carta %d\n", carta1.pontos_turisticos, carta2.pontos_turisticos, carta1.pontos_turisticos > carta2.pontos_turisticos ? 1 : 2);
    printf("PIB per Capita: Carta 1 = %.2f, Carta 2 = %.2f, Vencedor = Carta %d\n", carta1.pib_per_capita, carta2.pib_per_capita, carta1.pib_per_capita > carta2.pib_per_capita ? 1 : 2);
    printf("Densidade Populacional: Carta 1 = %.2f, Carta 2 = %.2f, Vencedor = Carta %d\n", carta1.densidade_populacional, carta2.densidade_populacional, carta1.densidade_populacional < carta2.densidade_populacional ? 1 : 2);
    printf("Super Poder: Carta 1 = %.2f, Carta 2 = %.2f, Vencedor = Carta %d\n", carta1.super_poder, carta2.super_poder, carta1.super_poder > carta2.super_poder ? 1 : 2);
}

int main() {
    Carta carta1, carta2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);
    while ((getchar()) != '\n');
    printf("Código: ");
    scanf("%d", &carta1.codigo);
    while ((getchar()) != '\n');
    printf("Nome: ");
    scanf(" %[^\n]", carta1.nome);
    while ((getchar()) != '\n');
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    while ((getchar()) != '\n');
    printf("Área: ");
    scanf("%f", &carta1.area);
    while ((getchar()) != '\n');
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    while ((getchar()) != '\n');
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);
    while ((getchar()) != '\n');

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);
    while ((getchar()) != '\n');
    printf("Código: ");
    scanf("%d", &carta2.codigo);
    while ((getchar()) != '\n');
    printf("Nome: ");
    scanf(" %[^\n]", carta2.nome);
    while ((getchar()) != '\n');
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    while ((getchar()) != '\n');
    printf("Área: ");
    scanf("%f", &carta2.area);
    while ((getchar()) != '\n');
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    while ((getchar()) != '\n');
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    while ((getchar()) != '\n');

    // Exibição dos nomes e populações
    printf("\nDados das Cartas:\n");
    printf("Carta 1: Nome = %s, População = %lu\n", carta1.nome, carta1.populacao);
    printf("Carta 2: Nome = %s, População = %lu\n", carta2.nome, carta2.populacao);

    // Cálculo dos atributos
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Comparação das cartas
    comparar_cartas(carta1, carta2);

    return 0;
}