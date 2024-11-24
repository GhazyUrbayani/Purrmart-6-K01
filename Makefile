testkarakter :
	gcc -o ./tests/testkarakter ./tests/test_m_karakter.c  ./src/ADT/mesinkarakter/mesinkarakter.c && ./tests/testkarakter

testkata :
	gcc -o ./tests/testkata ./tests/test_m_kata.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkarakter/mesinkarakter.c && ./tests/testkata

teststart :
	gcc -o ./tests/teststart ./tests/teststart.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/command/startnload.c ./src/structs/user.c ./src/structs/item.c ./src/ADT/utils.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/queue.c && ./tests/teststart

testdinamis :
	gcc -o ./tests/testdin ./tests/testdinamis.c ./src/structs/item.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/liststatis.c ./src/ADT/listdinamis.c ./src/ADT/queue.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/utils.c && ./tests/testdin

teststatis :
	gcc -o ./tests/teststatis ./tests/teststatis.c ./src/structs/user.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/liststatis.c ./src/ADT/listdinamis.c ./src/ADT/queue.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/utils.c && ./tests/teststatis

testqueue :
	gcc -o ./tests/testqueue ./tests/testqueue.c ./src/structs/item.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/liststatis.c ./src/ADT/listdinamis.c ./src/ADT/queue.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/utils.c && ./tests/testqueue

testregister :
	gcc -o ./tests/testregister ./tests/testregister.c ./src/structs/user.c ./src/command/register.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/liststatis.c ./src/ADT/listdinamis.c ./src/ADT/queue.c ./src/ADT/utils.c && ./tests/testregister

testlogin :
	gcc -o ./tests/testlogin ./tests/testlogin.c ./src/structs/user.c ./src/command/login.c ./src/ADT/liststatis.c ./src/ADT/listdinamis.c ./src/ADT/queue.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/utils.c && ./tests/testlogin

main :
	gcc -o main ./src/main.c ./src/ADT/mesinkarakter/mesinkarakter.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/listdinamis.c ./src/ADT/liststatis.c ./src/ADT/queue.c ./src/ADT/utils.c ./src/command/listen.c ./src/command/login.c ./src/command/logout.c ./src/command/register.c ./src/command/save.c ./src/command/startnload.c ./src/structs/item.c ./src/structs/user.c ./src/store/store.c ./src/work/work.c ./src/work/tebakangka.c ./src/work/wordle.c ./src/command/help.c && ./main

clean:
	rm -f ./main.exe ./tests/*.exe
