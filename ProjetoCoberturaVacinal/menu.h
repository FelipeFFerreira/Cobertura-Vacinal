/* menu.h
 * Defini��o dos prot�tipo para o menu de operacoes.
 *
 * Felipe Ferreira
 */
 #ifndef _MENU_H
#define _MENU_H


/*Defini�oes das opcoes do menu Cobertura Vacinal*/
#define LISTA_TODAS_CIDADES   1
#define PROCURAR_CIDADE       2
#define MAIORES_COBERTURAS    3
#define MENORES_COBERTURAS    4
#define SAIR                  5
#define NUM_OP                5

/*
 * Fun��o que carrega na saida do console o menu com as
 * operacoes disponiveis no programa.
 */
void Carregar_menu();

#endif // _MENU_H
