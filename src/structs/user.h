#ifndef USER_H
#define USER_H

#include "./../ADT/boolean.h"
#include "./../ADT/mesinkata/mesinkata.h"
#include "./../ADT/liststatis.h"
#include "./../ADT/listdinamis.h"
#include "./../ADT/queue.h"
#include "./../ADT/utils.h"
#include "./../ADT/linkedlist.h"
#include "./../ADT/stack.h"
#include "./../ADT/map.h"

#include <stdio.h>

#define STR_MAX 100
#define NAME(u) u.name
#define PASS(u) u.password
#define MONEY(u) u.money

typedef struct {
    char name[STR_MAX];     // Nama user
    char password[STR_MAX]; // Password user
    int money;              // Uang user
    Map keranjang;
    Stack riwayat_pembelian;
    LinkedList wishlist;
} User;

/* *** Konstruktor *** */
/**
 * Membuat User baru dengan atribut yang diberikan.
 * IS: User belum terinisialisasi.
 * FS: User terinisialisasi dengan nama, password, dan uang.
 */
void CreateUser(User *u, char name[], char password[], int money);

/* *** Fungsi dan Operasi *** */
/**
 * Mengecek apakah dua User sama berdasarkan nama.
 * IS: Kedua User valid.
 * FS: Tidak ada perubahan.
 * Return: true jika nama sama, false jika tidak.
 */
boolean CompareUser(User u1, User u2);

/**
 * Menghapus data User dengan mengosongkan atribut-atributnya.
 * IS: User valid dan terinisialisasi.
 * FS: Atribut User di-set menjadi kosong atau default.
 */
void DeleteUser(User *u);

/* 
    List Statis User
 */

void us_initList(SList *user_list);
void us_addItem(SList *user_list, User *user);
void us_insertItem(SList *user_list, size_t index, User *user);
void us_removeItem(SList *user_list, size_t index);
User* us_getItem(SList *user_list, size_t index);
void us_setItem(SList *user_list, size_t index, User *user);
void us_clearList(SList *user_list);

void us_ReadUser(SList *user_list);
void us_WriteUsers(SList *user_list, FILE *file);

/// @brief Cek apakah user ada dalam sebuah list
/// @param userList 
/// @param user 
/// @return mengembalikan value apakah ada atau tidaknya user dalam sebuah list of user
boolean us_isUserin(SList *userList, User *user);

size_t us_search(SList *userList, User *user);
#endif
