#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sexo;
    float altura;
    int idade;
    char olhos;
} Habitante;

int main() {
    int n, i, count_castanhos_altos = 0, soma_idade_castanhos_altos = 0;
    int maior_idade = 0;
    int count_mulheres = 0;
    int count_homens = 0;
    
    printf("Informe a quantidade de habitantes: ");
    scanf("%d", &n);

    Habitante *habitantes = (Habitante *) malloc(n * sizeof(Habitante));

    if (habitantes == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Coleta de dados
    for (i = 0; i < n; i++) {
        printf("\nHabitante %d:\n", i + 1);
        printf("Sexo (M/F): ");
        scanf(" %c", &habitantes[i].sexo);
        printf("Altura (em metros): ");
        scanf("%f", &habitantes[i].altura);
        printf("Idade: ");
        scanf("%d", &habitantes[i].idade);
        printf("Cor dos olhos (A/V/C/P): ");
        scanf(" %c", &habitantes[i].olhos);

        // a. Média de idade com olhos castanhos e altura > 1.60
        if (habitantes[i].olhos == 'C' && habitantes[i].altura > 1.60) {
            soma_idade_castanhos_altos += habitantes[i].idade;
            count_castanhos_altos++;
        }

        // b. Maior idade
        if (habitantes[i].idade > maior_idade) {
            maior_idade = habitantes[i].idade;
        }

        // c. Mulheres com idade entre 20 e 45 ou olhos verdes e altura < 1.70
        if (habitantes[i].sexo == 'F' &&
            ((habitantes[i].idade >= 20 && habitantes[i].idade <= 45) ||
             (habitantes[i].olhos == 'V' && habitantes[i].altura < 1.70))) {
            count_mulheres++;
        }

        // d. Contagem de homens
        if (habitantes[i].sexo == 'M') {
            count_homens++;
        }
    }

    // Resultados
    printf("\n=== Resultados ===\n");
    if (count_castanhos_altos > 0) {
        printf("a. Média de idade (olhos castanhos e altura > 1.60): %.2f\n",
               (float)soma_idade_castanhos_altos / count_castanhos_altos);
    } else {
        printf("a. Nenhum habitante com olhos castanhos e altura > 1.60.\n");
    }

    printf("b. Maior idade entre os habitantes: %d\n", maior_idade);
    printf("c. Mulheres com critérios específicos: %d\n", count_mulheres);
    printf("d. Percentual de homens: %.2f%%\n", (float)count_homens / n * 100.0);

    // Liberação da memória
    free(habitantes);

    return 0;
}
