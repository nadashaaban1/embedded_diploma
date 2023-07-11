#include <stdio.h>
#include <string.h>
int findName(char names[][14],int n,char *name)
{

		for(int i=0;i<n;i++)
		{
			if(strcmp(name,names[i])==0)
			return 1;
		}
		return 0;
}
int main()
{
	char name[14];
	char names[5][14]={"Alaa","Osama","Mamdouh","Samy","Hossain"};
	puts("Enter your first name: ");
	fflush(stdin); fflush(stdout);
	gets(name);
	if(findName(names,5,name)==1)
		puts("Welcome");
	else
		puts("Goodbye");

}
