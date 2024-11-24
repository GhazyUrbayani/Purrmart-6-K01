#include "./../src/command/logout.h"

int main(void) {
    /// State awal program (dianggap sudah login)
    User saya; CreateUser(&saya,"Kayla","Dyara",999);
    
    printf("\n=== *** Test Logout *** ===\n");
    /* 
        TC 01 : Logout dengan kondisi logged in.
     */
    printf("\nTC 01 :\tLogout dengan kondisi logged in.\n");
    printf("\tState sebelum -> nama : %s, pass : %s, uang : %d\nHasil :\t",saya.name,saya.password,saya.money);
    logout(&saya);
    printf("\tState setelah -> nama : %s, pass : %s, uang : %d\n",saya.name,saya.password,saya.money);

    /* 
        TC 01 : Logout dengan kondisi logged in.
     */
    printf("\nTC 02 :\tLogout dengan kondisi logged out.\n");
    printf("\tState sebelum -> nama : %s, pass : %s, uang : %d\nHasil :\t",saya.name,saya.password,saya.money);
    logout(&saya);
    printf("\tState setelah -> nama : %s, pass : %s, uang : %d\n",saya.name,saya.password,saya.money);

    return 0;
}