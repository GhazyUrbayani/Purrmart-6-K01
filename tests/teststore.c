#include "./../src/store/store.h"
#include "./../src/structs/item.h"
#include "./../src/command/startnload.h"

int main(void) {
    SList user_list; us_initList(&user_list);
    DList *item_list = id_createList();
    STARTPROGRAM(&user_list,&item_list,"teststore.txt");
    store_list(item_list);
    return 0;
}