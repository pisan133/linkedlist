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

// add the value given before other
// if other is not in the list add value at the end
void addBefore(Node *node, int value, int other) {
  // TODO
}

// add the value given after other
// if other is not in the list add value at the end
void addAfter(Node *node, int value, int other) {
  // TODO
}

// add the value given in sorted order
void addSorted(Node *node, int value) {
  // TODO
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

/**
 * Run several tests, expected output is:
 * Starting list
 * 0 --> 20 --> 30 --> 40 --> 50 --> 60 --> NULL
 * Adding 25 to be before 30
 * 0 --> 20 --> 25 --> 30 --> 40 --> 50 --> 60 --> NULL
 * Adding 45 to be after 40
 * 0 --> 20 --> 25 --> 30 --> 40 --> 45 --> 50 --> 60 --> NULL
 * Adding 80 to be before 1000
 * 0 --> 20 --> 25 --> 30 --> 40 --> 45 --> 50 --> 60 --> 80 --> NULL
 * Adding 100 to be after 1000
 * 0 --> 20 --> 25 --> 30 --> 40 --> 45 --> 50 --> 60 --> 80 --> 100 --> NULL
 * Adding sorted 5
 * Adding sorted 31
 * Adding sorted 120
 * 0 --> 5 --> 20 --> 25 --> 30 --> 31 --> 40 --> 45 --> 50 --> 60 --> 80 --> 100 --> 120 --> NULL
 * Deleting 0
 * Deleting 5
 * Deleting 20
 * Deleting 25
 * Deleting 30
 * Deleting 31
 * Deleting 40
 * Deleting 45
 * Deleting 50
 * Deleting 60
 * Deleting 80
 * Deleting 100
 * Deleting 120
 *
 */
void testAddBeforeAfterSorted() {
  Node *startPtr = (Node *) malloc(sizeof(Node));
  startPtr->data = 0;
  startPtr->nextPtr = NULL;
  for (int i = 20; i < 70; i += 10) {
    add(startPtr, i);
  }
  printf("Starting list\n");
  print(startPtr);

  printf("Adding 25 to be before 30\n");
  addBefore(startPtr, 25, 30);
  print(startPtr);

  printf("Adding 45 to be after 40\n");
  addAfter(startPtr, 45, 40);
  print(startPtr);

  printf("Adding 80 to be before 1000\n");
  addBefore(startPtr, 80, 1000);
  print(startPtr);

  printf("Adding 100 to be after 1000\n");
  addAfter(startPtr, 100, 1000);
  print(startPtr);

  printf("Adding sorted 5\n");
  addSorted(startPtr, 5);
  printf("Adding sorted 31\n");
  addSorted(startPtr, 31);
  printf("Adding sorted 120\n");
  addSorted(startPtr, 120);
  print(startPtr);

  freeAll(startPtr);
}