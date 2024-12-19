#include "user.h"
#include "./../ADT/mesinkata/mesinkata.h"
#include <stdio.h>

void CreateUser(User *u, char name[], char password[], int money) {
    CopyString(u->name, name);
    CopyString(u->password, password);
    u->money = money;
    initMap(&u->keranjang);
    initStack(&u->riwayat_pembelian);
    ll_initList(&u->wishlist);
    
}

boolean CompareUser(User u1, User u2) {
    return (str_compare(u1.name,u2.name));
}

void DeleteUser(User *u) {
    u->name[0] = '\0';
    u->password[0] = '\0';
    u->money = 0;
    ll_freeList(&u->wishlist);
    u->keranjang.neff = 0;
}
/* 
    List Statis User
 */
void us_initList(SList *list) {
    s_initList(list);
}
void us_addItem(SList *list, User *item) {
    s_addItem(list, item, sizeof(User));
}
void us_insertItem(SList *list, size_t index, User *item) {
    s_insertItem(list,index,item,sizeof(User));
}
void us_removeItem(SList *list, size_t index) {
    s_removeItem(list,index);
}
User* us_getItem(SList *list, size_t index) {
    return s_getItem(list,index);
}
void us_setItem(SList *list, size_t index, User *item) {
    s_setItem(list,index,item,sizeof(User));
}
void us_clearList(SList *list) {
    s_clearList(list);
}

void us_ReadUser(SList *userList) {
    ADVWORD();
    int uang_user = WordToInt(currentWord);

    ADVWORD();
    char nama_user[STR_MAX];
    CopyString(nama_user,currentWord.TabWord);

    ADVWORD();
    char password_user[STR_MAX];
    CopyString(password_user,currentWord.TabWord);
    
    User user;
    CreateUser(&user,nama_user,password_user,uang_user);

    ADVWORD();
    int jumlah_riwayat_pembelian = WordToInt(currentWord);
    for (int i = 0; i < jumlah_riwayat_pembelian; i++) {
        ADVWORD();
        int total_biaya = WordToInt(currentWord);
        ADVSENTENCENL();
        char* namabarang = str_copy(currentWord.TabWord);
        Riwayat currentRiwayat = newRiwayat(namabarang, total_biaya);
        stack_push(&user.riwayat_pembelian,currentRiwayat);
    }
    ADVWORD();
    int jumlah_wishlist = WordToInt(currentWord);
    for (int i = 0; i < jumlah_wishlist; i++) {
        ADVSENTENCENL();
        char* nama_barang = str_copy(currentWord.TabWord);
        ll_insert(&user.wishlist,nama_barang);
    }
    us_addItem(userList, &user);
}
void us_WriteUsers(SList *users, FILE *file) {
    fprintf(file, "%zu\n", users->size);
    for (size_t i = 0; i < users->size; i++) {
        User *user = (User *)users->items[i];
        fprintf(file, "%d %s %s\n", user->money, user->name, user->password);
        int jumlah_riwayat = user->riwayat_pembelian.top+1;
        fprintf(file, "%d",jumlah_riwayat);
        print_stackToFile(&user->riwayat_pembelian,file);
        int jumlah_wishlist = ll_count(&user->wishlist);
        ll_printToFile(&user->wishlist,file);
    }
}

boolean us_isUserin(SList *userList, User *user) {
    int size = userList->size;
    for (int i = 0; i < size; i++) {
        User *out = us_getItem(userList,i);
        if (str_compare(user->name,out->name)) {
            return true;
        }
    }
    return false;
}

size_t us_search(SList *userList, User *user) {
    for (int i = 0;i<userList->size;i++) {
        if (str_compare(us_getItem(userList,i)->name,user->name)) {
            return i;
        }
    }
    return -1;
}