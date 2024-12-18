#include <stdio.h>
#include <stdlib.h>
#include "wishlist_remove.h"

void wishlist_remove_index(LinkedList* wishlist, int index) 
{
    if (index < 1 || index > ll_count(wishlist)) 
    {
        printf("Penghapusan barang WISHLIST gagal dilakukan, index tidak valid!\n");
        return;
    }

    linkednode* current = wishlist->head;
    int currentIndex = 1;

    while (current != NULL && currentIndex < index) 
    {
        current = current->next;
        currentIndex++;
    }

    if (current != NULL) 
    {
        if (current->prev != NULL) 
        {
            current->prev->next = current->next;
        } 
        else 
        {
            wishlist->head = current->next;
        }

        if (current->next != NULL) 
        {
            current->next->prev = current->prev;
        }

        free(current->key);
        free(current);

        printf("Berhasil menghapus barang posisi ke-%d dari wishlist!\n", index);
    } 
    else 
    {
        printf("Penghapusan barang WISHLIST gagal dilakukan, index tidak valid!\n");
    }
}

void wishlist_remove_name(LinkedList* wishlist, char* name) 
{
    linkednode* current = wishlist->head;

    while (current != NULL) 
    {
        if (str_compare(current->key, name)) 
        {
            if (current->prev != NULL) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                wishlist->head = current->next;
            }

            if (current->next != NULL) 
            {
                current->next->prev = current->prev;
            }

            free(current->key);
            free(current);

            printf("%s berhasil dihapus dari WISHLIST!\n", name);
            return;
        }
        current = current->next;
    }

    printf("Penghapusan barang WISHLIST gagal dilakukan, %s tidak ada di WISHLIST!\n", name);
}
