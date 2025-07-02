#include <stdio.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char estado;
    char codigo[5];
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para calcular atributos derivados
void calcularAtributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1 / c->densidade);
}

// Função para exibir a carta formatada
void exibirCarta(Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
}

// Função para obter valor do atributo
float obterAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        case 7: return c.superPoder;
        default: return -1.0f;
    }
}

// Função para retornar nome do atributo
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Desconhecido";
    }
}

// Função para mostrar menu dinâmico
void mostrarMenu(int ignorar) {
    printf("\nEscolha o atributo para comparar:\n");
    for (int i = 1; i <= 7; i++) {
        if (i != ignorar) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
}

// Função para comparar atributos e mostrar resultado
int comparar(Carta c1, Carta c2, int atributo) {
    float v1 = obterAtributo(c1, atributo);
    float v2 = obterAtributo(c2, atributo);
    int resultado;

    // Regra especial: densidade populacional -> menor vence
    if (atributo == 5)
        resultado = (v1 < v2) ? 1 : (v1 > v2 ? 0 : -1);
    else
        resultado = (v1 > v2) ? 1 : (v1 < v2 ? 0 : -1);

    printf("\nComparação de Atributo: %s\n", nomeAtributo(atributo));
    printf("Carta 1 - %s: %.2f\n", c1.cidade, v1);
    printf("Carta 2 - %s: %.2f\n", c2.cidade, v2);

    if (resultado == 1) {
        printf("Resultado: Carta 1 venceu! (1)\n");
    } else if (resultado == 0) {
        printf("Resultado: Carta 2 venceu! (0)\n");
    } else {
        printf("Resultado: Empate!\n");
    }

    return resultado;
}

int main() {
    Carta carta1, carta2;

    // Entrada de dados
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): "); scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): "); scanf(" %s", carta1.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]", carta1.cidade);
    printf("População: "); scanf("%lu", &carta1.populacao);
    printf("Área (km²): "); scanf("%f", &carta1.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta1.pib);
    printf("Nº de Pontos Turísticos: "); scanf("%d", &carta1.pontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): "); scanf(" %c", &carta2.estado);
    printf("Código (ex: B02): "); scanf(" %s", carta2.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]", carta2.cidade);
    printf("População: "); scanf("%lu", &carta2.populacao);
    printf("Área (km²): "); scanf("%f", &carta2.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta2.pib);
    printf("Nº de Pontos Turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    // Cálculo de atributos
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Exibir cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu dinâmico para escolha de dois atributos
    int atributo1, atributo2;

    mostrarMenu(0);
    scanf("%d", &atributo1);
    while (atributo1 < 1 || atributo1 > 7) {
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &atributo1);
    }

    mostrarMenu(atributo1);
    scanf("%d", &atributo2);
    while (atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1) {
        printf("Opção inválida. Tente novamente: ");
        scanf("%d", &atributo2);
    }

    // Comparação dos dois atributos escolhidos
    int resultado1 = comparar(carta1, carta2, atributo1);
    int resultado2 = comparar(carta1, carta2, atributo2);

    // Soma dos dois atributos
    float soma1 = obterAtributo(carta1, atributo1) + obterAtributo(carta1, atributo2);
    float soma2 = obterAtributo(carta2, atributo1) + obterAtributo(carta2, atributo2);

    printf("\nSoma dos Atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.cidade, soma1);
    printf("Carta 2 (%s): %.2f\n", carta2.cidade, soma2);

    if (soma1 > soma2) {
        printf("\nResultado Final: Carta 1 venceu!\n");
    } else if (soma2 > soma1) {
        printf("\nResultado Final: Carta 2 venceu!\n");
    } else {
        printf("\nResultado Final: Empate!\n");
    }

    return 0;
}
