#include "./../src/command/register.h"

int main(void) {
    printf("\n=== *** Test Register *** ===\n");

    /* 
        TC 1
     */
    printf("\nTC 01 : User list kosong\n");
    
    SList user_list; us_initList(&user_list);
    printf("Hasil : Ukuran user list: %d\n",user_list.size);


    /* 
        TC 2
     */
    printf("\nTC 02 : Mendaftarkan user\n");
    User user1; CreateUser(&user1,"Noeriza","aeron",50000000);
    user_register(&user_list,&user1);
    printf("Hasil : Ukuran user list: %d\n",user_list.size);

    /* 
        TC 3
     */
    printf("\nTC 03 : Mendaftarkan user duplikat\n");
    user_register(&user_list,&user1);
    printf("Hasil : Ukuran user list: %d\n",user_list.size);

    return 0;
}