#include <stdio.h>

struct student {
    char name[50];
    int age;
    float grade;
};

void GetStudent(struct student child[][10], int *room);

int main() {
    struct student children[20][10];
    int group;
    GetStudent(children, &group);
    return 0;
}

void GetStudent(struct student child[][10], int *room) {
    printf("Enter the number of classrooms: ");
    scanf("%d", room);

    for (int i = 0; i < *room; i++) {
        printf("Enter information for classroom %d:\n", i + 1);
        for (int j = 0; j < 2; j++) {
            printf("Student %d:\n", j + 1);
            printf("Name: ");
            scanf("%s", child[i][j].name);
            printf("Age: ");
            scanf("%d", &child[i][j].age);
            printf("Grade: ");
            scanf("%f", &child[i][j].grade);
        }
    }
}
