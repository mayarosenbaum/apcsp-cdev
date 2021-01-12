#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 10; //variable declaration d
  float* ptrtod; //pointer to variable d
  ptrtod = &d;

  float e = 5; //variable declaration e
  float* ptrtoe; //pointer to variable e
  ptrtoe = &e;

  float temp;

  printf("Value of d: %f. Value of e: %f\n", d, e);
  printf("Address of d: %p. Address of e: %p\n", (void*)&d, (void*)&e);

  temp = *ptrtod;
  *ptrtod = *ptrtoe;
  *ptrtoe = temp;

  printf("Variables after swap: d = %f, e = %f\n", d, e);
}
