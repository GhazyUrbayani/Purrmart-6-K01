# include <stdio.h>
# include <time.h>
# include "./../structs/user.h"
# include "./../ADT/mesinkata/mesinkata.h"
# include "./../ADT/boolean.h"
# include "./../ADT/mesinkarakter/mesinkarakter.h"
# include "./wordle.h"

void LoadWords(WordList *wordList){
    wordList->wordCount = 0;
    const char *filename = "./ADT/data/vocab.txt";
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
    int idx = rand() % (*wordList).wordCount;
    return (*wordList).words[idx];
}

boolean IsInWordList(WordList *wordList, Word word){
    for (int i = 0; i < (*wordList).wordCount; i++) {
        currentWord = (*wordList).words[i];
        if (WordEqual(word)) {
            return true;
        }
    }
    return false;
}
Word GetValidInput(WordList *wordList){
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

char *checkGuess(Word word, Word tebakan, char hint[]){
    boolean used[5] = {false}; // Menandai huruf yang sudah digunakan

    // Awalnya, isi hint dengan tebakan dan tanda untuk huruf salah
    for (int i = 0; i < 5; i++) {
        hint[i * 3] = tebakan.TabWord[i]; // Huruf dari tebakan
        hint[i * 3 + 1] = '%';           // Default: tanda untuk huruf salah
        hint[i * 3 + 2] = ' ';           // Spasi setelah tanda
    }

    // Tandai huruf yang benar dan di posisi yang benar
    for (int i = 0; i < 5; i++) {
        if (tebakan.TabWord[i] == word.TabWord[i]) {
            hint[i * 3 + 1] = ' '; // Tidak diberi tanda
            used[i] = true;        // Tandai huruf ini sudah benar
        }
    }

    // Tandai huruf yang benar tetapi di posisi yang salah
    for (int i = 0; i < 5; i++) {
        if (hint[i * 3 + 1] == '%') { // Hanya periksa huruf yang belum benar
            for (int j = 0; j < 5; j++) {
                if (!used[j] && tebakan.TabWord[i] == word.TabWord[j]) {
                    hint[i * 3 + 1] = '*'; // Tandai posisi salah
                    used[j] = true;       // Tandai huruf ini sudah digunakan
                    break;
                }
            }
        }
    }

    hint[15] = '\0';
    return hint;
}

void printHistory(char history[][16], int attempts) {
    for (int i = 0; i < attempts; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%c", history[i][j]);
        }
        printf("\n");
    }
}

void underscore(int n){
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < 5; j++) { 
            printf("_ ");
        }
        printf("\n"); // Pindah ke baris berikutnya
    }
}

void Wordle (User *users){
    (*users).money -= 500;
    WordList wordList;
    LoadWords(&wordList);
    Word word = SelectWord(&wordList);
    int hadiah = 10000;
    int nyawa = 6;
    char history[6][16]; // Setiap feedback maksimal 15 karakter + null-terminator
    int percobaan = 0;
    printf("WELCOME TO W0RDL3, YOU HAVE 6 CHANCES TO ANSWER BEFORE YOU LOSE\n");
    underscore(nyawa);
    while (nyawa > 0) {
        currentWord = GetValidInput(&wordList);
        checkGuess(word,  currentWord , history[percobaan]);
        printHistory(history, percobaan + 1);
        if (WordEqual(word)) {
            (*users).money += hadiah;
            printf("\n");
            printf("YEYYY!!! KAMU BERHASIL MENEBAK KATA YANG BENAR\n");
            printf("KAMU MENDAPATKAN %d KOIN.\n", hadiah);
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