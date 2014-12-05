#include <stdio.h>
int SumArray(int num[], int n)
{
	if(n==0)
		return num[0];
	return num[n] + SumArray(num, n-1);
}
int main(int argc, char *argv[])
{
	int num[] = {1,2,3,4,5};
	int n = 5;
	printf("%d\n", SumArray(num,n-1));
	return 0;
}
