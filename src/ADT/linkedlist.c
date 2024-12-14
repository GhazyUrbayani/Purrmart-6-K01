#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils.h"

void ll_initList(LinkedList* l) {
    l->head = NULL;
}

void ll_insert(LinkedList* l, char* key) {
    linkednode* new = malloc(sizeof(linkednode));
    new->next = l->head;
    new->prev = NULL;
    new->key = alokasi_salin(key,str_len(key)+1);
    
    l->head = new;
}

linkednode* ll_search(LinkedList* l, char* key) {
    linkednode* cursor = l->head;
    while (cursor != NULL) {
        if (str_compare(cursor->key,key)) {
            return cursor;
        }
    }
    return cursor;
}

void ll_delete(LinkedList* l, char* key) {
    // Cari apakah key sudah ada
    linkednode* cursor = ll_search(l,key);
    if (cursor != NULL) {
        // Key ada
        
        if (cursor->prev != NULL) {
            // Kasus 1. Key merupakan elemen pertama list
            cursor->prev->next = cursor->next;
        } else {
            // Kasus 2. Key bukan elemen pertama list
            l->head = cursor->next;
        }
        if (cursor->next != NULL) {
            // Key bukan elemen terakhir, update next-nya
            cursor->next->prev = cursor->prev;
        }
    }
}

void ll_printList(LinkedList* l) {
    linkednode* cursor = l->head;
    int count = 1;
    while (cursor != NULL) {
        printf("%d. %s\n", count, cursor->key);
        count++; cursor = cursor->next;
    }
}

void ll_freeList(LinkedList* l) {
    linkednode* cursor = l->head;
    while (cursor != NULL) {
        linkednode* nextcursor = cursor->next;
        free(cursor->key);
        free(cursor);
        cursor = nextcursor;
    }
    l->head = NULL;
}