#include "register.h"

/// @brief Daftar user (nambahin user ke list user)
/// @param user_list isinya list user yang sudah di-load ke program.
/// @param candidate_user  candidate user. kenapa candidate? bisa aja list-nya penuh, atau usernya ga unique.
void user_register(SList *user_list, User *candidate_user) {
    if (!us_isUserin(user_list,candidate_user)) {
        if (str_len(candidate_user->name) == 0 || str_len(candidate_user->password) == 0) { // Tidak boleh kosong
            printf("Nama atau password tidak boleh kosong!\n");
        } else if (containsSpace(candidate_user->name) || containsSpace(candidate_user->password)) { // Tidak boleh lebih dari satu kata
            printf("Nama atau password tidak boleh terdiri lebih dari satu kata!\n");
        } else {
            us_addItem(user_list,candidate_user);
            printf("Berhasil meregister user!\n");  
        }
    } else {
        printf("User sudah ada!\n");
    }
    return;
}
