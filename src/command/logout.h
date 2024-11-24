#ifndef LOGOUT_H
#define LOGOUT_H

#include "./../structs/user.h"

/// @brief Mengecek apakah User di state program memiliki isi
/// @param user variabel user yang ada di state program
/// @return true jika user memiliki isi
boolean isLoggedIn(User *user);

/// @brief Me-logout user dengan cara mengosongkannya
/// @param user variabel user yang ada di state program
void logout(User *user);

#endif // LOGOUT_H
