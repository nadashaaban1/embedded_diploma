#include <stdio.h>


int main() {
	int a, b, c;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%d""%d""%d",&a,&b,&c);
	if(a>b)
	{
		if(a>c) printf("The largest number is %d \r\n",a);
	else printf("The largest number is %d \r\n",c);
	}
	else if(b>a)
	{
		if(b>c) printf("The largest number is %d \r\n",b);
		else    printf("The largest number is %d \r\n",c);
	}

}
