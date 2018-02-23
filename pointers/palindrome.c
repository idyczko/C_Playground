#include <stdio.h>

int is_palindrome(char *);

int main() {
  char *str;

  scanf("%s", str);
  printf("%d\n", is_palindrome(str));
  return 0;
}

int is_palindrome(char * str) {
  //cool, eh? It takes pointer to whole pointer, increments it (shifts it one place after pointed area)
  //then casts it back to char* and shifts it back once.
  char *l = (char *)(&str + 1) - 1;
  while(*str++ == *l--) {
    if(str >= l) {
      return 1;
    }
  }
  return 0;
}
