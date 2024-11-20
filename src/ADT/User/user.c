#include "user.h"
#include "../mesinkata.h" // Include MesinKata untuk fungsi salinan string

/* Membuat User baru */
void CreateUser(User *u, char name[], char password[], int money) {
    CopyString(u->name, name);       // Menggunakan fungsi dari MesinKata
    CopyString(u->password, password); // Menggunakan fungsi dari MesinKata
    u->money = money;
}

/* Mengecek apakah dua User sama berdasarkan nama */
boolean IsSameUser(User u1, User u2) {
    int i = 0;
    while (u1.name[i] != '\0' && u2.name[i] != '\0') {
        if (u1.name[i] != u2.name[i]) {
            return false;
        }
        i++;
    }
    return u1.name[i] == '\0' && u2.name[i] == '\0';
}

/* Menghapus data User */
void DeleteUser(User *u) {
    u->name[0] = '\0';      // Mengosongkan nama
    u->password[0] = '\0';  // Mengosongkan password
    u->money = 0;           // Mengosongkan saldo
}
