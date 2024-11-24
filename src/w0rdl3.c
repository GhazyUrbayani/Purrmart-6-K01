#include "w0rdl3.h"

static const char daftarKata[TOTAL_KATA][UKURAN_KATA + 1] = {
    "BLOOM", "FLAME", "COAST", "PEACE", "WORLD",
    "PAINT", "SHINE", "DREAM", "SWIFT", "CHARM"
};

char keKapital(char huruf) {
    return (huruf >= 'a' && huruf <= 'z') ? (huruf - 32) : huruf;
}

void salinKata(char *tujuan, const char *sumber) {
    int i;
    for (i = 0; sumber[i] != '\0'; i++) {
        tujuan[i] = sumber[i];
    }
    tujuan[i] = '\0';
}

void bacaInput(char *buffer) {
    STARTWORDINPUT();
    int i;
    for (i = 0; i < UKURAN_KATA && i < currentWord.Length; i++) {
        buffer[i] = keKapital(currentWord.TabWord[i]);
    }
    buffer[i] = '\0';
}

void periksaTebakan(const char *jawaban, const char *tebakan, char *hasil) {
    int frekuensi[26] = {0};
    boolean sudahCocok[UKURAN_KATA] = {false};
    int posHasil = 0;
    int i;
    
    for (i = 0; i < UKURAN_KATA; i++) {
        if (tebakan[i] == jawaban[i]) {
            sudahCocok[i] = true;
        } else {
            frekuensi[jawaban[i] - 'A']++;
        }
    }
    
    for (i = 0; i < UKURAN_KATA; i++) {
        hasil[posHasil++] = tebakan[i];
        
        if (sudahCocok[i]) {
            hasil[posHasil++] = ' ';
        } else if (frekuensi[tebakan[i] - 'A'] > 0) {
            hasil[posHasil++] = '*';
            hasil[posHasil++] = ' ';
            frekuensi[tebakan[i] - 'A']--;
        } else {
            hasil[posHasil++] = '%';
            hasil[posHasil++] = ' ';
        }
    }
    hasil[posHasil] = '\0';
}

int w0rdl3() {
    char jawaban[UKURAN_KATA + 1];
    char tebakan[UKURAN_KATA + 1];
    char hasilTebakan[MAKS_TEBAKAN][UKURAN_KATA * 3 + 1];
    int jumlahTebakan = 0;
    int i;
    
    srand(time(NULL));
    salinKata(jawaban, daftarKata[rand() % TOTAL_KATA]);
    
    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n", MAKS_TEBAKAN);
    for (i = 0; i < MAKS_TEBAKAN; i++) {
        printf("_ _ _ _ _\n");
    }
    
    /* Main game loop */
    while (jumlahTebakan < MAKS_TEBAKAN) {
        printf("\nMasukan kata tebakan Anda: ");
        bacaInput(tebakan);
        
        /* Validasi input */
        if (currentWord.Length != UKURAN_KATA) {
            printf("Kata harus terdiri dari 5 huruf!\n");
            continue;
        }
        
        periksaTebakan(jawaban, tebakan, hasilTebakan[jumlahTebakan]);
        
        printf("Hasil:\n");
        for (i = 0; i <= jumlahTebakan; i++) {
            printf("%s\n", hasilTebakan[i]);
        }
        for (i = jumlahTebakan + 1; i < MAKS_TEBAKAN; i++) {
            printf("_ _ _ _ _\n");
        }
        
        boolean menang = true;
        for (i = 0; i < UKURAN_KATA; i++) {
            if (tebakan[i] != jawaban[i]) {
                menang = false;
                break;
            }
        }
        
        if (menang) {
            printf("Selamat, Anda menang!\n");
            printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
            return 1500;
        }
        
        jumlahTebakan++;
    }
    
    printf("Boo! Anda kalah.\n");
    printf("Kata yang benar adalah: %s\n", jawaban);
    return 0;
}

int main() {
    return w0rdl3();
}