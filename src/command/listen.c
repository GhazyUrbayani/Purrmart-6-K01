#include "listen.h"
#include <stdio.h>
#include "./../ADT/utils.h"
#include "./../store/cart.h"
#include "./../store/wishlistshow.h"
#include "./../Wishlist/Wishlist-add.h"
#include "./../Wishlist/Wishlist-swap.h"
#include "./../Wishlist/Wishlist-clear.h"
#include "wishlist_remove.h"
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
        } else if (str_startwith(STRING(currentWord),"LOAD")) {
            Word filename = parseWordSpace(2);
            if (filename.Length == 0) {
                printf("Masukkan nama file!\n");
            } else {
                int loadsuccess = STARTPROGRAM(&user_list, &item_list, filename.TabWord);
                if (loadsuccess == true) {
                    printf("File %s berhasil di-load.\n", filename.TabWord);
                    started = true;
                } else {
                    printf("File %s gagal di-load.\n", filename.TabWord);
                }
            }

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
            // DEBUG START
            cartShow(&logged_user.keranjang,item_list);
            printUserHistory(&logged_user,100);
            wishlistshow(&logged_user.wishlist);
            // DEBUG END

        // ** HELP Command ** //
        } else if (str_compare(STRING(currentWord), "HELP")) {
            help(started,isLoggedIn(&logged_user));
            
        // ** LOGOUT Command ** //
        } else if (started && str_compare(STRING(currentWord), "LOGOUT")) {
            logout(&logged_user);

        // ** SAVE Command ** //
        } else if (started && str_startwith(STRING(currentWord), "SAVE")) {
            Word filename = parseWordSpace(2);
            if (filename.Length == 0) {
                printf("Masukkan nama file!\n");
            } else {
                SAVE(&user_list, item_list, filename.TabWord);
            }

        // ** STORE LIST Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE LIST")) {
            store_list(item_list);

        // ** STORE REQUEST Command ** //
        } else if (started && str_compare(STRING(currentWord), "STORE REQUEST")) {
            printf("Nama barang yang ingin di-request: ");
            STARTSENTENCEINPUT();

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

        } else if (started && str_compare(STRING(currentWord), "PRINTUSERS")) {
            us_printList(&user_list);

        // COMMAND PROFILE
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord), "PROFILE")) {
            printProfile(&logged_user);

        // COMMAND HISTORY
        } else if (started && isLoggedIn(&logged_user) && str_startwith(STRING(currentWord),"HISTORY")) {
            Word arg = parseWordSpace(2);
            if (countWords(currentWord) < 2) {
                printf("Masukan jumlah history yang ingin ditampilkan!\n");
            } else {
                int limitz = WordToInt(arg);
                if (limitz == -1) {
                    printf("Jumlah history tidak valid!\n");
                } else {
                    printUserHistory(&logged_user,limitz);
                }
            }
        // COMMAND CART ADD <namabarang> <jumlah>
        } else if (started && isLoggedIn(&logged_user) && str_startwith(STRING(currentWord),"CART ADD")) {
            Word arg = parseWordSpace(3);
            // DEBUG START
                printf("%s\n",arg.TabWord);
            // DEBUG END
            if (countWords(currentWord) < 4) {
                printf("Masukan nama barang dan kuantitas!\n");
            } else {
                Word wordbarang = parseUntilNumber(arg);
                // DEBUG START
                printf("%s\n",wordbarang.TabWord);
                // DEBUG END
                Word kuantitasbarang = parseWhenNumber();
                // DEBUG START
                printf("%d\n",WordToInt(kuantitasbarang));
                // DEBUG END
                cartAdd(&logged_user.keranjang,wordbarang.TabWord,WordToInt(kuantitasbarang),item_list);
            }
        // COMMAND CART REMOVE <namabarang> <jumlah>
        } else if (started && isLoggedIn(&logged_user) && str_startwith(STRING(currentWord),"CART REMOVE")) {
            Word arg = parseWordSpace(3);
            if (countWords(currentWord) < 4) {
                printf("Masukan nama barang dan kuantitas!\n");
            } else {
                Word wordbarang = parseUntilNumber(arg);
                Word kuantitasbarang = parseWhenNumber();
                cartRemove(&logged_user.keranjang,wordbarang.TabWord,WordToInt(kuantitasbarang));
            }
        // COMMAND CART SHOW
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"CART SHOW")) {
            cartShow(&logged_user.keranjang,item_list);
        // COMMAND CART PAY
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"CART PAY")) {
            cartPay(&logged_user.keranjang,&logged_user.riwayat_pembelian,&logged_user.money,item_list);
        // COMMAND WISHLIST ADD
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"WISHLIST ADD")) {
            wishlistadd(&logged_user.wishlist,*item_list);
        // Wishlist Swap i j
        } else if (started && isLoggedIn(&logged_user) && str_startwith(STRING(currentWord),"WISHLIST SWAP")) {
            if (countWords(currentWord) != 4) {
                printf("Jumlah argumen tidak sesuai. Masukkan 4\n");
            }
            int posisi_i = WordToInt(parsenth(currentWord, 3));
            int posisi_j = WordToInt(parsenth(currentWord, 4));
            wishlistswap(&logged_user.wishlist,posisi_i,posisi_j);
        // Wishlist remove
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"WISHLIST REMOVE")) {
            printf("Masukkan nama barang: ");
            STARTSENTENCEINPUT();
            wishlist_remove_name(&logged_user.wishlist,STRING(currentWord));
        } else if (started && isLoggedIn(&logged_user) && str_startwith(STRING(currentWord),"WISHLIST REMOVE")) {
            if (countWords(currentWord) != 3) {
                printf("Jumlah argumen tidak sesuai. Masukkan 3\n");
            }
            int posisi_i = WordToInt(parsenth(currentWord, 3));
            wishlist_remove_index(&logged_user.wishlist,posisi_i);
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"WISHLIST SHOW")) {
            wishlistshow(&logged_user.wishlist);
        } else if (started && isLoggedIn(&logged_user) && str_compare(STRING(currentWord),"WISHLIST CLEAR")) {
            wishlistclear(&logged_user.wishlist);
        }

        // ** Update User Data ** //
        for (int i = 0; i < user_list.size; i++) {
            User *current = us_getItem(&user_list, i);
            if (str_compare(current->name, logged_user.name)) {
                current->money = logged_user.money;
                current->keranjang = logged_user.keranjang;
                current->riwayat_pembelian = logged_user.riwayat_pembelian;
                current->wishlist = logged_user.wishlist;
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
