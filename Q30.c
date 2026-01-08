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

    // Open file in append mode
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    printf("Enter text to append (type 'STOP' on a new line to finish):\n");

    // Read lines until user types "STOP"
    while (1) {
        fgets(line, sizeof(line), stdin);
        
        // Check if user typed "STOP"
        if (strcmp(line, "STOP\n") == 0 || strcmp(line, "STOP") == 0) {
            break;
        }
        
        // Append line to file
        fprintf(fp, "%s", line);
    }

    // Close the file
    fclose(fp);
    printf("Text appended to file '%s' successfully!\n", filename);

    return 0;
}
