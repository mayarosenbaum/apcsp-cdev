#include <stdio.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], int* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%d", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your arrayAdd function here
int arrayAdd(int *arr, int size , int inc)
{
  int i;
  for (i = 0; i<size; i++){
    *arr = *arr + inc;
    arr++;
  }
}



int main(int argc, char* argv[]) 
{
  // the variable which controls the size of the array
  int size = 100;
  
  // the variable which increments the values in the array
  int inc = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &size, &inc);

  printf("array loop size: %d, inc %d\n", size, inc);
  
  // add your code below to:
  // - initialize the a 'size' element array
  // - fill it with the square of each index using a for loop i.e. 0, 1, 4, 9 etc
  // - pass the array to arrayAdd to add the increment of inc
  // - print out the array

  int array[size];
  int *ptrToArray = array; 
  int j;
  int k;
  for (j=0; j<size; j++){
    array[j] = j*j;
  }
    arrayAdd(ptrToArray, size, inc);
//  }
  for (k = 0; k < size; k++){
    printf("incremented value %d\n", array[k]);
  }
return 0; 
}
