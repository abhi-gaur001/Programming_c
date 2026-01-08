#include <stdio.h>
#include <string.h>

int main(void) {
    char filename[100];
    char line[256];
    FILE *fp;

    // Ask user for filename
    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove trailing newline from filename
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    // Open file in read mode
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    printf("\n===== FILE CONTENTS =====\n");

    // Read entire file line by line and display
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    printf("===== END OF FILE =====\n");

    // Close the file
    fclose(fp);
    printf("File '%s' read successfully!\n", filename);

    return 0;
}
