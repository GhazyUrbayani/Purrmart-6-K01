#include "user.h"
#include <string.h>

/* Membuat User baru */
void CreateUser(User *u, char name[], char password[], int money) {
    strcpy(u->name, name);
    strcpy(u->password, password);
    u->money = money;
}

/* Mengecek apakah dua User sama berdasarkan nama */
boolean IsSameUser(User u1, User u2) {
    return strcmp(u1.name, u2.name) == 0;
}

/* Menghapus data User */
void DeleteUser(User *u) {
    strcpy(u->name, "");       // Mengosongkan nama
    strcpy(u->password, "");   // Mengosongkan password
    u->money = 0;              // Mengosongkan saldo
}
