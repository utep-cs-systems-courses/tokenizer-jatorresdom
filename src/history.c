#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a history ite
typedef struct Item {
  
  int id;
  char *str;
  struct Item *next;
} Item;

// Struct to represent the history list
typedef struct List {
  
  Item *head;
  Item *tail;
} List;

// Initialize the linked list to keep the history
List* init_history() {

  List *list = (List*)malloc(sizeof(List));
  if (list != NULL) {
    list->head = NULL;
    list->tail = NULL;
  }
  return list;
}

// Add a history item to the end of the list
void add_history(List *list, char *str) {

  if (list == NULL) {
    return;
  }
  Item *newItem = (Item*)malloc(sizeof(Item));
  if (newItem != NULL) {
    newItem->str = strdup(str); // Duplicate the input string
    newItem->next = NULL;
    if (list->tail == NULL) {
      // The list is empty
      newItem->id = 1;
      list->head = newItem;
      list->tail = newItem;
    } else {
      // Append to the end of the list
      newItem->id = list->tail->id + 1;
      list->tail->next = newItem;
      list->tail = newItem;
    }
  }
}

// Retrieve the string stored in the node where Item->id == id
char *get_history(List *list, int id) {

  if (list == NULL || list->head == NULL) {
    return NULL;
  }
  Item *current = list->head;
  while (current != NULL) {
    if (current->id == id) {
      return current->str;
    }
    current = current->next;
  }
  return NULL; // Item with the given id not found
}

// Print the entire contents of the list
void print_history(List *list) {
  if (list == NULL || list->head == NULL) {
    printf("History is empty.\n");
  }
  Item *current = list->head;
  while (current != NULL) {
    printf("Item %d: %s\n", current->id, current->str);
    current = current->next;
  }
}

// Free the history list and the strings it references
void free_history(List *list) {

  if (list == NULL) {
    return;
  }
  Item *current = list->head;
  while (current != NULL) {
    Item *next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  free(list);
}
