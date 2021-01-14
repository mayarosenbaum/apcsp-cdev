#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}

// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(float radius)
{
  return(radius*radius*M_PI);
}

int main(int argc, char* argv[]) 
{
  float start;
  int reps;
  char *endptr;

  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  // add your code below to call areaOfCircle function with values between
  // start and end

  char input[256];

  if (argc != 3){
    printf("What is the start value? ");
    fgets(input, 256, stdin);
    sscanf(input, "%f", &start);

    printf("How many reps? ");
    fgets(input, 256, stdin);
    sscanf(input, "%i", &reps);
  }

  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);

  float i;
  for (i=1; i<=reps; i++)
  {
    float r = start + i; 
    //float a;
    float a = areaOfCircle(r);
    printf("Area of circle for radius %f: %f\n", r, a);
}
return 0;
}
