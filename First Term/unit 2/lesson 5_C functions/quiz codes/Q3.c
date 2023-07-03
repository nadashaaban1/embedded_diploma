#include <stdio.h>
#include <string.h>
void reverse(int arr[], int n)
{
	if (n < 0)
		return;
	printf("%d ", arr[n]);
	n--;
	reverse(arr, n);
}
int main()
{
	int arr[100], n;
	printf("Enter the size of array: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d", &n);

	printf("Input: ");
	fflush(stdin);
	fflush(stdout);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Output: ");
	reverse(arr, n - 1);
}
