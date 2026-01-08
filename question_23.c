#include <stdio.h>
#include <ctype.h>
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

    int vowels = 0, consonants = 0, digits = 0, special = 0;

    for (size_t i = 0; i < len; i++) {
        char ch = str[i];
        if (isalpha((unsigned char)ch)) {
            char lower = (char)tolower((unsigned char)ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit((unsigned char)ch)) {
            digits++;
        } else {
            // everything else (including spaces, punctuation) counted as special
            special++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special);

    return 0;
}
