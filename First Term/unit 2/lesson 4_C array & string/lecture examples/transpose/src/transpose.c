#include <stdio.h>
int main()
{
	float mat[3][3];
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			printf("Enter the item(%d,%d) : ",i,j);
			fflush(stdin); fflush(stdout);
			scanf("%f",&mat[i][j]);
		}
	}
	printf("the matrix is\n");
	for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
			{

				printf("%f ",mat[i][j]);
			}
			printf("\n");
		}
	printf("the transpose is\n");
		for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{

					printf("%f ",mat[j][i]);
				}
				printf("\n");
			}
}


