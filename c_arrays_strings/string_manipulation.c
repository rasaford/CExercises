#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
    char *content;
    int str_len;
    int max_len;
} string_t;

string_t string_after_empty_line(string_t original) {
   char delimiter[] = "\r\n\r\n";
   char* match = strstr(original.content, delimiter);
   // to remove the first n chars just offset the pointer
   match += strlen(delimiter);

   string_t out;
   out.content = match;
   out.str_len = strlen(out.content);
   out.max_len = out.str_len;
   return out;
}

int main() {
    string_t str;
    str.content = "HTTP/1.1 200 OK\r\nContent-Length: 107\r\nDate: Mon, 24 Nov 2014 10:21:21 GMT\r\n\r\n<!DOCTYPE html><html><head></head><body></body></html>";
    str.str_len = strlen(str.content);
    str.max_len = strlen(str.content);
    string_t out = string_after_empty_line(str);
    printf("%s\n", out.content);
    return 0;
}
