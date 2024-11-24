#include "save.h"
#include "./../ADT/utils.h"

void SAVE(SList *users, DList *items, char *filename) {
    char *dest = str_concat("./save/",filename);
    FILE *file = fopen(dest, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    // Write items to file
    WriteItems(items, file);

    // Write users to file
    us_WriteUsers(users, file);

    fclose(file); // Close the file
    printf("Data successfully written to %s.\n", filename);
}
