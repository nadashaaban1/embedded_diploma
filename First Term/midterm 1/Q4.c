#include <stdio.h>
#include <string.h>
void reverse(char number[],int n)
{
	if(n<0) return;
	printf("%d",number[n]-'0');
	n--;
	reverse(number,n);

}
int main()
{
	char number[100];
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	gets(number);
	printf("input:%s",number);
	printf("\noutput:");
	reverse(number,strlen(number)-1);


}