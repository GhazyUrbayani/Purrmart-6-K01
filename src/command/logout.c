#include "logout.h"

boolean isLoggedIn(User *user) {
    return (!str_compare(user->name,""));
}

void logout(User *user, SList *userlist) {
    if (isLoggedIn(user)) {
        CopyString(user->name,"");
        CopyString(user->password,"");
        user->money = 0;
        printf("Logout berhasil\n");
    } else {
        printf("Kamu belum login!\n");
    }
    return;
}
