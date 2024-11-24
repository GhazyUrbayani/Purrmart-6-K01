#include "login.h"

void login(SList *user_list, User *userout, char *username, char *password) {
    for (int i = 0; i < user_list->size; i++) {
        User *current = us_getItem(user_list,i);
        if (str_compare(username,current->name)) {
            if (str_compare(password,current->password)) {
                userout->money = current->money;
                CopyString(userout->name,username);
                CopyString(userout->password,password);
                printf("Login berhasil!\n");
                return;
            } else {
                printf("Password salah!\n");
                return;
            }
        }
    }
    printf("User tidak ditemukan!\n");
    return;
}
