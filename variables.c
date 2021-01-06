#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  printf("A is %d and C is %d\n", a, c);
  b = a;
  a = c;
  c = b;
  printf("A is %d and C is %d\n", a, c);
}
