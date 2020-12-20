/* avl.h
 * Definição do TAD para representar uma árvore AVL e protótipo
 * de suas operações.
 *
 * Felipe Ferreira
 */

#ifndef _AVL_H
#define _AVL_H

#include "hashmap.h"
#include "listaord.h"
#include <stdio.h>

// Definição da estrutura de dados
typedef struct {
    char coberturaVacinal[21];
    char nomeMunicipio[51];
    char codigoMunicipio[51];
}avl_info;

typedef struct avl_no * avl_tree;

struct avl_no {
    avl_info dado;
    avl_tree esq;
    avl_tree dir;
    int bal; // balanceamento do nó
};

/* Função que realiza tranferencia dos dados da arvore avl, para o hash map
 * operacao realizada por referencia, sem a necessidade de duplicamento
 * dos dados.
 */
void transferece_map(avl_tree t, hash_map m);

/*
 * Função que faz uma rotação para a esquerda na árvore AVL t.
 */
void rotacao_esq(avl_tree *);

/*
 * Função que faz o balanceamento da árvore AVL t após uma remoção
 * em sua subárvore esquerda e sinaliza se houve uma
 * dimuição da altura dessa subárvore através de h.
 */
void balance_esq(avl_tree * t, bool * h);

/*
 * Função que faz o balanceamento da árvore AVL t após uma remoção
 * em sua subárvore direita e sinaliza se houve uma
 * dimuição da altura dessa subárvore através de h.
 */
void balance_dir(avl_tree *, bool *);

/*
 * Função que devolve um ponteiro para o nó que contém o menor
 * valor na árvore AVL t e sinaliza através de h se
 * houve uma diminuição da altura de t.
 */
avl_tree get_min(avl_tree * t, bool * h);

/*
 * Função que carrega arquivos com os dados dos municipios e suas respectivas
 * coberturas vacinais para o programa.
 */
void load_cidades(avl_tree * t, char * filename);

/*
 * Função que adiciona um novo node na arvore.
 */
void add_dadoArvore(avl_tree * t, avl_info x, bool * h, bool * k);

/*
 *	Função que lista todas as coberturas vacinais, pecorrenco a arvore avl.
 */
void list_cidades(avl_tree t);

/*
 *	Função que realiza a busca de uma determinada cobertura vacinal, dado
 *  o seu respectivo codigo de município.
 */
avl_tree busca_coberturaVacinal(avl_tree , char * x);

/*
 * Função que lista as menores coberturas vacinais, pecorrendo a arvore avl.
 */
void maiores_coberturas(avl_tree);

/*
 * Função que lista as maiores coberturas vacinais, pecorrendo a arvore avl.
 */
void menores_coberturas(avl_tree);

/*
 * Função que realiza a abertura do arquivo em disco.
 */
FILE *open_arquivo();

#endif // _AVL_H

