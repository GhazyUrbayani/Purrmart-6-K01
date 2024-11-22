#ifndef REGISTER_H
#define REGISTER_H

#include "user.h"
#include "mesinkata.h"
#include "liststatususer.h"

// Deklarasi fungsi untuk mendaftar akun
void registerAccount(UserList *userList);

// Deklarasi fungsi untuk memeriksa ketersediaan username
boolean isUsernameAvailable(UserList userList, Word username);

// Deklarasi fungsi untuk menampilkan pesan kesalahan pendaftaran
void displayRegistrationError(Word username);

// Deklarasi fungsi untuk menampilkan pesan keberhasilan pendaftaran
void displayRegistrationSuccess(Word username);

#endif 
