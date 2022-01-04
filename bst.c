#include "bst.h"

bst * bst_create(){
  bst *b = (bst *) calloc(1,sizeof(bst));
  return b;
}

bool bst_add(bst *b, char * word){
  node * p = b->root;
  if(p == NULL){
    node * n = (node *) calloc(1,sizeof(node));
    node_set(n,word);
    b->root = n;
    return true;
  }
  while(1){
    if(!strcmp(word,p->word)){
      return false;
    } else if(strcmp(word,p->word) < 0){
      if(p->left == NULL){
        node * n = (node *) calloc(1,sizeof(node));
        node_set(n,word);
        p->left = n;
        return true;
      }
      p = p->left;
    } else {
      if(p->right == NULL){
        node * n = (node *) calloc(1,sizeof(node));
        node_set(n,word);
        p->right = n;
        return true;
      }
      p = p->right;
    }
  }
}

node * bst_find(bst *b, char * word){
  node * p = b->root;
  while(1){
    if(p == NULL || !strcmp(p->word,word)){
      return p;
    } else if(strcmp(word,p->word) < 0){
      p = p->left;
    } else {
      p = p->right;
    }
  }
}

void node_destroy(node *n){
  if(n != NULL){
    node_destroy(n->left);
    node_destroy(n->right);
    free(n);
  }
}

void bst_destroy(bst *b){
  node_destroy(b->root);
  free(b);
}
