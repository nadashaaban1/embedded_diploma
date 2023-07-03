#include <stdio.h>
#include <string.h>
int main()
{
char USERNAME[100];
char name[100];
printf("Enter a string:");
fflush(stdin); fflush(stdout);
gets(USERNAME);
printf("Enter your name:");
fflush(stdin); fflush(stdout);
gets(name);
if(stricmp(name,USERNAME)==0)
printf("The string is the same as the username");
else 
printf("The string is not the same as the username");
}
