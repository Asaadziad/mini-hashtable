/*
 * Hashtable implementing the seperate chaining solution for collision
 * */

#include "../headers/hashtable.h"
#include "stdio.h"
#include "stdlib.h"


#define INITIAL_LEN 10

typedef struct entry_t* Entry;

struct entry_t {
  void* key;
  void* value;
  Entry next;
};

Entry createEntry(void* key, void* value) {
  Entry entry = NULL;
  if(!key || !value){
    fprintf(stderr,"Null Arguments");
    return entry;
  } 

  entry = (Entry)malloc(sizeof(*entry));
  if(!entry) {
    fprintf(stderr, "Couldn't Allocate memory for Entry");
    return entry;
  } 
  
  entry->key   = key;
  entry->value = value; 
  entry->next  = NULL;
  return entry;
}

void destroyEntry(Entry e) {
  free(e->key);
  free(e->value);
  e->next = NULL;
  free(e);
}

struct hashtable_t {
  size_t size;
  Entry* entries; // Array of ptrs to lists
  void (*printElement)(Entry);
};


// Allocates memory and returns an empty table
HashTable createTable() {
  HashTable t = (HashTable)malloc( sizeof(*t) );
  if(!t) return NULL;
  
  t->entries = malloc(sizeof(Entry) * INITIAL_LEN);
  if(!t->entries) return NULL;
  
  t->size = 0;
  
  return t;
}

void destroyTable(HashTable table) {
  for(int i = 0; i < table->size; i++) {
    Entry current = table->entries[i];
    while(current) {
      Entry tmp = current->next;
      destroyEntry(current);
      current = tmp;
    } 
  }
  free(table);
}

size_t tableGetSize(HashTable table) {
  if(!table) return 0;
  return table->size;
}

void tablePrint(HashTable table) {
  for(int i = 0; i < table->size ; i++) {
    Entry current = table->entries[i];
    while(current) {
      Entry tmp = current->next;
      table->printElement(tmp);
      current = tmp;
    }
  }
}


