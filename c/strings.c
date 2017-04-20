#include <stdio.h>
#include <strings.h>

struct string {
  char *content;
  int str_len;
  int max_len;
};

int main() {
  typedef struct string string_t;
  string->content = "random_shit";
  printf("%s", string->content);
  return 0;
}
