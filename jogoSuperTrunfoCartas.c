#include <stdio.h>
#define TOTAL_CIDADES 32

// Estrutura para armazenar os dados de uma cidade.
typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Cidade;

// Função para calcular propriedades derivadas
double calcular_densidade(int populacao, float area) {
    return area > 0 ? populacao / area : 0;
}

double calcular_pib_per_capita(double pib, int populacao) {
    return populacao > 0 ? pib / populacao : 0;
}

// Função para cadastrar cidades
void cadastrar_cidades(Cidade cidades[]) {
    printf("\n--- Cadastro de Cidades ---\n");
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        printf("\nDigite os dados da cidade %d:\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cidades[i].estado);

        printf("Código da cidade (Ex: A01, B02 até H04): ");
        scanf("%s", cidades[i].codigo);

        printf("Nome da cidade: ");
        getchar();  // Captura o ENTER anterior
        scanf(" %[^\n]", cidades[i].nome);

        printf("População: ");
        scanf("%d", &cidades[i].populacao);

        printf("Área (km²): ");
        scanf("%f", &cidades[i].area);

        printf("PIB (em bilhões): ");
        scanf("%lf", &cidades[i].pib);

        printf("Número de pontos turísticos: ");
        scanf("%d", &cidades[i].pontos_turisticos);

        cidades[i].densidade_populacional = calcular_densidade(cidades[i].populacao, cidades[i].area);
        cidades[i].pib_per_capita = calcular_pib_per_capita(cidades[i].pib, cidades[i].populacao);
        cidades[i].super_poder = cidades[i].populacao + cidades[i].area + cidades[i].pib + cidades[i].pontos_turisticos;
    }
}

// Função para exibir cidades
void exibir_cidades(Cidade cidades[]) {
    printf("\n--- Cidades Cadastradas ---\n");
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        printf("\nEstado: %c\n", cidades[i].estado);
        printf("Código: %s\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("População: %d habitantes\n", cidades[i].populacao);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2lf bilhões\n", cidades[i].pib);
        printf("Pontos turísticos: %d\n", cidades[i].pontos_turisticos);
        printf("Densidade Populacional: %.2f pessoas/km²\n", cidades[i].densidade_populacional);
        printf("PIB per Capita: %.2f reais\n", cidades[i].pib_per_capita);
        printf("Super Poder: %.2f\n", cidades[i].super_poder);
    }
}

// Função para comparar duas cidades
void comparar_cidades(Cidade cidade1, Cidade cidade2) {
    printf("\n--- Comparação de Cidades ---\n");
    printf("Comparando %s (%s) e %s (%s)\n", cidade1.nome, cidade1.codigo, cidade2.nome, cidade2.codigo);
    
    printf("Densidade Populacional: %s vence!\n", cidade1.densidade_populacional < cidade2.densidade_populacional ? cidade1.nome : cidade2.nome);
    printf("População: %s vence!\n", cidade1.populacao > cidade2.populacao ? cidade1.nome : cidade2.nome);
    printf("Área: %s vence!\n", cidade1.area > cidade2.area ? cidade1.nome : cidade2.nome);
    printf("PIB: %s vence!\n", cidade1.pib > cidade2.pib ? cidade1.nome : cidade2.nome);
    printf("Pontos turísticos: %s vence!\n", cidade1.pontos_turisticos > cidade2.pontos_turisticos ? cidade1.nome : cidade2.nome);
    printf("Super Poder: %s vence!\n", cidade1.super_poder > cidade2.super_poder ? cidade1.nome : cidade2.nome);
}

int main() {
    Cidade cidades[TOTAL_CIDADES];
    cadastrar_cidades(cidades);
    exibir_cidades(cidades);
    
    // Exemplo de comparação entre duas cidades
    int index1, index2;
    printf("\nEscolha duas cidades para comparar (0 a %d):\n", TOTAL_CIDADES - 1);
    scanf("%d %d", &index1, &index2);
    
    if (index1 >= 0 && index1 < TOTAL_CIDADES && index2 >= 0 && index2 < TOTAL_CIDADES) {
        comparar_cidades(cidades[index1], cidades[index2]);
    } else {
        printf("Índices inválidos!\n");
    }
    
    return 0;
}