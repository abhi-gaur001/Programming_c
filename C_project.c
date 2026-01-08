#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 

#define MAX_PATIENTS 100


struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

struct Patient patients[MAX_PATIENTS];
int count = 0;


int read_int() {
    char buffer[100];
    int valid = 0, value;

    while (!valid) {
        fgets(buffer, sizeof(buffer), stdin);

        int ok = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i]) && buffer[i] != '\n') {
                ok = 0;
            }
        }

        if (ok) {
            value = atoi(buffer);
            valid = 1;
        } else {
            printf("Invalid input! Enter digits only: ");
        }
    }
    return value;
}


int read_nonzero_int() {
    int x;
    while (1) {
        x = read_int();
        if (x == 0) {
            printf("ID cannot be 0. Enter again: ");
        } else {
            return x;
        }
    }
}


void read_string_alpha(char *str) {
    char buffer[100];

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);

        int valid = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isalpha(buffer[i]) && buffer[i] != ' ' && buffer[i] != '\n') {
                valid = 0;
            }
        }

        if (valid) {
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(str, buffer);
            return;
        } else {
            printf("Invalid input! Enter alphabets only: ");
        }
    }
}

// Add new patient
void add_patient() {
    if (count >= MAX_PATIENTS) {
        printf("Hospital database is full!\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    p.id = read_nonzero_int();

    printf("Enter Patient Name: ");
    read_string_alpha(p.name);

    printf("Enter Patient Age: ");
    p.age = read_int();

    printf("Enter Disease: ");
    read_string_alpha(p.disease);

    patients[count++] = p;

    printf("\nPatient added successfully!\n");
}

// Display all patients
void display_patients() {
    if (count == 0) {
        printf("No patients found!\n");
        return;
    }

    printf("\n---- Patient Records ----\n");
    for (int i = 0; i < count; i++) {
        printf("\nPatient %d:\n", i + 1);
        printf("ID      : %d\n", patients[i].id);
        printf("Name    : %s\n", patients[i].name);
        printf("Age     : %d\n", patients[i].age);
        printf("Disease : %s\n", patients[i].disease);
    }
}

// Search patient by ID
void search_patient() {
    int id;
    printf("\nEnter ID to search: ");
    id = read_int();

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("\nPatient Found:\n");
            printf("ID      : %d\n", patients[i].id);
            printf("Name    : %s\n", patients[i].name);
            printf("Age     : %d\n", patients[i].age);
            printf("Disease : %s\n", patients[i].disease);
            return;
        }
    }
    printf("Patient not found!\n");
}

// Delete patient
void delete_patient() {
    int id, found = -1;

    printf("\nEnter ID to delete: ");
    id = read_int();

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Patient not found!\n");
        return;
    }

    for (int i = found; i < count - 1; i++) {
        patients[i] = patients[i + 1];
    }

    count--;
    printf("Patient deleted successfully!\n");
}

// Main menu
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
            case 2: display_patients(); break;
            case 3: search_patient(); break;
            case 4: delete_patient(); break;
            case 5: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
