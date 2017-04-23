#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("This programm does nothing but take 2GB of memory and release it after you enter a value to the prompt");
  void *ptr1 = NULL;
  ptr1 = malloc(1024 * 1024 * 1024);
  memset(ptr1, 0, 1024 * 1024 * 1024);

  void *ptr2 = NULL;
  ptr2 = malloc(1024 * 1024 * 1024);
  memset(ptr2, 0, 1024 * 1024 * 1024);

  printf("Enter some values to keep c happy:\n");
  int trash = 0;
  scanf("%d", &trash);
  free(ptr1);
  free(ptr2);
  printf("released the memory\n");
  return 0;
}
