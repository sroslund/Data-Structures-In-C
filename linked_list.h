#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

typedef struct linked_list{
  node * head;
  node * tail;
  int count;
}linked_list;

linked_list * linked_list_create();
void linked_list_push(linked_list *l, char * word);
void linked_list_push_back(linked_list *l, char * word);
node * linked_list_find(linked_list *l, char * word);
void linked_list_remove(linked_list *l, node * target);
int linked_list_size(linked_list *l);
void linked_list_destroy(linked_list *l);
void linked_list_print(linked_list *l);