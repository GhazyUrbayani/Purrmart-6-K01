#include "save.h"

void SAVE(SList *users, DList *items, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    // Write items to file
    WriteItems(items, file);

    // Write users to file
    WriteUsers(users, file);

    fclose(file); // Close the file
    printf("Data successfully written to %s.\n", filename);
}