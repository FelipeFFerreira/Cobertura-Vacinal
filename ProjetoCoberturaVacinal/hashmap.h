/* hashmap.h
 *
 * Defeni��o do TAD hash_map e prot�tipos de suas opera��es
 *
 * Felipe Ferreira
*/
#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdbool.h>
#define M 1024  // n�mero de encaixes da tabela de hashing
#define NUM_BITS 16
#define MAX_DEF 21
#define MAX_WORD 30

typedef char map_key[MAX_WORD + 1];

typedef void *  map_value; //ref endere�o logico

typedef struct map_node * map_ptr;


struct map_node {
    map_key key;
    map_value value; //endere�o
    map_ptr prox;
};

typedef map_ptr hash_map[M];

/*
 * Fun��o que inicializa o hash map.
 */
void map_init(hash_map);

/*
 * Fun��o que devolve o n�mero de elementos do hash mapa.
 */
int map_size(hash_map);

/*
 * Fun��o que devolve verdadeiro se o hash map estiver vazio.
 */
bool map_isempty(hash_map);

/*
 * Fun��o que devolve o endere�o do valor associado a chave no mapa,
 * caso a chave esteja contida no mapa, ou NULL, caso contr�rio.
 */
map_value * map_get(hash_map, map_key);

/*
 * Fun��o que insere a entrada (chave, valor) no mapa se mapa n�o possuir
 * um entrada para a chave.
 */
void map_put(hash_map, map_key, map_value);

/*
 * Fun��o que remove a entrada (chave, valor) do mapa e devolve o endere�o
 * do valor, caso a chave esteja contido no mapa, ou NULL, caso contr�rio.
 */
map_value * map_remove(hash_map, map_key);

/*
 * Fun��o de hashing que utiliza o m�todo do meio do quadrado.
 */
int h(map_key);

/*
 * Fun��o que imprime todas as entradas do hash map .
 */
void map_print(hash_map);

/*
 * Fun��o que destr�i o hash_map.
 */
void map_kill(hash_map);

#endif // _HASHMAP_H

