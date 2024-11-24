#include "./../src/command/startnload.h"

int main(void) {
    SList users; us_initList(&users);
    DList *items = id_createList();
    printf("\n=== *** Test Start *** ===\n");

    /* 
        Buka file default
     */
    printf("\nTC 01 : Default (config.txt)\n");
    printf("Masukkan command: START\n");
    if (STARTPROGRAM(&users,&items,"config.txt")) {
       printf("Success buka config default (TEST SUCCESS).\n");
    } else {
       printf("Gagal buka config default (TEST FAILED).\n");
    }

    /* 
        Buka file gaada
     */
    printf("\nTC 02 : Loading non-existent file (notexists.txt)\n");
    printf("Masukkan command: LOAD notexists.txt\n");
    if (STARTPROGRAM(&users,&items,"notexists.txt")) {
       printf("Success buka file non-existent (TEST FAILED).\n");
    } else {
       printf("Gagal buka file non-existent (TEST SUCCESS).\n");
    }

    /* 
        Buka file dari input user (tolong valid)
     */
    printf("\nTC 03 : User-inputted filename\n");
    printf("Masukkan filename dengan 'cloud.txt'\n");
    printf("Masukkan command: LOAD ");
    STARTWORDINPUT();
    char *namafile = (char *) alokasi_salin(STRING(currentWord),str_len(STRING(currentWord)));
    if (STARTPROGRAM(&users,&items,namafile)) {
       printf("Success buka file %s (TEST SUCCESS).\n",namafile);
    } else {
       printf("Gagal buka file %s (TEST FAILED).\n",namafile);
    }
    free(namafile);

    /* 
        Buka file dari input user (jangan valid)
     */
    printf("\nTC 04 : User-inputted wrong filename\n");
    printf("Masukkan filename dengan selain 'config.txt' atau 'cloud.txt'\n");
    printf("Masukkan command: LOAD ");
    STARTWORDINPUT();
    namafile = alokasi_salin(STRING(currentWord),str_len(STRING(currentWord))+1);
    if (STARTPROGRAM(&users,&items,namafile)) {
       printf("Success buka file %s (TEST FAILED).\n",namafile);
    } else {
       printf("Gagal buka file %s (TEST SUCCESS).\n",namafile);
    }
    free(namafile);

    return 0;
}
