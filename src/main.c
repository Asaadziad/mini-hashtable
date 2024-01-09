#include "stdio.h"

#include "../headers/hashtable.h"

int main() {
  HashTable table = createTable();
  if(table) {printf("createtable - success");}
  printf("table size: %zu\n", tableGetSize(table));
  int t = 2;
  tableInsert(table,"asaad",&t);
  tableInsert(table,"aya",&t);
  tableInsert(table,"arwa",&t);
  tableInsert(table,"ziad",&t);
  tableInsert(table,"manal",&t);

  tableInsert(table,"llola",&t);
  tableInsert(table,"asaad2",&t);
  tableInsert(table,"dell",&t);
  tableInsert(table,"linux",&t);
  tableInsert(table,"windows",&t);

  int* value = tableSearch(table, "asaad");
  printf("%d\n", *value);
  tablePrint(table); 

  tableDelete(table, "linux");
  tableDelete(table, "windows");
  tableDelete(table, "manal");

  tablePrint(table);
  return 0;
}
