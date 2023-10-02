#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char string[100];
  int choice;
  List *history = init_history();
  int numHistory;
  char *stringHistory;
  char specificString[100];

  printf("Welcome to my tokenizer!\n");
  
  while (1) {
    
    // Simple menu intro
    printf("1. Write 't' to tokenize a sentence.\n");
    printf("2. Write '!' followed by a sequence number to display that sentence\n");
    printf("3. Write '!h' to all the sentence in the history.\n");
    printf("4. Write 'q' to quit.\n");
    printf("Enter your answer: ");

    //Ask for an input
    fgets(string,100,stdin);
    choice = menuOpt(string);

    //Switch to decide what to do
    switch (choice) {
    case 1:
      printf("Please enter the sentence to be tokenize.\n");
      fgets(string,100,stdin);
      char **tokens = tokenize(string);
      printf("\n");
      print_tokens(tokens);
      add_history(history, *tokens);
      break;
    case 2:
      //specificString = get_history(history,int(string[1]));
      printf("Item in [%c]: ",&string);
      //printf("%c\n", specificString);
      
      break;
    case 3:
      print_history(history);
      free_history(history);
      printf("All the history is free!\n");
      break;
    case 4:
      printf("Thank you. Goodbye!\n");
      return 0;
    default:
      printf("Invalid input. Please try again.\n");
      break;
    } 
  }
  return 0;
}
