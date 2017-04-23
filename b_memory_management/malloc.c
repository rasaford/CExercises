#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  void *ptr = NULL;
  ptr = malloc(10000000);
  printf("Enter some values to keep c happy:\n");
  int trash = 0;
  scanf("%d", &trash);
  free(ptr);
  printf("cleared the memory");
  return 0;
}
