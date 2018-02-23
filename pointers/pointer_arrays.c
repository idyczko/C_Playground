#include <stdio.h>

/*If you can pass pointer - you can pass array! And vice versa!
*/
void printElementsBackwards(int *subarrayStart, int *superarray);

int main() {
  int tab[] = {0,1,2,3,4,5,6,7,8,9}; // Size is resolved by compiler.
  printElementsBackwards(tab + 4, tab); //Arrays and pointers are almost the same (typewise).
  printf("%d\n", (tab+9)[-4]); //Look at this hack to prevent C from wining about negative indices :D! Sweet!
  int pointer = tab[-10];
  printf("%d\n", pointer);
  return 0;
}

void printElementsBackwards(int *subarrayStart, int *superarray) {
  for(;subarrayStart-- != superarray;)
    printf("%d\n", *subarrayStart);
}
