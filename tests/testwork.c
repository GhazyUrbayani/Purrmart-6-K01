#include "./../src/work/work.h"

int main(void) {
    User saya; CreateUser(&saya,"Timur","superpips",135);
    printf("\n=== *** Test Work *** ===\n");

    printf("\n=== TC 01 : Kerja ===\n");
    printf("Nama: %s\nUang: %d\n\n",saya.name,saya.money);
    simple_work(&saya);
    printf("\n=== Hasil TC 01 : Kerja ===\n");
    printf("Nama: %s\nUang: %d\n\n",saya.name,saya.money);
    printf("Test selesai.\n");
    return 0;
}
