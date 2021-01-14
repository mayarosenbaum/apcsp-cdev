#include <stdio.h>
#include <string.h>

int main ()
{
  char myString[27], myUpperString[27], myJoinedString[54];
  int i;
    for (i=0; i<26; i++){
      myString[i] = 'a' + i;
    }
    myString[26] = '\0';

  char* strConst = "abcdefghijklmnopqrstuvwxyz";

  if (strcmp(myString, strConst) == 0){
    printf("Strings are the same\n");
  }
  else{
    printf("Strings are not the same\n");
  }

  for (i=0; i<26; i++){
	myUpperString[i] = myString[i] - 32;
  }
  myUpperString[26] = '\0';

  // printf("myString[%d]=%s\n",i,myString);
  if (strcmp(myUpperString, strConst) == 0){
    printf("Strings are the same\n");
  }    
  else{
    printf("Strings are not the same\n");
  }

strcat(strcat(myJoinedString,myString),myUpperString);
printf("%s\n%s\n%s\n",myString,myUpperString,myJoinedString);

}

