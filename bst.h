#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"

typedef struct bst{
  node * root;
  int count;
}bst;

bst * bst_create();
bool bst_add(bst *b, char * word);
node * bst_find(bst *b, char * word);
void node_destroy(node *n);
void bst_destroy(bst *b);