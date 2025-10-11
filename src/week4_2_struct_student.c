#include <stdio.h>
#include <string.h>

// basic student struct
struct Student {
    char name[50];
    int id;
    float grade;
};

int main() {
    struct Student s1;
    struct Student s2; // just two students for this task

    // set values (not using input here)
    strcpy(s1.name, "Mustafa Akhan");
    s1.id = 999;
    s1.grade = 9.1f;

    strcpy(s2.name, "John Wick");
    s2.id = 001;
    s2.grade = 8.7f;

    // print students
    printf("Student 1 -> Name: %s, ID: %d, Grade: %.1f\n", s1.name, s1.id, s1.grade);
    printf("Student 2 -> Name: %s, ID: %d, Grade: %.1f\n", s2.name, s2.id, s2.grade);

    // nothing else to do
    return 0;
}