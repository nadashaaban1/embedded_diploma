#include <stdio.h>
#include <string.h>

int main()
{
	char str[100],x;
	int freq=0;
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);

	for(int i=0; i<strlen(str); i++)
	{
		if(str[i]==x) freq++;
	}
	printf("Frequency of %c = %d",x,freq);

}


