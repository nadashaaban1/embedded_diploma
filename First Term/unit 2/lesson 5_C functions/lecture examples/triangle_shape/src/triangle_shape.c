#include <stdio.h>
void shape()
{
	for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(i+j>9) break;
				printf("%d ",i+j);
			}
			printf("\n");
		}
}
int main()
{
shape();

}
