#include <stdio.h>
#include <string.h>

//As estruturas, ou struct, são variáveis compostas heterogêneas
//ou seja, seus componentes podem ser de diferentes tipos.

//Definição da estrutura:



typedef struct Pessoa{
    char nome[20];
    int idade;
    float peso;
}DadosPessoa;

//A estrutura fora do main é apenas um esqueleto do vai ser o meu
//tipo de dado.

int main(){

//Uma vez criado o esqueleto, podemos criar variáveis do tipo DadosPessoa

DadosPessoa Ana;

//o preenchimento dos campos são feito campo a campo usando a forma:

strcpy(Ana.nome, "Adelaide Ana");
Ana.idade = 10;
printf("Digite o peso de Ana: \n");
scanf("%f", &Ana.peso);

printf("%f\n", Ana.peso);
printf("%s\n", Ana.nome);
printf("%i\n", Ana.idade);


//Podemos atribuir os dados de uma estrutura para outra, desde que sejam do mesmo tipo.


DadosPessoa Carla;

Carla = Ana;
printf("Carla tem os seguintes dados: \n");
printf("%s\n%i\n%f", Carla.nome, Carla.idade, Carla.peso);

}