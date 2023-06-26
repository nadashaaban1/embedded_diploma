#include <stdio.h>
#include <string.h>

int main()
{
char a[20]="alaa ezzat";
char b[20];
strcpy(b,a);
printf("%s",b);
strcat(a,b);
printf("\n%s",a);
strupr(a);
printf("\n%s",a);
printf("\n%d",strlen(b));
printf("\n%d",sizeof(b));
}

