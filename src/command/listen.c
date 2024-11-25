#include "listen.h"
#include <stdio.h>

// Function Definition
void listen(void) {
    // ** Initialization ** //
    SList user_list;
    us_initList(&user_list);               // Initialize user list

    DList *item_list = id_createList();    // Initialize item list
    Queue item_request;
    iinitQueue(&item_request);             // Initialize item request queue

    User logged_user;                      // Initialize logged user
    CreateUser(&logged_user, "", "", 0);

    boolean started = false;               // Program start state

    // ** Command Input Loop ** //
    printf("Masukkan command (HELP jika butuh arahan): ");
    STARTSENTENCEINPUT();

    while (!WordEqual(stringToWord("EXIT"))) {
        // ** START Command ** //
        if (str_compare(STRING(currentWord), "START")) {
            int result = STARTPROGRAM(&user_list, &item_list, "config.txt");
            printf(result ? 
                "Berhasil memulai dengan config default!\n" :
                "Gagal memulai dengan config default!\n");
            started = true;

        // ** LOAD Command ** //
        } else if (str_compare(STRING(currentWord), "LOAD")) {
            printf("Masukkan nama file: ");
            ADVWORD();
            char *filename = str_concat(STRING(currentWord), "");
            int result = STARTPROGRAM(&user_list, &item_list, filename);
            printf(result ?
                "File %s berhasil di-load.\n" :
                "File %s gagal di-load.\n", filename);
            started = true;

        // ** REGISTER Command ** //
        } else if (started && str_compare(STRING(currentWord), "REGISTER")) {
            printf("\nUser dan password hanya satu kata, sehingga hanya kata pertama yang akan dihiraukan.\n");
            printf("Masukkan username: ");
            STARTWORDINPUT();
            Word username = currentWord;

            printf("Masukkan password: ");
            STARTWORDINPUT();
            Word password = currentWord;

            User candidate;
            CreateUser(&candidate, STRING(username), STRING(password), 0);
            user_register(&user_list, &candidate);

        // ** LOGIN Command ** //
        } else if (started && str_compare(STRING(currentWord), "LOGIN")) {
            printf("\nUser dan password hanya satu kata, sehingga hanya kata pertama yang akan dihiraukan.\n");
            printf("Masukkan username: ");
            STARTWORDINPUT();
            Word username = currentWord;
            printf("Masukkan password: ");
            STARTWORDINPUT();
            Word password = currentWord;

            login(&user_list, &logged_user, STRING(username), STRING(password));

        // ** HELP Command ** //
        } else if (str_compare(STRING(currentWord), "HELP")) {
            help(started,isLoggedIn(&logged_user));
            
        // ** LOGOUT Command ** //
        } else if (started && str_compare(STRING(currentWord), "LOGOUT")) {
            logout(&logged_user);

        // ** SAVE Command ** //
        } else if (started && str_compare(STRING(currentWord), "SAVE")) {
            printf("Masukkan nama file: ");
            STARTWORDINPUT();
            char *filename = alokasi_salin(STRING(currentWord),currentWord.Length+1);
            SAVE(&user_list, item_list, filename);
            free(filename);

        // ** STORE LIST Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE LIST")) {
            store_list(item_list);

        // ** STORE REQUEST Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE REQUEST")) {
            printf("Nama barang yang ingin di-request: ");
            STARTWORDINPUT();

            char *barang = alokasi_salin(STRING(currentWord),currentWord.Length+1);

            int hasil = store_req(&item_request, item_list, barang);
            printf(hasil ?
                "Berhasil me-request %s\n" :
                "Gagal me-request %s\n", barang);
            free(barang);

        // ** STORE SUPPLY Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE SUPPLY")) {
            store_supply(&item_request, item_list);

        // ** STORE REMOVE Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE REMOVE")) {
            printf("Nama barang yang akan dihapus: ");
            STARTSENTENCEINPUT();

            char *namabarang = alokasi_salin(STRING(currentWord),currentWord.Length+1);

            boolean hasil = store_remove(item_list, namabarang);
            printf(hasil ? 
                "Berhasil menghapus %s dari store.\n" :
                "Gagal menghapus %s dari store (Tidak ada %s di toko!).\n", namabarang, namabarang);
            free(namabarang);

        // ** WORK CHALLENGE Command ** //
        } else if (started && isLoggedIn(&logged_user) &&
                   str_compare(STRING(currentWord), "WORK CHALLENGE")) {
            printf("Daftar challenge yang tersedia:\n");
            printf("1. Tebak Angka (biaya main = 200)\n");
            printf("2. WORDLE (biaya main = 500)\n\n");
            printf("Masukkan nomor challenge (uang kamu = %d): ", logged_user.money);

            STARTWORDINPUT();
            printf("\n");
            int nomor = WordToInt(currentWord);

            if (nomor == 1 && logged_user.money >= 200) {
                logged_user.money -= 200;
                logged_user.money += tebakangka();
            } else if (nomor == 2 && logged_user.money >= 500) {
                Wordle(&logged_user);
            } else {
                printf("Permainan tidak diketahui atau uang tidak cukup.\n");
            }

        // ** WORK Command ** //
        } else if (started && isLoggedIn(&logged_user) &&
                   str_compare(STRING(currentWord), "WORK")) {
            simple_work(&logged_user);
        }

        // ** Update User Data ** //
        for (int i = 0; i < user_list.size; i++) {
            User *current = us_getItem(&user_list, i);
            if (str_compare(current->name, logged_user.name)) {
                current->money = logged_user.money;
            }
        }

        // Prompt for next command
        printf("Masukkan command (HELP jika butuh arahan): ");
        STARTSENTENCEINPUT();
    }
    // Di luar while
    if (started) {
        printf("Apakah kamu ingin menyimpan dahulu?\n(y jika ya) >>> ");
        STARTWORDINPUT();
        if (str_compare(STRING(currentWord),"y")) {
            printf("Masukkan nama file: ");
            STARTWORDINPUT();
            char *filename = alokasi_salin(STRING(currentWord),currentWord.Length+1);
            SAVE(&user_list, item_list, filename);
            free(filename);
        }
    }
    printf("Goodbye!\n");
}
