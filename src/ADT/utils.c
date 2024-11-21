#include <stdlib.h>
#include "utils.h"
#include <stdio.h>

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
