#include <stdio.h>
#include "profile.h"

void show_profile(User* user) {
    if (user == NULL) {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
        return;
    }

    printf("\nProfil Pengguna:\n");
    printf("Nama: %s\n", user->name);
    printf("Saldo: %d\n", user->money);

}
