#include <stdio.h>
#include "../src/ADT/set.h"

int main() {
    Set s1, s2, result;
    printf("=== Test SET ===\n");
    CreateEmpty(&s1);

    printf("Test 1: Kondisi set setelah Ininialisasi\n");
    if (IsEmpty(s1)) {
        printf("Set kosong\n");
    } else {
        printf("Set tidak kosong\n");
    }
    printf("\n");

    printf("Test 2: Insert elemen\n");
    Insert(&s1, 1);
    Insert(&s1, 2);
    Insert(&s1, 3);
    printf("Set s1 setelah ditambahkan 1, 2, 3:\n");
    for(int i = 0; i < s1.Count; i++) {
        printf("%d ", s1.Elements[i]);
    }
    printf("\n");

    printf("Menambahkan elemen yang sama (2 lagi):\n");
    Insert(&s1, 2);
    for(int i = 0; i < s1.Count; i++) {
        printf("%d ", s1.Elements[i]);
    }
    printf("\n\n");

    printf("Test 3: IsMember\n");
    if (IsMember(s1, 2)) {
        printf("2 ada di dalam set\n");
    } else {
        printf("2 tidak ada di dalam set\n");
    }

    if (IsMember(s1, 5)) {
        printf("5 ada di dalam set\n");
    } else {
        printf("5 tidak ada di dalam set\n");
    }
    printf("\n\n");

    printf("Test 4: Delete elemen\n");
    printf("Sebelum menghapus 2:\n");
    for(int i = 0; i < s1.Count; i++) {
        printf("%d ", s1.Elements[i]);
    }
    printf("\n");

    Delete(&s1, 2);
    printf("Setelah menghapus 2:\n");
    for(int i = 0; i < s1.Count; i++) {
        printf("%d ", s1.Elements[i]);
    }
    printf("\n\n");

    printf("Test Operasi SET\n");
    CreateEmpty(&s2);
    Insert(&s2, 2);
    Insert(&s2, 3);
    Insert(&s2, 4);

    printf("Set s1: ");
    for(int i = 0; i < s1.Count; i++) {
        printf("%d ", s1.Elements[i]);
    }
    printf("\n");

    printf("Set s2: ");
    for(int i = 0; i < s2.Count; i++) {
        printf("%d ", s2.Elements[i]);
    }
    printf("\n\n"); 

    printf("Test 5: Hasil Union S1&S2\n");
    result = SetUnion(s1, s2);
    for(int i = 0; i < result.Count; i++) {
        printf("%d ", result.Elements[i]);
    }
    printf("\n\n");

    printf("Test 6: Hasi Intersection S1&S2\n");
    result = SetIntersection(s1, s2);
    for(int i = 0; i < result.Count; i++) {
        printf("%d ", result.Elements[i]);
    }
    printf("\n\n");

    printf("Test 7: Hasil Symetric Difference S1&S2\n");
    result = SetSymmetricDifference(s1, s2);
    for(int i = 0; i < result.Count; i++) {
        printf("%d ", result.Elements[i]);
    }
    printf("\n\n");

    printf("Test 8: Hasil Subtract S1-S2\n");
    result = SetSubtract(s1, s2);
    for(int i = 0; i < result.Count; i++) {
        printf("%d ", result.Elements[i]);
    }
    printf("\n\n");

    return 0;
}
