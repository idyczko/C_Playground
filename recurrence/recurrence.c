#include <stdio.h>

int tab[] = {1,2,3,4,5,6,7,8,9};
void reverse(int tab[], int index);

int main() {
  reverse(tab, 0);
  int i;
  for(i = 0; i < 9; i++){
    printf("%d\n", tab[i]);
  }
  return 0;
}

/*Reversing array in place
*/
void reverse(int tab[], int index) {
  static int written = 0;
  int mem = tab[index];
  if(index < 8) {
    reverse(tab, ++index);
  }
  tab[written++] = mem;
}
