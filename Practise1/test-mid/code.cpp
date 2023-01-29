//แดนชัย สุรินทร์ รหัส65543206058-1 sec 2
//https://youtu.be/bD_0HRGD1EY

#include <stdio.h>
#include <stdlib.h>

struct StructureNode {
  int data;
  struct StructureNode * next;
};

void AddNode(struct StructureNode ** head, int newData) {
  struct StructureNode * newNode = (struct StructureNode * ) malloc(sizeof(struct StructureNode));
  newNode -> data = newData;
  newNode -> next = NULL;

  if ( * head == NULL) {
    * head = newNode;
    return;
  }

  struct StructureNode * curr = * head;
  struct StructureNode * prev = NULL;
  while (curr != NULL) {
    prev = curr;
    curr = curr -> next;
  }
  prev -> next = newNode;
} //end function

void ShowAll(struct StructureNode * head) {
  struct StructureNode * temp = head;
  while (temp != NULL) {
    printf("%d ", temp -> data);
    temp = temp -> next;
  }
  printf(" ");
} //end function

void UpdateNode(struct StructureNode * head, int ref, int want) {
  struct StructureNode * curr = head;
  while (curr && curr -> data != ref) {
    curr = curr -> next;
  }
  if (curr) {
    curr -> data = want;
  }
} //end function

void SwapNode(struct StructureNode ** head, int first, int second) {
  if (head == NULL || first == second) return;

  struct StructureNode * firstNode = * head, * secondNode = * head;
  struct StructureNode * prevFirst = NULL, * prevSecond = NULL;

  while (firstNode && firstNode -> data != first) {
    prevFirst = firstNode;
    firstNode = firstNode -> next;
  }
  while (secondNode && secondNode -> data != second) {
    prevSecond = secondNode;
    secondNode = secondNode -> next;
  }

  if (firstNode == NULL || secondNode == NULL) return;

  if (prevFirst) {
    prevFirst -> next = secondNode;
  } else * head = secondNode;

  if (prevSecond) {
    prevSecond -> next = firstNode;
  } else * head = firstNode;

  struct StructureNode * temp = secondNode -> next;
  secondNode -> next = firstNode -> next;
  firstNode -> next = temp;
} //end function

void Showback(struct StructureNode * head) {
  if (head == NULL) return;
  Showback(head -> next);
  printf("%d ", head -> data);
} //end function

int main() {

  struct StructureNode * head = NULL;

  AddNode( & head, 10);
  AddNode( & head, 20);
  AddNode( & head, 30);
  AddNode( & head, 40);
  ShowAll(head); //10, 20, 30, 40
  printf("\n------------------------------\n");
  printf(" Update_Node 10 to 99 \n");
  UpdateNode(head, 10, 99);
  ShowAll(head);
  printf("\n Update_Node 10 to 98 \n");
  UpdateNode(head, 10, 98);
  ShowAll(head); //99, 20, 30, 40
  printf("\n------------------------------\n");
  printf(" Showback\n");
  Showback(head);
  //ShowAll(head); //40, 30, 20, 99
  printf("\n------------------------------\n");
  printf(" SwapNode\n");
  SwapNode( & head, 30, 40);
  ShowAll(head); //99, 40, 30, 20
}
