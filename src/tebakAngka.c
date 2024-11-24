#include "tebakAngka.h"

int tebakAngka() {
    int targetNumber;
    int attempts = 10; 
    int guess;
    int uang = 500;   
    int penalty = 50; 
    boolean gameWon = false;
    Word input;
    time_t t;

    srand((unsigned)time(&t));
    
    targetNumber = (rand() % 100) + 1;
    
    printf("Tebak angka: ");
    while (attempts > 0 && !gameWon) {
        STARTWORDINPUT();
        
        guess = WordToInt(currentWord);
        
        if (guess == targetNumber) {
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda.\n", uang);
            gameWon = true;
            return uang;
        } else {
            attempts--;
            uang -= penalty; 
            
            if (attempts > 0) {
                if (guess < targetNumber) {
                    printf("Tebakanmu lebih kecil!\n");
                } else {
                    printf("Tebakanmu lebih besar!\n");
                }
                printf("Tebak angka: ");
            }
        }
    
        if (attempts == 0 && !gameWon) {
            printf("Maaf, kesempatan menebak telah habis.\n");
            printf("Angka yang benar adalah: %d\n", targetNumber);
            return 0;  
        }
    }
} 
 
int main() {
    int hasil = tebakAngka();
    printf("Skor akhir: %d\n", hasil);
    return 0;
}