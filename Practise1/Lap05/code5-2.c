#include <stdio.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode * next;
};

void ShowAll(struct studentNode ** walk);
struct studentNode * AddNode(struct studentNode ** head, char n[], int a, char s, float g);
void InsNode(struct studentNode * prev, char n[], int a, char s, float g);
void DelNode(struct studentNode * prev);

int main() {
  struct studentNode * start, ** now;
  start = NULL;
  now = & start;
  InsNode(now, "one", 6, 'M', 3.11);
  ShowAll(&start);
  InsNode(now, "two", 8, 'F', 3.22);
  ShowAll(&start);
  now = &((*now)->next);
  InsNode(now, "three", 10, 'M', 3.33);
  ShowAll(&start);
  InsNode(now, "four", 12, 'F', 3.44);
  ShowAll(&start);
  now = &((*now)->next);
  DelNode(now);
  ShowAll(&start);
  return 0;
} //end function

void ShowAll(struct studentNode ** walk) {
    while (*walk != NULL) {
      printf("%s ", (*walk)->name);
      walk = &(*walk)->next;
    } //end while
    printf("\n");
} //end function

struct studentNode * AddNode(struct studentNode ** head, char n[], int a, char s, float g) {
  struct studentNode * newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
  strcpy(newNode->name, n);
  newNode->age = a;
  newNode->sex = s;
  newNode->gpa = g;
  newNode->next = *head;
  *head = newNode;
  return newNode;
} //end function

void InsNode(struct studentNode * prev, char n[], int a, char s, float g) {
  struct studentNode * newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
  strcpy(newNode->name, n);
  newNode->age = a;
  newNode->sex = s;
  newNode->gpa = g;
  newNode->next = prev->next;
  prev->next = newNode;
} //end function

void DelNode(struct studentNode * prev) {
  struct studentNode * temp = prev->next;
  prev->next = temp->next;
  free(temp);
} //end function
