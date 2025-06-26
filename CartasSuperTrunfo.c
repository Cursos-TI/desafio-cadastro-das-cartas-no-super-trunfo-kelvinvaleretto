#include <stdio.h>

int main() {
  char estado1[50], estado2[50], codigo1[10], codigo2[10], nomeCidade1[50], nomeCidade2[50];
  int populacao1, populacao2, numPontosTuristicos1, numPontosTuristicos2;
  float area1, area2, pib1, pib2, densidadePopulacional1, densidadePopulacional2, pibPerCapita1, pibPerCapita2;

  // Carta 1
  printf("Carta 1:\n");
  printf("Estado: ");
  scanf("%s", estado1);
  printf("Código: ");
  scanf("%s", codigo1);
  printf("Nome da Cidade: ");
  scanf("%s", nomeCidade1);
  printf("População: ");
  scanf("%d", &populacao1);
  printf("Área (km²): ");
  scanf("%f", &area1);
  printf("PIB (bilhões de reais): ");
  scanf("%f", &pib1);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &numPontosTuristicos1);

  densidadePopulacional1 = (float)populacao1 / area1;
  pibPerCapita1 = (pib1 * 1000000000) / populacao1;


  // Carta 2
  printf("\nCarta 2:\n");
  printf("Estado: ");
  scanf("%s", estado2);
  printf("Código: ");
  scanf("%s", codigo2);
  printf("Nome da Cidade: ");
  scanf("%s", nomeCidade2);
  printf("População: ");
  scanf("%d", &populacao2);
  printf("Área (km²): ");
  scanf("%f", &area2);
  printf("PIB (bilhões de reais): ");
  scanf("%f", &pib2);
  printf("Número de Pontos Turísticos: ");
  scanf("%d", &numPontosTuristicos2);

  densidadePopulacional2 = (float)populacao2 / area2;
  pibPerCapita2 = (pib2 * 1000000000) / populacao2;

  // Exibindo resultados
  printf("\nResultados:\n");

  printf("Carta 1:\n");
  printf("Estado: %s\n", estado1);
  printf("Código: %s\n", codigo1);
  printf("Nome da Cidade: %s\n", nomeCidade1);
  printf("População: %d\n", populacao1);
  printf("Área: %.2f km²\n", area1);
  printf("PIB: %.2f bilhões de reais\n", pib1);
  printf("Número de Pontos Turísticos: %d\n", numPontosTuristicos1);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

  printf("\nCarta 2:\n");
  printf("Estado: %s\n", estado2);
  printf("Código: %s\n", codigo2);
  printf("Nome da Cidade: %s\n", nomeCidade2);
  printf("População: %d\n", populacao2);
  printf("Área: %.2f km²\n", area2);
  printf("PIB: %.2f bilhões de reais\n", pib2);
  printf("Número de Pontos Turísticos: %d\n", numPontosTuristicos2);
  printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
  printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

  return 0;
}