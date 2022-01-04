#pragma once

#include <string.h>

typedef struct node{
  char word[30];
  struct node * left;
  struct node * right;
}node;

void node_set(node * n,char * word);