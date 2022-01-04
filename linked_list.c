#include "linked_list.h"

linked_list * linked_list_create(){
  linked_list *l = (linked_list*) calloc(1,sizeof(linked_list));
  return l;
}

void linked_list_push(linked_list *l, char * word){
  node * new_node = (node *) calloc(1,sizeof(node));
  if(l->head == NULL){
    l->head = new_node;
    l->tail = new_node;
    return;
  }
  l->head->left = new_node;
  new_node->right = l->head;
  node_set(new_node,word);
  l->head = new_node;
  l->count++;
}


node * linked_list_find(linked_list *l, char * word){
  node * pointer = l->head;
  while(pointer != NULL){
    if(!strcmp(pointer->word, word)){
      return pointer;
    }
    pointer = pointer->right;
  }
  return NULL;
}

void linked_list_remove(linked_list *l, node * target){
  if(target == l->head && target == l->tail){
    l->head = NULL;
    l->tail = NULL;
  } else if(target == l->head){
    l->head = l->head->right;
    l->head->left = NULL;
  } else if(target == l->tail){
    l->tail = l->tail->left;
    l->tail->right = NULL;
  } else {
    target->left->right = target->right;
    target->right->left = target->left;
  }
  free(target);
}

int linked_list_size(linked_list *l){
  return l->count;
}

void linked_list_destroy(linked_list *l){
  node * pointer = l->head;
  while(pointer != NULL){
    node * temp = pointer;
    pointer = pointer->right;
    free(temp);
  }
  free(l);
}

void linked_list_print(linked_list *l){
  node * pointer = l->head;
  while(pointer != NULL){
    printf("%s - ",pointer->word);
    pointer = pointer->right;
  }
  printf("\n");
}