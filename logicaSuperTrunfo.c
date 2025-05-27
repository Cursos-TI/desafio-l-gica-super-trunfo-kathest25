#include <stdio.h>

// Desafio Super Trunfo - Comparação das Cartas

int main() {
    // Definindo as variáveis que armazenam as propriedades das cidades:
    
    char nomeCidade1[25], nomeCidade2[25];
    char estado1, estado2;
    char cod1[5], cod2[5];
    float populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int ptTuristico1, ptTuristico2;
    float denspop1, denspop2;
    float pibpcap1, pibpcap2;
    
    // Cadastro das Cartas:
    // Lendo a Carta 1 
    printf("Digite o nome da cidade da carta 1: ");
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Digite o código da Carta (ex: 01 a 04): ");
    scanf(" %s", cod1);
    printf("Populacao (milhões): ");   
    scanf("%f", &populacao1);
    printf("Area (km²): ");            
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");     
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");     
    scanf("%d", &ptTuristico1);
    getchar();  

    //  Lendo a Carta 2 
    printf("Digite o nome da cidade da carta 2: ");
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o código da Carta (ex: 01 a 04): ";
    scanf(" %s", cod2);
    printf("Populacao (milhões): ");   
    scanf("%f", &populacao2);
    printf("Area (km²): ");            
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");      
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");     
    scanf("%d", &ptTuristico2);
    getchar();  

    // Calculando a densidade e PIB per capita 
    denspop1 = (populacao1 ) / area1;
    denspop2 = (populacao2 ) / area2;
    pibpcap1 = (pib1   * 1000000000) / (populacao1 );
    pibpcap2 = (pib2   * 1000000000) / (populacao2 );

    int escolha1 = 0, escolha2 = 0;
    float CARTA1_ATR1 = 0, CARTA2_ATR1 = 0;
    float CARTA1_ATR2 = 0, CARTA2_ATR2 = 0;
    float soma1, soma2;
    char* nomeAtributos[7] = { 
       "", "Populacao", "Area", "PIB", "Pontos Turisticos", "Densidade Demografica", "PIB per Capita"
    };

    //  Menu Interativo 1
    int exibeMenu = 1;
    switch (exibeMenu) {
        case 1:
            printf("\nDigite o número do primeiro atributo:\n");
            printf("1 - Populacao\n");
            printf("2 - Area\n");
            printf("3 - PIB\n");
            printf("4 - Pontos Turisticos\n");
            printf("5 - Densidade Demografica\n");
            printf("6 - PIB per Capita\n");
            break;
    }
    scanf("%d", &escolha1);

    switch (escolha1) {
        case 1: CARTA1_ATR1 = populacao1; CARTA2_ATR1 = populacao2; break;
        case 2: CARTA1_ATR1 = area1;       CARTA2_ATR1 = area2;       break;
        case 3: CARTA1_ATR1 = PIB1;        CARTA2_ATR1 = PIB2;        break;
        case 4: CARTA1_ATR1 = pontoTuristico1; CARTA2_ATR1 = pontoTuristico2; break;
        case 5: CARTA1_ATR1 = denspop1;    CARTA2_ATR1 = denspop2;    break;
        case 6: CARTA1_ATR1 = PIBpcap1;    CARTA2_ATR1 = PIBpcap2;    break;
        default:
            printf("Opcao inválida para atributo 1.\n");
            return 0;
    }
    //  Menu Interativo 2
    printf("\nEscolha o segundo atributo (diferente de %d):\n", escolha1);
    switch (escolha1) {
        case 1:
            printf("2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per Capita\n");
            break;
        case 2:
            printf("1 - Populacao\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per Capita\n");
            break;
        case 3:
            printf("1 - Populacao\n2 - Area\n4 - Pontos Turisticos\n5 - Densidade Demografica\n6 - PIB per Capita\n");
            break;
        case 4:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n5 - Densidade Demografica\n6 - PIB per Capita\n");
            break;
        case 5:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n6 - PIB per Capita\n");
            break;
        case 6:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
            break;
    }
    
    //  Lendo e validando a segunda escolha
    
    do {
        scanf("%d", &escolha2);
        if (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1) {
            printf("Opcao inválida! Tente novamente:\n");
        }
    } while (escolha2 < 1 || escolha2 > 6 || escolha2 == escolha1);

    // Atribuir valores segundo escolha 
    switch (escolha2) {
        case 1: CARTA1_ATR2 = populacao1;      CARTA2_ATR2 = populacao2;      break;
        case 2: CARTA1_ATR2 = area1;            CARTA2_ATR2 = area2;            break;
        case 3: CARTA1_ATR2 = PIB1;             CARTA2_ATR2 = PIB2;             break;
        case 4: CARTA1_ATR2 = pontoTuristico1;  CARTA2_ATR2 = pontoTuristico2;  break;
        case 5: CARTA1_ATR2 = denspop1;         CARTA2_ATR2 = denspop2;         break;
        case 6: CARTA1_ATR2 = PIBpcap1;         CARTA2_ATR2 = PIBpcap2;         break;
    }

    //  Exibição dos dados 
    printf("\n== DADOS DAS CARTAS ==\n");
    printf("Carta 1: %sEstado: %c | Codigo: %s\n"
           " Pop: %.2f mi | Area: %.2f km² | PIB: %.2f bi | PTur: %d | Den: %.2f hab/km² | PCap: %.2f R$\n",
           nomeCidade1, estado1, cod1,
           populacao1, area1, pib1, ptTuristico1, denspop1, pibpcap1); 

    printf("Carta 2: %sEstado: %c | Codigo: %s\n"
           " Pop: %.2f mi | Area: %.2f km² | PIB: %.2f bi | PTur: %d | Den: %.2f hab/km² | PCap: %.2f R$\n",
           nomeCidade2, estado2, cod2,
           populacao2, area2, pib2, ptTuristico2, denspop2, pibpcap2);
    
      // Comparação de Cartas utilizando estruturas de decisão (if, if-else) com os atributos:
      // Comparações individuais:
    printf("\n== COMPARACAO ==\n");
    printf("%s: C1=%.2f | C2=%.2f => ",
           nomeAtributos[escolha1], CARTA1_ATR1, CARTA2_ATR1);
    if (escolha1 == 5)
        printf(CARTA1_ATR1 < CARTA2_ATR1 ? "C1 venceu\n"
               : CARTA2_ATR1 < CARTA1_ATR1 ? "C2 venceu\n" : "Empate\n");
    else
        printf(CARTA1_ATR1 > CARTA2_ATR1 ? "C1 venceu\n"
               : CARTA2_ATR1 > CARTA1_ATR1 ? "C2 venceu\n" : "Empate\n");

    printf("%s: C1=%.2f | C2=%.2f => ",
           nomeAtributos[escolha2], CARTA1_ATR2, CARTA2_ATR2);
    if (escolha2 == 5)
        printf(CARTA1_ATR2 < CARTA2_ATR2 ? "C1 venceu\n"
               : CARTA2_ATR2 < CARTA1_ATR2 ? "C2 venceu\n" : "Empate\n");
    else
        printf(CARTA1_ATR2 > CARTA2_ATR2 ? "C1 venceu\n"
               : CARTA2_ATR2 > CARTA1_ATR2 ? "C2 venceu\n" : "Empate\n");

    // Exibição dos Resultados (qual carta venceu e com base em qual atributo):
    //  Soma final 
    soma1 = CARTA1_ATR1 + CARTA1_ATR2;
    soma2 = CARTA2_ATR1 + CARTA2_ATR2;
    printf("\n== PONTUACAO FINAL ==\n"
           "C1=%.2f | C2=%.2f => %s\n",
           soma1, soma2,
           soma1 > soma2 ? "Carta 1 venceu" :
           soma2 > soma1 ? "Carta 2 venceu" :
           "Empate");

    return 0;
}
