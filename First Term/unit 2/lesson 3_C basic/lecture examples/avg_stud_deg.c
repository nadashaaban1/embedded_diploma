#include <stdio.h>

int main() {
	int nStudents=0;
	float sum=0, degree,avg;
	printf("Enter the number of the students");
	fflush(stdin); fflush(stdout);
	scanf("%d",&nStudents);
	for(int i=1; i<=nStudents; i++)
	{
		printf("Enter student %d degree",i);
			fflush(stdin); fflush(stdout);
			scanf("%f",&degree);
		sum+=degree;
		avg=sum/nStudents;
	}
printf("average of students degrees is: %f",avg);
}
