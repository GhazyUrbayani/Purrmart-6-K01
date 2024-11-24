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

Word SelectWord(WordList *wordList);

boolean IsInWordList(WordList *wordList);

Word GetValidInput(WordList *wordList);

char *checkGuess(Word word, Word tebakan, char hint[]);

void underscore(int n);

void Wordle (User *users);
#endif