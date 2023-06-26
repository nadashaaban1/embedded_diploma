#include <stdio.h>

int main()
{
	char a;
	float b,c;
	printf("Enter operator either + or - or * or /: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&a);
	printf("Enter two operands: ");
		fflush(stdin); fflush(stdout);
		scanf("%f""%f",&b,&c);
	switch(a)
	{
	case'+':
	{
		printf("%f + %f = %f",b,c,b+c);
	}break;
	case'-':
		{
		printf("%f - %f = %f",b,c,b-c);
		}break;
	case'*':
		{
			printf("%f * %f = %f",b,c,b*c);
		}break;
	case'/':
		{
			printf("%f / %f = %f",b,c,b/c);
		}break;
	}
}
