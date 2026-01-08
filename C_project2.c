#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient p[MAX];
int count = 0;

// Read valid integer
int read_int() {
    char s[50];
    int i;

    while (1) {
        fgets(s, sizeof(s), stdin);

        int ok = 1;
        for (i = 0; s[i] != '\0'; i++) {
            if (!isdigit(s[i]) && s[i] != '\n') {
                ok = 0;
                break;
            }
        }

        if (ok) return atoi(s);

        printf("Enter digits only: ");
    }
}

// Read only alphabets
void read_alpha(char *out) {
    char s[50];

    while (1) {
        fgets(s, sizeof(s), stdin);

        int ok = 1;
        for (int i = 0; s[i] != '\0'; i++) {
            if (!isalpha(s[i]) && s[i] != ' ' && s[i] != '\n') {
                ok = 0;
                break;
            }
        }

        if (ok) {
            s[strcspn(s, "\n")] = '\0';
            strcpy(out, s);
            return;
        }

        printf("Enter alphabets only: ");
    }
}

// Add Patient
void add_patient() {
    if (count >= MAX) {
        printf("Database full!\n");
        return;
    }

    struct Patient temp;
    
    printf("\nEnter Patient ID: ");
    temp.id = read_int();
    if (temp.id == 0) {
        printf("ID cannot be 0!\n");
        return;
    }

    printf("Enter Name: ");
    read_alpha(temp.name);

    printf("Enter Age: ");
    temp.age = read_int();

    printf("Enter Disease: ");
    read_alpha(temp.disease);

    p[count++] = temp;
    printf("Patient added!\n");
}

// Display Patients
void display() {
    if (count == 0) {
        printf("No patients found!\n");
        return;
    }

    printf("\n---- All Patients ----\n");
    for (int i = 0; i < count; i++) {
        printf("\nID      : %d\n", p[i].id);
        printf("Name    : %s\n", p[i].name);
        printf("Age     : %d\n", p[i].age);
        printf("Disease : %s\n", p[i].disease);
    }
}

// Search Patient
void search() {
    printf("\nEnter ID to search: ");
    int id = read_int();

    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nPatient Found:\n");
            printf("ID      : %d\n", p[i].id);
            printf("Name    : %s\n", p[i].name);
            printf("Age     : %d\n", p[i].age);
            printf("Disease : %s\n", p[i].disease);
            return;
        }
    }

    printf("Patient not found!\n");
}

// Delete Patient
void delete() {
    printf("\nEnter ID to delete: ");
    int id = read_int();

    int pos = -1;
    for (int i = 0; i < count; i++) {
        if (p[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Patient not found!\n");
        return;
    }

    for (int i = pos; i < count - 1; i++) {
        p[i] = p[i + 1];
    }

    count--;
    printf("Patient deleted!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== HOSPITAL MANAGEMENT SYSTEM =====\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        choice = read_int();

        switch (choice) {
            case 1: add_patient(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: delete(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
