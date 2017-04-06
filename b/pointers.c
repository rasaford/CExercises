#include <stdio.h>
#include <stdlib.h>

void func1(int val){
  val = 10;
}

void func2(int *ref){
  *ref = 10;
}

int main() {
  int var = 345;
  int *ptr = NULL;
  ptr = &var;
  printf("This is the address of the pointer %p\n", ptr);
  *ptr = 42;

  int a = 20;
  func1(a);
  printf("after calling func1 a = %d\n", a);
  func2(&a);
  printf("after calling func2 a = %d\n", a);

  return 0;
}
