#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode *next;
  struct studentNode *back;
};

void ShowAll(struct studentNode *walk);

struct studentNode *AddNode(struct studentNode **start, char name[], int age, char sex, float gpa) {
  struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->sex = sex;
  newNode->gpa = gpa;
  newNode->next = NULL;
  newNode->back = NULL;

  if (*start == NULL) {
    *start = newNode;
  } else {
    struct studentNode *temp = *start;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->back = temp;
  }

  return newNode;
}

void InsNode(struct studentNode *now, char name[], int age, char sex, float gpa) {
  struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->sex = sex;
  newNode->gpa = gpa;
  newNode->next = now;
  newNode->back = now->back;
  now->back->next = newNode;
  now->back = newNode;
}

void DelNode(struct studentNode *node) {
  if (node->back == NULL) {
    printf("Cannot delete start node\n");
    return;
  }
  node->back->next = node->next;
  if (node->next != NULL) {
    node->next->back = node->back;
  }
  free(node);
}

void GoBack(struct studentNode **now) {
  if ((*now)->back == NULL) {
    printf("Already at the start node\n");
    return;
  }
  *now = (*now)->back;
}

void ShowAll(struct studentNode *walk) {
  while (walk != NULL) {
    printf("%s ", walk->name);
    walk = walk->next;
  }
  printf("\n");
}

int main() {
  struct studentNode *start = NULL;
  struct studentNode *now = NULL;
  now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
  now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
  InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
  InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);
  GoBack(&now); DelNode(now); ShowAll(start);
  GoBack(&now); DelNode(now); ShowAll(start);
  GoBack(&now); DelNode(now); ShowAll(start);
  return 0;
}