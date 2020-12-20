/* menu.h
 * Definição dos protótipo para o menu de operacoes.
 *
 * Felipe Ferreira
 */
 #ifndef _MENU_H
#define _MENU_H


/*Definiçoes das opcoes do menu Cobertura Vacinal*/
#define LISTA_TODAS_CIDADES   1
#define PROCURAR_CIDADE       2
#define MAIORES_COBERTURAS    3
#define MENORES_COBERTURAS    4
#define SAIR                  5
#define NUM_OP                5

/*
 * Função que carrega na saida do console o menu com as
 * operacoes disponiveis no programa.
 */
void Carregar_menu();

#endif // _MENU_H
