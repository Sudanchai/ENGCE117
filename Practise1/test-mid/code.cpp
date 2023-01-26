//แดนชัย สุรินทร์ รหัส65543206058-1 sec 2

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

void UpdateNode(struct StructureNode ** head, int ref, int want) {
  if ( * head == NULL)
    return;
  struct StructureNode * prevref = NULL, * currref = * head;
  while (currref && currref -> data != ref) {
    prevref = currref;
    currref = currref -> next;
  }

  if (currref == NULL)
    return;

  currref -> data = want;
} //end function

void SwapNode(struct StructureNode ** head, int first, int second) {
  if ( * head == NULL)
    return;
  struct StructureNode * prevfirst = NULL, * currfirst = * head;
  while (currfirst && currfirst -> data != first) {
    prevfirst = currfirst;
    currfirst = currfirst -> next;
  }

  struct StructureNode * prevsecond = NULL, * currsecond = * head;
  while (currsecond && currsecond -> data != second) {
    prevsecond = currsecond;
    currsecond = currsecond -> next;
  }

  if (currfirst == NULL || currsecond == NULL)
    return;

  if (prevfirst != NULL)
    prevfirst -> next = currsecond;
  else
    *
    head = currsecond;

  if (prevsecond != NULL)
    prevsecond -> next = currfirst;
  else
    *
    head = currfirst;

  struct StructureNode * temp = currsecond -> next;
  currsecond -> next = currfirst -> next;
  currfirst -> next = temp;
} //end function

void Showback(struct StructureNode * node) {
  if (node == NULL) {
    return;
  }
  Showback(node -> next);
  printf("%d ", node -> data);
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
  UpdateNode( & head, 10, 99);
  ShowAll(head);
  printf("\n Update_Node 10 to 98 \n");
  UpdateNode( & head, 10, 98);
  ShowAll(head); //99, 20, 30, 40
  printf("\n------------------------------\n");
  printf(" Showback\n");
  Showback(head);
  //ShowAll(head); //40, 30, 20, 99
  printf("\n------------------------------\n");
  printf(" SwapNode\n");
  SwapNode( & head, 40, 20);
  ShowAll(head); //99, 40, 30, 20
}
