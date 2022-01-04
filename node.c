#include "node.h"

void node_set(node * n,char * word){
  strcpy(n->word,word);
}