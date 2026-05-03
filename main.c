#include "headers.h"

int main() {
#ifndef ARQUIVO
    printf("Arquivo não definido.\n");
    return -1;
#endif

    ListaAdjacencia *grafo = cria_grafo_csv(ARQUIVO);
    if(!grafo) {
        printf("Saindo...\n");
        return -2;
    }

    int opt = -1;
    do {
        menu();
        scanf("%d", &opt);

        switch(opt) {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            printf("Grau máximo: %u\n", grau_maximo(grafo));
            break;
        case 2:
            printf("Grau mínimo: %u\n", grau_minimo(grafo));
            break;
        case 3: {
            uint *valores = is_multigrafo(grafo);
            if(!valores) {
                printf("Erro na alocação de memória.\n");
                return -3;
            }

            if(!valores[0])
                printf("O grafo analisado é simples.\n");
            else
                printf("O grafo analisado é um multigrafo.\n"
                       "Possui %u laços e %u arestas múltiplas.\n",
                       valores[1], valores[2]);
            free(valores);
            break;
        }
        case 4:
        // WIP
        default:
            printf("Opção inválida.\n");
        }
    } while(opt != 0);
}


void menu() {
    printf("Escolha:\n"
           "0 - Sair\n"
           "1 - Determinar grau máximo do grafo\n"
           "2 - Determinar grau mínimo do grafo\n"
           "3 - Determinar se o grafo é simples ou multigrafo\n"
           "4 - Determinar quantos componentes conexos existem no grafo\n"
          );
}
