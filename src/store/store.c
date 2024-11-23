#include "store.h"

void store_list(DList *item_list) {
    for (int i = 0; i < item_list->size; i++) {
        printf("%d. %s\n", i, id_getItem(item_list,i)->name);
    }
}
