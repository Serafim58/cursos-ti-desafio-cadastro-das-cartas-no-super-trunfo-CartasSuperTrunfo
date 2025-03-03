#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade populacional e o PIB per capita
void calcular_dados_adicionais(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar as cartas com base no atributo escolhido
int comparar_cartas(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // População
            return carta1.populacao > carta2.populacao;
        case 2: // Área
            return carta1.area > carta2.area;
        case 3: // PIB
            return carta1.pib > carta2.pib;
        case 4: // Densidade Populacional
            return carta1.densidade_populacional < carta2.densidade_populacional;
        case 5: // PIB per capita
            return carta1.pib_per_capita > carta2.pib_per_capita;
        case 6: // numero de pontos turisticos
            return carta1.pontos_turisticos > carta2.pontos_turisticos;
        default:
            return 0; // Atributo inválido
    }
}

int main() {
    Carta carta1, carta2;
    int atributo_comparacao = 1; // Atributo escolhido: População

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado: ");
    scanf("%s", carta1.estado);
    printf("Código: ");
    scanf("%s", carta1.codigo);
    printf("Cidade: ");
    scanf(" %[^\n]s", carta1.cidade); // Leitura de string com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    calcular_dados_adicionais(&carta1);

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Estado: ");
    scanf("%s", carta2.estado);
    printf("Código: ");
    scanf("%s", carta2.codigo);
    printf("Cidade: ");
    scanf(" %[^\n]s", carta2.cidade); // Leitura de string com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    calcular_dados_adicionais(&carta2);

    // Comparação das cartas
    printf("\nComparação de cartas (Atributo: ");
    switch (atributo_comparacao) {
        case 1:
            printf("População");
            break;
        case 2:
            printf("Área");
            break;
        case 3:
            printf("PIB");
            break;
        case 4:
            printf("Densidade Populacional");
            break;
        case 5:
            printf("PIB per capita");
            break;
        case 6:
            printf("Pontos turisticos");
            break;
    }
    printf("):\n");

    printf("Carta 1 - %s (%s): ", carta1.cidade, carta1.estado);
    switch (atributo_comparacao) {
        case 1:
            printf("%d\n", carta1.populacao);
            break;
        case 2:
            printf("%.2f\n", carta1.area);
            break;
        case 3:
            printf("%.2f\n", carta1.pib);
            break;
        case 4:
            printf("%.2f\n", carta1.densidade_populacional);
            break;
        case 5:
            printf("%.2f\n", carta1.pib_per_capita);
            break;
        case 6:
            printf("%d\n", carta1.pontos_turisticos);
            break;
    }

    printf("Carta 2 - %s (%s): ", carta2.cidade, carta2.estado);
    switch (atributo_comparacao) {
        case 1:
            printf("%d\n", carta2.populacao);
            break;
        case 2:
            printf("%.2f\n", carta2.area);
            break;
        case 3:
            printf("%.2f\n", carta2.pib);
            break;
        case 4:
            printf("%.2f\n", carta2.densidade_populacional);
            break;
        case 5:
            printf("%.2f\n", carta2.pib_per_capita);
            break;
        case 6:
            printf("%d\n", carta2.pontos_turisticos);
            break;
    }

    // Determinação da carta vencedora
    if (comparar_cartas(carta1, carta2, atributo_comparacao)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    }

    return 0;
}