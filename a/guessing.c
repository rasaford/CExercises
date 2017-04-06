#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandNumRange(int min, int max) {
  return rand() % max + min;
}

int main() {
  srand( (unsigned) time( NULL  )  );
  printf("The game will chose a number bewteen 1 and 50, It is your job to guess that number\n");
  printf("If your guess wrong the game will tell your weather your guess was over or under\n");

  int userNum = 0;
  int aiNum = getRandNumRange(1, 50);
  int tries = 10;

  while (userNum != aiNum && tries > 0) {
    printf("Your Guess: ");
    scanf("%d", &userNum);
    if (userNum < aiNum) {
      printf("Your number is too low\n");
      tries--;
    } else if (userNum == aiNum) {
      printf("Congrats! your guessed the right number\n");
    } else {
      printf("Your Number is too high\n");
      tries--;
    }
    printf("You have %d tries remaining\n", tries);
  }
}
