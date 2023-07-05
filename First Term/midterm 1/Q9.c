#include <stdio.h>
#include <string.h>
void reverse(char str[],int n);
int main()
{
	char str[100];
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(str);
	printf("input: %s",str);
	printf("\noutput: ");
	reverse(str,strlen(str));


}
void reverse(char str[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(str[i-1]==' ')
        {
        printf("%s ",&str[i]);
        break;
        }
    }
     for(int k=0;k<n-1;k++)
    {
        printf("%c",str[k]);
        if(str[k]==' ')
        return;
    }

}