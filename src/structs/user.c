#include "user.h"
#include "./../ADT/mesinkata/mesinkata.h"
#include <stdio.h>

void CreateUser(User *u, char name[], char password[], int money) {
    CopyString(u->name, name);
    CopyString(u->password, password);
    u->money = money;
}

boolean CompareUser(User u1, User u2) {
    int i = 0;
    while (u1.name[i] != '\0' && u2.name[i] != '\0') {
        if (u1.name[i] != u2.name[i]) {
            return false;
        }
        i++;
    }
    return u1.name[i] == '\0' && u2.name[i] == '\0';
}

void DeleteUser(User *u) {
    u->name[0] = '\0';
    u->password[0] = '\0';
    u->money = 0;
}
/* 
    List Statis User
 */
void us_initList(SList *list) {
    s_initList(list);
}
void us_addItem(SList *list, User *item) {
    s_addItem(list, item, sizeof(User));
}
void us_insertItem(SList *list, size_t index, User *item) {
    s_insertItem(list,index,item,sizeof(User));
}
void us_removeItem(SList *list, size_t index) {
    s_removeItem(list,index);
}
User* us_getItem(SList *list, size_t index) {
    return s_getItem(list,index);
}
void us_setItem(SList *list, size_t index, User *item) {
    s_setItem(list,index,item,sizeof(User));
}
void us_clearList(SList *list) {
    s_clearList(list);
}

void us_ReadUser(SList *userList) {
    User user;
    ADVWORD();
    user.money = WordToInt(currentWord);
    ADVWORD();
    CopyString(user.name, currentWord.TabWord);
    ADVWORD();
    CopyString(user.password, currentWord.TabWord);
    us_addItem(userList, &user);
}
void us_WriteUsers(SList *users, FILE *file) {
    fprintf(file, "%zu\n", users->size);
    for (size_t i = 0; i < users->size; i++) {
        User *user = (User *)users->items[i];
        fprintf(file, "%d %s %s\n", user->money, user->name, user->password);
    }
}

boolean us_isUserin(SList *userList, User *user) {
    int size = userList->size;
    for (int i = 0; i < size; i++) {
        User *out = us_getItem(userList,i);
        if (str_compare(user->name,out->name)) {
            return true;
        }
    }
    return false;
}

size_t us_search(SList *userList, User *user) {
    for (int i = 0;i<userList->size;i++) {
        if (str_compare(us_getItem(userList,i)->name,user->name)) {
            return i;
        }
    }
    return -1;
}

/* 
    List Dinamis User
 */
DList* ud_createList() {
    return d_createList();
}
void ud_addItem(DList *list, User *item) {
    d_addItem(list,item,sizeof(User));
}
void ud_insertItem(DList *list, size_t index, User *item) {
    d_insertItem(list,index,item,sizeof(User));
}
void ud_removeItem(DList *list, size_t index) {
    d_removeItem(list,index);
}
User* ud_getItem(DList *list, size_t index) {
    d_getItem(list,index);
}
void ud_setItem(DList *list, size_t index, User *item) {
    d_setItem(list,index,item,sizeof(User));
}
void ud_clearList(DList *list) {
    d_clearList(list);
}
void ud_freeList(DList *list) {
    d_freeList(list);
}

/* 
    Queue User
 */

void uinitQueue(Queue *queue) {
    initQueue(queue);
}
boolean uisQueueEmpty(Queue *queue) {
    return isQueueEmpty(queue);
}
boolean uisQueueFull(Queue *queue) {
    return isQueueFull(queue);
}
void uenqueue(Queue *queue, User *user) {
    enqueue(queue,user,sizeof(User));
}
User* udequeue(Queue *queue) {
    dequeue(queue);
}
User* upeekQueue(Queue *queue) {
    peekQueue(queue);
}
void uclearQueue(Queue *queue) {
    clearQueue(queue);
}
