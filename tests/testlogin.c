/// dasd
#include "./../src/command/login.h"
#include "./../src/command/startnload.h"

/// @brief 3 kemungkinan: sukses, password salah, dan username tidak ada
/// @return 0 jika program bener
int main() {

    /// User yang ada di state program
    User saya; CreateUser(&saya,"","",0);
    printf("\n=== *** Test Login *** ===\n");

    /// Populate list user
    SList user_list; us_initList(&user_list);
    User a; CreateUser(&a,"Noeriza","Aeron",30000000);
    User b; CreateUser(&b,"SpringTrap","WilliamAfton",1983);
    User c; CreateUser(&c,"Ghazy","KetuaDies",182);
    us_addItem(&user_list,&a);
    us_addItem(&user_list,&b);
    us_addItem(&user_list,&c);
    printf("Initial state:\nLogged username: %s | password: %s | money: %d\n",saya.name,saya.password,saya.money);
    /* 
        TC 01 : Login Berhasil
     */
    printf("\nTC 01 :\tLogin dengan kredensial sesuai.\n");
    printf("\tParameter: (user=Noeriza, pass=Aeron)\n\tHarusnya: (user=Noeriza, pass=Aeron)\nHasil:\t");
    login(&user_list,&saya,"Noeriza","Aeron");
    printf("Logged username: %s | password: %s | money: %d\n",saya.name,saya.password,saya.money);

    /* 
        TC 02 : Password Salah
     */
    printf("\nTC 02 :\tLogin dengan kredensial salah.\n");
    printf("\tParameter: (user=SpringTrap, pass=MichaelAfton)\n\tHarusnya: (user=SpringTrap, pass=WilliamAfton)\nHasil:\t");
    login(&user_list,&saya,"SpringTrap","MichaelAfton");
    printf("Logged username: %s | password: %s | money: %d\n",saya.name,saya.password,saya.money);

    /* 
        TC 03 : Akun tidak ditemukan
     */
    printf("\nTC 03 : Login dengan kredensial imajiner.\n");
    printf("\tParameter: (user=Aurelia, pass=Vizal)\n\tHarusnya: (user=(tidak ada), pass=(tidak ada))\nHasil:\t");
    login(&user_list,&saya,"Aurelia","Vizal");
    printf("Logged username: %s | password: %s | money: %d\n",saya.name,saya.password,saya.money);

    /* 
        TC 04 : Login akun lain
     */
    printf("\nTC 04 :\tLogin dengan akun lain.\n");
    printf("\tParameter: (user=Ghazy, pass=KetuaDies)\n\tHarusnya: (user=Ghazy, pass=KetuaDies)\nHasil:\t");
    login(&user_list,&saya,"Ghazy","KetuaDies");
    printf("Logged username: %s | password: %s | money: %d\n",saya.name,saya.password,saya.money);

    return 0;
}
