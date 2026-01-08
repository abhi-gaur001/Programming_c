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

    // Open file in write mode
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot create file '%s'\n", filename);
        return 1;
    }

    printf("Enter text (type 'END' on a new line to stop):\n");

    // Read lines until user types "END"
    while (1) {
        fgets(line, sizeof(line), stdin);
        
        // Check if user typed "END"
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0) {
            break;
        }
        
        // Write line to file
        fprintf(fp, "%s", line);
    }

    // Close the file
    fclose(fp);
    printf("Text written to file '%s' successfully!\n", filename);

    return 0;
}
