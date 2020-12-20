/* hashmap.h
 *
 * Defenição do TAD hash_map e protótipos de suas operações
 *
 * Felipe Ferreira
*/
#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdbool.h>
#define M 1024  // número de encaixes da tabela de hashing
#define NUM_BITS 16
#define MAX_DEF 21
#define MAX_WORD 30

typedef char map_key[MAX_WORD + 1];

typedef void *  map_value; //ref endereço logico

typedef struct map_node * map_ptr;


struct map_node {
    map_key key;
    map_value value; //endereço
    map_ptr prox;
};

typedef map_ptr hash_map[M];

/*
 * Função que inicializa o hash map.
 */
void map_init(hash_map);

/*
 * Função que devolve o número de elementos do hash mapa.
 */
int map_size(hash_map);

/*
 * Função que devolve verdadeiro se o hash map estiver vazio.
 */
bool map_isempty(hash_map);

/*
 * Função que devolve o endereço do valor associado a chave no mapa,
 * caso a chave esteja contida no mapa, ou NULL, caso contrário.
 */
map_value * map_get(hash_map, map_key);

/*
 * Função que insere a entrada (chave, valor) no mapa se mapa não possuir
 * um entrada para a chave.
 */
void map_put(hash_map, map_key, map_value);

/*
 * Função que remove a entrada (chave, valor) do mapa e devolve o endereço
 * do valor, caso a chave esteja contido no mapa, ou NULL, caso contrário.
 */
map_value * map_remove(hash_map, map_key);

/*
 * Função de hashing que utiliza o método do meio do quadrado.
 */
int h(map_key);

/*
 * Função que imprime todas as entradas do hash map .
 */
void map_print(hash_map);

/*
 * Função que destrói o hash_map.
 */
void map_kill(hash_map);

#endif // _HASHMAP_H

