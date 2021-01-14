#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// student structure
//struct Student...

struct Student {
  char firstname[50];
  char lastname[50];
  char age[3];
  int studentid[20];
};

void printStudent(struct Student* student)
{

  //struct Student myStudent;
  printf("\n-----student-----\n");
  printf("  Student: %s %s\n",student->firstname,student->lastname);
  printf("    age: %s\n",student->age);
  printf("    id: %s\n",student->studentid);
}

void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i=1; i<=num; i++){
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;

  int numStudents = 0;
  char input[50];
  struct Student students[100]; // maximum of 100 students alloweda
  struct Student* st = malloc(1000);

  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
      
    }
    else if (c == 'a')
    {
      // enter a new student
    
      numStudents++;
      printf("Enter first name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", st->firstname);

      printf("Enter last name: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", st->lastname);

      printf("Enter age: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", st->age);
      
      printf("Enter student ID: ");
      fgets(input, 256, stdin);
      sscanf(input, "%s", st->studentid);

      students[numStudents] = *st;
    }
  }
  
  printf("\nGoodbye!\n");
}
