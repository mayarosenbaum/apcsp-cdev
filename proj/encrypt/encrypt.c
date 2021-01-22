//
// encrypt.c
//
//

#include <string.h>
#include <stdio.h>
#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  
  // First determine direction - if positive (for encrypt)
  if (direction == 1){
      // check which character you have then shift it to the next one in the list
      for (int i = 0; i<CHARS_LEN; i++){
          if (CHARS[i] == c){
              // use the MODULUS operator so that the list wraps around
              int j = (i + shift) % CHARS_LEN;
              c = CHARS[j];
              break;
          }
      }
  }
  
  // If negative direction (for decrypt)
  if (direction == 0){
      // check which character you have then shift it to the next one in the list
      for (int i = 0; i<CHARS_LEN; i++){
          if (CHARS[i] == c){
              // use the MODULUS operator so that the list wraps around
              int j = ((i + CHARS_LEN) - shift) % CHARS_LEN;
              c = CHARS[j];
              break;
          }
      }
  }

  return c;
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];
    
    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}
