#include <stdio.h>

int main()
{
	int mat[10][10],transpose[10][10],row=0,col=0;
	printf("Enter rows and columns of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d""%d",&row,&col);

	printf("Enter the elements of matrix:\n");
	for(int i=0; i<row;i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("Enter a%d%d : ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&mat[i][j]);

		}
	}
	printf("Entered Matrix:\n");
	for(int i=0; i<row;i++)
	{
		for(int j=0; j<col; j++)
		{
			printf("%d  ",mat[i][j]);

		} printf("\n");
	}
	for(int i=0; i<row;i++)
	{
		for(int j=0; j<col; j++)
		{

			transpose[j][i]=mat[i][j];
		}
	}

	printf("Transpose of Matrix:\n");
	for(int i=0; i<col;i++)
	{
		for(int j=0; j<row; j++)
		{
			printf("%d  ",transpose[i][j]);

		} printf("\n");
	}
}


