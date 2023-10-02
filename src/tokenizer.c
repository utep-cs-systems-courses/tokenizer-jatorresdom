#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int space_char(char c) {
  return (c == ' ' || c == '\t') ? 1 : 0;
}

int non_space_char(char c) {
  return !space_char(c) && c != '\0' ? 1 : 0;
}

char *word_start(char *str) {

  while (space_char(*str))
    str++;
  return (*str == '\0') ? NULL : str;
}

char *word_terminator(char *str) {
  
  while (non_space_char(*str))
    str++;
  return str;
}

int count_words(char *str) {

  int count = 0;
  char *word = word_start(str);
  while (word != NULL) {
    count++;
    word = word_terminator(word);
    word = word_start(word);
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  
  char *copy = (char *)malloc(len + 1);
  if (copy != NULL) {
    strncpy(copy, inStr, len);
    copy[len] = '\0';
  }
  return copy;
}

char **tokenize(char *str) {

  int num_tokens = count_words(str);
  char **tokens = (char **)malloc((num_tokens + 1) * sizeof(char *));
  if (tokens != NULL) {
    char *word = word_start(str);
    for (int i = 0; i < num_tokens; i++) {
      char *terminator = word_terminator(word);
      tokens[i] = copy_str(word, terminator - word);
      word = word_start(terminator);
    }
    tokens[num_tokens] = NULL;
  }
  return tokens;
}

void print_tokens(char **tokens) {

  for (int i = 0; tokens[i] != NULL; i++) {
    printf("tokens[%d] = \"%s\" \n", i, tokens[i]);
  }
}

void free_tokens(char **tokens) {

  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

int menuOpt(char *str){

  if (str == NULL || *str == '\0') {
    return 0; // Input is null or empty
  } else if (*str == '!' && *(str + 1) == 'h') {
    return 3; // "!h" maps to 3
  } else if (*str == 't') {
    return 1; // 't' and '1' both map to 1
  } else if (*str == 'q') {
    return 4; // 'q' maps to 4
  } else if (*str == '!' && isdigit(*(str + 1))) {
    return 2; // '!1', '!2', etc. map to 2
  } else {
    return -1; // No valid option found
  }
}

int word_length(char *str) {

  int length = 0;
  while (non_space_char(*str)) {
    length++;
    str++;
  }
  return length;
}
