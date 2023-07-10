#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];
	int length=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);


	for(int i=0; str[i]!=0; i++)
	{
		length++;
	}
	printf("Length of string: %d",length);

}


