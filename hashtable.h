#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "node.h"

#define MOD 1000000

typedef struct hash_table{
  bst * arr[MOD];
}hash_table;

hash_table * hash_table_create();
void hash_table_add(hash_table *h, char * word);
node* hash_table_find(hash_table *h, char * word);