/* avl.c
 * Implementação das operações realizadas sobre o TAD que representa uma árvore AVL.
 *
 * Felipe Ferreira
 */

#include "avl.h"
#include "listaord.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void load_cidades(avl_tree * t, char * filename) {

    FILE * arq; // Arquivo lógico
    char palavra[10001], * token = NULL; // Nome do arquivo sobre o qual a contagem será realizada
    bool h, k = false;
    if ((arq = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo %s\n", filename);
        exit(1);
     }

    avl_tree x = NULL;
    avl_info city;

    while (fscanf(arq, " %1000[^\n]s", palavra) != EOF) {

        token = strtok(palavra, ";");
        strcpy(city.codigoMunicipio, token);
        token = strtok(NULL, ";");
        strcpy(city.nomeMunicipio, token);
        token = strtok(NULL, ";");
        strcpy(city.coberturaVacinal, token);
        add_dadoArvore(t, city, &k, &k);
    }
}

void add_dadoArvore(avl_tree * t, avl_info x, bool * h, bool * k) {

    if (*t == NULL) {
        if ((*t = (avl_tree) malloc(sizeof(struct avl_no))) == NULL) {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }

        *h = true;

        (*t)->dado = x;
        (*t)->esq = (*t)->dir = NULL;
        (*t)->bal = 0;
        *k = true;

    }
    else if (atof(x.coberturaVacinal) < atof((*t)->dado.coberturaVacinal)) { // Inserir a esquerda
        add_dadoArvore(&(*t)->esq, x, h, k);
        if (*h) { // O ramo esquerdo cresceu
            switch ((*t)->bal) {
                case 1: (*t)->bal = 0;
                        *h = false;
                        break;
                case 0: (*t)->bal = -1;
                        break;
                case -1:
                    // Rebalanceamento
                    if ((*t)->esq->bal == -1) { //Rotação simples p/ direita
                        rotacao_dir(t);
                        (*t)->dir->bal = 0; //Ajusta o fator de balanceamento
                    }
                    else { // Rotação dupla para direita
                        rotacao_esq(&(*t)->esq);
                        rotacao_dir(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                    }
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else if (atof(x.coberturaVacinal) > atof((*t)->dado.coberturaVacinal)) { // Inserir a direita
        add_dadoArvore(&(*t)->dir, x, h, k);
        if (*h) { // O ramo direito cresceu
            switch ((*t)->bal) {
                case -1: (*t)->bal = 0;
                         *h = false;
                         break;
                case 0 : (*t)->bal = 1;
                         break;
                case 1: // Rebalanceamento
                    if ((*t)->dir->bal == 1) { // Rotação simples p/ esquerda
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        (*t)->esq->bal = 0;
                    }
                    else { // Rotação dupla para esquerda
                        rotacao_dir(&(*t)->dir);
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                    } // fim do else
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else { // a chave já está na árvore
        *k = false;
        //printf("NO já existente\n");
    }

} // fim de add_new_user

avl_tree get_min(avl_tree * t, bool * h) {
    avl_tree q;
    if ((*t)->esq != NULL) {
        q = get_min(&((*t)->esq),h);
        if (*h) balance_esq(t, h);
        return q;
    }
    else {
        *h = true;
        q = *t;
        *t = (*t)->dir;
        return q;
    }
}

void balance_dir(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case 1: (*t)->bal = 0;
                break;
        case 0: (*t)->bal = -1;
                *h = false;
                break;
        case -1: // rebalanceamento
                p1 = (*t)->esq;
                b1 = p1->bal;
                if (b1 <= 0) { // rotação simples
                    (*t)->esq = p1->dir;
                    p1->dir = *t;
                    if (b1 == 0) {
                        (*t)->bal = -1;
                        p1->bal = 1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->dir;
                    b2 = p2->bal;
                    p1->dir = p2->esq;
                    p2->esq = p1;
                    p1->esq = p2->dir;
                    p2->dir = *t;
                    if(b2 == -1) (*t)->bal = 1;
                    else (*t)->bal = 0;
                    if(b2 == 1) p1->bal = -1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

void balance_esq(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case -1: (*t)->bal = 0;
                 break;
        case 0: (*t)->bal = 1;
                *h = false;
                break;
        case 1: // rebalanceamento
                p1 = (*t)->dir;
                b1 = p1->bal;
                if (b1 >= 0) { // rotação simples
                    (*t)->dir = p1->esq;
                    p1->esq = *t;
                    if (b1 == 0) {
                        (*t)->bal = 1;
                        p1->bal = -1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->esq;
                    b2 = p2->bal;
                    p1->esq = p2->dir;
                    p2->dir = p1;
                    p1->dir = p2->esq;
                    p2->esq = *t;
                    if (b2 == 1) (*t)->bal = -1;
                    else (*t)->bal = 0;
                    if (b2 == -1) p1->bal = 1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

// Rotaçao para a esquerda
void rotacao_esq(avl_tree * t) {
    avl_tree p;
    p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

// Rotação para a direita
void rotacao_dir(avl_tree * t) {
    avl_tree p;
    p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}

void transferece_map(avl_tree t, hash_map m)
{
    if (t != NULL) {
        transferece_map(t->esq, m);
        map_put(m, t->dado.codigoMunicipio, &(t->dado));
        transferece_map(t->dir, m);
    }
}

void list_cidades(avl_tree t) {
    if (t != NULL) {
        list_cidades(t->esq);
        printf("> codigoMunicipio:[%-6s]\tNome Do Municipio:[ %-31s]\tCobertura Vacinal:[%-10s]\t\n",
                t->dado.codigoMunicipio,
                t->dado.nomeMunicipio,
                t->dado.coberturaVacinal);
        list_cidades(t->dir);
    }
}

/* Realiza uma busca pelo valor x na ABB t */
avl_tree busca_coberturaVacinal(avl_tree t, char * x)
{
    if (t == NULL)
        return NULL;
    else
        if (strcmp(t->dado.coberturaVacinal, x) == 0) return t;
        else
            if (strcmp(x, t->dado.coberturaVacinal) < 0) return busca_coberturaVacinal(t->esq, x);
            else return busca_coberturaVacinal(t->dir, x);
}

void menores_coberturas(avl_tree t)
{
    if (t != NULL) {
        menores_coberturas(t->esq);
        printf("> codigoMunicipio:[%-6s]\tNome Do Municipio:[ %-31s]\tCobertura Vacinal:[%-10s]\t\n",
               t->dado.codigoMunicipio,
               t->dado.nomeMunicipio,
               t->dado.coberturaVacinal);
    }

}

void maiores_coberturas(avl_tree t)
{
    if (t != NULL) {
        menores_coberturas(t->dir);
        printf("> codigoMunicipio:[%-6s]\tNome Do Municipio:[ %-31s]\tCobertura Vacinal:[%-10s]\t\n",
               t->dado.codigoMunicipio,
               t->dado.nomeMunicipio,
               t->dado.coberturaVacinal);
    }

}

FILE *open_arquivo() {

    FILE * arq; // Arquivo lógico
    if ((arq = fopen("filename", "w")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo %s\n", "filename");
     }

    return arq;
}
