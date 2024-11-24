# include <stdio.h>
#include "help.h"

void help(boolean started,boolean logged) {
    if(logged && started) {
        help_m();
    } else if (started) {
        help_l();
    } else {
        help_s();
    }
}

void help_s(){
    printf("=================================== Welcome Menu Help PURRMART ===================================\n");
    printf (" 1. START -> Untuk masuk sesi baru\n");
    printf (" 2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf (" 3. EXIT -> Untuk keluar dari program\n");
}

void help_l(){
    printf("==================================== Login Menu Help PURRMART ====================================\n");
    printf (" 1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf (" 2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf (" 3. EXIT -> Untuk keluar dari program\n");
}

void help_m(){
    printf("====================================== Menu Help PURRMART ======================================\n");
    printf (" 1. WORK -> Untuk bekerja\n");
    printf (" 2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf (" 3. STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf (" 4. STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf (" 5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf (" 6. STORE REMOVE -> Untuk menghapus barang\n");
    printf (" 7. LOGOUT -> Untuk keluar dari sesi\n");
    printf (" 8. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf (" 9. EXIT -> Untuk keluar dari program\n");
}
