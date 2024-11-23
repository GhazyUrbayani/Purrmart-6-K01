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
        
        } else if (str_compare(STRING(currentWord),"LOAD")) {
            ADVWORD();
            char *filename = str_concat(STRING(currentWord),"");
            int result = STARTPROGRAM(&user_list,&item_list,filename);
            if (result) {
                printf("File %s berhasil di-load.\n", filename);
            } else {
                printf("File %s gagal di-load.\n", filename);
            }

        } else if (str_compare(STRING(currentWord),"REGISTER")) {
            printf("Masukkan username: ");
            ADVWORD();
            Word username = currentWord;
            printf("Masukkan password: ");
            ADVWORD();
            Word password = currentWord;
            User candidate; CreateUser(&candidate,STRING(username),STRING(password),0);
            user_register(&user_list,&candidate);

        } else if (str_compare(STRING(currentWord),"LOGIN")) {
            printf("Masukkan username: ");
            ADVWORD();
            Word username = currentWord;
            printf("Masukkan password: ");
            ADVWORD();
            Word password = currentWord;
            login(&user_list,&logged_user,STRING(username),STRING(password));

        } else if (str_compare(STRING(currentWord),"SAVE")) {
            printf("Masukkan nama file: ");
            ADVWORD();
            char *filename = STRING(currentWord);
            SAVE(&user_list,item_list,filename);
        }
        printf("Masukkan command: ");
        STARTWORDINPUT();
    }
}
