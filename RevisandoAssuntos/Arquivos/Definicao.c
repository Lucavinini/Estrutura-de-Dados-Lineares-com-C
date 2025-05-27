/*

Arquivos podem assumir o formato txt e binário. São informações persistentes em disco rigido que são acessadas
por meio de ponteiros.

*/

#include <stdio.h>

int main(){

    FILE *ListaDeCompras; //Definição de um arquivo.

    //Uma vez nomeado o ponteiro, vamos criar um arquivo usando o fopen()
    // !! fopen("NomeDoArquivo.formato", "Tipo de procedimento");

    ListaDeCompras = fopen("Compras.txt", "r");

    //Sempre que terminar de usar o arquivo, feche:
    
    fclose(ListaDeCompras);

    ListaDeCompras = fopen()

    



}