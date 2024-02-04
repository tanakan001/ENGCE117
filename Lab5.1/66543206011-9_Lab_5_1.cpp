#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void DelNode(struct studentNode **walk );
void InsNode(struct studentNode **walk, char name[], int age, char sex, float gpa, struct studentNode **begin);
void showAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa);

int main() {
	
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11);		showAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);		showAll(start);
    InsNode(&now, "three", 10, 'M', 3.33, &start);	showAll(start);
    InsNode(&now, "four", 12, 'F', 3.44, &start);	showAll(start);
    DelNode(&now);	showAll(start);
    return 0;
    
}
void showAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf( "%s " , walk->name );
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **walk, char name[], int age, char sex, float gpa) {
	struct studentNode *temp = NULL;
	while( *walk != NULL){
		walk = &(*walk)->next;
	}
    *walk = new struct studentNode;
    strcpy((*walk)->name, name);
    (*walk)->age = age;
    (*walk)->sex = sex;
    (*walk)->gpa = gpa;
    (*walk)->next = NULL;
	return *walk;
}

void InsNode(struct studentNode **walk, char name[], int age, char sex, float gpa, struct studentNode **begin) {
	
	if( walk != NULL ){
	struct studentNode *temp = new struct studentNode;
    strcpy(temp->name, name);
    temp->age = age;
    temp->sex = sex;
    temp->gpa = gpa;
    temp->next = (*walk)->next;
    (*walk)->next = temp;
	}
    else{
    *begin = new struct studentNode;
    strcpy((*begin)->name, name);
    (*begin)->age = age;
    (*begin)->sex = sex;
    (*begin)->gpa = gpa;
    (*begin)->next = *walk;
    *walk = *begin;
	}
}

void DelNode(struct studentNode **walk) {
    struct studentNode *temp;

    if (*walk != NULL) {
    	temp = (*walk)->next;
        DelNode(&((*walk)->next));
        delete *walk;
        *walk = temp;
    }
}
