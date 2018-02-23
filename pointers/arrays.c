#include <stdio.h>

//Array name IS NOT a variable, therefore it cannot be incremented!
int main() {
  int arr_2[] = {1,2,3};
  int arr[] = {1,2,3,4};
  int *ptr = arr;
  //printf("%d", *++arr); //BOOM! lvalue required as increment operand!
  printf("%d", *(arr+1)); //Perfectly fine!
  printf("%d", *++ptr); // Pointer IS a variable!
  printf("%d", ptr[-1]); //No problemo!
  printf("%d", ptr[-100]); //Syntactic no problemo - there is no mechanism to ensure safety of such operations :(((
  //arr = arr_2; //ALSO WRONG, you cannot reassign array! Assignment to expression with array type!
  return 0;
}
