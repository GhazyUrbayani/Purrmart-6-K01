# include <stdio.h>
# include <time.h>
# include "./../structs/user.h"
# include "./../ADT/mesinkata/mesinkata.h"
# include "./../ADT/boolean.h"
# include "./../ADT/mesinkarakter/mesinkarakter.h"
# include "./wordle.h"

void LoadWords(WordList *wordList){
    wordList->wordCount = 0;
    const char *filename = "./data/vocab.txt";
    STARTWORD(filename);
    while(!EndWord&&(*wordList).wordCount<MAX_WORDS){
        (*wordList).words[(*wordList).wordCount] = currentWord;
        wordList->wordCount++;
        ADVWORD();
    }
     if ((*wordList).wordCount == 0) {
        printf("Error: Tidak ada kata yang terbaca dari file '%s'.\n", filename);
    }
}

Word SelectWord(WordList *wordList){ 
    srand(time(NULL));
    int idx = rand() % (*wordList).wordCount; // randomize the index
    return (*wordList).words[idx]; // get the randomize word
}

boolean IsInWordList(WordList *wordList, Word word){ // check if the word is in the wordlist
    for (int i = 0; i < (*wordList).wordCount; i++) {
        currentWord = (*wordList).words[i];
        if (WordEqual(word)) {
            return true;
        }
    }
    return false;
}
Word GetValidInput(WordList *wordList){ // get the valid input, will not decrease the attempt 
    Word input;
    boolean valid = false;
    while (!valid) {
        printf("Masukkan kata: ");
        STARTWORDINPUT();
        input = currentWord;
        if (IsInWordList(wordList, input)) {
            valid = true;
        } else {
            printf("Kata tidak valid. Silakan coba lagi.\n");
        }
    }
    return input;
}

char *checkGuess(Word word, Word tebakan, char history[]){
    boolean used[5] = {false};  // initialze that every character in the word has not been used
    for (int i = 0; i < 5; i++) { // initialize every input character is wrong
        history[i * 3] = tebakan.TabWord[i]; 
        history[i * 3 + 1] = '%';           
        history[i * 3 + 2] = ' ';           
    }
    for (int i = 0; i < 5; i++) { // check if the character is in the true position
        if (tebakan.TabWord[i] == word.TabWord[i]) {
            history[i * 3 + 1] = ' '; 
            used[i] = true;    // the character is set as used   
        }
    }
    for (int i = 0; i < 5; i++) {
        if (history[i * 3 + 1] == '%') { //only check the wrong character to search is there any right character in the wrong position
            for (int j = 0; j < 5; j++) {
                if (!used[j] && tebakan.TabWord[i] == word.TabWord[j]) {
                    history[i * 3 + 1] = '*'; 
                    history[j] = true;       // the character is set as used   
                }
            }
        }
    }

    history[15] = '\0'; // set the null terminator
    return history;
}

void printHistory(char history[][16], int percobaan) {
    for (int i = 0; i < percobaan; i++) { //print the previous also the current guess with their feedback
        for (int j = 0; j < 15; j++) {
            printf("%c", history[i][j]);
        }
        printf("\n");
    }
}

void Wordle (User *users){
    (*users).money -= 500; // biaya awal
    WordList wordList;
    LoadWords(&wordList);
    Word word = SelectWord(&wordList); // get the random word
    int hadiah = 10000;
    int nyawa = 6;
    char history[6][16]; // store the hint from checkguess feedback
    int percobaan = 0;
    printf("WELCOME TO W0RDL3, YOU HAVE 6 CHANCES TO ANSWER BEFORE YOU LOSE\n");
    printf("_ _ _ _ _\n _ _ _ _ _\n _ _ _ _ _\n _ _ _ _ _\n _ _ _ _ _\n _ _ _ _ _\n");
    while (nyawa > 0) {
        currentWord = GetValidInput(&wordList);
        checkGuess(word,  currentWord , history[percobaan]);
        printHistory(history, percobaan + 1);
        if (WordEqual(word)) {
            (*users).money += hadiah;
            printf("\n");
            printf("YEYYY!!! KAMU BERHASIL MENEBAK KATA YANG BENAR\n");
            printf("KAMU MENDAPATKAN %d RUPIAH.\n", hadiah);
            return;
        } else {
            nyawa--;
            percobaan++;
        }
    }
    printf("YAHHH KAMU KALAH\n Kata yang benar adalah: ");
    for (int i = 0; i < word.Length; i++) {
        printf("%c", word.TabWord[i]);
    }
    printf("\n");
}