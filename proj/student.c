//:
// student.c
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt/encrypt.h"

const char *STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student *students[100] = { 0 };

void
createStudent (char *fname, char *lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

  // First allocate the memory for the variable currentStudent
  Student *currentStudent = (Student *) malloc (sizeof (Student));
  // Then allocate memory for first and last name
  currentStudent->firstName =
    (char *) malloc ((strlen (fname) + 1) * sizeof (char));
  currentStudent->lastName =
    (char *) malloc ((strlen (lname) + 1) * sizeof (char));
  // Now copy the first and last name into currentStudent
  strcpy (currentStudent->firstName, fname);
  strcpy (currentStudent->lastName, lname);
  currentStudent->age = age;
  currentStudent->id = id;

  students[numStudents] = currentStudent;

  numStudents++;
}


void
deleteStudent (Student * currentStudent)
{
  // free the memory associated with a student including the strings
  free (currentStudent->firstName);
  free (currentStudent->lastName);
  free (currentStudent);
}


void
deleteStudents ()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0

  for (int i = 0; i < numStudents; i++)
    {
      deleteStudent (students[i]);
      students[i] = 0;
    }
  numStudents = 0;
}

void
saveStudents (int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532

  FILE *fp;
  char buffer[256];

  fp = fopen ("studentdata.txt", "w");
  if (fp){
      for (int i = 0; i < numStudents; i++){
	  Student *currentStudent = students[i];
	  sprintf (buffer, "%s %s %d %ld", currentStudent->firstName,
		   currentStudent->lastName, currentStudent->age,
		   currentStudent->id);

	  if (key != 0)
	    {
	      caesarEncrypt (buffer, key);
	    }
          printf("saving: %s\n",buffer); 
    
	  fprintf (fp, "%s\n", buffer);
	  }
      fclose (fp);
    }
}


void
loadStudents (int key)
{
  int loadedStudents = 0;
  char buff1[256];
  char buff2[256];
  char buff3[256];
  char buff4[256];
  int moreToRead = 1;
  if (numStudents > 0){
      
      deleteStudents ();
      
  }
  
  // load the students from the data file overwriting all exisiting students in memory
  FILE *fp;

  fp = fopen ("studentdata.txt", "r");
  // check to make sure that file exists
  if (fp){
      
      while (moreToRead == 1){
          
          // check how many elements are in the line
          int match = fscanf (fp, "%s %s %s %s", buff1, buff2, buff3, buff4);
          // if there are 4 elements in the line, the line is valid
          if (match == 4){
              loadedStudents++;
              if (key != 0){
                  caesarDecrypt (buff1, key);
                  caesarDecrypt (buff2, key);
                  caesarDecrypt (buff3, key);
                  caesarDecrypt (buff4, key);
              }
              int age;
              long id;
              sscanf (buff3, "%d", &age);
              sscanf (buff4, "%ld", &id);
              createStudent (buff1, buff2, age, id);
          }
          if (match != 4){
              moreToRead = 0;
          }
      }
      printf("loaded %d students\n",loadedStudents);
  }
  fclose (fp);
}

void
printStudent (Student * student)
{
  printf ("  Student: %s %s\n", student->firstName, student->lastName);
  printf ("    age: %d\n", student->age);
  printf ("    id: %ld\n", student->id);
}

void
printStudents ()
{
  for (int i = 0; i < numStudents; i++)
    {
      printf ("\n----- student %d ------\n", i + 1);
      printStudent (students[i]);
    }
}
