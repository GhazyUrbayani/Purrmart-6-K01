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
    printf("============================== Welcome Menu Help PURRMART ===============================\n");
    printf (" 1. START -> Untuk masuk sesi baru\n");
    printf (" 2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    printf (" 3. EXIT -> Untuk keluar dari program\n");
    printf("=========================================================================================\n");
}

void help_l(){
    printf("================================ Login Menu Help PURRMART ================================\n");
    printf (" 1. REGISTER -> Untuk melakukan pendaftaran akun baru\n");
    printf (" 2. LOGIN -> Untuk masuk ke dalam akun dan memulai sesi\n");
    printf (" 3. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf (" 4. EXIT -> Untuk keluar dari program\n");
    printf("=========================================================================================\n");
}

void help_m(){
    printf("====================================== Menu Help PURRMART ======================================\n");
    printf (" 1. WORK -> Untuk bekerja\n");
    printf (" 2. WORK CHALLENGE -> Untuk mengerjakan challenge\n");
    printf (" 3. STORE LIST -> Untuk melihat barang-barang di toko\n");
    printf (" 4. STORE REQUEST -> Untuk meminta penambahan barang\n");
    printf (" 5. STORE SUPPLY -> Untuk menambahkan barang dari permintaan\n");
    printf (" 6. STORE REMOVE -> Untuk menghapus barang\n");
    printf (" 7. PROFILE -> Untuk melihat data diri pengguna\n");
    printf (" 8. CART ADD <nama> <n> -> Untuk menambah n barang ke keranjang belanja\n");
    printf (" 9. CART REMOVE <nama> <n> -> Untuk menghapus n barang ke keranjang belanja\n");
    printf (" 10. CART SHOW -> Untuk menunjukkan isi keranjang belanja\n");
    printf (" 11. CART PAY -> Untuk membeli barang dalam keranjang belanja\n");
    printf (" 12. HISTORY <n> -> Untuk menunjukkan riwayat pembelian pengguna\n");
    printf (" 13. WISHLIST ADD -> Untuk menambah suatu barang ke wishlist\n");
    printf (" 14. WISHLIST SWAP <i> <j> -> Untuk menukar urutan barang posisi ke-i dengan barang posisi ke-j pada wishlist\n");
    printf (" 15. WISHLIST REMOVE <i> -> Untuk menghapus barang pada posisi ke-i ke keranjang belanja\n");
    printf (" 16. WISHLIST CLEAR -> Untuk menghapus semua barang dari wishlist\n");
    printf (" 17. WISHLIST SHOW -> Untuk menampilkan barang dalam wishlist\n");
    printf (" 18. LOGOUT -> Untuk keluar dari sesi\n");
    printf (" 19. SAVE -> Untuk menyimpan state ke dalam file\n");
    printf (" 20. EXIT -> Untuk keluar dari program\n");
    printf("=========================================================================================\n");
}
