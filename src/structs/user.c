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
void us_addItem(SList *list, void *item) {
    s_addItem(list, item, sizeof(User));
}
void us_insertItem(SList *list, size_t index, void *item) {
    s_insertItem(list,index,item,sizeof(User));
}
void us_removeItem(SList *list, size_t index) {
    s_removeItem(list,index);
}
void* us_getItem(SList *list, size_t index) {
    return s_getItem(list,index);
}
void us_setItem(SList *list, size_t index, void *item) {
    s_setItem(list,index,item,sizeof(User));
}
void us_clearList(SList *list) {
    s_clearList(list);
}

void ReadUser(SList *userList) {
    User user;
    ADVWORD();
    user.money = WordToInt(currentWord);
    ADVWORD();
    CopyString(user.name, currentWord.TabWord);
    ADVWORD();
    CopyString(user.password, currentWord.TabWord);
    us_addItem(userList, &user);
}
void WriteUsers(SList *users, FILE *file) {
    fprintf(file, "%zu\n", users->size);
    for (size_t i = 0; i < users->size; i++) {
        User *user = (User *)users->items[i];
        fprintf(file, "%d %s %s\n", user->money, user->name, user->password);
    }
}

/* 
    List Dinamis User
 */
DList* ud_createList() {
    return d_createList();
}
void ud_addItem(DList *list, void *item) {
    d_addItem(list,item,sizeof(User));
}
void ud_insertItem(DList *list, size_t index, void *item) {
    d_insertItem(list,index,item,sizeof(User));
}
void ud_removeItem(DList *list, size_t index) {
    d_removeItem(list,index);
}
void* ud_getItem(DList *list, size_t index) {
    d_getItem(list,index);
}
void ud_setItem(DList *list, size_t index, void *item) {
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
int uisQueueEmpty(Queue *queue) {
    return isQueueEmpty(queue);
}
int uisQueueFull(Queue *queue) {
    return isQueueFull(queue);
}
void uenqueue(Queue *queue, void *item) {
    enqueue(queue,item,sizeof(User));
}
void* udequeue(Queue *queue) {
    dequeue(queue);
}
void* upeekQueue(Queue *queue) {
    peekQueue(queue);
}
void uclearQueue(Queue *queue) {
    clearQueue(queue);
}
