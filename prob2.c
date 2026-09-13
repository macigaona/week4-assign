#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 100

// *** Function Protoypes ***
char *newString(char *str, int size);
void showArray(char **strings);

int main(int argc, char *argv[]){

  char **strings;
  strings = malloc(SIZE * sizeof(char *));
  char temp[SIZE];
  int count = 0;

  while(fgets(temp, SIZE, stdin)){

    strings[count] = newString(temp, strlen(temp) + 1);
    count++;
  }

  strings[count] = NULL;
  showArray(strings);

  for(int i = 0; i < count; i++){
    free(strings[i]);
  }
  free(strings);
    return 0;
}

char *newString(char *str, int size){

    char *newStr;
    newStr = malloc(size * sizeof(char));
    int index;

    for(index = 0; index < size; index++){
        newStr[index] = str[index];
    }

    return newStr;
}

void showArray(char **strings){

    int i;
    while(*strings != NULL){
        
        for(i = 0; i < strlen(*strings); i++){

            printf("%c", (*strings)[i]);
        }
        strings++;
    }
}

