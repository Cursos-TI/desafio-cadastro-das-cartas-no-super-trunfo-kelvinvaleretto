#include <stdio.h>
#include <string.h>

typedef struct {
    char estado;              // Estado da carta (letra A a H)
    char codigo[5];           // Código da carta (ex: A01, B03)
    char cidade[100];         // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area;               // Área da cidade em km²
    float pib;                // PIB da cidade (em bilhões de reais)
    int pontosTuristicos;     // Número de pontos turísticos
    float densidadePopulacional; // Densidade populacional
    float pibPerCapita;       // PIB per capita
    float superPoder;         // Super Poder da carta
} Carta;

void calcularDados(Carta *carta) {
    // Calcular a densidade populacional e o PIB per capita
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1e9 / carta->populacao; // PIB em reais

    // Calcular o Super Poder
    carta->superPoder = carta->populacao + carta->area + carta->pib * 1e9 + carta->pontosTuristicos + 
                        (1 / carta->densidadePopulacional);
}

void compararCartas(Carta *carta1, Carta *carta2) {
    printf("Comparação de Cartas:\n");

    // Comparando População
    printf("População: Carta 1 venceu (%d)\n", carta1->populacao > carta2->populacao);
    // Comparando Área
    printf("Área: Carta 1 venceu (%d)\n", carta1->area > carta2->area);
    // Comparando PIB
    printf("PIB: Carta 1 venceu (%d)\n", carta1->pib > carta2->pib);
    // Comparando Pontos Turísticos
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1->pontosTuristicos > carta2->pontosTuristicos);
    // Comparando Densidade Populacional (menor vence)
    printf("Densidade Populacional: Carta 2 venceu (%d)\n", carta1->densidadePopulacional > carta2->densidadePopulacional);
    // Comparando PIB per Capita
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1->pibPerCapita > carta2->pibPerCapita);
    // Comparando Super Poder
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1->superPoder > carta2->superPoder);
}

void imprimirCarta(Carta *carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->cidade);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta->pibPerCapita);
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados para a Carta 1
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    getchar();  // Para consumir o newline deixado por scanf
    fgets(carta1.cidade, 100, stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = '\0'; // Remover o newline da string
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcular dados da Carta 1
    calcularDados(&carta1);

    // Entrada de dados para a Carta 2
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: A01, B03): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    getchar();  // Para consumir o newline deixado por scanf
    fgets(carta2.cidade, 100, stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0'; // Remover o newline da string
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calcular dados da Carta 2
    calcularDados(&carta2);

    // Imprimir as cartas
    imprimirCarta(&carta1, 1);
    imprimirCarta(&carta2, 2);

    // Comparar as cartas
    compararCartas(&carta1, &carta2);

    return 0;
}
