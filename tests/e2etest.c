#include "./../src/structs/item.h"
#include "./../src/structs/user.h"
#include "./../src/command/startnload.h"
#include "./../src/command/save.h"
#include <stdio.h>

int main(void) {
    SList user_list;
    DList* item_list;
    Queue req_list;
    printf("\nEnter command:\n>> ");
    STARTINPUT();
    while (1) {
        if (WordEqual(stringToWord("START"))) {
            STARTPROGRAM(&user_list,&item_list,"./save/config.txt");
            break;
        }
        ADVWORD();
    }
    printf("First item: %s\n", *item_list->items);
    printf("First user: %s", *user_list.items);

    User new_user;
    CreateUser(&new_user,"faiz","alfikrona",500);
    Item new_item;
    CreateItem(&new_item,"Buku Algoritma dan Struktur Data",500);
    us_addItem(&user_list,&new_user);
    id_addItem(item_list,&new_item);
    SAVE(&user_list,item_list,"./save/bismillah works.txt");
    return 0;
}