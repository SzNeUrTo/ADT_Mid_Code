#include <stdio.h>
int nfac(int n)
{
	if(n==1 || n==0)
		return 1;
	return n*nfac(n-1);
}
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	printf("%d\n", nfac(n));
	return 0;
}
