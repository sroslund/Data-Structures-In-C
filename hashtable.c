#include "hashtable.h"

int hash(char * word){
  int sum = 0;
  for(int i=0;i<strlen(word);i++){
    sum += word[i];
  }
  return sum % MOD;
}

hash_table * hash_table_create(){
  hash_table * h = (hash_table *)calloc(1,sizeof(hash_table));
  for(int i=0;i<MOD;i++){
    h->arr[i] = bst_create();
  }
  return h;
}

void hash_table_add(hash_table *h, char * word){
  int index = hash(word);
  bst_add(h->arr[index],word);
}

node* hash_table_find(hash_table *h, char * word){
  int index = hash(word);
  return bst_find(h->arr[index],word);
}