#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 100

// *** Function Protoypes ***
char *newString(char *str, int size);
void showArray(char **strings, int count);

int main(int argc, char *argv[]){
 
  char *strings[SIZE];
  char temp[SIZE];
  int count = 0;

  while(fgets(temp, SIZE, stdin)){

    strings[count] = newString(temp, strlen(temp) + 1);
    count++;
  }

  showArray(strings, count);

  for(int i = 0; i < count; i++){
    free(strings[i]);
  }

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

void showArray(char **strings, int count){

    int i;
    int j;
    for(i = 0; i < count; i++){
        
        for(j = 0; j < strlen(strings[i]); j++){

            printf("%c", strings[i][j]);
        }
    }
}
