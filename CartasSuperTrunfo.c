#include <stdio.h>
#include <string.h>

// Função para ler os dados de uma carta
void lerCarta(char *estado, char *codigo, char *nomeCidade, int *populacao, float *area, float *pib, int *pontosTuristicos) {
    printf("Estado: ");
    scanf(" %c", estado);
    while (getchar() != '\n');
    printf("Codigo: ");
    scanf("%s", codigo);
    while (getchar() != '\n');
    printf("Nome da Cidade: ");
    scanf(" %[^\n]s", nomeCidade);
    while (getchar() != '\n');
    printf("Populacao: ");
    scanf("%d", populacao);
    while (getchar() != '\n');
    printf("Area (km²): ");
    scanf("%f", area);
    while (getchar() != '\n');
    printf("PIB (bilhoes de reais): ");
    scanf("%f", pib);
    while (getchar() != '\n');
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", pontosTuristicos);
    while (getchar() != '\n');
}

// Função para exibir os dados de uma carta
void exibirCarta(char estado, char *codigo, char *nomeCidade, int populacao, float area, float pib, int pontosTuristicos) {
    printf("Estado: %c\n", estado);
    printf("Codigo: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nomeCidade);
    printf("Populacao: %d\n", populacao);
    printf("Area: %.2f km²\n", area);
    printf("PIB: %.2f bilhoes de reais\n", pib);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos);
}

int main() {
    // Dados da Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Dados da Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // Leitura dos dados da Carta 1
    printf("Digite os dados da Carta 1:\n");
    lerCarta(&estado1, codigo1, nomeCidade1, &populacao1, &area1, &pib1, &pontosTuristicos1);

    // Leitura dos dados da Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&estado2, codigo2, nomeCidade2, &populacao2, &area2, &pib2, &pontosTuristicos2);

    // Exibição dos dados da Carta 1
    printf("\nCarta 1:\n");
    exibirCarta(estado1, codigo1, nomeCidade1, populacao1, area1, pib1, pontosTuristicos1);

    // Exibição dos dados da Carta 2
    printf("\nCarta 2:\n");
    exibirCarta(estado2, codigo2, nomeCidade2, populacao2, area2, pib2, pontosTuristicos2);

    return 0;
}
