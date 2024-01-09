#ifndef HASHTABLE_C
#define HASHTABLE_C

#include "stddef.h"

// Bundle the data
typedef struct hashtable_t* HashTable;

// Initialization and Destroying
HashTable createTable();
void      destroyTable(HashTable table);

// Methods
size_t  tableGetSize(HashTable table);
void    tableInsert(HashTable table, void* key, void* value);
void*   tableSearch(HashTable table, void* key);
void    tableDelete(HashTable table, void* key);

// prints the whole table as { key : value } 
void tablePrint(HashTable table);
#endif
