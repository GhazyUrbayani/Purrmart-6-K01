#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "boolean.h"
#include <stdio.h>

typedef struct linkednode {
    struct linkednode* prev;
    struct linkednode* next;
    char* key;
} linkednode;

typedef char* wishlist;

typedef struct LinkedList {
    linkednode* head;
} LinkedList;

void ll_initList(LinkedList* list);

void ll_insert(LinkedList* l, char* key);

linkednode* ll_search(LinkedList* list, char* key);

void ll_delete(LinkedList* list, char* key);

void ll_printList(LinkedList* list);

void ll_freeList(LinkedList* list);

void ll_printToFile(LinkedList* list, FILE* stream);

boolean ll_isEmpty(LinkedList* list);

int ll_count(LinkedList* list);

#endif