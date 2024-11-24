#include "./../src/structs/item.h"

int main(void) {
    printf("\n=== *** Test Start *** ===\n");

    printf("\nTC 01 : Buat list item\n");
    DList *item_list = id_createList();
    printf("Terbentuk list dinamis dengan ukuran %d dan kapasitas %d\n",item_list->size,item_list->capacity);

    printf("\nTC 02 : Add item ke list item\n");
    Item test; CreateItem(&test,"Test",80);
    id_addItem(item_list,&test);
    printf("Menambahkan item dengan nama %s dengan harga %d\n", test.name, test.price);
    printf("Ukuran list sekarang adalah %d\n", item_list->size);

    printf("\nTC 03 : Get item dari list_item\n");
    printf("Mengambil item dengan indeks %d\n", 0);
    Item *ipointer = id_getItem(item_list,0);
    printf("Item dengan indeks %d memiliki nama %s, dan harga %d\n", 0, ipointer->name, ipointer->price);

    printf("\nTC 04 : Delete item dari list_item\n");
    id_removeItem(item_list,0);
    printf("Ukuran list sekarang adalah %d\n", item_list->size);

    return 0;
}