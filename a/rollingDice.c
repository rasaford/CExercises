#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandNumRange(int min, int max) {
  return rand() % max + min;
}

int main() {
  srand ( (unsigned) time ( NULL ));
  printf("Dice rolling game... starting\n");
  printf("pick a number bewtween 1 and 6\n");

  int userNum = 0;
  while (userNum < 1 || userNum > 6) {
    scanf("%d", &userNum);
    if (userNum < 1 || userNum > 6) {
      printf("The number must be between 1 and 6");
    }
  }

  int done = 0;
  int steps = 0;
  while (!done) {
    steps++;
    int a = getRandNumRange(1 ,6);
    int b = getRandNumRange(1 ,6);
    int c = getRandNumRange(1 ,6);
    printf("D1:  %d, D2:  %d, D3:  %d\n", a, b, c);
    if (a == userNum && b == userNum && c == userNum) {
      done = 1;
    }
  }
  printf("DONE! It took %d steps to have all three dice match\n", steps);
}
