testkarakter : ./tests/test_m_karakter.c  ./src/ADT/mesinkarakter/mesinkarakter.c
	gcc -o ./tests/build/testkarakter ./tests/test_m_karakter.c  ./src/ADT/mesinkarakter/mesinkarakter.c

testkata : ./tests/test_m_kata.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkarakter/mesinkarakter.c
	gcc -o ./tests/build/testkata ./tests/test_m_kata.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkarakter/mesinkarakter.c

main : ./src/main.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/ADT/queue.c ./src/ADT/utils.c ./src/command/listen.c ./src/command/login.c ./src/command/logout.c ./src/command/register.c ./src/command/save.c ./src/command/startnload.c ./src/structs/item.c ./src/structs/user.c ./src/store/store.c
	gcc -o main ./src/main.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/ADT/queue.c ./src/ADT/utils.c ./src/command/listen.c ./src/command/login.c ./src/command/logout.c ./src/command/register.c ./src/command/save.c ./src/command/startnload.c ./src/structs/item.c ./src/structs/user.c ./src/store/store.c
