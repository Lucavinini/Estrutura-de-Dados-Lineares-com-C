/*Implemente um programa para criar o cadastro dos 
funcionários de uma empresa utilizando um vetor de estruturas. 
A empresa possui 50 funcionários. O cadastro deverá conter o nome, 
o número de matrícula, o grau de escolaridade (1, 2 ou 3), o 
tempo de serviço (em anos) e o salário de cada funcionário. O cadastro de 
funcionários deverá ser preenchido pelo usuário do programa. Após preenchido o 
cadastro, o programa deverá percorrê-lo procurando todos os funcionários com 3º grau, 
que tenham mais de 5 anos de serviço e que ganhem menos de R$ 1500,00 e deverá dar a 
eles um aumento de 20%. O programa deverá exibir o nome, o número de matrícula e o novo 
salário de todos os funcionários que receberam aumento. O programa deverá ter, no mínimo,
dois procedimentos: um para preencher o cadastro de funcionários e outro para dar o 
aumento aos funcionários e exibir o novo salário deles.*/

#include <stdio.h>

 //Criando o esqueleto da estrutura

 typedef struct funcionarios{

    char nome[30];
    int matricula;
    int escolaridadeGrau;
    int tempoServico;
    float salario;

}Funcionarios;

//Criando a função preenchedora


void PreencherFuncionarios(Funcionarios *vet){

    int i;
    for(i = 0; i < 2; i++){
        printf("Digite o Nome do Funcionario:");
        fgets(vet[i].nome, 30, stdin);
        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0'; 

        printf("Digite a matricula:");
        scanf("%d", &vet[i].matricula);
        getchar();
        printf("Digite o grau de 1 a 3:");
        scanf("%d", &vet[i].escolaridadeGrau);
        getchar();
        printf("Digite o salario:");
        scanf("%f", &vet[i].salario);
        getchar();
        printf("Digite o tempo de servico:");
        scanf("%d", &vet[i].tempoServico);
        getchar();
    }
}

void PercorrerAumento(Funcionarios *vet){

    int i;

    for(i = 0; i < 49; i++){

        if(vet[i].escolaridadeGrau == 3){
            if(vet[i].tempoServico > 5){
                if(vet[i].salario <= 1.500){

                    vet[i].salario = vet[i].salario + (vet[i].salario * 0.20);
                    printf("Recebeu o aumento:\n");
                    printf("%s\n", vet[i].nome);
                    printf("%d\n", vet[i].matricula);
                    printf("%f\n", vet[i].salario);

                }
            }
        }
    }
}

int main(){

    Funcionarios Colaboradores[49];

    PreencherFuncionarios(Colaboradores);
    printf("\n");
    PercorrerAumento(Colaboradores);

    return 0;
}