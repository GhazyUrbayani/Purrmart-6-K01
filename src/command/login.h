#ifndef LOGIN_H
#define LOGIN_H

#include "user.h"
#include "mesinkata.h"
#include "liststatuser.h"
#include "boolean.h"

void displayLoginSuccess(Word username);
/*
    Menampilkan pesan bahwa login berhasil
    I.S: Username valid yang sudah terautentikasi.
    F.S: Menampilkan pesan login berhasil dengan menyebutkan username.
*/

void displayLoginFailed();
/*
    Menampilkan pesan bahwa login gagal
    I.S: Login gagal karena username atau password salah.
    F.S: Menampilkan pesan login gagal.
*/

void displayAlreadyLoggedIn(Word currentUsername);
/*
    Menampilkan pesan bahwa user sudah login
    I.S: Username sudah login ke dalam sistem.
    F.S: Menampilkan pesan bahwa pengguna saat ini sudah login.
*/

boolean isLoginValid(ListStatUser userList, Word username, Word password);
/*
    Mengecek apakah login valid berdasarkan username dan password
    I.S: userList berisi daftar pengguna terdaftar, username dan password adalah input dari user.
    F.S: Mengembalikan true jika username dan password cocok dengan data di userList.
         Mengembalikan false jika username tidak ditemukan atau password salah.
*/

void loginAccount(ListStatUser userList, Word *currentUsername);
/*
    Melakukan login dengan memvalidasi username dan password
    I.S: userList berisi daftar pengguna terdaftar, currentUsername menunjuk ke username pengguna aktif atau NULL.
    F.S: Jika login berhasil, currentUsername diisi dengan username pengguna.
         Jika login gagal, currentUsername tetap NULL dan menampilkan pesan kesalahan.
*/

#endif
