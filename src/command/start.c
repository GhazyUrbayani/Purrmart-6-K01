#include "../ADT/Mesin Karakter/mesinkarakter.h"
#include "../ADT/Mesin Kata/mesinkata.h"
#include "../ADT/ListDin/listdinstring.h"
#include "../ADT/List Statis/liststatuser.h"
#include <stdio.h>
#include <stdlib.h>

void STARTPROGRAM(ListUser *users, ListBarang *items, char *filename) {
    STARTWORD(filename);
    CreateListDin(items, 100);
    int jumlahBarang = WordToInt(currentWord);
    items->neff = jumlahBarang;
    for (int i = 0; i < jumlahBarang; i++) {
        ADVWORD();
        items->barang[i].price = WordToInt(currentWord);
        ADVSENTENCENL();
        for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            items->barang[i].name[j] = currentWord.TabWord[j];
        }
        items->barang[i].name[currentWord.Length] = '\0';
    }
    ADVWORD();
    CreateListStatUser(users);
    int jumlahUser = WordToInt(currentWord);
    users->neff = jumlahUser;
    for (int i = 0;i<jumlahUser;i++){
    ADVWORD(); 
    users->users[i].money = WordToInt(currentWord);
    ADVWORD();
    for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            users->users[i].name[j] = currentWord.TabWord[j];
        }
    users->users[i].name[currentWord.Length] = '\0';
    ADVWORD();
    for (int j = 0; j < currentWord.Length && j < MAX_LEN - 1; j++) {
            users->users[i].password[j] = currentWord.TabWord[j];
        }
    users->users[i].password[currentWord.Length] = '\0'; 
    }
}