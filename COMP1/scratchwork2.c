#include <stdio.h>

int main(void) {
  
  long blanks, tabs, newlines, input;

  blanks = 0;
  tabs = 0;
  newlines = 0;
  input = 0;

  while ((input = getchar()) != EOF){
    if (input == '\n') {
      ++newlines;
    }

    else if (input == '\t') {
      ++tabs;
    }
  }

  printf("Total newlines: %ld\nTotal Tabs: %ld", newlines, tabs);


    return 0;
}