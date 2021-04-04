#include <stdio.h>
#include <string.h>

void printRLA(char str[]){

  int length = 1; 

  for (int i = 1; str[i] != '\0' ; i++){
    char prevChar = str[i-1];
    if ((prevChar != str[i]) || (length ==9)){
      printf("%d%c", length, prevChar);
            length = 0;

    }

    length += 1;
  }

  //now print the last length and last character
  printf("%d%c", length, str[strlen(str)-1]);

}

int main(void) {
  char str[]= "A";
  printRLA(str);
}
