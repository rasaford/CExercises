#include <stdio.h>
#include <sys/time.h>

double sec_between(struct timeval *start, struct timeval *end) {
  return end->tv_usec - start->tv_usec;
}

double sec_between2(struct timeval *start, struct timeval *end) {
  return (*end).tv_usec - (*start).tv_usec;
}

int main() {
  struct timeval t1_tv;
  struct timeval t2_tv;
  double t;

  gettimeofday(&t1_tv, NULL);
  for (int i = 0; i < 10000; i++) {
    // do something random
  }
  gettimeofday(&t2_tv, NULL);

  t = sec_between(&t1_tv, &t2_tv);
  printf("%lf microseconds have passed since starting the programm\n",t);
  return 0;
}
