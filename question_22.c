#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1000];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1; // read error or EOF
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    printf("Reversed string: ");
    for (size_t i = len; i > 0; i--) {
        putchar(str[i - 1]);
    }
    putchar('\n');

    return 0;
}
