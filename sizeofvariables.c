#include<stdio.h>

int main()
{
  int a = 545;
  char b = 'b';
  float c = 4.6;
  double d = 26.78;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  // print value and size of a char variable
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));

  // print value and size of a float variable
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  // print value and size of a double variable
  printf("double d value: %g and size: %lu bytes\n", d, sizeof(d));
}

