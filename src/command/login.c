#include "login.h"

void login(SList *user_list, User *userout, char *username, char *password) {
    for (int i = 0; i < user_list->size; i++) {
        if (str_compare(username,us_getItem(user_list,i)->name)) {
            if (str_compare(password,us_getItem(user_list,i)->password)) {
                userout->money = us_getItem(user_list,i)->money;
                CopyString(userout->name,username);
                CopyString(userout->password,password);
                printf("Login berhasil!\n");
                return;
            } else {
                printf("Password salah!\n");
                return;
            }
        } else {
                printf("User tidak ditemukan!\n");
                return;
        }
    }
}
