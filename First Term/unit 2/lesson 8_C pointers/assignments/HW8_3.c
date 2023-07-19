#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    char *p = s;
    printf("Input a string: ");
    scanf("%s",p);
    printf("Reverse of the string is: ");

    p=&s[strlen(s)-1];
  
    for (int i = strlen(s); i >=0; i--)
    {
        printf("%c",*p);
        p--;
       
    }
    
    return 0;
}