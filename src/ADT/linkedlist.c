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
    linkednode* current_node = l->head;
    while (current_node != NULL) {
        if (str_compare(current_node->key,key)) {
            return current_node;
        }
    }
    return current_node;
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
    ll_printToFile(l,stdout);
}

void ll_freeList(LinkedList* l) {
    // Mulai di head
    linkednode* cursor = l->head;
    while (cursor != NULL) {
        // Selama cursor bukan NIL
        // Simpan next-nya di suatu variabel dulu
        linkednode* nextcursor = cursor->next;

        // Free char*-nya
        free(cursor->key);
        // Free alokasi node-nya
        free(cursor);
        
        // Ke node selanjutnya
        cursor = nextcursor;
    }
    l->head = NULL;
}

void ll_printToFile(LinkedList* l, FILE* stream) {
    if (ll_isEmpty(l)) {
        return;
    } else {
        linkednode* currentnode = l->head;
        while (currentnode != NULL) {
            fprintf(stream,"%s\n", currentnode->key);
            currentnode = currentnode->next;
        }
    }
}

boolean ll_isEmpty(LinkedList* l) {
    return l->head == NULL;
}

int ll_count(LinkedList* list) {
    int count = 0;
    if (!ll_isEmpty(list)) {
        linkednode* currentnode = list->head;
        while(currentnode != NULL) {
            count++;
            currentnode = currentnode->next;
        }
    }
    return count;
}