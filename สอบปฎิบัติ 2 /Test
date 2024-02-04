#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    struct studentNode *next;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **walk, const char *name);
void swapNodes( studentNode **head, char *name1, char *name2);

int main() {
    char A[20] ;
    char B[20] ;
    studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one");
    now = AddNode(&start, "two");
    now = AddNode(&start, "three");
    now = AddNode(&start, "four");
    printf("Original Node: ");
    ShowAll(start);

    printf("Name Node A: ");
    scanf(" %s", &A);

    printf("Name Node B: ");
    scanf(" %s", &B);

    
    swapNodes(&start, A, B);
    printf("New Node: ");
    ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode* walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode* AddNode(struct studentNode** walk, const char* name) {
    while (*walk != NULL) {
        walk = &(*walk)->next;
    }

    *walk = new struct studentNode;
    strcpy((*walk)->name, name);
    (*walk)->next = NULL;
    return *walk;
}

void swapNodes( studentNode **head, char *name1, char *name2) {
    
    struct studentNode* node1 = NULL, * node2 = NULL;
    struct studentNode* now = *head;
    while (now != NULL) {
        if (strcmp(now->name, name1) == 0) {
            node1 = now;
        } else if (strcmp(now->name, name2) == 0) {
            node2 = now;
        }
        now = now->next;
    }
    char temp[20];
    strcpy(temp, node1->name);
    strcpy(node1->name, node2->name);
    strcpy(node2->name, temp);
}
