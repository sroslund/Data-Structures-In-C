#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"
#include "bst.h"
#include "hashtable.h"

int main(void) {
  linked_list * l = linked_list_create();
  bst * b = bst_create();
  hash_table * h = hash_table_create();
  
  char * word;
  size_t len;
  FILE * fp = fopen("words.txt","r");

  while (getline(&word, &len, fp) != -1) {
    linked_list_push(l, word);
    bst_add(b,word);
    hash_table_add(h,word);
  }

  fclose(fp);

  FILE * fp_2 = fopen("lookups.txt","r");

  clock_t hash_table_time = clock();
  while (getline(&word, &len, fp_2) != -1) {
    hash_table_find(h,word);
  }
  hash_table_time = clock() - hash_table_time;

  printf("Hash Table time: %f\n",((double)hash_table_time)/CLOCKS_PER_SEC);

  fseek(fp_2,0,SEEK_SET);
  clock_t bst_time = clock();
  while (getline(&word, &len, fp_2) != -1) {
    bst_find(b,word);
  }
  bst_time = clock() - bst_time;

  printf("Binary Search Tree time: %f\n",((double)bst_time)/CLOCKS_PER_SEC);

  fseek(fp_2,0,SEEK_SET);
  clock_t unsorted_list_time = clock();
  while (getline(&word, &len, fp_2) != -1) {
    linked_list_find(l, word);
  }
  unsorted_list_time = clock() - unsorted_list_time;

  fclose(fp_2);

  printf("Unsorted List time: %f\n",((double)unsorted_list_time)/CLOCKS_PER_SEC);

  return 0;
}