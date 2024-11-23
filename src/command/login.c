#include "login.h"
#include <stdio.h>

// Login berhasil
void displayLoginSuccess(Word username) {
    printf("\nAnda telah login ke PURRMART sebagai ");
    printWord(username);
    printf(".\n");
}

// Login gagal
void displayLoginFailed() {
    printf("\nUsername atau password salah.\n");
}

// Menampilkan pesan login gagal karena belum logout
void displayAlreadyLoggedIn(Word currentUsername) {
    printf("\nAnda masih tercatat sebagai ");
    printWord(currentUsername);
    printf(". Silakan LOGOUT terlebih dahulu.\n");
}

// Mengecek login valid atau tidak
boolean isLoginValid(ListStatUser userList, Word username, Word password) {
    for (int i = 0; i < userList.neff; i++) {
        Word existingUsername, existingPassword;
        int j = 0;

        // Menyalin username dari daftar pengguna 
        while (userList.buffer[i].name[j] != '\0' && j < MAX_LEN) {
            existingUsername.TabWord[j] = userList.buffer[i].name[j];
            j++;
        }
        existingUsername.Length = j;

        // Menyalin password dari daftar pengguna 
        j = 0;
        while (userList.buffer[i].password[j] != '\0' && j < MAX_LEN) {
            existingPassword.TabWord[j] = userList.buffer[i].password[j];
            j++;
        }
        existingPassword.Length = j;

        // Membandingkan username dan password
        if (WordEqual(existingUsername, username) && WordEqual(existingPassword, password)) {
            return true;
        }
    }
    return false;
}

// Login akun
void loginAccount(ListStatUser userList, Word *currentUsername) {
    Word username, password;
    printf(">> LOGIN\n");

    // Input username
    printf("Username: ");
    STARTWORDINPUT();
    username = currentWord;

    // Input password
    printf("Password: ");
    STARTWORDINPUT();
    password = currentWord;

    // Jika sudah ada pengguna yang login, cek apakah dia belum logout
    if (currentUsername->Length > 0) {
        displayAlreadyLoggedIn(*currentUsername);
        return;
    }

    boolean statuslog = false;
    if (isLoginValid(userList, username, password)) {
        *currentUsername = username; 
        displayLoginSuccess(username);
        boolean statuslog = true;
    } else {
        displayLoginFailed();
    }
}
