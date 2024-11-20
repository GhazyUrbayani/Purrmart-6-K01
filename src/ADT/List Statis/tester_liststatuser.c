#include <stdio.h>
#include "liststatisuser.h"
#include "../user.h" // Include file untuk definisi struct User

int main() {
    ListStatUser daftarUser;
    User user1, user2, user3;
    User deletedUser;

    /* Inisialisasi list statis */
    CreateListStatUser(&daftarUser);
    printf("List dibuat. Apakah kosong? %s\n", IsEmptyUser(daftarUser) ? "Ya" : "Tidak");

    /* Membuat data pengguna */
    CreateUser(&user1, "user1", "password1", 100);
    CreateUser(&user2, "user2", "password2", 200);
    CreateUser(&user3, "user3", "password3", 300);

    /* Menambahkan user ke dalam list */
    InsertLastUser(&daftarUser, user1);
    InsertLastUser(&daftarUser, user2);
    printf("Menambahkan user1 dan user2 ke dalam list.\n");

    /* Menampilkan status list */
    printf("List sekarang memiliki %d user. Apakah penuh? %s\n", daftarUser.neff, IsFullUser(daftarUser) ? "Ya" : "Tidak");

    /* Menambahkan user3 ke dalam list */
    InsertLastUser(&daftarUser, user3);
    printf("Menambahkan user3 ke dalam list.\n");

    /* Menampilkan user di dalam list */
    printf("Daftar user:\n");
    for (int i = 0; i < daftarUser.neff; i++) {
        printf("User %d: %s, Password: %s, Uang: %d\n", i + 1, daftarUser.buffer[i].name, daftarUser.buffer[i].password, daftarUser.buffer[i].money);
    }

    /* Menghapus elemen terakhir dari list */
    DeleteLastUser(&daftarUser, &deletedUser);
    printf("User terakhir (%s) dihapus dari list.\n", deletedUser.name);

    /* Menampilkan user setelah penghapusan */
    printf("Daftar user setelah penghapusan:\n");
    for (int i = 0; i < daftarUser.neff; i++) {
        printf("User %d: %s, Password: %s, Uang: %d\n", i + 1, daftarUser.buffer[i].name, daftarUser.buffer[i].password, daftarUser.buffer[i].money);
    }

    /* Mengecek apakah list kosong */
    printf("Apakah list kosong? %s\n", IsEmptyUser(daftarUser) ? "Ya" : "Tidak");

    return 0;
}
