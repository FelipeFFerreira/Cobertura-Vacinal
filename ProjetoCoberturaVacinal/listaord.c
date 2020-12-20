/* listaord.c
 *
 * Implementação das operações sobre o TAD lista encadeada ordenada adaptada
 * para um hash map.
 *
 * Felipe Ferreira
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"
#include "hashmap.h"
#include "listaord.h"
#include "avl.h"

void lst_init(map_ptr * l)
{
	*l = NULL;
}

int lst_size(map_ptr l)
{
	int cont = 0;
	while (l != NULL) {
		cont++;
		l = l->prox;
	}
	return cont;
}

bool lst_isempty(map_ptr l)
{
	return l == NULL;
}

void lst_ins(map_ptr * l, map_key key, map_value val)
{
	map_ptr n;
	if (*l == NULL || strcmp(key, (*l)->key) < 0) {
		if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		strcpy(n->key, key);
		if ((n->value = (map_value *) malloc(sizeof(map_value))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		n->value = val;
		n->prox = *l;
		*l = n;
	}
	else {
		map_ptr p = *l;
		while (p->prox != NULL && strcmp(p->prox->key, key) < 0)
			p = p->prox;
		if (strcmp(p->key, key) != 0 && (p->prox == NULL || strcmp(p->prox->key, key) != 0)) {
			if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			strcpy(n->key, key);
			if ((n->value = (map_value *) malloc(sizeof(map_value))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			n->value = val;
			n->prox = p->prox;
			p->prox = n;
		}
		else { // já existe na lista, atualiza seu valor
			(*l)->value = val;
		}
	}
}

void lst_print(map_ptr l)
{
	while (l != NULL) {
		//printf("(%s, %s) ", l->key, char * (l->value->nomeMunicipio));
		l = l->prox;
	}
}


/* método do meio do quadrado para chaves alfanuméricas*/
int f(map_key key)
{
	int i, soma = 0;
	// converte a chave para um inteiro
	for (i = 0; key[i] != '\0'; i++) {
		soma += key[i] << (i % 8);
	}

	// meio do quadrado
	soma *= soma;
	int x = log10(M) / log10(2);
	int desl = (NUM_BITS - x) / 2;
	soma >>= desl;
	return soma & ((int) pow(2, x) - 1);
}


map_value busca_coberturaVacinal_HashMap(hash_map m, map_key key)
{
    int k = f(key);
    //printf("\n>>>key %s, encaixe %d\n\n",  key, k);
    if (m != NULL && strcmp(key, "110001") > 0) {
        strcmp(m[k]->value, key);
        map_ptr x = lst_busca(m[k], key);
        if (x == NULL){
                printf("\n>> O codigo do município informado, nao foi encontrado!\n");
                return;
        }
        avl_info * ptr =  x->value;
        printf("\nResultado: ");
        printf("[%s; %s; %s]\n", ptr->nomeMunicipio, ptr->codigoMunicipio, ptr->coberturaVacinal);
    }
}

map_ptr lst_busca(map_ptr l, map_key key)
{
    while (l != NULL && strcmp(key, l->key) > 0) {
        l = l->prox;
    }
    if (l != NULL && strcmp(key, l->key) == 0) {
        return l;
    }
    return NULL;
}
