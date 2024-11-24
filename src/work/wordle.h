#ifndef WORDLE_H
#define WORDLE_H

#include "./../ADT/mesinkata/mesinkata.h"
#include "./../structs/user.h"

#define MAX_WORDS 2135 // Maksimal kata yang ada di dalam file vocab.txt
typedef struct {
    Word words[MAX_WORDS];  // Array kata-kata
    int wordCount;          // Jumlah kata
} WordList;


/** 
 * Membuat Wordlist.
 * IS: Wordlist belum terisi.
 * FS: WordList terisi dengan kata-kata dari vocab.txt.
 */
void LoadWords(WordList *wordList); 

/// @brief mengambil kata random
/// @param wordList array kumpulan kata
/// @return kata random
Word SelectWord(WordList *wordList);

/// @brief cek apakah kata ada di array kumpulan kata
/// @param wordList array kumpulan kata
/// @param word kata yang ingin di cek
/// @return 
boolean IsInWordList(WordList *wordList,Word word);

/// @brief melakukan looping sampai kata yang diinput benar (berada di wordlist)
/// @param wordList 
/// @return kata yang valid
Word GetValidInput(WordList *wordList);

/// @brief 
/// @param word kata random wordle
/// @param tebakan input tebakan user
/// @param history hasil pengecekan/feedback hasil pengecekan
/// @return hasil pengecekan
char *checkGuess(Word word, Word tebakan, char history[]);

void Wordle (User *users);
#endif