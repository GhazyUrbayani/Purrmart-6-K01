#include "work.h"

void simple_work(User *logged_user) {
    SList kerjaan; buatlistkerjaan(&kerjaan);

    Kerja softeng, datalys, proman;
    buatkerja(&softeng, "Software Engineer", 6, 800);
    buatkerja(&datalys, "Data Analyst", 7, 650);
    buatkerja(&proman, "Project Manager", 6, 700);

    tambahkerjaan(&kerjaan, &softeng);
    tambahkerjaan(&kerjaan, &datalys);
    tambahkerjaan(&kerjaan, &proman);

    printf("Daftar kerjaan:\n");
    for (int i = 0; i < kerjaan.size; i++) {
        Kerja *current = (Kerja *) s_getItem(&kerjaan,i);
        printf(" %d. %s (pendapatan=%d,durasi=%0.0fs)\n",i+1,current->nama,current->gaji,current->durasi);
    }

    printf("Masukan kerjaan yang dipilih: ");
    STARTSENTENCEINPUT();
    int idxkerja = -1;
    for (int i = 0; i < kerjaan.size; i++) {
        Kerja *current = (Kerja *) s_getItem(&kerjaan,i);
        if (str_compare(STRING(currentWord),current->nama)) {
            idxkerja = i;
            break;
        }
    }
    if (idxkerja != -1) {
        Kerja *current = (Kerja *) s_getItem(&kerjaan,idxkerja);
        printf("Anda bekerja sebagai %s... harap tunggu.\n\n(sabar, ini bukan error)\n\n",current->nama);
        delay(current->durasi);
        logged_user->money += (int) current->gaji;
        printf("Pekerjaan selesai, +%d rupiah sudah ditambahkan ke akun Anda.\n", current->gaji);
    } else {
        printf("Pekerjaan tidak ditemukan.\n");
    }

    s_clearList(&kerjaan);
}

void buatkerja(Kerja *kerja, char *nama, double durasi, int gaji) {
    kerja->durasi = durasi;
    kerja->gaji = gaji;
    kerja->nama = alokasi_salin(nama,str_len(nama)+1);
}

void buatlistkerjaan(SList *kerjaan) {
    s_initList(kerjaan);
}

void tambahkerjaan(SList *kerjaan, Kerja *kerja) {
    s_addItem(kerjaan,kerja,sizeof(Kerja));
}

void kurangkerjaan(SList *kerjaan, size_t index) {
    s_removeItem(kerjaan,index);
}

void hapuskerjaan(SList *kerjaan) {
    s_clearList(kerjaan);
}