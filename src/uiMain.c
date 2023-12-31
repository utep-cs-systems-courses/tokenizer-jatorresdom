#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  
  char string[100];
  int choice;
  List *history = init_history();
  int numHistory;
  char *specificString;
  int temp;
  //  char specificString[100];

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
    choice = menuOpt(string,0);

    //Switch to decide what to do
    switch (choice) {
    case 1:
      printf("Please enter the sentence to be tokenize.\n");
      fgets(string,100,stdin);
      char **tokens = tokenize(string);
      printf("\n");
      print_tokens(tokens);
      choice = -1;
      while(choice != 1 && choice != 2){
	printf("Please enter 'w' to save each word or 's' to save the whole string in the history: ");
	fgets(string,100,stdin);
	choice = menuOpt(string,1);
	switch (choice) {
	case 1:
	  add_history(history,string);
	  break;
	case 2:
	  for (int i = 0; tokens[i] !=NULL; i++){
	    add_history(history, tokens[i]);
	  }
	  break;
	default:
	  printf("Invalid input Please try again.\n");
	  break;
	}
      }
      free_tokens(tokens);
      break;
    case 2:
      temp = string[1] - '0';
      specificString = get_history(history,temp);
      if (specificString != NULL){
	printf("Item in [%c]: ",*(string+1));
	printf("%s\n", specificString);
      }
      else{
	printf("That index is empty \n");
      }
	break;
    case 3:
      print_history(history);
      free_history(history);
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
