/**
 * Linked list implementation
 *
 * For simplicity, the Linked List starts with 0 as first element
 */

#include <stdio.h>
#include <stdlib.h>

// self-referential Node structure
struct Node {
  // each Node contains an int
  int data;
  // pointer to next node */
  struct Node *nextPtr;
};

// synonym for struct Node
typedef struct Node Node;

// get an int from keyboard
int getInt(const char *prompt) {
  char *cstr;
  char buffer[256];
  printf("%s", prompt);
  cstr = fgets(buffer, 255, stdin);
  return atoi(cstr);
}

// print all nodes starting from given node
void print(Node *curr) {
  while (curr != NULL) {
    printf("%d --> ", curr->data);
    curr = curr->nextPtr;
  }
  printf("NULL\n");
}

// add a new item to the end of the list
void add(Node *curr, int value) {
  // create new node
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->data = value;
  newNode->nextPtr = NULL;
  // fid the tail
  while (curr->nextPtr != NULL) {
    curr = curr->nextPtr;
  }
  curr->nextPtr = newNode;
}

// free all nodes
void freeAll(Node *curr) {
  while (curr != NULL) {
    Node *todelete = curr;
    curr = curr->nextPtr;
    printf("Deleting %d\n", todelete->data);
    free(todelete);
  }
}

// get new values from user and add them to the list
void testInteractive() {
  // head is set to a node instead of NULL for simplicity
  Node *head = (Node *) malloc(sizeof(Node));
  head->data = 0;
  head->nextPtr = NULL;
  int input = getInt("Enter a number (-1 to end): ");
  while (input != -1) {
    add(head, input);
    print(head);
    input = getInt("Enter a number (-1 to end): ");
  }
  freeAll(head);
}

