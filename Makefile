testkarakter : ./tests/test_m_karakter.c  ./src/ADT/mesinkarakter/mesinkarakter.c
	gcc -o ./builds/testkarakter ./tests/test_m_karakter.c  ./src/ADT/mesinkarakter/mesinkarakter.c

e2e : ./tests/e2etest.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/ADT/queue.c ./src/ADT/utils.c ./src/command/save.c ./src/command/startnload.c ./src/structs/item.c ./src/structs/user.c
	gcc -o ./builds/e2e ./tests/e2etest.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/ADT/queue.c ./src/ADT/utils.c ./src/command/save.c ./src/command/startnload.c ./src/structs/item.c ./src/structs/user.c