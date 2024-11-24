#ifndef LOGIN_H
#define LOGIN_H

#include "./../structs/user.h"

/// @brief Prosedur untuk login
/// @param user_list list of user yang ada di state program
/// @param userout perubahan variabel user yang ada di state program
/// @param username username masukan
/// @param password password masukan
void login(SList *user_list, User *userout, char *username, char *password);

#endif //LOGIN_H
