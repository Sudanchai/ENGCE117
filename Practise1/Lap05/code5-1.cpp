#include <stdio.h>
#include <string.h>

struct studentNode {
  char name[20];
  int age;
  char sex;
  float gpa;
  struct studentNode * next;
};

void showAll(struct studentNode * walk) {
  while (walk != NULL) {
    printf("%s ", walk -> name);
    walk = walk -> next;
  } //end while
  printf(" ");
} //end function

void AddNode(struct studentNode * child, const char * n, int a, char s, float g){
    strcpy(child -> name, n);
    child -> age = a;
    child -> sex = s;
    child -> gpa = g;
}

void InsNode(){
    
}

void DelNode(){
    
}

int main() {
  struct studentNode * start, * now;
  start = NULL;
  now = AddNode( & start, "one", 6, 'M', 3.11);
  ShowAll(start);
  now = AddNode( & start, "two", 8, 'F', 3.22);
  ShowAll(start);
  InsNode(now, "three", 10, 'M', 3.33);
  ShowAll(start);
  InsNode(now, "four", 12, 'F', 3.44);
  ShowAll(start);
  DelNode(now);
  ShowAll(start);
  return 0;
} //end function
