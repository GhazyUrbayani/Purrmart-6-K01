#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "utils.h"


void *mem_salin(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}

size_t str_len(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void* alokasi_salin(const void *item, size_t itemSize) {
    void *newItem = malloc(itemSize);
    if (!newItem) {
        fprintf(stderr,"Gagal mengalokasi memori.\n");
        exit(EXIT_FAILURE);
    }
    mem_salin(newItem, item, itemSize);
    return newItem;
}

boolean str_compare(char s1[],char s2[]) {
    if (str_len(s1) != str_len(s2)) return false;
    while (*s1 != '\0') {
        if (*s1++ != *s2++) {
            return false;
        }
    }
    return true;
}

char *str_concat(char *s1, char *s2) {
    size_t l1 = str_len(s1); size_t l2 = str_len(s2);
    char *s3 = malloc (l1 + l2 + 1);
    
    size_t i = 0;
    for (; i < l1; i++) {
        s3[i] = s1[i];
    }

    size_t j = 0;
    for (; j < l2; j++) {
        s3[i + j] = s2[j];
    }

    s3[i+j] = '\0';

    return s3;
} 

char* str_copy(char* tobecopied) {
    return str_concat("",tobecopied);
}

void delay(double seconds) {
    clock_t start_time = clock(); // Get the current clock time
    double end_time = seconds * CLOCKS_PER_SEC;

    while ((clock() - start_time) < end_time) {
        // Busy-wait loop to simulate delay
    }
}
