#include <stdio.h>

struct student {
    char name[50];
    int age;
    float grade;
};

struct student (*GetStudent(int *room))[10] {
    printf("Enter the number of classrooms: ");
    scanf("%d", room);

    struct student (*children)[10] = new struct student[*room][10];

    for (int i = 0; i < *room; i++) {
        printf("Enter information for classroom %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d:\n", j + 1);
            printf("Name: ");
            scanf("%s", children[i][j].name);
            printf("Age: ");
            scanf("%d", &children[i][j].age);
            printf("Grade: ");
            scanf("%f", &children[i][j].grade);
        }
    }

    return children;
}

void FreeMemory(struct student (*children)[10]) {
    delete[] children;
}

void PrintStudent(struct student (*children)[10], int room) {
    for (int i = 0; i < room; i++) {
        printf("Classroom %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("Student %d:\n", j + 1);
            printf("Name: %s\n", children[i][j].name);
            printf("Age: %d\n", children[i][j].age);
            printf("Grade: %.2f\n", children[i][j].grade);
        }
    }
}

int main() {
    struct student (*children)[10];
    int group;
    children = GetStudent(&group);
    PrintStudent(children, group);
    FreeMemory(children);

    return 0;
}
