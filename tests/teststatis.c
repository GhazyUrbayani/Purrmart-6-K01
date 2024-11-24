#include "./../src/structs/user.h"

int main(){
    printf("\n=== *** Test Start *** ===\n");

    printf("\nTC 01 : Buat list user\n");
    SList tes;
    us_initList (&tes);
    printf("Terbentuk list statis dengan neff %d dan ukuran tiap elemen %d \n",tes.size,sizeof(User));

    printf("\nTC 02 : Add user ke list user\n");
    User test;
    CreateUser(&test, "tesnama", "tespassword", 80);
    us_addItem(&tes,&test);
    printf("Menambahkan user dengan nama %s dengan passord %s dan uang %d\n", test.name, test.password, test.money);
    printf("Ukuran list sekarang adalah %d\n", tes.size);

    printf("\nTC 03 : Get user dari list user\n");
    printf("Mengambil user dengan indeks %d\n", 0);
    User *upointer = us_getItem(&tes, 0);
    printf("user dengan indeks %d memiliki nama %s, password %s, dan uang %d\n", 0, upointer->name, upointer->password, upointer->money);

    printf("\nTC 04 : Remove user dari list_user\n");
    us_removeItem(&tes, 0);
    printf("Ukuran list sekarang adalah %d\n", tes.size);

    return 0;
}