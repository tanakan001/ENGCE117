#include <stdio.h>
#include <string.h>

struct StudentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    StudentNode* next;
};

void showAll(StudentNode* walk);

StudentNode* AddNode(StudentNode** start, const char name[], int age, char sex, float gpa);
void InsNode(StudentNode* now, const char name[], int age, char sex, float gpa);
void DelNode(StudentNode* now);

int main() {
    StudentNode* start = nullptr;
    StudentNode* now = AddNode(&start, "one", 6, 'M', 3.11);
    showAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    showAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    showAll(start);

    InsNode(now, "four", 12, 'F', 3.44);
    showAll(start);

    DelNode(now);
    showAll(start);

    return 0;
}

void showAll(StudentNode* walk) {
    while (walk != nullptr) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

StudentNode* AddNode(StudentNode** start, const char name[], int age, char sex, float gpa) {
    StudentNode* newNode = new StudentNode;

    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = nullptr;

    if (*start == nullptr) {
        *start = newNode;
    } else {
        StudentNode* walk = *start;
        while (walk->next != nullptr) {
            walk = walk->next;
        }
        walk->next = newNode;
    }

    return newNode;
}

void InsNode(StudentNode* now, const char name[], int age, char sex, float gpa) {
    if (now == nullptr) {
        fprintf(stderr, "Invalid insertion point.\n");
        return;
    }

    StudentNode* newNode = new StudentNode;

    strncpy(newNode->name, name, sizeof(newNode->name));
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = now->next;
    now->next = newNode;
}

void DelNode(StudentNode* now) {
    if (now == nullptr || now->next == nullptr) {
        fprintf(stderr, "Invalid deletion point.\n");
        return;
    }

    StudentNode* temp = now->next;
    now->next = temp->next;
    delete temp;
}
