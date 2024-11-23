#include "listen.h"
#include <stdio.h>

void listen(void) {
    // User and Item list
    SList user_list; us_initList(&user_list);       // List of users
    DList *item_list = id_createList();             // List of items
    Queue item_request; iinitQueue(&item_request);  // Queue of items

    // Logged user
    User logged_user;
    CreateUser(&logged_user,"","",0);

    boolean started = false;

    // Proses
    printf("Masukkan command: ");
    STARTWORDINPUT();
    while (!WordEqual(stringToWord("EXIT"))) {
        if (str_compare(STRING(currentWord),"START")) {
            int result = STARTPROGRAM(&user_list,&item_list,"config.txt");
            if (result) {
                printf("Berhasil memulai dengan config default!\n");
            } else {
                printf("Gagal memulai dengan config default!\n");
            }
            started = true;
        
        } else if (str_compare(STRING(currentWord),"LOAD")) {
            ADVWORD();
            char *filename = str_concat(STRING(currentWord),"");
            int result = STARTPROGRAM(&user_list,&item_list,filename);
            if (result) {
                printf("File %s berhasil di-load.\n", filename);
            } else {
                printf("File %s gagal di-load.\n", filename);
            }
            started = true;
        } else if (started && str_compare(STRING(currentWord),"REGISTER")) {
            printf("Masukkan username: ");
            ADVWORD();
            Word username = currentWord;
            printf("Masukkan password: ");
            ADVWORD();
            Word password = currentWord;
            User candidate; CreateUser(&candidate,STRING(username),STRING(password),0);
            user_register(&user_list,&candidate);

        } else if (started && str_compare(STRING(currentWord),"LOGIN")) {
            printf("Masukkan username: ");
            ADVWORD();
            Word username = currentWord;
            printf("Masukkan password: ");
            ADVWORD();
            Word password = currentWord;
            login(&user_list,&logged_user,STRING(username),STRING(password));

        } else if (started && str_compare(STRING(currentWord),"SAVE")) {
            printf("Masukkan nama file: ");
            ADVWORD();
            char *filename = STRING(currentWord);
            SAVE(&user_list,item_list,filename);
        } else if (started && str_compare(STRING(currentWord),"STORE")) {
            ADVWORD();
            if (str_compare(STRING(currentWord),"LIST")) {
                store_list(item_list);
            } else if (str_compare(STRING(currentWord),"REQUEST")) {
                printf("Nama barang yang ingin di-request: ");
                STARTWORDINPUT();
                char *barang;
                CopyString(barang,STRING(currentWord));
                int hasil = store_req(&item_request,item_list,barang);
                if (hasil) {
                    printf("Berhasil me-request %s\n", barang);
                } else {
                    printf("Gagal me-request %s\n", barang);
                }
            } else if (str_compare(STRING(currentWord),"SUPPLY")) {
                store_supply(&item_request,item_list);
            } else if (str_compare(STRING(currentWord),"REMOVE")) {
                printf("Nama barang yang akan dihapus: ");
                STARTSENTENCEINPUT();
                char* namabarang = (char*) malloc (currentWord.Length + 1);
                CopyString(namabarang,STRING(currentWord));
                printf("berhasil kopi\n");
                boolean hasil = store_remove(item_list,namabarang);
                if (hasil) {
                    printf("Berhasil menghapus %s dari store.\n", namabarang);
                } else {
                    printf("Gagal menghapus %s dari store (Tidak ada %s di toko!).\n", namabarang, namabarang);
                }
            }
        }
        // DI LUAR COMMAND TREE
        printf("Masukkan command: ");
        STARTWORDINPUT();
    }
    // DI LUAR LOOP
}
