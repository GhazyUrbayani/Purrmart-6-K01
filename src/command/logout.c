#include "logout.h"
#include <stdio.h>

void logout(ListStatUser *userList, Word username) {
    printf(">> LOGOUT\n");

    // Cari penggunanya
    boolean found = false;
    for (int i = 0; i < (*userList).neff; i++) {
        // Jadiin existing username buat dicek
        Word existingUsername = stringToWord((*userList).buffer[i].name);

        // Jika username ditemukan
        if (WordEqual(existingUsername, username)) {
            found = true;
            boolean statuslog = true;
            // Periksa apakah user sedang login atau tidak
            if ((*userList).buffer[i]) {
            
                if ((*userList).buffer[i].name[0] != '\0') { 
                    (*userList).buffer[i].name[0] = '\0';
                    (*userList).buffer[i].password[0] = '\0';
                    (*userList).buffer[i].money = 0;

                    printf("%s telah logout dari sistem PURRMART. Data pengguna telah dihapus.\n", existingUsername.TabWord);
                    printf("Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n");

                    boolean statuslog = false;
                }
            } 
            else {
                printf("Logout gagal! Pengguna %s belum login.\n", (*userList).buffer[i].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Logout gagal! Pengguna tidak ditemukan dalam sistem.\n");
    }
}
