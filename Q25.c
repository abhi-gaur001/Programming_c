#include <stdio.h>
#include <string.h>

#define N_STUDENTS 5
#define NAME_LEN 51 // 50 chars + null terminator

typedef struct {
    char name[NAME_LEN];
    int sap_id;
    float marks;
} Student;

int main(void) {
    Student students[N_STUDENTS];

    for (int i = 0; i < N_STUDENTS; i++) {
        printf("Enter details for student %d:\n", i + 1);

        // Read name (may contain spaces)
        printf("  Name: ");
        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            // input error or EOF
            students[i].name[0] = '\0';
        } else {
            // strip trailing newline if present
            size_t ln = strlen(students[i].name);
            if (ln > 0 && students[i].name[ln - 1] == '\n')
                students[i].name[ln - 1] = '\0';
        }

        // Read SAP ID
        printf("  SAP ID: ");
        if (scanf("%d", &students[i].sap_id) != 1) {
            students[i].sap_id = 0; // fallback
        }

        // Read marks
        printf("  Marks: ");
        if (scanf("%f", &students[i].marks) != 1) {
            students[i].marks = 0.0f;
        }

        // consume the rest of the line including newline so next fgets works
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        printf("\n");
    }

    printf("Details of all students:\n");
    for (int i = 0; i < N_STUDENTS; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name  : %s\n", students[i].name);
        printf("  SAP ID: %d\n", students[i].sap_id);
        printf("  Marks : %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}
