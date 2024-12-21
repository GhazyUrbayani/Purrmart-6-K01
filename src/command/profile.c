#include <stdio.h>
#include "profile.h"

void show_profile(User* user) {
    if (user == NULL) {
        printf("Anda belum login. Silakan login terlebih dahulu.\n");
        return;
    }

    printf("================================================================================\n");
    printf("                               PROFIL PENGGUNA                                  \n");
    printf("================================================================================\n");
    printf("                                   /\\_/\\                        Halo, %s!      \n", user->name);
    printf("                                  ( o.o )                                       \n");
    printf("                                   > ^ <                                        \n");
    printf("================================================================================\n");
    printf("Nama  : %s\n", user->name);
    printf("Uang  : %d\n", user->money);
    printf("================================================================================\n");
    printf("                          TERIMA KASIH SUDAH BERKUNJUNG                         \n");
    printf("================================================================================\n");
}
