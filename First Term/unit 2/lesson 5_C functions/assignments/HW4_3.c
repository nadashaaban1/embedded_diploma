#include <stdio.h>
#include <string.h>
void reverse(char sentence[],int n)
{
	if(n<0) return;
	printf("%c",sentence[n]);
	n--;
	reverse(sentence,n);

}
int main()
{
	char sentence[100];
	printf("Enter a sentence: ");
	fflush(stdin); fflush(stdout);
	gets(sentence);
	reverse(sentence,strlen(sentence)-1);


}
