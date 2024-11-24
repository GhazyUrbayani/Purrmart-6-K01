#ifndef WORK_H
#define WORK_H

#include "./../ADT/liststatis.h"
#include "./../structs/user.h"

typedef struct Kerja {
    char *nama;
    double durasi;
    int gaji;
} Kerja;

void simple_work(User *logged_user);

void buatkerja(Kerja *kerja, char *nama, double durasi, int gaji);

void buatlistkerjaan(SList *kerjaan);

void tambahkerjaan(SList *kerjaan, Kerja *kerja);

void kurangkerjaan(SList *kerjaan, size_t index);

void hapuskerjaan(SList *kerjaan);

#endif // WORK_H