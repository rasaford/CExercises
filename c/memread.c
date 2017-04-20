#include <stdio.h>
#include <string.h>

int main() {
  int strings = 0;
  char pointer[] = "";
  for (int i = 0; i < 10000000000; i += 20) {
    printf("BEFORE:   %s\n", pointer - i);
    printf("AFTER:    %s\n", pointer + i);
    strings += 2;
    if (strings % 10 == 0) {
      printf("\nRead %d lines from memory\n\n", strings);
    }
  }
}
