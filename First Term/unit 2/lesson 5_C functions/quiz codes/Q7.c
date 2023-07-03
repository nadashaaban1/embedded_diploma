#include <stdio.h>
#include <string.h>
int checkPow(int n)
{
if(n%3==0)
return 0;
return 1;

}
int main()
{
	int n;
	
	scanf("%d",&n);
    fflush(stdin); fflush(stdout);
    printf("%d ==> %d ",n,checkPow(n));
	


}
