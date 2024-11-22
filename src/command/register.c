#include "register.h"
#include <stdio.h>

// Registrasi gagal
void displayRegistrationFailed(Word username) {
    printf("\nAkun dengan username ");
    printWord(username);
    printf(" gagal dibuat. Silakan lakukan REGISTER ulang.\n");
}

// Registrasi berhasil
void displayRegistrationSuccess(Word username) {
    printf("\nAkun dengan username ");
    printWord(username);
    printf(" telah berhasil dibuat. Silakan LOGIN untuk melanjutkan.\n");
}

// Mengecek username bisa digunakan atau tidak
boolean isUsernameAvailable(ListStatUser userList, Word username) {
    for (int i = 0; i < userList.neff; i++) {
        Word existingUsername;
        int j = 0;

        // Menyalin username dari list pengguna 
        while (userList.buffer[i].name[j] != '\0' && j < MAX_LEN) {
            existingUsername.TabWord[j] = userList.buffer[i].name[j];
            j++;
        }
        existingUsername.Length = j;

        // Membandingkan username dengan username yang sudah ada
        if (WordEqual(existingUsername, username)) {
            return false;
        }
    }
    return true;
}

// Registrasi akun
void registerAccount(ListStatUser *userList) {
    Word username, password;
    printf(">> REGISTER\n");

    // Input username
    printf("Username: ");
    STARTWORDINPUT();
    username = currentWord;

    // Input password
    printf("Password: ");
    STARTWORDINPUT();
    password = currentWord;

    // Cek username bisa digunakan atau tidak
    if (!isUsernameAvailable(*userList, username)) {
        displayRegistrationFailed(username);
    } else {
        // Buat user baru
        User newUser;
        CreateUser(&newUser, username.TabWord, password.TabWord, 0);

        // Tambahkan user baru ke dalam daftar
        if (!IsFullUser(*userList)) {
            InsertLastUser(userList, newUser);
            displayRegistrationSuccess(username);
        } else {
            printf("\nRegistrasi gagal: kapasitas maksimum pengguna telah tercapai.\n");
        }
    }
}
