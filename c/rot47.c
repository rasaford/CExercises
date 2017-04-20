#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rot47(char plain) {
  if (plain == ' ') {
    return plain;
  }

  int result = plain + 47;
  if (result > 126) {
    return (result % 127) + 33;
  } else {
    return result;
  }
}

int main(){
  char input[256];
  scanf("%[^\n]%*c", input);
  for (int i = 0; i < strlen(input); i++) {
    printf("%c", rot47(input[i]));
  }
  return 0;
}
