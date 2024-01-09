#include "stdio.h"

#include "../headers/hashtable.h"

int main() {
  HashTable table = createTable();
  if(table) {printf("createtable - success");}
  printf("table size: %zu", tableGetSize(table));
  printf("hello world");
  return 0;
}
