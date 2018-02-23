#include <stdio.h>

struct point {
  int x;
  int y;
  char c;
} points[] = {1,2, 'c',3,4,'c',5,6,'c',7,8,'c',9,10,'c'};

/*
*Note that -> and . access opreators are really strong.
*/
int main() {
  printf("%d\n", points->x);
  printf("%d\n", points[0].x);
  printf("%d\n", ++points[-1].x);
  printf("%d\n", (*points).x); /*Parentheses are necessary, as . has higher priority.
  //printf("%d\n", *points.x); //BOOM points is neither structure nor union!*/
  struct point pt = {10, 12};
  struct point *ptr = &pt;
  struct point *ptr_2 = &points[-12031239];
  ptr->x = 114;
  (*ptr).y = 110; /*// again, paratheses are necessary!*/

  printf("%d\n", ptr->x + (*ptr).y);
  printf("%d\n", (points + 4) - points); /*// number of elements between pointers*/
  printf("%d\n", sizeof pt); /*// on my pc it returns 12 - 12 bytes though char is taking only one!*/
  printf("%d\n", sizeof ptr); /*// pointer is 8 bytes - long!*/
  printf("%d\n", sizeof(long)); /*// long is 8 bytes long :D*/
  return 0;
}
