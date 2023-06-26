#include <stdio.h>
#include <string.h>

int main()
{
	char str[100],rev[100];
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	int n=strlen(str);

	for(int i=0; i<n+1; i++)
	{
		rev[i]=str[n-i-1];

	}
	printf("Reverse string is : %s",rev);
}


