#include "startnload.h"

void STARTPROGRAM(SList *users, DList **items, char *filename) {
    STARTWORD(filename);
    // Menginput item
    int num_of_items = WordToInt(currentWord);
    *items = id_createList();
    for (int i = 0; i < num_of_items; i++) {
        ReadItem(*items);
    }
    // Menginput user
    ADVWORD();
    int num_of_users = WordToInt(currentWord);
    us_initList(users);
    for (int i = 0; i < num_of_users; i++) {
        ReadUser(users);
    }
}