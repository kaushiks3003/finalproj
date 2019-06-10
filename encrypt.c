#include <stdio.h>
#include "encrypt.h"
int main (int argc, char *argv[])
{
 char string[100];
  sscanf(argv[1], "%s", &string); 
  int shift;
  int found2 = sscanf(argv[2], "%d", &shift);
//Integer corresponds to a shift for caesar
  if (found2 !=1)
{
printf("please enter a shift value\n");
return 1;
}
  int eord;
  int found = sscanf(argv[3], "%d", &eord);
  if (found != 1)
 {
  printf("please enter a integer value\n");
  return 1;
 }

 if (!( eord == 1 || eord == 2))
{
printf("Please enter either 1 or 2 for encrypt and decrypt respectivley\n");
return 1;
}

 char porf = argv[4][0];
 if (!( porf == 'p' || porf == 'f'))
{
printf("Please enter either p or f for print and file respectivley\n");
return 1;
}
switch(eord)
{
case 1:
for (int i = 0; (i < 100 && string[i] != '\0'); i++)
 string[i] = string[i] + shift;
  if (porf == 'p')
{
 printf("Encrypted String: %s\n", string);
}
else
{
printf("output saved in storedvalue.txt.\n");
FILE * Fptr;
Fptr = fopen("/var/tmp/storedvalue.txt", "w");
fputs(string, Fptr);
}
break;


case 2:
for(int i = 0; (i < 100 && string[i] != '\0'); i++)
 string[i] = string[i] - shift;
 if (porf == 'p')
{
 printf("Decrypted string: %s\n", string);
}
else
{
printf("Output saved in storedvalue.txt\n");
FILE * Fptr;
Fptr = fopen("/var/tmp/storedvalue.txt", "w");
fputs(string, Fptr);
}
break;
}
return 0;
}
