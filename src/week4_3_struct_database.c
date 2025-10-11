#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// student struct (same like before)
struct Student {
    char name[50];
    int id;
    float grade;
};

void clean_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() {
    int n;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wrong number\n");
        return 1;
    }
    clean_input();

    // malloc for students
    struct Student *list = malloc(n * sizeof(struct Student));
    if (!list) {
        printf("Memory fail\n");
        return 1;
    }

    // get students
    for (int i = 0; i < n; i++) {
        printf("Student %d name: ", i + 1);
        fgets(list[i].name, 50, stdin);
        // remove \n
        size_t len = strlen(list[i].name);
        if (len > 0 && list[i].name[len - 1] == '\n') {
            list[i].name[len - 1] = '\0';
        }

        printf("Student %d ID: ", i + 1);
        scanf("%d", &list[i].id);

        printf("Student %d grade: ", i + 1);
        scanf("%f", &list[i].grade);
        clean_input();
    }

    // print table
    printf("\n%-10s %-20s %-10s\n", "ID", "Name", "Grade");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.1f\n", list[i].id, list[i].name, list[i].grade);
    }

    // little average
    float total = 0;
    for (int i = 0; i < n; i++) total += list[i].grade;
    printf("\nAverage grade: %.2f\n", total / n);

    free(list);
    return 0;
}