#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "avl.h"
#include "listaord.h"
#include "hashmap.h"
#include "menu.h"


typedef struct
{
    hash_map m_hash_vacinacao;
    avl_tree t_tree_vacinacao;
}Dados;

static Dados DadosVacinacao;

static int menu_load(char * opcao[NUM_OP])
{
    int i, op;
    printf("\n\n*************************************************\n\t* * * [ MENU PRINCIPAL ] * * *\n*************************************************\n\n");
    for (i = 0; i < NUM_OP; i++) {
        printf("%-30s\t\t\tOP:%d\n", opcao[i], i + 1);
    }
    printf("\n[SELECIONE UMA OP]: ");
    scanf(" %d", &op);
    return op;
}

static void Menu()
{
    char codigoCidade[31];
    char * opcoes[NUM_OP] = { "Todas Coberturas Vacinais",
                              "Procurar Municipio", "Maiores Coberturas", "Menores Coberturas",
                              "Sair do Programa"
                            };
    int op;

    do {

        op = menu_load(opcoes);

        switch (op) {

        case LISTA_TODAS_CIDADES:
            list_cidades(DadosVacinacao.t_tree_vacinacao);
            printf(">>FIM DA PESQUISA");
            break;
        case PROCURAR_CIDADE :
            printf("Informe o Numero da Cidade Para Busca: ");
            scanf(" %31[^\n]", codigoCidade);
            busca_coberturaVacinal_HashMap(DadosVacinacao.m_hash_vacinacao, codigoCidade);
            printf(">>FIM DA PESQUISA");
            break;
        case MAIORES_COBERTURAS:
            maiores_coberturas(DadosVacinacao.t_tree_vacinacao);
            printf(">>FIM DA PESQUISA");
            break;
        case MENORES_COBERTURAS:
            menores_coberturas(DadosVacinacao.t_tree_vacinacao);
            printf(">>FIM DA PESQUISA");
            break;
        case SAIR:
            break;
        default:
            printf( "\n\tOpção invalida!" );
        }
    }

    while(op != SAIR);

    return;
}

static void Inicializar_load_dates()
{
    char filename[61];
    DadosVacinacao.t_tree_vacinacao = NULL;
    map_init(DadosVacinacao.m_hash_vacinacao);

    printf("\n<Enter FileName *there is a file filename: ");
    scanf(" %60[^\n]", filename);
    printf("\n<Data loaded from disk!\n");
    load_cidades(&DadosVacinacao.t_tree_vacinacao, filename);
    transferece_map(DadosVacinacao.t_tree_vacinacao, DadosVacinacao.m_hash_vacinacao); //Realiza transferencia
                                                                                      //por referencia de endereco

}

void Carregar_menu()
{
    Inicializar_load_dates();
    Menu();
}




