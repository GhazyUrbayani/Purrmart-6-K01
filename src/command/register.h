#ifndef REGISTER_H
#define REGISTER_H

#include "./../structs/user.h"
#include "./../ADT/utils.h"

/// @brief Tambahkan user ke list possible user
/// @param user_list 
/// @param candidate_user 
void user_register(SList *user_list, User *candidate_user);

#endif // REGISTER_H
